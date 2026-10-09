#include <stdio.h>
#include "department.h"
#include "menu.h"
#include "attendance.h"

char departments[4][100] = {"Department of Engineering Technology","Department of Information and Communication Technology","Department of Biosystems Technology","Department of Multidisciplinary Studies"};

int selectDepartment(){
    int choice;
    do{
        clearScreen();
         printf("===============================================\n\n");
        printf("\tSELECT DEPARTMENT\n\n");
        printf("===============================================\n\n");
        printf("[1] Department of Engineering Technology\n\n");
        printf("[2] Department of Information and Communication Technology\n\n");
        printf("[3] Department of Biosystems Technology\n\n");
        printf("[4] Department of Multidisciplinary Studies\n\n");
        printf("[0] Back\n\n");
        printf("-----------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d",&choice); getchar();
        if(choice>=0 && choice<=4) return choice;
    }while(1);
}
void showDepartmentMenuForAttendance(){
    int dept = selectDepartment();
    if(dept==0) return;
    selectedDept = dept;
    showAttendanceMenu();
}