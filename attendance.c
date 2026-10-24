#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "attendance.h"
#include "attendance_count.h"   /* <-- ADD KALA */
#include "menu.h"

#define EMP_FILE "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt"
#define ATT_FILE "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\attendance.txt"
#define MAX_ATT  5000

typedef struct {
    char id[50], name[100], date[15], status[20], time[10];
} AttRec;

static AttRec recs[MAX_ATT];

/* ================= helpers ================= */

static void attReadLine(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    if (!fgets(buf, size, stdin)) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\r\n")] = '\0';
}

static void attPause(void) {
    printf("\nPress Enter...");
    getchar();
}

static void attHeader(const char *title) {
    printf("===============================================\n\n");
    printf(" %s\n\n", departments[selectedDept - 1]);
    printf("\t\t%s\n\n", title);
    printf("===============================================\n\n");
}

static int attSplit(char *line, char *f[], int max) {
    int n = 0;
    f[n++] = line;
    for (char *p = line; *p && n < max; p++)
        if (*p == '|') { *p = '\0'; f[n++] = p + 1; }
    return n;
}

static int attFindEmployee(const char *id, char *name, int nsz, char *dept, int dsz) {
    FILE *fp = fopen(EMP_FILE, "r");
    if (!fp) return 0;
    char line[600];
    while (fgets(line, sizeof line, fp)) {
        line[strcspn(line, "\r\n")] = '\0';
        char *f[9];
        if (attSplit(line, f, 9) < 6) continue;
        if (strcmp(f[0], id) == 0) {
            snprintf(name, nsz, "%s", f[1]);
            snprintf(dept, dsz, "%s", f[5]);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

static int attValidDate(const char *s) {
    int y, m, d;
    if (strlen(s) != 10 || s[4] != '-' || s[7] != '-') return 0;
    if (sscanf(s, "%d-%d-%d", &y, &m, &d) != 3) return 0;
    int dm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) dm[1] = 29;
    return y >= 2000 && y <= 2100 && m >= 1 && m <= 12 && d >= 1 && d <= dm[m - 1];
}

static int attValidMonth(const char *s) {
    int y, m;
    if (strlen(s) != 7 || s[4] != '-') return 0;
    if (sscanf(s, "%d-%d", &y, &m) != 2) return 0;
    return y >= 2000 && y <= 2100 && m >= 1 && m <= 12;
}

static void attNow(char *date, char *tm) {
    time_t t = time(NULL);
    struct tm *l = localtime(&t);
    strftime(date, 15, "%Y-%m-%d", l);
    strftime(tm, 10, "%H:%M", l);
}

/* select karapu department eke records witharak load karanawa */
static int attLoad(void) {
    FILE *fp = fopen(ATT_FILE, "r");
    if (!fp) return 0;
    int n = 0;
    char line[500];
    while (n < MAX_ATT && fgets(line, sizeof line, fp)) {
        line[strcspn(line, "\r\n")] = '\0';
        char *f[6];
        if (attSplit(line, f, 6) < 6) continue;
        /* id|name|dept|date|status|time */
        if (strcmp(f[2], departments[selectedDept - 1]) != 0) continue;
        snprintf(recs[n].id,     sizeof recs[n].id,     "%s", f[0]);
        snprintf(recs[n].name,   sizeof recs[n].name,   "%s", f[1]);
        snprintf(recs[n].date,   sizeof recs[n].date,   "%s", f[3]);
        snprintf(recs[n].status, sizeof recs[n].status, "%s", f[4]);
        snprintf(recs[n].time,   sizeof recs[n].time,   "%s", f[5]);
        n++;
    }
    fclose(fp);
    return n;
}

static int attExists(const char *id, const char *date) {
    int n = attLoad();
    for (int i = 0; i < n; i++)
        if (strcmp(recs[i].id, id) == 0 && strcmp(recs[i].date, date) == 0) return 1;
    return 0;
}

static void attPrintTableHead(void) {
    printf("%-16s %-24s %-12s %-10s %s\n", "Employee ID", "Name", "Date", "Status", "Time");
    printf("---------------------------------------------------------------------\n");
}

static void attPrintRec(const AttRec *r) {
    printf("%-16s %-24s %-12s %-10s %s\n", r->id, r->name, r->date, r->status, r->time);
}

/* ================= 1. Mark Attendance ================= */

void markAttendance(void) {
    char id[50], name[100], dept[120], date[15], tm[10], today[15], buf[20];
    const char *statuses[] = {"", "Present", "Absent", "Half Day", "Late"};

    clearScreen();
    attHeader("MARK ATTENDANCE");

    attReadLine("Employee ID : ", id, sizeof id);
    if (id[0] == '\0') { printf("\nEmployee ID empty!"); attPause(); return; }

    if (!attFindEmployee(id, name, sizeof name, dept, sizeof dept)) {
        printf("\nEmployee not found!");
        attPause();
        return;
    }
    if (strcmp(dept, departments[selectedDept - 1]) != 0) {
        printf("\nThis employee belongs to:\n%s\n", dept);
        attPause();
        return;
    }
    printf("Name        : %s\n\n", name);

    attNow(today, tm);
    attReadLine("Date (YYYY-MM-DD, Enter = today) : ", date, sizeof date);
    if (date[0] == '\0') snprintf(date, sizeof date, "%s", today);
    if (!attValidDate(date)) { printf("\nInvalid date!"); attPause(); return; }

    if (attExists(id, date)) {
        printf("\nAttendance already marked for %s on %s!", id, date);
        attPause();
        return;
    }

    printf("\n[1] Present\n[2] Absent\n[3] Half Day\n[4] Late\n\n");
    attReadLine("Status : ", buf, sizeof buf);
    int s = atoi(buf);
    if (s < 1 || s > 4) { printf("\nInvalid status!"); attPause(); return; }

    const char *timeStr = (s == 2) ? "-" : tm;

    FILE *fp = fopen(ATT_FILE, "a");
    if (!fp) { printf("\nCannot open %s!", ATT_FILE); attPause(); return; }
    fprintf(fp, "%s|%s|%s|%s|%s|%s\n", id, name, dept, date, statuses[s], timeStr);
    fclose(fp);

    update_attendance_count();   /* <-- METHANA: fclose ekata passe */

    printf("\nAttendance marked: %s - %s (%s)", name, statuses[s], date);
    attPause();
}

/* ================= 2. View Attendance ================= */

void viewAttendance(void) {
    clearScreen();
    attHeader("VIEW ATTENDANCE");
    int n = attLoad();
    if (n == 0) { printf("No attendance records.\n"); attPause(); return; }
    attPrintTableHead();
    for (int i = 0; i < n; i++) attPrintRec(&recs[i]);
    printf("\nTotal records : %d\n", n);
    attPause();
}

/* ================= 3. Search Attendance ================= */

void searchAttendance(void) {
    char id[50], date[15];
    clearScreen();
    attHeader("SEARCH ATTENDANCE");

    attReadLine("Employee ID (Enter to skip) : ", id, sizeof id);
    attReadLine("Date YYYY-MM-DD (Enter to skip) : ", date, sizeof date);

    if (id[0] == '\0' && date[0] == '\0') {
        printf("\nEnter at least one search value!");
        attPause();
        return;
    }
    if (date[0] != '\0' && !attValidDate(date)) {
        printf("\nInvalid date!");
        attPause();
        return;
    }

    int n = attLoad(), found = 0;
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (id[0]   && strcmp(recs[i].id, id)     != 0) continue;
        if (date[0] && strcmp(recs[i].date, date) != 0) continue;
        if (!found) attPrintTableHead();
        attPrintRec(&recs[i]);
        found++;
    }
    if (!found) printf("No matching records.\n");
    else        printf("\nFound : %d\n", found);
    attPause();
}

/* ================= 4. Monthly Report ================= */

void monthlyReport(void) {
    char month[10];
    clearScreen();
    attHeader("MONTHLY REPORT");

    attReadLine("Month (YYYY-MM) : ", month, sizeof month);
    if (!attValidMonth(month)) { printf("\nInvalid month!"); attPause(); return; }

    int n = attLoad();

    FILE *fp = fopen(EMP_FILE, "r");
    if (!fp) { printf("\nCannot open %s!", EMP_FILE); attPause(); return; }

    printf("\nReport for %s\n\n", month);
    printf("%-16s %-24s %8s %7s %9s %5s\n", "Employee ID", "Name", "Present", "Absent", "Half Day", "Late");
    printf("-------------------------------------------------------------------------\n");

    char line[600];
    int count = 0;
    while (fgets(line, sizeof line, fp)) {
        line[strcspn(line, "\r\n")] = '\0';
        char *f[9];
        if (attSplit(line, f, 9) < 6) continue;
        if (strcmp(f[5], departments[selectedDept - 1]) != 0) continue;

        int p = 0, a = 0, h = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(recs[i].id, f[0]) != 0) continue;
            if (strncmp(recs[i].date, month, 7) != 0) continue;
            if      (strcmp(recs[i].status, "Present")  == 0) p++;
            else if (strcmp(recs[i].status, "Absent")   == 0) a++;
            else if (strcmp(recs[i].status, "Half Day") == 0) h++;
            else if (strcmp(recs[i].status, "Late")     == 0) l++;
        }
        printf("%-16s %-24s %8d %7d %9d %5d\n", f[0], f[1], p, a, h, l);
        count++;
    }
    fclose(fp);

    if (!count) printf("No employees in this department.\n");
    attPause();
}