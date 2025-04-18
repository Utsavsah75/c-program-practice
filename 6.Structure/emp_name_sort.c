#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    float salary;
}emp[50];

int main() {
    int i, j, n;
    struct employee temp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // struct employee emp[n];

    // Input employee data
    for(i = 0; i < n; i++) {
        printf("\nEnter information of employee %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", emp[i].name);
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Sort by name (ascending)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(strcmp(emp[i].name, emp[j].name) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }

    // Display employee info
    printf("\n\"Displaying Information of Employees (Sorted by Name)\"\n");
    for(i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("ID: %d\n", emp[i].id);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    return 0;
}
