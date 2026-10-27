
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "report.h"


#define EMPLOYEE_FILE "File_Manegement/employee.txt"
#define ATTENDANCE_FILE "File_Manegement/attendance.txt"
#define LEAVE_FILE "File_Manegement/leave.txt"
#define SALARY_FILE "File_Manegement/salary.txt"
#define TEMP_FILE "File_Manegement/temp.txt"
#define ATTENDANCE_COUNT_FILE "File_Manegement/attendance_count.txt"

#define LINE_SIZE 512

/* Display heading */
void printHeader(const char *title)
{
    printf("\n============================================================\n");
    printf("                    %s\n", title);
    printf("============================================================\n");
}

/* 1. Employee Report */
void generateEmployeeReport(void)
{
   FILE *file = fopen(EMPLOYEE_FILE, "r");
    char line[LINE_SIZE];
    int count = 0;

    if (file == NULL)
    {
        printf("\nError: Cannot open employee.txt\n");
        printf("Check the File_Manegement folder and file name.\n");
        return;
    }

    printHeader("EMPLOYEE REPORT");

    printf("%-10s %-22s %-8s %-20s\n",
           "ID", "NAME", "DEPT", "POSITION");

    printf("------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *id = strtok(line, "|\r\n");
        char *name = strtok(NULL, "|\r\n");
        char *department = strtok(NULL, "|\r\n");
        char *position = strtok(NULL, "|\r\n");

        if (id != NULL && name != NULL &&
            department != NULL && position != NULL)
        {
            printf("%-10s %-22.22s %-8s %-20.20s\n",
                   id, name, department, position);

            count++;
        }
    }

    printf("------------------------------------------------------------\n");
    printf("Total Employees: %d\n", count);

    fclose(file);
}

/* 2. Attendance Report */

void generateAttendanceReport(void)
{
    FILE *file = fopen(ATTENDANCE_FILE, "r");
    char line[LINE_SIZE];

    int totalRecords = 0;
    int presentCount = 0;
    int absentCount = 0;
    int totalHours = 0;

    if (file == NULL)
    {
        printf("\nCannot open attendance.txt\n");
        return;
    }

    printHeader("ATTENDANCE REPORT");

    printf("%-15s %-15s %-15s %-10s\n",
           "EMPLOYEE ID", "DATE", "STATUS", "HOURS");

    printf("------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *id = strtok(line, "|\r\n");
        char *date = strtok(NULL, "|\r\n");
        char *status = strtok(NULL, "|\r\n");
        char *hours = strtok(NULL, "|\r\n");

        if (id != NULL && date != NULL &&
            status != NULL && hours != NULL)
        {
            int workedHours = atoi(hours);

            printf("%-15s %-15s %-15s %-10d\n",
                   id, date, status, workedHours);

            totalRecords++;
            totalHours += workedHours;

            if (strcmp(status, "Present") == 0)
            {
                presentCount++;
            }
            else if (strcmp(status, "Absent") == 0)
            {
                absentCount++;
            }
        }
    }

    printf("------------------------------------------------------------\n");
    printf("Total Attendance Records: %d\n", totalRecords);
    printf("Present Records: %d\n", presentCount);
    printf("Absent Records: %d\n", absentCount);
    printf("Total Hours Worked: %d\n", totalHours);

    fclose(file);
}


/* 3. Leave Report */


