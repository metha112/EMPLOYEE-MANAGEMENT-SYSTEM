#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "employee.h"
#include "department.h"
#include "attendance.h"
#include "leave.h"
#include "salary.h"

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*main manu*/

void showMainMenu(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n\n");
        printf("\tUNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("\t\tEMPLOYEE MANAGEMENT SYSTEM");
        printf("\n\n================================================================\n");
        printf("\n");
        printf("[1] Employee Management\n\n");
        printf("[2] Attendance Management\n\n");
        printf("[3] Leave Management\n\n");
        printf("[4] Salary Management\n\n");
        printf("[5] Reports\n\n");
        printf("[0] Exit\n\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                showEmployeeMenu();
                break;
            case 2:
                showDepartmentMenuForAttendance();
                break;
            case 3:
                showLeave();
                break;
            case 4:
                 showSalary();
                 break;
            case 5:
                printf("\nNot implemented yet!\n");
                printf("Press Enter...");
                getchar();
                break;
            case 0:
                login();
                break;
            default:
                printf("\nInvalid!\n");
                printf("Press Enter...");
                getchar();
        }
    }while(1);
}

/*Employee management menu*/

void showEmployeeMenu(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n\n");
        printf("\t\tEMPLOYEE MANAGEMENT MODULE");
        printf("\n\n");
        printf("================================================================\n\n");
        printf("[1] Add Employee\n\n");
        printf("[2] View Employees\n\n");
        printf("[3] Search\n\n");
        printf("[4] Update\n\n");
        printf("[0] Back\n\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        switch(choice){
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 0: return;
            default: printf("Invalid!"); getchar();
        }
    }while(1);
}


void searchEmployee(){ clearScreen(); printf("Search\nPress Enter..."); getchar(); }
void updateEmployee(){ clearScreen(); printf("Update\nPress Enter..."); getchar(); }


char departments[5][100] = {
    "Department of Engineering Technology",
    "Department of Information and Communication Technology",
    "Department of Biosystems Technology",
    "Department of Multidisciplinary Studies",
    "None Dipartment"
};
int selectedDept = 0;

/* clearScreen() already menu.c eke thiyenawanam meka nawatha liyanna epa */

static void readLine(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    if (!fgets(buf, size, stdin)) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\r\n")] = '\0';
}

int selectDepartment(void) {
    char buf[20];
    do {
        clearScreen();
        printf("===============================================\n\n");
        printf("\t\tSELECT DEPARTMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Department of Engineering Technology\n\n");
        printf("[2] Department of Information and Communication Technology\n\n");
        printf("[3] Department of Biosystems Technology\n\n");
        printf("[4] Department of Multidisciplinary Studies\n\n");
        printf("[5] None Dipartment\n\n");
        printf("[0] Back\n\n");
        printf("-----------------------------------------------\n");
        readLine("Enter Choice : ", buf, sizeof buf);
        char *end;
        long c = strtol(buf, &end, 10);
        if (end != buf && c >= 0 && c <= 5) return (int)c;
    } while (1);
}

void showDepartmentMenuForAttendance(void) {
    int dept = selectDepartment();
    if (dept == 0) return;
    selectedDept = dept;
    showAttendanceMenu();
}
void showAttendanceMenu(void) {
    char buf[20];
    do {
        clearScreen();
        printf("===============================================\n\n");
        printf(" %s\n\n", departments[selectedDept - 1]);
        printf("\t\tATTENDANCE MANAGEMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Mark Attendance\n\n");
        printf("[2] View Attendance\n\n");
        printf("[3] Search Attendance\n\n");
        printf("[4] Monthly Report\n\n");
        printf("[0] Back\n\n");
        printf("===============================================\n\n");
        printf("Example (after selecting an option):\n\n");
        printf("Employee ID : TG/IT/2025/2517\n\n");
        printf("Date : 2026-10-08\n\n");
        printf("-----------------------------------------------\n");
        readLine("Enter Choice : ", buf, sizeof buf);

        if (buf[0] == '0' && buf[1] == '\0') return;
        switch (atoi(buf)) {
            case 1: markAttendance();   break;
            case 2: viewAttendance();   break;
            case 3: searchAttendance(); break;
            case 4: monthlyReport();    break;
            default:
                printf("Invalid! Press Enter to continue...");
                getchar();
        }
    } while (1);
}
/*leave management*/

void showLeave(){
    int choice;
    do{
        clearScreen();
       printf("===============================================\n\n");
        printf("\t\tLeave MANAGEMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Apply Leave \n\n");
        printf("[2] View Leave \n\n");
        printf("[3] Approve Leave \n\n");
        printf("[4] Reject Leave \n\n");
        printf("[0] Back\n\n");
        printf("===============================================\n\n");
        printf("-----------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        switch(choice){
            case 1: apply_leave(); 
                    printf("\nPress Enter to continue...");
                    getchar();
                    break;
            case 2: view_leave();
                    printf("\nPress Enter to continue...");
                    getchar();
                    break;
            case 3: approve_leave(); 
                    break;
            case 4: reject_leave();
                    break;
            case 0: return;
            default: printf("Invalid!"); 
            getchar();
        }
    }while(1);
}


void applyLeave (){clearScreen(); printf("Apply Leave\nPress Enter..."); getchar();}
void viewLeave (){ clearScreen(); printf("View Leave\nPress Enter..."); getchar(); }
void approveLeave (){ clearScreen(); printf("Approve Leave\nPress Enter..."); getchar(); }
void rejectLeave (){ clearScreen(); printf("Reject Leave\nPress Enter..."); getchar(); }

/*salary Management*/

void showSalary(){
    int choice;
    do{
        clearScreen();
       printf("===============================================\n\n");
        printf("\t\tSALARY MANAGEMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Basic Salary  \n\n");
        printf("[2] Allowances  \n\n");
        printf("[3] Deductions  \n\n");
        printf("[4] Net Salary  \n\n");
        printf("[0] Back\n\n");
        printf("===============================================\n\n");
        printf("-----------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        switch(choice){
            case 1: basicSalary(); break;
            case 2: allowances(); break;
            case 3: deductions(); break;
            case 4: netSalary(); break;
            case 0: return;
            default: printf("Invalid!"); getchar();
        }
    }while(1);
}

void basicSalary(){clearScreen(); printf("Apply Leave\nPress Enter..."); getchar();}
void allowances(){ clearScreen(); printf("View Leave\nPress Enter..."); getchar(); }
void deductions(){ clearScreen(); printf("Approve Leave\nPress Enter..."); getchar(); }
void netSalary(){ clearScreen(); printf("Reject Leave\nPress Enter..."); getchar(); }
