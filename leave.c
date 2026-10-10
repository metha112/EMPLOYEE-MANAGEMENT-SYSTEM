#include <stdio.h>
#include "leave.h"
#include "menu.h"

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

