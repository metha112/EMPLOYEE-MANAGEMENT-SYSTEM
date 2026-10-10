#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "menu.h"
#include "department.h"

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