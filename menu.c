#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "employee.h"

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printCenter(char text[]){
    int len = strlen(text);
    int pad = (80 - len) / 2;
    for(int i=0; i<pad; i++) printf(" ");
    printf("%s", text);
}

void printMainHeader(){
    printf("================================================================\n");
    printf("\n");
    printCenter("UNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
    printf("\n\n");
    printCenter("EMPLOYEE MANAGEMENT SYSTEM");
    printf("\n\n");
    printf("================================================================\n");
}

// Palaweni interface eka thibba ekata
void showMainInterface(){
    clearScreen();
    printMainHeader();
    printf("\n\n");
    printCenter("[1] Employee Management");
    printf("\n");
    printCenter("[0] Exit");
    printf("\n");
}

// Aluth Word eke thiyena main menu eka - Input ganna widihata
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
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                showEmployeeMenu(); // 1 click karama mekata yanawa
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                printf("\nThis module is not implemented yet!\n");
                printf("Press Enter...");
                getchar();
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid Choice! Press Enter...");
                getchar();
        }
    } while(1);
}

// 1 click karama enna ona Employee Management athule tika
void showEmployeeMenu(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n");
        printf("\n");
        printCenter("EMPLOYEE MANAGEMENT MODULE");
        printf("\n\n");
        printf("================================================================\n");
        printf("\n");
        printf("[1] Add Employee\n\n");
        printf("[2] View Employees\n\n");
        printf("[3] Search Employee\n\n");
        printf("[4] Update Employee\n\n");
        printf("[5] Delete Employee\n\n");
        printf("[0] Back to Main Menu\n\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 0: return;
            default:
                printf("\nInvalid! Press Enter...");
                getchar();
        }
    } while(1);
}