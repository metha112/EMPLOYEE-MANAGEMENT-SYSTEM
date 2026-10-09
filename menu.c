#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

#define WIDTH 80

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printCenter(char text[]){
    int len = strlen(text);
    int padding = (WIDTH - len) / 2;
    if(padding < 0) padding = 0;
    for(int i=0; i<padding; i++) printf(" ");
    printf("%s\n", text);
}

void printMainHeader(){
    printf("\n\n");
    for(int i=0; i<WIDTH; i++) printf("=");
    printf("\n\n");
    printCenter("UNIVERSITY OF RUHUNA");
    printCenter("FACULTY OF TECHNOLOGY");
    printf("\n");
    printCenter("EMPLOYEE MANAGEMENT SYSTEM");
    printf("\n\n");
    for(int i=0; i<WIDTH; i++) printf("=");
    printf("\n\n");
}

void showMainInterface(){
    clearScreen();
    printMainHeader();

    printf("\n\n");

    // Menu options - center karala box nathuwa
    printCenter(" [1] Employee Management ");
    printf("\n");
    printCenter(" [2] Attendance Management ");
    printf("\n");
    printCenter(" [3] Leave Management ");
    printf("\n");
    printCenter(" [4] Salary Management ");
    printf("\n");
    printCenter(" [5] Reports ");
    printf("\n");
    printCenter(" [0] Exit ");

    printf("\n\n\n");
    for(int i=0; i<WIDTH; i++) printf("-");
    printf("\n\n");

    char prompt[] = "Enter your choice > ";
    int len = strlen(prompt);
    int padding = (WIDTH - len) / 2;
    for(int i=0; i<padding; i++) printf(" ");
    printf("%s", prompt);
}