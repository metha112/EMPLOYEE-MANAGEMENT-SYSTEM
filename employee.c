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
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
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
            choice = -1;                 
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

void userPassword(){
    char username[20];
    char password[20];
    int i;
    int ch;

    while(1){
        clearScreen();
        printf("================================================================\n\n");
        printf("\tUNIVERSITY OF RUHUNA - FACULTY OF TECHNOLOGY");
        printf("\n\n");
        printf("\t\tEMPLOYEE MANAGEMENT SYSTEM");
        printf("\n\n");
        printf("\t\t    LOGING EMPLOYEE");
        printf("\n\n================================================================\n");
        printf("\n");

        printf("Username: ");
        scanf("%19s", username);
        getchar();                       

        printf("Password: ");
        fflush(stdout);
        i = 0;
        while(1){
            ch = readKey();
            if(ch == 13 || ch == 10) break;            
            if(ch == 8 || ch == 127){                 
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
            return;                     
        } else {
            printf("\n\nWrong Username or password\n");
            printf("Press Enter to try again...");
            fflush(stdout);
            getchar();
        }
    }
}

int countLines()
{
    FILE *fp;
    char line[300];
    int lines = 0;

    fp = fopen("C:\\Users\\USER\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "r");
    if (fp == NULL)
    {
        return 0;                     
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
           
                lines++;
        
    }

    fclose(fp);
    return lines;                     
}

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

void viewEmployees(){
    int i = 0;
    int count = countLines();
    struct employee emp[count];
    FILE*fp;
    char line[200];
   
    fp= fopen("C:\\Users\\USER\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt","r");
     if (fp == NULL)
    {
        printf("Error opening file! Check the folder path.\n");
        return;
    }
    printf("\nALL EMPLOYEES\n");
    printf("================================================================================================\n");
    printf("-\n");
    printf("  \n");
    printf("================================================================================================\n");
    printf("   %-18s %-20s %-18s %-22s %-18s\n","ID","Name","Phone_NO","Designations","Department");
    printf("------------------------------------------------------------------------------------------------\n");
    while ( i <= count && fgets(line,sizeof(line),fp)!=NULL){
   
     line[strcspn(line, "\n")] = '\0';

        sscanf(line,"%49[^|]|%49[^|]|%*[^|]|%14[^|]|%29[^|]|%19[^|]|%29[^|]",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].depr);
         
        printf("   %-18s %-20s %-18s %-22s %-18s\n",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].depr);
        i++;

    }
    fclose(fp);
    printf("\n================================================================================================\n");
    printf("-\n");
    printf("Showing 1-%d of %d employees\n",i,count);


}
