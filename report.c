#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "report.h"

#define MAX_FIELDS 16
#define MAX_LINE   512
#define MAX_EMP    500

/* ------------------------------------------------------------------
 * FILE FORMATS (as used in the project)
 *
 *  employee.txt         id|name|NIC|phone|designation|department|joined|id|password|...
 *  attendance.txt       id|name|department|date|status|time
 *  leave.txt            id type days status          (space separated)
 *  salary.txt           id amount                    (space separated)
 *
 *  The password column of employee.txt is never printed.
 * ------------------------------------------------------------------ */

#define FIELD_NAME_LOOKUP  (-2)   /* column value = employee name found by id */

enum { COL_TEXT, COL_DEPT };

typedef struct {
    const char *header;   /* column title                             */
    int         field;    /* field number in the file (0,1,2...)      */
    int         width;    /* column width on screen / in report file  */
    int         kind;     /* COL_TEXT or COL_DEPT (short dept name)   */
} Column;

/* ---------------- small helpers ---------------- */

/* print to the screen AND to the report file */
static void emit(FILE *out, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    if (out) {
        va_start(ap, fmt);
        vfprintf(out, fmt, ap);
        va_end(ap);
    }
}

static void rule(FILE *out, char ch, int len)
{
    int i;
    for (i = 0; i < len; i++)
        emit(out, "%c", ch);
    emit(out, "\n");
}

/* split a line into fields. delim ' ' means "any spaces / tabs" */
static int split_line(char *line, char delim, char *fields[], int max)
{
    int n = 0;
    char *p;

    line[strcspn(line, "\r\n")] = '\0';

    if (delim == ' ') {
        p = strtok(line, " \t");
        while (p && n < max) {
            fields[n++] = p;
            p = strtok(NULL, " \t");
        }
        return n;
    }

    if (line[0] == '\0')
        return 0;

    p = line;
    fields[n++] = p;
    while (*p && n < max) {
        if (*p == delim) {
            *p = '\0';
            fields[n++] = p + 1;
        }
        p++;
    }
    return n;
}

/* find employee name from employee.txt using the id */
static void lookup_name(const char *id, char *out, size_t size)
{
    FILE *f = fopen(EMPLOYEE_FILE, "r");
    char line[MAX_LINE];
    char *fields[MAX_FIELDS];
    int n;

    snprintf(out, size, "-");
    if (!f)
        return;

    while (fgets(line, sizeof line, f)) {
        n = split_line(line, '|', fields, MAX_FIELDS);
        if (n > 1 && strcmp(fields[0], id) == 0) {
            snprintf(out, size, "%s", fields[1]);
            break;
        }
    }
    fclose(f);
}

/* long department name -> short code */
static const char *dept_short(const char *d)
{
    if (strstr(d, "nformation"))  return "ICT";
    if (strstr(d, "ngineering"))  return "ET";
    if (strstr(d, "iosystem"))    return "BST";
    return d;
}

/* ---------------- report layout ---------------- */

static FILE *begin_report(const char *outFile, const char *title, int width)
{
    FILE *out = fopen(outFile, "w");    /* if it fails we still show the screen */

    emit(out, "\n");
    rule(out, '=', width);
    emit(out, "  FACULTY OF TECHNOLOGY - UNIVERSITY OF RUHUNA\n");
    emit(out, "  %s\n", title);
    rule(out, '=', width);
    return out;
}

static void end_report(FILE *out, const char *outFile, int width)
{
    rule(out, '=', width);
    if (out) {
        fclose(out);
        printf("\nReport saved to %s\n", outFile);
    }
}

static void section_title(FILE *out, const char *text, int width)
{
    emit(out, "\n  %s\n", text);
    rule(out, '-', width);
}

/* print one table from a data file */
static void print_table(FILE *out, const char *inFile, char delim,
                        const Column cols[], int nCols,
                        int sumCol, const char *sumLabel, int decimals)
{
    FILE *in = fopen(inFile, "r");
    char line[MAX_LINE], buf[128];
    char *fields[MAX_FIELDS];
    int i, n, count = 0, width = 4;
    double total = 0.0;

    for (i = 0; i < nCols; i++)
        width += cols[i].width;

    if (!in) {
        emit(out, "  Cannot open %s\n", inFile);
        return;
    }

    emit(out, "%-4s", "No");
    for (i = 0; i < nCols; i++)
        emit(out, "%-*s", cols[i].width, cols[i].header);
    emit(out, "\n");
    rule(out, '-', width);

    while (fgets(line, sizeof line, in)) {
        n = split_line(line, delim, fields, MAX_FIELDS);
        if (n == 0)
            continue;                       /* skip blank lines */

        count++;
        emit(out, "%-4d", count);
        for (i = 0; i < nCols; i++) {
            const char *val = "-";

            if (cols[i].field == FIELD_NAME_LOOKUP) {
                lookup_name(fields[0], buf, sizeof buf);
                val = buf;
            } else if (cols[i].field < n && fields[cols[i].field][0] != '\0') {
                val = fields[cols[i].field];
            }

            if (cols[i].kind == COL_DEPT)
                val = dept_short(val);
            if (i == sumCol)
                total += atof(val);

            emit(out, "%-*.*s", cols[i].width, cols[i].width - 1, val);
        }
        emit(out, "\n");
    }
    fclose(in);

    rule(out, '-', width);
    emit(out, "Total records : %d\n", count);
    if (sumCol >= 0)
        emit(out, "%-16s: %.*f\n", sumLabel, decimals, total);
}

