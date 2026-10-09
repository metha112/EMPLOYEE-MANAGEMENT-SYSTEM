#include<stdio.h>
void employee(int  x);
int main(){
    int x;
    printf("enter the numbre : ");
    scanf("%d",&x);

    employee(x);
    return 0;
}
void employee(int  x){
    int empid,ph;
    float salary;
    char name[50],email[100],position[50],dep[50];

    switch (x)
    {

    case 1:
        printf("add employee");
        printf("Employee id : ");
        scanf("%d",&empid );

        printf("Name : ");
        scanf("%49s", name);

        printf("Department : ");
        scanf("%49s", dep);

        printf("Position :");
        scanf("%49s", position);

        printf("Email :");
        scanf("%99s", email);

        printf("Phone : ");
        scanf("%d",&ph);

        printf("Salary : ");
        scanf("%f",salary);

        break;
    case 2:
        printf("view employee");
        break;
     case 3:
        printf("serch employee");
        break;
     case 4:
        printf("update employee");
        break;
     case 5:
        printf("delete employee");
        break;
     case 6:
        printf("employee profile");
        break;
     case 0:
        printf("exit");
        break;
    
    default:
        break;
    }
}