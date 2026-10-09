#include <stdio.h>
#include "attendance.h"
#include "menu.h"
#include "department.h"

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
            case 0: return;
        }
    }while(1);
}
