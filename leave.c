#include<stdio.h>
#include<string.h>

struct Leave
{
    
    int employeeID;
    char leaveType[20];
    int leavedays;
    char status[20];
};

void leave(int n);
void apply_leave();
void view_leave();
void approve_leave();
void reject_leave();
int main(){
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    leave(n);

    return 0;
}
void leave(int n){
    switch (n)
    {
    case 1:
        apply_leave();
        break;
    case 2:
        view_leave();
        break;
    case 3:
        approve_leave();
        break;
    case 4:
        reject_leave();
        break;
    
    case 0:
        
        break;
    default:
        break;
    }
}
void apply_leave(){
    
    int choice;
    struct Leave l1;
    printf("\n--- Select Leave Type ---\n");
    printf("Annual leave=1\n");
    printf("Casual leave=2\n");
    printf("Medicle leave=3\n");
    printf("No-Pay leave=4\n");
    

    printf("Enter your leave type : ");
    scanf("%d",&choice);


    


    switch (choice)
    {
    case 1:
        strcpy(l1.leaveType, "Annual");
        break;
    case 2:
        strcpy(l1.leaveType, "Casual");
        break;
    case 3:
            strcpy(l1.leaveType, "Medical");
            break;
    case 4:
            strcpy(l1.leaveType, "No-Pay");
            break;
    
    default:
            printf("Invalid leave type!\n");
            return;
    
    }
    





    FILE *file;
    int empid,schempid,ph;
    int x=0,y=0;
    float salary,allowance,deduction,netsalary;
    char name[50],dep[50],position[50],email[100];
    
    

    file=fopen("employee.txt","r");
    if (file==NULL)
    {
        printf("file is not in management system\n");

        y=1;
    }
    if (y==0)
    {
        printf("Enter Employee ID: ");
        scanf("%d", &l1.employeeID);

        while (fscanf(file, "%d %49s %49s %49s %99s %d %f",&empid,name,dep,position,email,&ph,&salary)==7)
        {
            if (empid==l1.employeeID)
            {

                printf("Enter number of leave days: ");
                scanf("%d", &l1.leavedays);

                if (l1.leavedays <= 0)
                {
                    printf("Invalid number of days!\n");
                    fclose(file);
                    return;
                }
                strcpy(l1.status, "Pending");

                printf("\nLeave application details\n");
                printf("Employee ID: %d\n", l1.employeeID);
                printf("Leave Type: %s\n", l1.leaveType);
                printf("Leave Days: %d\n", l1.leavedays);
                printf("Status: %s\n", l1.status);
                
                FILE *leaveFile;

                leaveFile = fopen("leave.txt", "a");

                if (leaveFile == NULL)
                {
                    printf("Unable to open leave file!\n");
                    fclose(file);
                    return;
                }

                fprintf(leaveFile, "%d %s %d %s\n",
                        l1.employeeID,
                        l1.leaveType,
                        l1.leavedays,
                        l1.status);

                fclose(leaveFile);

                printf("Leave application saved successfully!\n");


                x=1;
                break;
            }
        }
        if (x==0)
        {
            printf("employee is not found\n");
            fclose(file);
            return;
        }
        fclose(file);
    
        
    }
}
void view_leave(){
   
    FILE *file;
    struct Leave l1;
    int found = 0;

    file = fopen("leave.txt", "r");

    if (file == NULL)
    {
        printf("No leave applications found!\n");
        return;
    }

    printf("\n--- Leave Applications ---\n");

    while (fscanf(file, "%d %19s %d %19s",
                  &l1.employeeID,
                  l1.leaveType,
                  &l1.leavedays,
                  l1.status) == 4)
    {
        printf("\nEmployee ID: %d\n", l1.employeeID);
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

void approve_leave(){


    FILE*file ,*temp;
    struct Leave l1;
    int empid,found=0;
    file=fopen("leave.txt","r");


    if (file==NULL)
    {
        printf("No leave applications found!\n");
        return;
    }
    
    temp=fopen("temp.txt","w");

    if (temp == NULL)
    {
        printf("Unable to create temporary file!\n");
        fclose(file);
        return;
    }

    printf("Enter Employee ID to approve leave: ");
    scanf("%d", &empid);

    while (fscanf(file, "%d %19s %d %19s",
                  &l1.employeeID,
                  l1.leaveType,
                  &l1.leavedays,
                  l1.status) == 4)
    {
        if (l1.employeeID==empid)
        {
            if (strcmp(l1.status, "Pending") == 0)
            {
                strcpy(l1.status,"Approved");
                found=1;
            }
            else
            {
                printf("Leave status is already %s.\n",
                       l1.status);
                found = 1;
            }

            
        }
        fprintf(temp, "%d %s %d %s\n",
                l1.employeeID,
                l1.leaveType,
                l1.leavedays,
                l1.status);
    }
    fclose(file);
    fclose(temp);

    if (rename("temp.txt", "leave.txt") != 0)
    {
        printf("Unable to update leave file!\n");
        return;
    }
        
    if (found == 1)
    {
        printf("Leave approval process completed.\n");
    }
    else
    {
        printf("Employee ID not found!\n");
    }




}
void reject_leave(){


    FILE*file ,*temp;
    struct Leave l1;
    int empid,found=0;
    file=fopen("leave.txt","r");


    if (file==NULL)
    {
        printf("No leave applications found!\n");
        return;
    }
    
    temp=fopen("temp.txt","w");

    if (temp == NULL)
    {
        printf("Unable to create temporary file!\n");
        fclose(file);
        return;
    }

    printf("Enter Employee ID to reject leave: ");
    scanf("%d", &empid);

    while (fscanf(file, "%d %19s %d %19s",
                  &l1.employeeID,
                  l1.leaveType,
                  &l1.leavedays,
                  l1.status) == 4)
    {
        if (l1.employeeID==empid)
        {
            if (strcmp(l1.status, "Pending") == 0)
            {
                strcpy(l1.status,"Rejected");
                found=1;
            }
            else
            {
                printf("Leave status is already %s.\n", l1.status);
                found = 1;
            }

            
        }
        fprintf(temp, "%d %s %d %s\n",
                l1.employeeID,
                l1.leaveType,
                l1.leavedays,
                l1.status);
    }
    fclose(file);
    fclose(temp);

    if (rename("temp.txt", "leave.txt") != 0)
    {
        printf("Unable to update leave file!\n");
        return;
    }
        
    if (found == 1)
    {
        printf("Leave rejection process completed.\n");
    }
    else
    {
        printf("Employee ID not found!\n");
    }
}