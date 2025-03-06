#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
}emp;

int main() {
    // struct employee ;
    
    printf("Enter information of employees:\n");
    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    getchar(); // to consume the newline character left by previous scanf
    fgets(emp.name, 50, stdin);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);


    printf("\n\"Displaying Information of Employees\"\n");
    printf("id=%d\n", emp.id);
    printf("Name=%s", emp.name);
    printf("Salary=%.2f", emp.salary);
    return 0;
}