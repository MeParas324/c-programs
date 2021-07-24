#include<stdio.h>
#include<stdlib.h>

struct Employees
{
    char name[20];
    int age;
    double salary;
};


int main()
{
    int no, i;
   

    printf("Enter the number of employees\n");
    scanf("%d", &no);
    struct Employees *emp = (struct Employees*)calloc(no,sizeof(struct Employees));

    for (i = 1; i <= no; i++)
    {
        printf("Enter the details of %d Employee:\n", i);

        printf("Name: ");
        scanf(" %[^\n]s", &emp[i].name);
        
        printf("Age: ");
        scanf("%d", &emp[i].age);

        printf("Salary: ", i);
        scanf("%lf", &emp[i].salary);
    }
    
    printf("=======================Employees details========================\n");
    for (i = 1; i <= no; i++)
    {
        printf("\n\t Printing the details of %d Employee:\n", i);
        printf("\n\t Name: %s", emp[i].name);
        printf("\n\t Age: %d", emp[i].age);
        printf("\n\t Salary: %lf\n", emp[i].salary);
    }
    

}