void generateLeaveReport(void)
{
    FILE *file = fopen(TEMP_FILE, "r");

    char employeeID[100];
    char leaveType[50];
    char status[50];
    int days;

    int count = 0;
    int approvedCount = 0;
    int pendingCount = 0;
    int rejectedCount = 0;

    if (file == NULL)
    {
        printf("\nCannot open temp.txt\n");
        return;
    }

    printHeader("LEAVE REPORT");

    printf("%-24s %-15s %-10s %-12s\n",
           "EMPLOYEE ID", "LEAVE TYPE", "DAYS", "STATUS");

    printf("--------------------------------------------------------------------------\n");

    while (fscanf(file, "%99s %49s %d %49s",
                  employeeID, leaveType, &days, status) == 4)
    {
        printf("%-24s %-15s %-10d %-12s\n",
               employeeID, leaveType, days, status);

        count++;

        if (strcmp(status, "Approved") == 0)
            approvedCount++;
        else if (strcmp(status, "Pending") == 0)
            pendingCount++;
        else if (strcmp(status, "Rejected") == 0)
            rejectedCount++;
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Total Leave Records: %d\n", count);
    printf("Approved Requests: %d\n", approvedCount);
    printf("Pending Requests: %d\n", pendingCount);
    printf("Rejected Requests: %d\n", rejectedCount);

    fclose(file);
}



/* 4. Salary Report */

/* Identify category from employee position */
static const char *getSalaryCategory(const char *position)
{
    if (strcmp(position, "Lecturer") == 0 ||
        strcmp(position, "Professor") == 0 ||
        strcmp(position, "professor") == 0 ||
        strcmp(position, "Demonstrator") == 0 ||
        strcmp(position, "Senior Lecturer") == 0)
        return "Academic";

    if (strcmp(position, "Technician") == 0 ||
        strcmp(position, "Technical Officer") == 0 ||
        strcmp(position, "Engineer") == 0)
        return "Technical";

    return "Non-academic";
}

void generateSalaryReport(void)
{
    char ids[500][100];
    char categories[500][30];
    double salaries[500] = {0};
    int hasSalary[500] = {0};
    int count = 0;
    int i, j;
    char line[LINE_SIZE];
    char salaryID[100];
    double salary;

    int academicCount = 0, technicalCount = 0, nonAcademicCount = 0;
    double academicTotal = 0, technicalTotal = 0, nonAcademicTotal = 0;

    FILE *empFile = fopen(EMPLOYEE_FILE, "r");

    if (empFile == NULL)
    {
        printf("Cannot open employee.txt\n");
        return;
    }

    /* employee.txt:
       ID|Name|NIC|Phone|Position|Department|Date|Username|Password
    */
    while (fgets(line, sizeof(line), empFile) != NULL && count < 500)
    {
        char *id = strtok(line, "|\r\n");
        char *name = strtok(NULL, "|\r\n");
        char *nic = strtok(NULL, "|\r\n");
        char *phone = strtok(NULL, "|\r\n");
        char *position = strtok(NULL, "|\r\n");

        if (id == NULL || name == NULL || nic == NULL ||
            phone == NULL || position == NULL)
            continue;

        /* Avoid duplicate employee IDs */
        for (i = 0; i < count; i++)
            if (strcmp(ids[i], id) == 0)
                break;

        if (i != count)
            continue;

        snprintf(ids[count], sizeof(ids[count]), "%s", id);
        snprintf(categories[count], sizeof(categories[count]),
                 "%s", getSalaryCategory(position));
        count++;
    }

    fclose(empFile);

    /* salary.txt format: EmployeeID Salary */
    FILE *salFile = fopen(SALARY_FILE, "r");

    if (salFile == NULL)
    {
        printf("Cannot open salary.txt\n");
        return;
    }

    while (fscanf(salFile, "%99s %lf", salaryID, &salary) == 2)
    {
        for (i = 0; i < count; i++)
        {
            if (strcmp(ids[i], salaryID) == 0)
            {
                salaries[i] = salary;
                hasSalary[i] = 1;
                break;
            }
        }
    }

    fclose(salFile);

    /* Calculate category totals using employees with salaries */
    for (i = 0; i < count; i++)
    {
        if (!hasSalary[i])
            continue;

        if (strcmp(categories[i], "Academic") == 0)
        {
            academicCount++;
            academicTotal += salaries[i];
        }
        else if (strcmp(categories[i], "Technical") == 0)
        {
            technicalCount++;
            technicalTotal += salaries[i];
        }
        else
        {
            nonAcademicCount++;
            nonAcademicTotal += salaries[i];
        }
    }

    printHeader("REPORT - EMPLOYEES BY CATEGORY");

    printf("%-18s %-12s %-20s %-20s\n",
           "Category", "Employees", "Total Salary", "Average Salary");
    printf("--------------------------------------------------------------------------\n");

    printf("%-18s %-12d Rs. %12.2f Rs. %12.2f\n",
           "Academic", academicCount, academicTotal,
           academicCount ? academicTotal / academicCount : 0.0);

    printf("%-18s %-12d Rs. %12.2f Rs. %12.2f\n",
           "Technical", technicalCount, technicalTotal,
           technicalCount ? technicalTotal / technicalCount : 0.0);

    printf("%-18s %-12d Rs. %12.2f Rs. %12.2f\n",
           "Non-academic", nonAcademicCount, nonAcademicTotal,
           nonAcademicCount ? nonAcademicTotal / nonAcademicCount : 0.0);

    printf("--------------------------------------------------------------------------\n");
    printf("Total employees: %d\n",
           academicCount + technicalCount + nonAcademicCount);
}



/* Reports Menu */
void reportsMenu(void)
{
    int choice;

    do
    {
        printHeader("REPORTS MENU");

        printf("[1] Employee Report\n");
        printf("[2] Attendance Report\n");
        printf("[3] Leave Report\n");
        printf("[4] Salary Report\n");
        printf("[0] Back to Main Menu\n");

        printf("------------------------------------------------------------\n");
        printf("Enter Choice: ");

        if (scanf("%d", &choice) != 1)
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                /* Clear invalid input */
            }

            choice = -1;
            printf("Invalid input. Enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                generateEmployeeReport();
                break;

            case 2:
                generateAttendanceReport();
                break;

            case 3:
                generateLeaveReport();
                break;

            case 4:
                generateSalaryReport();
                break;

            case 0:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);
}
