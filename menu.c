#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "employee.h"
#include "department.h"
#include "attendance.h"

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void printCenter(char text[]){
    int len=strlen(text);
    int pad=(80-len)/2;
    for(int i=0;i<pad;i++) printf(" ");
    printf("%s",text);
}
void printMainHeader(){
    printf("================================================================\n\n");
    printCenter("UNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
    printf("\n\n");
    printCenter("EMPLOYEE MANAGEMENT SYSTEM");
    printf("\n\n================================================================\n");
}
void showEmployeeMenu(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n\n");
        printCenter("EMPLOYEE MANAGEMENT MODULE");
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
void showMainMenu(){
    int choice;
    do{
       clearScreen();
        printMainHeader();
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