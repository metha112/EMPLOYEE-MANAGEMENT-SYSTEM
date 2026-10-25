
#include <stdio.h>
#include <string.h>

struct salary
{
    char sch_emp_id[50];
   
};

void salary();

int main()
{
    salary();
    return 0;
}

void salary()
{
    FILE *file;
    FILE *fp;
    struct salary l1;

    int x = 0, y = 0;
    int count;
    int attend = 0;
    char id[50];

    char empid[50], name[50], nic[30], ph[15],position[30], dep[100], joint_date[20],username[50], password[20];

    char line[500];

    file = fopen("employee.txt", "r");

    if (file == NULL)
    {
        printf("Employee file is not in management system\n");
        return;
    }

    printf("Enter the employee ID: ");
    scanf("%49s", l1.sch_emp_id);

    fp = fopen("attendance_count.txt", "r");

    if (fp == NULL)
    {
        printf("Attendance count file is not in management system\n");
        fclose(file);
        return;
    }

    int found = 0;

    while (fscanf(fp, " %49[^|]|%d", id, &count) == 2)
    {
        if (strcmp(id, l1.sch_emp_id) == 0)
        {
            attend = count;
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found == 0)
    {
        printf("Employee is not in attendance count file\n");
        fclose(file);
        return;
    }

    
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *fields[9];
        int field_count = 1;

        
        line[strcspn(line, "\r\n")] = '\0';

        fields[0] = line;
        for (int j = 0; line[j] != '\0'; j++)
        {
            if (line[j] == '|')
            {
                line[j] = '\0';

                if (field_count < 9)
                {
                    fields[field_count] = &line[j + 1];
                }

                field_count++;
            }
        }

        if (field_count != 9)
        {
            continue;
        }

        strcpy(empid, fields[0]);
        strcpy(name, fields[1]);
        strcpy(nic, fields[2]);
        strcpy(ph, fields[3]);
        strcpy(position, fields[4]);
        strcpy(dep, fields[5]);
        strcpy(joint_date, fields[6]);
        strcpy(username, fields[7]);
        strcpy(password, fields[8]);

        if (strcmp(empid, l1.sch_emp_id) == 0)
        {
            
            float salary=0;
            int valid_position = 1;
            if (strcmp(position, "professor") == 0)
            {
                salary = attend * 10000;
                
            }
            else if (strcmp(position, "Senior Lecturer") == 0)
            {
                salary = attend * 9000;
                
            }
            else if (strcmp(position, "Lecturer") == 0)
            {
                salary = attend * 7000;
                
            }
            else if (strcmp(position, "Demonstrator") == 0)
            {
                salary = attend * 5000;
                
            }
            else if (strcmp(position, "Instructor") == 0)
            {
                salary = attend * 3000;
                
            }
            else if (strcmp(position, "Registant") == 0)
            {
                salary = attend * 2000;
                
            }
            else if (strcmp(position, "Management Assistant") == 0)
            {
                salary = attend * 2000;
                
            }
            else if (strcmp(position, "Finance Division staff") == 0)
            {
                salary = attend * 2000;
                
            }
            else if (strcmp(position, "Technical Officer") == 0)
            {
                salary = attend * 1500;
                
            }
            else if (strcmp(position, "Laboratory Attendant") == 0)
            {
                salary = attend * 1500;
                
            }
            else if (strcmp(position, "Office Aide") == 0)
            {
                salary = attend * 1000;
                
            }
            else if (strcmp(position, "Driver") == 0)
            {
               salary = attend * 1000;
                
            }
            else if (strcmp(position, "Security") == 0)
            {
                salary = attend * 1000;
                
            }
            else
            {
                printf("Salary calculation is not available for this position.\n");
                valid_position = 0;
            }


            if (valid_position == 1)
            {

                FILE *f;

                f=fopen("salary.txt","a");
                if (f!=NULL)
                {
                    fprintf(f,"%s %.2f\n",l1.sch_emp_id,salary);
                    fclose(f);
                    printf("NOW SALARY IS ADD TO THE SALARY MANAGEMENT SYSTEM");
                    
                }
                else{
                    printf("file is not management system");
                }
            }
            

            x = 1;
            break;
        }
    }

    if (x == 0)
    {
        printf("Employee is not found in employee file\n");
    }

    fclose(file);
}
