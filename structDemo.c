// Online C compiler to run C program online
#include <stdio.h>

void addRecord();
void displayRecord();
void searchEmployees();
void updateEmployees();
void deleteRecord();
void calculateSalary();

struct Employee
{
    int emp_id;
    char emp_name[20];
    char emp_dept[20];
    float emp_salary;
} emp[50];
// struct Employee emp[50];
int n = 0;

int main()
{
    char ch;
    int flag = 1;
    printf("a.Add a new employee record\n");
    printf("b.Display all record employee\n");
    printf("c.Search for an employee by id\n");
    printf("d.Update emplyee details by id\n");
    printf("e.Delete an emplyee record by id\n");
    printf("f.calculate and display total salary of employee\n");
    printf("g.Generate a report of employee in a specific department.\n");
    printf("h.Exit\n");

    do
    {
        printf("Enter Choice:\n");
        fflush(stdin);
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            addRecord();
            break;

        case 'b':
            displayRecord();
            break;

        case 'c':
            searchEmployees();
            break;

        case 'd':
            updateEmployees();
            break;

        case 'e':
            deleteRecord();
            break;

        case 'f':
            calculateSalary();
            break;

        case 'g':
            break;

        case 'h':
            flag = 0;
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (ch != 'h');

    return 0;
}

void calculateSalary()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + emp[i].emp_salary;
    }
    printf("Total salary of employee:%d", sum);
}

void deleteRecord()
{
    int index;
    printf("Enter index of employee to delete\n");
    scanf("%d", &index);
    for (int i = index; i < n; i++)
    {
        emp[i] = emp[i + 1];
    }
    n = n - 1;
}

void updateEmployees()
{
    int index;
    printf("Enter index of employee to update\n");
    scanf("%d", &index);
    struct Employee e;
    printf("Enter emp id:");
    scanf("%d", &e.emp_id);

    for (int i = 0; i < n; i++)
    {
        if (e.emp_id == emp[i].emp_id)
        {
            printf("emp id already exist.");
            return;
        }
    }
    printf("Enyter emp name:");
    scanf("%s", &e.emp_name);
    printf("Enyter emp department:");
    scanf("%s", &e.emp_dept);
    printf("Enyter emp salary:");
    scanf("%f", &e.emp_salary);

    emp[index] = e;
}

void searchEmployees()
{
    int id;
    printf("Enter Employee id:");
    scanf("%d", &id);
    for (int i = 0; i < n; i++)
    {
        if (id == emp[i].emp_id)
        {
            printf("Employee ID:%d\n", emp[i].emp_id);
            printf("Employee Name:%d\n", emp[i].emp_name);
            printf("Employee Salary:%d\n", emp[i].emp_salary);
            printf("Employee Dept:%d\n", emp[i].emp_dept);
        }
    }
}

void displayRecord()
{
    for (int i = 0; i < n; i++)
    {
        printf("Employee ID:%d\n", emp[i].emp_id);
        printf("Employee Name:%d\n", emp[i].emp_name);
        printf("Employee Salary:%d\n", emp[i].emp_salary);
        printf("Employee Dept:%d\n", emp[i].emp_dept);
    }
}

void addRecord()
{
    struct Employee e;
    printf("Enter emp id:");
    scanf("%d", &e.emp_id);

    for (int i = 0; i < n; i++)
    {
        if (e.emp_id == emp[i].emp_id)
        {
            printf("emp id already exist.");
            return;
        }
    }
    printf("Enyter emp name:");
    scanf("%s", &e.emp_name);
    printf("Enyter emp department:");
    scanf("%s", &e.emp_dept);
    printf("Enyter emp salary:");
    scanf("%f", &e.emp_salary);

    emp[n] = e;
    n = 1;
    printf("Employee added succesfully\n");
}