#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"



struct employee
{
    char emp_id[50];
    char emp_name[50];
    char nic[30];
    char phone[15];
    char dep[30];
    char category[20];
    char designation[30];
    char join_date[15];
    char username[20];
    char password[20];
   
};
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
    int d, c, des;
    char ans;

    do
    {
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

        printf("\nDepartment:\n");
        printf("1. ICT\n");
        printf("2. Engineering Tech\n");
        printf("3. Bio-systems Tech\n");
        printf("4. Interdisciplinary\n");
        printf("5. Administration\n");
        printf("Select (number): ");
        fgets(buffer, sizeof(buffer), stdin);
        d = atoi(buffer);

        switch (d)
        {
        case 1:
            strcpy(emp.dep, "ICT");
            break;
        case 2:
            strcpy(emp.dep, "Engineering Tech");
            break;
        case 3:
            strcpy(emp.dep, "Bio-systems Tech");
            break;
        case 4:
            strcpy(emp.dep, "Interdisciplinary");
            break;
        case 5:
            strcpy(emp.dep, "Administration");
            break;
        default:
            strcpy(emp.dep, "Unknown");
            break;
        }

        printf("\nCategory:\n");
        printf("1. Academic\n");
        printf("2. Technical\n");
        printf("3. Non-academic\n");
        printf("Select (number): ");
        fgets(buffer, sizeof(buffer), stdin);
        c = atoi(buffer);

        switch (c)
        {
        case 1:
            strcpy(emp.category, "Academic");
            break;
        case 2:
            strcpy(emp.category, "Technical");
            break;
        case 3:
            strcpy(emp.category, "Non-academic");
            break;
        default:
            strcpy(emp.category, "Unknown");
            break;
        }

        printf("\nDesignation:\n");
        printf("1. Management Assistant\n");
        printf("2. Clerk\n");
        printf("3. Driver\n");
        printf("4. Labourer\n");
        printf("Select (number): ");
        fgets(buffer, sizeof(buffer), stdin);
        des = atoi(buffer);

        switch (des)
        {
        case 1:
            strcpy(emp.designation, "Management Assistant");
            break;
        case 2:
            strcpy(emp.designation, "Clerk");
            break;
        case 3:
            strcpy(emp.designation, "Driver");
            break;
        case 4:
            strcpy(emp.designation, "Labourer");
            break;
        default:
            strcpy(emp.designation, "Unknown");
            break;
        }

        printf("\nJoin Date (DD/MM/YYYY): ");
        fgets(emp.join_date, sizeof(emp.join_date), stdin);
        emp.join_date[strcspn(emp.join_date, "\n")] = '\0';

        printf("Save this employee? (Y/N): ");
        fgets(buffer, sizeof(buffer), stdin);
        ans = buffer[0];

    } while (ans != 'Y' && ans != 'y');

    strcpy(emp.username, emp.emp_id);
    printf("UserName is : %s\n", emp.username);

    printf("Password: ");
    fgets(emp.password, sizeof(emp.password), stdin);
    emp.password[strcspn(emp.password, "\n")] = '\0';

    FILE *fp = fopen("C:\\Users\\USER\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file! Check the folder path.\n");
        return;
    }

    fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
            emp.emp_id, emp.emp_name, emp.nic, emp.phone,
            emp.dep, emp.category, emp.designation,
            emp.join_date, emp.username, emp.password);

    
                   
               

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
    printf("   %-18s %-20s %-18s %-18s %-14s %-22s\n","ID","Name","Phone_NO","Department","Category","Designation");

    while ( i <= count && fgets(line,sizeof(line),fp)!=NULL){
   
     line[strcspn(line, "\n")] = '\0';

        sscanf(line,"%49[^|]|%49[^|]|%*[^|]|%14[^|]|%29[^|]|%19[^|]|%29[^|]",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
         
        printf("   %-18s %-20s %-18s %-18s %-14s %-22s\n",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
        i++;

    }
    fclose(fp);
    printf("\n================================================================================================\n");
    printf("-\n");
    printf("Showing 1-%d of %d employees\n",i,count);


}

void searchEmployee(){
    int count = countLines();
    struct employee emp[count];
    FILE*fp;
    char line[200];
   
    int choice,select;
    char search[50];
    char buffer[20];
    do{
        int i = 0;
        printf("+======================================================================================================================+\n");
        printf("|\t\t\t\t\t\tSEARCH EMPLOYEE\t\t\t\t\t\t\t       |\n");
        printf("+======================================================================================================================+\n");
        printf("|1. By Employee ID\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|2. By Name\t\t\t\t\t\t\t\t\t\t\t\t\t       |\n");  
        printf("|3. By NIC\t\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|4. By Department\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|0. Back\t\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("-\n");

        printf("Enter choice:");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);
    

        switch (choice)
        {
            case 1 :
                printf("Enter ID: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                select=1;
                break;
            
            case 2 :
                printf("Enter Name: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                select=2;
                break;

            case 3 :
                printf("Enter NIC: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                select=3;
                break;

            case 4 :
                printf("Enter Department: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                select=4;
                break;
            case 0 :
                printf("Back ");
                
                break;
            default:
                printf("Invalid Number\n ");
                break;
        }
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|   %-18s %-20s %-18s %-18s %-14s %-22s|\n","ID","Name","Phone_NO","Department","Category","Designation");
        fp= fopen("C:\\Users\\USER\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt","r");
        if (fp == NULL)
        {
            printf("Error opening file! Check the folder path.\n");
            return;
        }

         while ( i <= count && fgets(line,sizeof(line),fp)!=NULL){
   
            line[strcspn(line, "\n")] = '\0';

            sscanf(line,"%49[^|]|%49[^|]|%29[^|]|%14[^|]|%29[^|]|%19[^|]|%29[^|]",emp[i].emp_id,emp[i].emp_name,emp[i].nic,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
           
            switch (select)
            {
            case 1 :
               if (strstr(emp[i].emp_id, search) != NULL)
                {
                    printf("|   %-18s %-20s %-18s %-18s %-14s %-22s|\n",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
                    //found++;
                }
                break;
            case 2 :
               if (strstr(emp[i].emp_name, search) != NULL)
                {
                    printf("|   %-18s %-20s %-18s %-18s %-14s %-22s|\n",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
                    //found++;
                }
                break;
            case 3 :
               if (strcmp(search, emp[i].nic) == 0)
                {
                    printf("|   %-18s %-20s %-18s %-18s %-14s %-22s|\n",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
                    //found++;
                }
                break;
            case 4 :
               if (strstr(emp[i].dep, search) != NULL)
                {
                    printf("|   %-18s %-20s %-18s %-18s %-14s %-22s|\n",emp[i].emp_id,emp[i].emp_name,emp[i].phone,emp[i].dep,emp[i].category,emp[i].designation);
                    //found++;
                }
                break;
            
            }
            
            
            i++;

        }
        fclose(fp);
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
    }while (choice!=0);
   
    
   
    printf("-\n");


}


void updateEmployee(){

    int count = countLines();
    if (count == 0)
    {
        printf("No employees found.\n");
        return;
    }

    struct employee emp[count];
    FILE*fp;
    char line[300];
    int choice;
    char change[50];
    char buffer[20];
    char login[20];
    strcpy(login,"001");

    do{
        int i = 0;
        int j = 0;
        int pos = -1;                    
        
        fp = fopen("C:\\Users\\USER\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt","r");
        if (fp == NULL)
        {
            printf("Error opening file! Check the folder path.\n");
            return;
        }

        while ( i < count && fgets(line,sizeof(line),fp)!=NULL){

            line[strcspn(line, "\n")] = '\0';
            if (line[0] == '\0') continue;

            memset(&emp[i], 0, sizeof(emp[i]));
            if (sscanf(line,"%49[^|]|%49[^|]|%29[^|]|%14[^|]|%29[^|]|%19[^|]|%29[^|]|%14[^|]|%19[^|]|%19[^|]",
                       emp[i].emp_id,emp[i].emp_name,emp[i].nic,emp[i].phone,
                       emp[i].dep,emp[i].category,emp[i].designation,
                       emp[i].join_date,emp[i].username,emp[i].password) != 10)
            {
                continue;                
            }

            if (strcmp(emp[i].emp_id, login) == 0){
                pos = i;                 
            }
            i++;                         
        }
        fclose(fp);

        if (pos == -1)
        {
            printf("Employee %s not found.\n", login);
            return;
        }

        
        printf("Employee ID : %s (Cannot be changed)\n",emp[pos].emp_id);

        printf("   1. Full Name       : %s\n",emp[pos].emp_name);
        printf("   2. NIC             : %s\n",emp[pos].nic);
        printf("   3. Phone           : %s\n",emp[pos].phone);
        printf("   4. Department      : %s\n",emp[pos].dep);
        printf("   5. Category        : %s\n",emp[pos].category);
        printf("   6. Designation     : %s\n",emp[pos].designation);
        printf("   7. Join Date       : %s\n",emp[pos].join_date);
        printf("   8. Password        : %s\n",emp[pos].password);
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("   0. Discard changes and go back\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("Enter choice:");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        change[0] = '\0';
        if (choice >= 1 && choice <= 8)
        {
            printf("Enter New Value: ");
            fgets(change, sizeof(change), stdin);
            change[strcspn(change, "\n")] = '\0';
        }

        switch (choice)
        {
            case 1 : snprintf(emp[pos].emp_name,    sizeof(emp[pos].emp_name),    "%s", change); break;
            case 2 : snprintf(emp[pos].nic,         sizeof(emp[pos].nic),         "%s", change); break;
            case 3 : snprintf(emp[pos].phone,       sizeof(emp[pos].phone),       "%s", change); break;
            case 4 : snprintf(emp[pos].dep,         sizeof(emp[pos].dep),         "%s", change); break;
            case 5 : snprintf(emp[pos].category,    sizeof(emp[pos].category),    "%s", change); break;
            case 6 : snprintf(emp[pos].designation, sizeof(emp[pos].designation), "%s", change); break;
            case 7 : snprintf(emp[pos].join_date,   sizeof(emp[pos].join_date),   "%s", change); break;
            case 8 : snprintf(emp[pos].password,    sizeof(emp[pos].password),    "%s", change); break;
            case 0 :
                printf("Back\n");
                break;
            default:
                printf("Invalid Number\n");
                break;
        }

       
        if (choice >= 1 && choice <= 8)
        {
            fp = fopen("C:\\Users\\USER\\Documents\\GitHub\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "w");
            if (fp == NULL)
            {
                printf("Error opening file! Check the folder path.\n");
                return;
            }

            while ( j < i ){
                fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
                    emp[j].emp_id, emp[j].emp_name, emp[j].nic, emp[j].phone,
                    emp[j].dep, emp[j].category, emp[j].designation,
                    emp[j].join_date, emp[j].username, emp[j].password);
                j++;
            }

            fclose(fp);
            printf("Save Change...\n");
        }

        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("\n");

    }while (choice != 0);

}




















