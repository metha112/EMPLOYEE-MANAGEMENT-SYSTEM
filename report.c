
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "report.h"
#include "menu.h"


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
    FILE *file = fopen("C:\\Users\\New\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt", "r");
    char line[LINE_SIZE];

    int count = 0;
    int approvedCount = 0;
    int pendingCount = 0;
    int rejectedCount = 0;

    if (file == NULL)
    {
        printf("\nCannot open leave.txt\n");
        return;
    }

    printHeader("LEAVE REPORT");

    printf("%-10s %-12s %-15s %-15s %-12s\n",
           "LEAVE ID", "EMPLOYEE ID",
           "START DATE", "END DATE", "STATUS");

    printf("--------------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {   
        printf(" %s", line);

        char *leaveID = strtok(line, "|\r\n");
        char *employeeID = strtok(NULL, "|\r\n");
        char *startDate = strtok(NULL, "|\r\n");
        char *endDate = strtok(NULL, "|\r\n");
        char *status = strtok(NULL, "|\r\n");

        if (leaveID != NULL && employeeID != NULL &&
            startDate != NULL && endDate != NULL &&
            status != NULL)
        {
            printf("%-10s %-12s %-15s %-15s %-12s\n",
                   leaveID, employeeID,
                   startDate, endDate, status);

            count++;

            if (strcmp(status, "Approved") == 0)
                approvedCount++;
            else if (strcmp(status, "Pending") == 0)
                pendingCount++;
            else if (strcmp(status, "Rejected") == 0)
                rejectedCount++;
        }
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Total Leave Records: %d\n", count);
    printf("Approved Requests: %d\n", approvedCount);
    printf("Pending Requests: %d\n", pendingCount);
    printf("Rejected Requests: %d\n", rejectedCount);

    fclose(file);
}


/* 4. Salary Report */

/* 4. Salary Report */
void generateSalaryReport(void)
{
    FILE *file = fopen(SALARY_FILE, "r");
    char line[LINE_SIZE];

    int count = 0;
    double totalBasic = 0.0;
    double totalAllowances = 0.0;
    double totalDeductions = 0.0;
    double totalNet = 0.0;

    if (file == NULL)
    {
        printf("\nCannot open salary.txt\n");
        return;
    }

    printHeader("SALARY REPORT");

    printf("%-10s %-15s %-15s %-15s %-15s\n",
           "ID", "BASIC", "ALLOWANCES",
           "DEDUCTIONS", "NET SALARY");

    printf("--------------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *id = strtok(line, "|\r\n");
        char *basic = strtok(NULL, "|\r\n");
        char *allowance = strtok(NULL, "|\r\n");
        char *deduction = strtok(NULL, "|\r\n");
        char *net = strtok(NULL, "|\r\n");

        if (id != NULL && basic != NULL &&
            allowance != NULL && deduction != NULL &&
            net != NULL)
        {
            double basicSalary = atof(basic);
            double allowanceAmount = atof(allowance);
            double deductionAmount = atof(deduction);
            double netSalary = atof(net);

            printf("%-10s %-15.2f %-15.2f %-15.2f %-15.2f\n",
                   id, basicSalary, allowanceAmount,
                   deductionAmount, netSalary);

            totalBasic += basicSalary;
            totalAllowances += allowanceAmount;
            totalDeductions += deductionAmount;
            totalNet += netSalary;
            count++;
        }
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Total Salary Records: %d\n", count);
    printf("Total Basic Salary: Rs. %.2f\n", totalBasic);
    printf("Total Allowances: Rs. %.2f\n", totalAllowances);
    printf("Total Deductions: Rs. %.2f\n", totalDeductions);
    printf("Combined Net Salary: Rs. %.2f\n", totalNet);

    fclose(file);
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
