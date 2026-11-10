#ifndef REPORT_H
#define REPORT_H

/* data files that are opened (read) */
#define EMPLOYEE_FILE    "File_Manegement/employee.txt"
#define ATTENDANCE_FILE  "File_Manegement/attendance.txt"
#define LEAVE_FILE       "File_Manegement/leave.txt"
#define SALARY_FILE      "File_Manegement/salary.txt"

/* report files that are created (written) */
#define EMPLOYEE_REPORT_FILE    "File_Manegement/employee_report.txt"
#define ATTENDANCE_REPORT_FILE  "File_Manegement/attendance_report.txt"
#define LEAVE_REPORT_FILE       "File_Manegement/leave_report.txt"
#define SALARY_REPORT_FILE      "File_Manegement/salary_report.txt"

void employee_report(void);    
void attendance_report(void);  
void leave_report(void);      
void salary_report(void);     
void report_menu(void);   
void clearScreen();     

#endif
