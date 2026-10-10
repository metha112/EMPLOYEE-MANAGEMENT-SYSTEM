#include<stdio.h>
void salary();
int main(){

    return 0;
}
void salary(){
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
        printf("enter the employee id : ");
        scanf("%d",&schempid);

        while (fscanf(file, "%d %49s %49s %49s %99s %d %f",&empid,name,dep,position,email,ph,&salary)==7)
        {
            if (empid==schempid)
            {
                printf("Employee id :%d\n",empid);
                printf("Basic salary :%f\n",salary);
                printf("Enter the allowance : ");
                scanf("%f",&allowance);

                printf("Enter the deduction : ");
                scanf("%f",&deduction);

                netsalary=(salary+allowance)-deduction;

                printf("\n");

                printf("---------------------------------\n");
                printf("Net salary = %.2f\n",netsalary);

                x=1;
                break;
            }
        }
        if (x==0)
        {
            printf("employee is not found\n");
        }
        fclose(file);
    
        
    }
    
    
    
}