#include "menu.h"
#include <string.h>
#include "employee.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>

    static int readKey(void){
        HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
        DWORD oldMode, n;
        char c = 0;
        GetConsoleMode(h, &oldMode);
        SetConsoleMode(h, oldMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
        ReadConsoleA(h, &c, 1, &n, NULL);
        SetConsoleMode(h, oldMode);
        return (unsigned char)c;
    }

    #define EMPLOYEE_FILE "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt"
#else
    #include <termios.h>
    #include <unistd.h>

    static int readKey(void){
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    #define EMPLOYEE_FILE "File_Manegement/employee.txt"
#endif

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
        if(scanf("%d",&choice) != 1){
            choice = -1;                 /* letter ekak gahuwoth infinite loop wenna epa */
            scanf("%*[^\n]");
        }
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
    FILE *fp = fopen(EMPLOYEE_FILE, "r");
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
    int ch;

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
        getchar();                       /* scanf eken ithuru '\n' eka ayin karanna */

        printf("Password: ");
        fflush(stdout);
        i = 0;
        while(1){
            ch = readKey();
            if(ch == 13 || ch == 10) break;            /* Enter: Windows 13, Linux 10 */
            if(ch == 8 || ch == 127){                  /* Backspace: Windows 8, Linux 127 */
                if(i > 0){
                    i--;
                    printf("\b \b");
                    fflush(stdout);
                }
            } else if(i < 19){          /* prevent overflow */
                password[i++] = (char)ch;
                printf("*");
                fflush(stdout);
            }
        }
        password[i] = '\0';

        if(checkLogin(username, password)){
            showMainMenu();
            return;                     /* back to login menu after logout */
        } else {
            printf("\n\nWrong Username or password\n");
            printf("Press Enter to try again...");
            fflush(stdout);
            getchar();
        }
    }
}