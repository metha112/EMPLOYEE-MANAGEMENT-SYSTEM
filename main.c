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


int checkLogin(const char *username, const char *password){
    FILE *fp = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "r");
    if(fp == NULL){
        return 0;               /* file not found */
    }

    char line[512];
    int found = 0;

    while(fgets(line, sizeof(line), fp)){
        line[strcspn(line, "\r\n")] = '\0';   /* remove newline */

        /* last field = password */
        char *passPtr = strrchr(line, '|');
        if(passPtr == NULL) continue;
        *passPtr = '\0';
        passPtr++;

        /* second last field = username */
        char *userPtr = strrchr(line, '|');
        userPtr = (userPtr == NULL) ? line : userPtr + 1;

        if(strcmp(userPtr, username) == 0 && strcmp(passPtr, password) == 0){
            found = 1;
            break;
        }
    }

    fclose(fp);
    return found;
}

/*username and password page*/

void userPassword(){
    char username[20];
    char password[20];
    int i;
    char ch;

    while(1){
        clearScreen();
        printf("================================================================\n\n");
        printf("UNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n\n");
        printf("Loging Employs");
        printf("\n\n================================================================\n");
        printf("\n");

        printf("Username: ");
        scanf("%19s", username);

        printf("Password: ");
        i = 0;
        while(1){
            ch = getch();
            if(ch == 13) break;
            if(ch == 8){
                if(i > 0){
                    i--;
                    printf("\b \b");
                }
            } else if(i < 19){          /* prevent overflow */
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';

        if(checkLogin(username, password)){
            showMainMenu();
            return;                     /* back to login menu after logout */
        } else {
            printf("\n\nWrong Username or password\n");
            printf("Press any key to try again...");
            getch();
        }
    }
}