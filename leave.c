#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include "leave.h"
#include "menu.h"

/* Password eka type karaddi "*" pennanawa. Backspace support karanawa. */
static void readPassword(char *buf, int size) {
    int i = 0;
    int ch;

    while ((ch = getch()) != '\r' && ch != '\n') {
        if (ch == 0 || ch == 224) {      /* arrow / function keys skip */
            getch();
            continue;
        }
        if (ch == '\b') {                /* backspace */
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (i < size - 1 && isprint(ch)) {
            buf[i++] = (char)ch;
            printf("*");
        }
    }
    buf[i] = '\0';
    printf("\n");
}

void apply_leave(){
    clearScreen();
    int choice;
    struct Leave l1;

    printf("\n--- Select Leave Type ---\n");
    printf("Annual leave=1\n");
    printf("Casual leave=2\n");
    printf("Medical leave=3\n");
    printf("Enter your leave type : ");
    if (scanf("%d", &choice) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid input!\n");
        return;
    }

    switch (choice) {
        case 1: strcpy(l1.leaveType, "Annual"); break;
        case 2: strcpy(l1.leaveType, "Casual"); break;
        case 3: strcpy(l1.leaveType, "Medical"); break;
        default: printf("Invalid leave type!\n"); return;
    }

    FILE *file = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "r");
    if (file == NULL) {
        printf("employee file not found!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%49s", l1.employeeID);

    char line[512];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        char *id = strtok(line, "|");          // palaweni field eka (empid)
        if (id != NULL && strcmp(id, l1.employeeID) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Employee is not found!\n");
        return;
    }

    printf("Enter number of leave days: ");
    if (scanf("%d", &l1.leavedays) != 1 || l1.leavedays <= 0) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid number of days!\n");
        return;
    }

    strcpy(l1.status, "Pending");

    printf("\nLeave application details\n");
    printf("Employee ID: %s\n", l1.employeeID);
    printf("Leave Type: %s\n", l1.leaveType);
    printf("Leave Days: %d\n", l1.leavedays);
    printf("Status: %s\n", l1.status);

    FILE *leaveFile = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt", "a");
    if (leaveFile == NULL) {
        printf("Unable to open leave file!\n");
        return;
    }

    fprintf(leaveFile, "%s %s %d %s\n", l1.employeeID, l1.leaveType, l1.leavedays, l1.status);
    fclose(leaveFile);

    printf("Leave application saved successfully!\n");

    int c; while ((c = getchar()) != '\n' && c != EOF);   // buffer eka clear karanna
}
void view_leave(){

    clearScreen();
   
    FILE *file;
    struct Leave l1;
    int found = 0;

    file = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt", "r");

    if (file == NULL)
    {
        printf("No leave applications found!\n");
        return;
    }

    printf("\n--- Leave Applications ---\n");

    while (fscanf(file, "%49s %19s %d %19s",
                  l1.employeeID,
                  l1.leaveType,
                  &l1.leavedays,
                  l1.status) == 4)
    {
        printf("\nEmployee ID: %s\n", l1.employeeID);
        printf("Leave Type: %s\n", l1.leaveType);
        printf("Leave Days: %d\n", l1.leavedays);
        printf("Status: %s\n", l1.status);

        found = 1;
    }

    if (found == 0)
    {
        printf("No leave applications found!\n");
    }

    fclose(file);
}


void approve_leave()
{
    clearScreen();
    char password[20];

    printf("Enter your data entry password: ");
    readPassword(password, sizeof password);

    if (strcmp(password, "123456") != 0)
    {
        printf("Invalid entry password!\n");
        return;
    }

    FILE *file, *temp;
    struct Leave records[1000];
    int count = 0;
    int target = -1;
    char empid[50];

    file = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt", "r");

    if (file == NULL)
    {
        printf("No leave applications found!\n");
        return;
    }

    while (count < 1000 &&
           fscanf(file, "%49s %19s %d %19s",
                  records[count].employeeID,
                  records[count].leaveType,
                  &records[count].leavedays,
                  records[count].status) == 4)
    {
        count++;
    }

    fclose(file);

    if (count == 1000)
    {
        printf("Maximum record limit reached!\n");
        return;
    }

    printf("Enter Employee ID to approve leave: ");
    scanf("%49s", empid);


    for (int i = 0; i < count; i++)
    {
        if (strcmp(records[i].employeeID, empid) == 0)
        {
            target = i;
        }
    }

    if (target == -1)
    {
        printf("Employee ID not found!\n");
        return;
    }

    
    if (strcmp(records[target].status, "Pending") != 0)
    {
        printf("Last leave status is already %s.\n",
               records[target].status);
        return;
    }

    strcpy(records[target].status, "Approved");

    temp = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\temp.txt", "w");

    if (temp == NULL)
    {
        printf("Unable to create temporary file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(temp, "%s %s %d %s\n",
                records[i].employeeID,
                records[i].leaveType,
                records[i].leavedays,
                records[i].status);
    }

    fclose(temp);

    if (rename("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\temp.txt", "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt") != 0)
    {
        perror("Unable to update leave file");
        return;
    }

    printf("Last pending leave application approved successfully!\n");
}





 

void reject_leave()
{
    clearScreen();
    char password[20];

    printf("Enter your data entry password: ");
    readPassword(password, sizeof password);

    if (strcmp(password, "123456") != 0)
    {
        printf("Invalid entry password!\n");
        return;
    }

    FILE *file, *temp;
    struct Leave records[5000];
    int count = 0;
    int target = -1;
    char empid[50];

    file = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt", "r");

    if (file == NULL)
    {
        printf("No leave applications found!\n");
        return;
    }

    while (count < 5000 &&
           fscanf(file, "%49s %19s %d %19s",
                  records[count].employeeID,
                  records[count].leaveType,
                  &records[count].leavedays,
                  records[count].status) == 4)
    {
        count++;
    }

    fclose(file);

    if (count == 5000)
    {
        printf("Maximum record limit reached!\n");
        return;
    }

    printf("Enter Employee ID to reject leave: ");
    scanf("%49s", empid);

    
    for (int i = 0; i < count; i++)
    {
        if (strcmp(records[i].employeeID, empid) == 0)
        {
            target = i;
        }
    }

    if (target == -1)
    {
        printf("Employee ID not found!\n");
        return;
    }

    
    if (strcmp(records[target].status, "Pending") != 0)
    {
        printf("Last leave status is already %s.\n",
               records[target].status);
        return;
    }

    strcpy(records[target].status, "Rejected");

    temp = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\temp.txt", "w");

    if (temp == NULL)
    {
        printf("Unable to create temporary file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(temp, "%s %s %d %s\n",
                records[i].employeeID,
                records[i].leaveType,
                records[i].leavedays,
                records[i].status);
    }

    fclose(temp);

    if (rename("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\temp.txt", "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\leave.txt") != 0)
    {
        perror("Unable to update leave file");
        return;
    }

    printf("Last pending leave application rejected successfully!\n");
}