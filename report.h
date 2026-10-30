#ifndef REPORT_H
#define REPORT_H

/* data files that are opened (read) */
#define EMPLOYEE_FILE    "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt"
#define ATTENDANCE_FILE  "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\attendance.txt"
#define LEAVE_FILE       "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt"
#define SALARY_FILE      "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\salary.txt"

/* report files that are created (written) */
#define EMPLOYEE_REPORT_FILE    "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee_report.txt"
#define ATTENDANCE_REPORT_FILE  "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\attendance_report.txt"
#define LEAVE_REPORT_FILE       "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave_report.txt"
#define SALARY_REPORT_FILE      "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\salary_report.txt"

void employee_report(void);    /* employee.txt   -> employee_report.txt   */
void attendance_report(void);  /* attendance.txt -> attendance_report.txt */
void leave_report(void);       /* leave.txt      -> leave_report.txt      */
void salary_report(void);      /* salary.txt     -> salary_report.txt     */
void report_menu(void);        /* simple menu to pick a report            */

#endif
