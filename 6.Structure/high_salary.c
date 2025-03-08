#include <stdio.h>
#include <stdlib.h>

struct employee {
    // char name[30];
    int age;
    float salary;

} emp[50];

int main() {
    int i, n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter The detail of %d employee", i + 1);
        printf("\nEnter the name : ");
        scanf("%s", emp[i].name);
        printf("Enter the age of employee: ");
        scanf("%d", &emp[i].age);
        printf("Enter the salary of employee: ");
        scanf("%f", &emp[i].salary);
    }
    printf("\nEmployees with salary less than 10000 are: ");
    for (i = 0; i < n; i++) {
        if (emp[i].salary > 1000) {
            printf("\nName: %s\n", emp[i].name);
            printf("\nAge: %d", emp[i].age);
            printf("\nSalary: %.2f", emp[i].salary);
        }
    }
}