/* ================= 1. ATTENDANCE REPORT ================= */

void attendance_report(void)
{
    clearScreen();
    const Column cols[] = {
        { "Employee ID", 0, 17, COL_TEXT },
        { "Name",        1, 16, COL_TEXT },
        { "Dept",        2,  6, COL_DEPT },
        { "Date",        3, 12, COL_TEXT },
        { "Status",      4,  9, COL_TEXT },
        { "Time",        5,  7, COL_TEXT }
    };
    int width = 71;
    FILE *out = begin_report(ATTENDANCE_REPORT_FILE, "ATTENDANCE REPORT", width);

    print_table(out, ATTENDANCE_FILE, '|', cols, 6, -1, "", 0);

    end_report(out, ATTENDANCE_REPORT_FILE, width);
}

/* ================= 2. EMPLOYEE REPORT ================= */

void employee_report(void)
{
    clearScreen();
    const Column cols[] = {
        { "Employee ID", 0, 16, COL_TEXT },
        { "Name",        1, 15, COL_TEXT },
        { "NIC",         2, 15, COL_TEXT },
        { "Phone",       3, 12, COL_TEXT },
        { "Designation", 4, 12, COL_TEXT },
        { "Dept",        5,  6, COL_DEPT },
        { "Joined",      6, 11, COL_TEXT }
    };                                       /* password columns not shown */
    int width = 91;
    FILE *out = begin_report(EMPLOYEE_REPORT_FILE, "EMPLOYEE REPORT", width);

    print_table(out, EMPLOYEE_FILE, '|', cols, 7, -1, "", 0);

    end_report(out, EMPLOYEE_REPORT_FILE, width);
}

/* ================= 3. LEAVE REPORT ================= */

void leave_report(void)
{
    clearScreen();
    const Column cols[] = {
        { "Employee ID", 0, 17, COL_TEXT },
        { "Name",        FIELD_NAME_LOOKUP, 16, COL_TEXT },
        { "Leave Type",  1, 12, COL_TEXT },
        { "Days",        2,  7, COL_TEXT },
        { "Status",      3, 10, COL_TEXT }
    };
    int width = 66;
    FILE *out = begin_report(LEAVE_REPORT_FILE, "LEAVE REPORT", width);

    print_table(out, LEAVE_FILE, ' ', cols, 5, 3, "Total leave days", 0);

    end_report(out, LEAVE_REPORT_FILE, width);
}

/* ================= 4. SALARY REPORT ================= */

typedef struct {
    char   id[48];
    int    count;
    double total;
} SalaryTotal;

static void salary_summary(FILE *out, int width)
{
    FILE *in = fopen(SALARY_FILE, "r");
    SalaryTotal t[MAX_EMP];
    char line[MAX_LINE], name[128];
    char *fields[MAX_FIELDS];
    int i, n, nt = 0;
    double grand = 0.0;

    if (!in)
        return;

    while (fgets(line, sizeof line, in)) {
        n = split_line(line, ' ', fields, MAX_FIELDS);
        if (n < 2)
            continue;

        for (i = 0; i < nt; i++)
            if (strcmp(t[i].id, fields[0]) == 0)
                break;
        if (i == nt) {
            if (nt == MAX_EMP)
                continue;
            snprintf(t[nt].id, sizeof t[nt].id, "%s", fields[0]);
            t[nt].count = 0;
            t[nt].total = 0.0;
            nt++;
        }
        t[i].count++;
        t[i].total += atof(fields[1]);
    }
    fclose(in);

    section_title(out, "SALARY SUMMARY (total per employee)", width);
    emit(out, "%-4s%-17s%-16s%-10s%-14s\n", "No", "Employee ID", "Name",
         "Payments", "Total Salary");
    rule(out, '-', width);

    for (i = 0; i < nt; i++) {
        lookup_name(t[i].id, name, sizeof name);
        emit(out, "%-4d%-17.16s%-16.15s%-10d%-14.2f\n",
             i + 1, t[i].id, name, t[i].count, t[i].total);
        grand += t[i].total;
    }
    rule(out, '-', width);
    emit(out, "Total employees : %d\n", nt);
    emit(out, "Grand total     : %.2f\n", grand);
}

void salary_report(void)
{
    clearScreen();
    const Column cols[] = {
        { "Employee ID", 0, 17, COL_TEXT },
        { "Name",        FIELD_NAME_LOOKUP, 16, COL_TEXT },
        { "Amount",      1, 14, COL_TEXT }
    };
    int width = 64;
    FILE *out = begin_report(SALARY_REPORT_FILE, "SALARY REPORT", width);

    print_table(out, SALARY_FILE, ' ', cols, 3, 2, "Total salary", 2);
    salary_summary(out, width);

    end_report(out, SALARY_REPORT_FILE, width);
}

/* ================= menu ================= */

void report_menu(void)
{
    clearScreen();
    int choice;
    char buf[32];

    do {
        printf("\n===== REPORTS =====\n");
        printf("1. Attendance Report\n");
        printf("2. Employee Report\n");
        printf("3. Leave Report\n");
        printf("4. Salary Report\n");
        printf("0. Back\n");
        printf("Enter choice: ");

        if (!fgets(buf, sizeof buf, stdin))
            return;
        choice = atoi(buf);

        switch (choice) {
            case 1: attendance_report(); break;
            case 2: employee_report();   break;
            case 3: leave_report();      break;
            case 4: salary_report();     break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
}