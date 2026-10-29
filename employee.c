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
    char designation[30];
    char category[20];
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

#define EMP_FILE "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt"

int countLines(void) {
    FILE *fp = fopen(EMP_FILE, "r");
    if (!fp) return 0;
    int count = 0;
    char line[200];
    while (fgets(line, sizeof line, fp)) count++;
    fclose(fp);
    return count;
}

void viewEmployees() {
    clearScreen();

    int i = 0;
    int count = countLines();
    if (count == 0) {
        printf("No employees found.\n");
        getchar();
        return;
    }

    struct employee emp[count];
    FILE *fp;
    char line[200];

    fp = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "r");
    if (fp == NULL) {
        printf("Error opening file! Check the folder path.\n");
        return;
    }

    printf("\n\t\t\t\t\t\tALL EMPLOYEES\n");
    printf("=============================================================================================================================================\n");
    printf("   %-18s %-20s %-18s %-22s %-18s\n", "ID", "Name", "Phone_NO", "Designations", "Department");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (i < count && fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';

        sscanf(line, "%49[^|]|%49[^|]|%*[^|]|%14[^|]|%29[^|]|%60[^|]",
               emp[i].emp_id, emp[i].emp_name, emp[i].phone, emp[i].dep, emp[i].depr);

        printf("   %-18s %-20s %-18s %-22s %-18s\n",
               emp[i].emp_id, emp[i].emp_name, emp[i].phone, emp[i].dep, emp[i].depr);
        i++;
    }
    fclose(fp);

       printf("=============================================================================================================================================\n");
    printf("Showing 1-%d of %d employees\n", i, count);

    getchar();
}

void searchEmployee(){
    clearScreen();
    int count = countLines();
    struct employee emp[count + 1];
    FILE *fp;
    char line[200];

    int choice, select;
    char search[50];
    char buffer[20];

    while (1) {
        int i = 0;
        int found = 0;

        printf("+======================================================================================================================+\n");
        printf("|\t\t\t\t\t\tSEARCH EMPLOYEE\t\t\t\t\t\t\t       |\n");
        printf("+======================================================================================================================+\n");
        printf("|1. By Employee ID\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|2. By Name\t\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|3. By NIC\t\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|4. By Department\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("|0. Back\t\t\t\t\t\t\t\t\t\t\t\t\t       |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("Enter choice: ");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        if (choice == 0) {
            return;
        }

        switch (choice) {
            case 1: printf("Enter ID: ");         select = 1; break;
            case 2: printf("Enter Name: ");       select = 2; break;
            case 3: printf("Enter NIC: ");        select = 3; break;
            case 4: printf("Enter Department: "); select = 4; break;
            default:
                printf("Invalid Number\n");
                continue;
        }

        fgets(search, sizeof(search), stdin);
        search[strcspn(search, "\n")] = '\0';

        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|   %-18s %-20s %-18s %-35s %-20s|\n",
               "ID", "Name", "Phone_NO", "Designation", "Department");

        fp = fopen("D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt", "r");
        if (fp == NULL) {
            printf("Error opening file! Check the folder path.\n");
            return;
        }

        while (i < count && fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = '\0';

            memset(&emp[i], 0, sizeof(emp[i]));
            // file order: id | name | nic | phone | designation | department
            sscanf(line, "%49[^|]|%49[^|]|%29[^|]|%14[^|]|%29[^|]|%29[^|]",
                   emp[i].emp_id, emp[i].emp_name, emp[i].nic,
                   emp[i].phone, emp[i].designation, emp[i].dep);

            int match = 0;
            switch (select) {
                case 1: match = (strstr(emp[i].emp_id,   search) != NULL); break;
                case 2: match = (strstr(emp[i].emp_name, search) != NULL); break;
                case 3: match = (strcmp(emp[i].nic,      search) == 0);    break;
                case 4: match = (strstr(emp[i].dep,      search) != NULL); break;
            }

            if (match) {
                printf("|   %-18s %-20s %-18s %-35s %-20s|\n",
                       emp[i].emp_id, emp[i].emp_name, emp[i].phone,
                       emp[i].designation, emp[i].dep);
                found++;
            }
            i++;
        }
        fclose(fp);

        if (found == 0) {
            printf("|   No matching employee found.\n");
        }
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
    }
     getchar();
}



static int splitFields(char *line, char *f[], int max){
    int n = 0;
    f[n++] = line;
    for (char *p = line; *p && n < max; p++) {
        if (*p == '|') {
            *p = '\0';
            f[n++] = p + 1;
        }
    }
    return n;
}

