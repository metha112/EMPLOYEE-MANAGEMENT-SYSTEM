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

void showMainMenu(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n\n");
        printf("UNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("EMPLOYEE MANAGEMENT SYSTEM");
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
                exit(0);
            default:
                printf("\nInvalid!\n");
                printf("Press Enter...");
                getchar();
        }
    }while(1);
}

void showEmployeeMenu(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n\n");
        printf("EMPLOYEE MANAGEMENT MODULE");
        printf("\n\n");
        printf("================================================================\n\n");
        printf("[1] Add Employee\n\n");
        printf("[2] View Employees\n\n");
        printf("[3] Search\n\n");
        printf("[4] Update\n\n");
        printf("[5] Delete\n\n");
        printf("[0] Back\n\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        switch(choice){
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 0: return;
            default: printf("Invalid!"); getchar();
        }
    }while(1);
}

void addEmployee(){clearScreen(); printf("Add Employees\nPress Enter..."); getchar();}
void viewEmployees(){ clearScreen(); printf("View Employees\nPress Enter..."); getchar(); }
void searchEmployee(){ clearScreen(); printf("Search\nPress Enter..."); getchar(); }
void updateEmployee(){ clearScreen(); printf("Update\nPress Enter..."); getchar(); }
void deleteEmployee(){ clearScreen(); printf("Delete\nPress Enter..."); getchar(); }


char departments[4][100] = {"Department of Engineering Technology","Department of Information and Communication Technology","Department of Biosystems Technology","Department of Multidisciplinary Studies"};

int selectDepartment(){
    int choice;
    do{
        clearScreen();
         printf("===============================================\n\n");
        printf("\tSELECT DEPARTMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Department of Engineering Technology\n\n");
        printf("[2] Department of Information and Communication Technology\n\n");
        printf("[3] Department of Biosystems Technology\n\n");
        printf("[4] Department of Multidisciplinary Studies\n\n");
        printf("[0] Back\n\n");
        printf("-----------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        if(choice>=0 && choice<=4) return choice;
    }while(1);
}
void showDepartmentMenuForAttendance(){
    int dept = selectDepartment();
    if(dept==0) return;
    selectedDept = dept;
    showAttendanceMenu();
}


int selectedDept=0;

void showAttendanceMenu(){
    int choice;
    do{
        clearScreen();
       printf("===============================================\n\n");
        printf(" %s Department\n\n", departments[selectedDept-1]);
        printf(" ATTENDANCE MANAGEMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Mark Attendance\n\n");
        printf("[2] View Attendance\n\n");
        printf("[3] Search Attendance\n\n");
        printf("[4] Monthly Report\n\n");
        printf("[0] Back\n\n");
        printf("===============================================\n\n");
        printf("Example:\n\n");
        printf("Employee ID : 1001\n\n");
        printf("Date : 2026-10-08\n\n");
        printf("-----------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        switch(choice){
            case 1: markAttendance(); break;
            case 2: viewAttendance(); break;
            case 3: searchAttendance(); break;
            case 4: monthlyReport(); break;
            case 0: return;
            default: printf("Invalid!"); getchar();
        }
    }while(1);
}

void markAttendance(){clearScreen(); printf("Mark Attendance\nPress Enter..."); getchar();}
void viewAttendance(){ clearScreen(); printf("View Attendance\nPress Enter..."); getchar(); }
void searchAttendance(){ clearScreen(); printf("Search Attendance\nPress Enter..."); getchar(); }
void monthlyReport(){ clearScreen(); printf("Monthly Report\nPress Enter..."); getchar(); }


void showLeave(){
    int choice;
    do{
        clearScreen();
       printf("===============================================\n\n");
        printf(" Leave MANAGEMENT\n\n");
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
            case 1: applyLeave (); break;
            case 2: viewLeave (); break;
            case 3: approveLeave (); break;
            case 4: rejectLeave (); break;
            case 0: return;
            default: printf("Invalid!"); getchar();
        }
    }while(1);
}


void applyLeave (){clearScreen(); printf("Apply Leave\nPress Enter..."); getchar();}
void viewLeave (){ clearScreen(); printf("View Leave\nPress Enter..."); getchar(); }
void approveLeave (){ clearScreen(); printf("Approve Leave\nPress Enter..."); getchar(); }
void rejectLeave (){ clearScreen(); printf("Reject Leave\nPress Enter..."); getchar(); }



void showSalary(){
    int choice;
    do{
        clearScreen();
       printf("===============================================\n\n");
        printf(" SALARY ANAGEMENT\n\n");
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
