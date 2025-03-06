#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct employee emp, high_emp, low_emp;
    int i, n;
    float high = 0, low = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("\nEnter details of %d employee:-\n", i + 1);

        printf("Enter Name: ");
        scanf(" %[^\n]", emp.name);  // Read full name including spaces

        printf("Enter ID: ");
        scanf("%d", &emp.id);

        printf("Enter Salary: ");
        scanf("%f", &emp.salary);

        // Initialize high and low with the first employee's salary
        if (i == 0) {
            high = low = emp.salary;
            high_emp = low_emp = emp;
        } else {
            if (emp.salary > high) {
                high = emp.salary;
                high_emp = emp;
            }
            if (emp.salary < low) {
                low = emp.salary;
                low_emp = emp;
            }
        }
    }

    // Displaying Employee with Highest Salary
    printf("\nEmployee with Highest Salary:\n");
    printf("Name: %s\n", high_emp.name);
    printf("ID: %d\n", high_emp.id);
    printf("Salary: %.2f\n", high_emp.salary);

    // Displaying Employee with Lowest Salary
    printf("\nEmployee with Lowest Salary:\n");
    printf("Name: %s\n", low_emp.name);
    printf("ID: %d\n", low_emp.id);
    printf("Salary: %.2f\n", low_emp.salary);

    return 0;
}
