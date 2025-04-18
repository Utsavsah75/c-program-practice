#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
}emp;

int main() {
    // struct employee ;
    int i, n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
    printf("Enter information of employees: %d",i+1);
    printf("\nEnter Name: ");
    getchar(); // to consume the newline character left by previous scanf
    fgets(emp.name, 50, stdin);
    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    printf("\n");


}

printf("\n\"Displaying Information of Employees\"\n");
for(i=0;i<n;i++){
    printf("Information of employees: %d",i+1);
    printf("Name: %s", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Salary: %.2f\n", emp.salary);
    // 
    printf("\n");
}
    return 0;
}