void updateEmployee(){
    clearScreen();
    const char *PATH = "D:\\C program\\network update\\EMPLOYEE-MANAGEMENT-SYSTEM\\EMS-Final\\EMPLOYEE-MANAGEMENT-SYSTEM\\File_Manegement\\employee.txt";

    int count = countLines();
    if (count == 0)
    {
        printf("No employees found.\n");
        return;
    }

    struct employee emp[count + 1];
    FILE *fp;
    char line[300];
    int choice;
    char change[50];
    char buffer[20];
    char login[50];

    printf("Enter Employee ID: ");
    fgets(login, sizeof(login), stdin);
    login[strcspn(login, "\n")] = '\0';

    do{
        int i = 0;
        int j = 0;
        int pos = -1;

        fp = fopen(PATH, "r");
        if (fp == NULL)
        {
            printf("Error opening file! Check the folder path.\n");
            return;
        }

        while (i < count && fgets(line, sizeof(line), fp) != NULL){

            line[strcspn(line, "\r\n")] = '\0';
            if (line[0] == '\0') continue;

            memset(&emp[i], 0, sizeof(emp[i]));

            char *f[10] = {0};
            int n = splitFields(line, f, 10);
            if (n < 6) continue;      // really broken line

            // file order: id | name | nic | phone | designation | department | category(hidden) | join_date | username | password
            snprintf(emp[i].emp_id,      sizeof(emp[i].emp_id),      "%s", f[0]);
            snprintf(emp[i].emp_name,    sizeof(emp[i].emp_name),    "%s", f[1]);
            snprintf(emp[i].nic,         sizeof(emp[i].nic),         "%s", f[2]);
            snprintf(emp[i].phone,       sizeof(emp[i].phone),       "%s", f[3]);
            snprintf(emp[i].designation, sizeof(emp[i].designation), "%s", f[4]);
            snprintf(emp[i].dep,         sizeof(emp[i].dep),         "%s", f[5]);
            snprintf(emp[i].category,    sizeof(emp[i].category),    "%s", n > 6 ? f[6] : "");
            snprintf(emp[i].join_date,   sizeof(emp[i].join_date),   "%s", n > 7 ? f[7] : "");
            snprintf(emp[i].username,    sizeof(emp[i].username),    "%s", n > 8 ? f[8] : "");
            snprintf(emp[i].password,    sizeof(emp[i].password),    "%s", n > 9 ? f[9] : "");

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

        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("Employee ID : %s (Cannot be changed)\n", emp[pos].emp_id);
        printf("   1. Full Name       : %s\n", emp[pos].emp_name);
        printf("   2. NIC             : %s\n", emp[pos].nic);
        printf("   3. Phone           : %s\n", emp[pos].phone);
        printf("   4. Designation     : %s\n", emp[pos].designation);
        printf("   5. Department      : %s\n", emp[pos].dep);
        printf("   6. Join Date       : %s\n", emp[pos].join_date);
        printf("   7. Password        : %s\n", emp[pos].password);
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("   0. Discard changes and go back\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("Enter choice: ");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        change[0] = '\0';
        if (choice >= 1 && choice <= 7)
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
            case 4 : snprintf(emp[pos].designation, sizeof(emp[pos].designation), "%s", change); break;
            case 5 : snprintf(emp[pos].dep,         sizeof(emp[pos].dep),         "%s", change); break;
            case 6 : snprintf(emp[pos].join_date,   sizeof(emp[pos].join_date),   "%s", change); break;
            case 7 : snprintf(emp[pos].password,    sizeof(emp[pos].password),    "%s", change); break;
            case 0 :
                printf("Back\n");
                break;
            default:
                printf("Invalid Number\n");
                break;
        }

        if (choice >= 1 && choice <= 7)
        {
            fp = fopen(PATH, "w");
            if (fp == NULL)
            {
                printf("Error opening file! Check the folder path.\n");
                return;
            }

            while (j < i){
                // same file order as when reading
                fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
                        emp[j].emp_id, emp[j].emp_name, emp[j].nic, emp[j].phone,
                        emp[j].designation, emp[j].dep, emp[j].category,
                        emp[j].join_date, emp[j].username, emp[j].password);
                j++;
            }

            fclose(fp);
            printf("Save Change...\n");
        }

        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("\n");

    } while (choice != 0);
     getchar();
}