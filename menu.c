#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "employee.h"
#include "department.h"
#include "attendance.h"
#include "leave.h"

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