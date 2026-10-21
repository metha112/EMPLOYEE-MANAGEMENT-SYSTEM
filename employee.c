#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "menu.h"

struct employee
{
    char emp_id[20];
    char emp_name[50];
    char nic[15];
    char phone[15];
    char dep[30];
    char depr[60];
    char join_date[15];
    char username[20];
    char password[20];
};

void addEmployee()
{



    struct employee emp;
    char buffer[20];
    int d,c;
    char ans;

    
    
         clearScreen();
        printf("================================================================\n\n");
        printf("\tUNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("\t\tEMPLOYEE MANAGEMENT SYSTEM");
        printf("\n\n");
        printf("\t\t    REGISTER EMPLOYEE");
        printf("\n\n================================================================\n");
        printf("\n");
        printf("Enter the Employee ID: ");
        fgets(emp.emp_id, sizeof(emp.emp_id), stdin);
        emp.emp_id[strcspn(emp.emp_id, "\n")] = '\0';

        printf("Enter the Employee Name: ");
        fgets(emp.emp_name, sizeof(emp.emp_name), stdin);
        emp.emp_name[strcspn(emp.emp_name, "\n")] = '\0';

        printf("Enter the Employee NIC: ");
        fgets(emp.nic, sizeof(emp.nic), stdin);
        emp.nic[strcspn(emp.nic, "\n")] = '\0';

        printf("Enter the Employee Phone Number: ");
        fgets(emp.phone, sizeof(emp.phone), stdin);
        emp.phone[strcspn(emp.phone, "\n")] = '\0';

    
        printf("1. Academic\n");
        printf("2. Non-Academic\n");
        printf("Select (number): ");
        fgets(buffer, sizeof(buffer), stdin);
        d = atoi(buffer);
        
        printf("\n");
         
        switch (d)
        {
        case 1:
            printf("1. professor\n");
            printf("2. Senior Lecturer\n");
            printf("3. Lecturer\n");
            printf("4. Demonstrator\n");
            printf("5. Instructor\n");
            printf("Select (number): ");
            fgets(buffer, sizeof(buffer), stdin);
            d = atoi(buffer);
            if (d == 1){
                strcpy(emp.dep, "professor");
            }
            else if(d==2){
                strcpy(emp.dep, "Senior Lecturer");
            }
            else if(d==3){
                strcpy(emp.dep, "Lecturer");
            }
            else if(d==4){
                strcpy(emp.dep, "Demonstrator");
            }
            else if(d==5){
                strcpy(emp.dep, "Instructor");
            }
            break;
        case 2:
            printf("1. Registant\n");
            printf("2. Management Assistant\n");
            printf("3. Finance Division staff\n");
            printf("4. Technical Officer\n");
            printf("5. Laboratory Attendant\n");
            printf("6. Office Aide\n");
            printf("7. Driver\n");
            printf("8. Security\n");
            printf("Select (number): ");
            fgets(buffer, sizeof(buffer), stdin);
            d = atoi(buffer);
            if (d == 1){
                strcpy(emp.dep, "Registant");
            }
            else if(d==2){
                strcpy(emp.dep, "Management Assistant");
            }
            else if(d==3){
                strcpy(emp.dep, "Finance Division staff");
            }
            else if(d==4){
                strcpy(emp.dep, "Technical Officer");
            }
            else if(d==5){
                strcpy(emp.dep, "Laboratory Attendant");
            }
            else if(d==6){
                strcpy(emp.dep, "Office Aide");
            }
            else if(d==7){
                strcpy(emp.dep, "Driver");
            }
            else if(d==8){
                strcpy(emp.dep, "Security");
            }
            break;
        default:
            strcpy(emp.dep, "Unknown");
            break;
        }

        printf("\n");

        printf("1. Department of Engineering Technology\n");
        printf("2. Department of Information and Communication Technology\n");
        printf("3. Department of Biosystems Technology\n");
        printf("4. Department of Multidisciplinary Studies\n");
        printf("5. None Dipartment\n");
        printf("Select (number): ");
        fgets(buffer, sizeof(buffer), stdin);
        c = atoi(buffer);

        printf("\n");

        switch (c)
        {
        case 1:
                strcpy(emp.depr, "Department of Engineering Technology");
                break;
        case 2:
                strcpy(emp.depr, "Department of Information and Communication Technology");
                break; 
        case 3:
                strcpy(emp.depr, "Department of Biosystems Technology");
                break; 
        case 4:
                strcpy(emp.depr, "Department of Multidisciplinary Studies");
                break;
        case 5:
                strcpy(emp.depr, "None Dipartment");
                break;
        default:
            strcpy(emp.dep, "Unknown");
            break;
        }         
                        
                               

        printf("\nJoin Date (DD/MM/YYYY): ");
        fgets(emp.join_date, sizeof(emp.join_date), stdin);
        emp.join_date[strcspn(emp.join_date, "\n")] = '\0';

        printf("Save this employee? (Y/N): ");
        fgets(buffer, sizeof(buffer), stdin);
        ans = buffer[0];

    if (ans != 'Y' && ans != 'y'){
             login();
    }

    strcpy(emp.username, emp.emp_id);
    printf("UserName is : %s\n", emp.username);

    printf("Password: ");
    fgets(emp.password, sizeof(emp.password), stdin);
    emp.password[strcspn(emp.password, "\n")] = '\0';

    FILE *fp = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file! Check the folder path.\n");
        return;
    }

    fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
            emp.emp_id, emp.emp_name, emp.nic, emp.phone,
            emp.dep, emp.depr, emp.join_date, emp.username, emp.password);

    fclose(fp);
    printf("Employee added successfully.\n");
}
