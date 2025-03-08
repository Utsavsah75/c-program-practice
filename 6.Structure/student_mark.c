#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int id;
    float marks[3]; // Array to store marks of 3 subjects
};

int main() {
    int n, i, j,n1=3;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct student std[n]; // Array of structures to store multiple students
    
    for (i = 0; i < n; i++) {
        printf("\nEnter the details of student %d", i + 1);
        
        printf("\nEnter the name of the student: ");
        getchar(); // Clear the newline character from buffer
        fgets(std[i].name, sizeof(std[i].name), stdin);
        
        printf("Enter the ID: ");
        scanf("%d", &std[i].id);

        for (j = 0; j < n1; j++) {
            printf("Enter the marks of subject %d: ", j + 1);
            scanf("%f", &std[i].marks[j]);
        }
    }

    // Printing student details
    printf("\n************Student Information:*************\n");
    for (i = 0; i < n; i++) {
        printf("\nInformation of student %d", i + 1);
        printf("\nName: %s", std[i].name);
        printf("ID: %d\n", std[i].id);
        
        for (j = 0; j < n1; j++) {
            printf("Marks of subject %d: %.2f \n", j + 1, std[i].marks[j]);
        }
    }

    return 0;
}
