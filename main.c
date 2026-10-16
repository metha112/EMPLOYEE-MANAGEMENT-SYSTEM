#include "menu.h"
#include <conio.h>
#include <string.h>
#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    login();
    return 0;
}

/*main login and register page*/

void login(){
    int choice;
    do{
        clearScreen();
        printf("================================================================\n\n");
        printf("\tUNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("\t\tEMPLOYEE MANAGEMENT SYSTEM");
        printf("\n\n");
        printf("\t\t    LOGING AND REGISTER");
        printf("\n\n================================================================\n");
        printf("\n");
        printf("[1] Login\n\n");
        printf("[2] Register\n\n");
        printf("[0] Exit\n\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                userPassword();
                break;
            case 2:
                addEmployee();
                break;    
            case 0:
                exit(0);
            default:
                printf("\nInvalid!\n");
                printf("Press Enter...");
                getchar();
        }
    }
    while(1);
}

/*username and password page*/

void userPassword(){
    char username[20];
    char password[20];
    char correctUser[] = "admin";
    char correctPass[] = "1234";
    int i = 0;
    char ch;
  do{  
    clearScreen();
        printf("================================================================\n\n");
        printf("UNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n\n");
        printf("Loging Employs");
        printf("\n\n================================================================\n");
        printf("\n");

    /*give username*/
    printf("Username: ");
    scanf("%s", username);

    /*give password*/
    printf("Password: ");
    i = 0;
    while(1) {
        ch = getch();
        if(ch == 13) break;
        if(ch == 8) {
            if(i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    password[i] = '\0';

    /*check corect username and password*/
    if(strcmp(username, correctUser) == 0 && strcmp(password, correctPass) == 0) {
        showMainMenu();
    } 
    else {
        printf("\n\nWrong Username or password ❌\n");
    }
}
 while(1);
}   