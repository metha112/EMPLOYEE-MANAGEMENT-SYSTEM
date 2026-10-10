#include<stdio.h>
void salary();
int main(){

    return 0;
}
void salary(){
    FILE *file;
    int empid,schempid;
    int x,y=0;
    float salary,allowance,deduction,netsalary;
    
    

    file=fopen("employee.txt","r");
    if (file==NULL)
    {
        printf("file is not in management system\n");

        y==1;
    }
    if (y==0)
    {
        printf("enter the employee id : ");
        scanf("%d",&schempid);

        while (fscanf(file, "%d %lf",&empid,&salary)==3)
        {
            if (empid==schempid)
            {
                printf("Employee id :%d",empid);
                printf("Basic salary :%f",salary);
                printf("Enter the allowance : ");
                scanf("%d",&allowance);

                printf("Enter the deduction : ");
                scanf("%d",&deduction);

                netsalary=(salary+allowance)-deduction;

                printf("\n");

                printf("---------------------------------\n");
                printf("Net salary = %f",netsalary);

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