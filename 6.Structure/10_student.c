#include <stdio.h>
#include <string.h>

// Define a structure for Student
struct Student {
    int rollNo;
    char fname[50];
    char lname[50];
} std[10]; // Global declaration (removing duplicate inside main)

int main() {
    struct Student temp; // Temporary variable for swapping
    int i, j;

    // Input student details
    printf("Enter details for 10 students (Roll No, First Name, Last Name):\n");
    for (i = 0; i < 10; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &std[i].rollNo);
        printf("First Name: ");
        scanf("%s", std[i].fname);
        printf("Last Name: ");
        scanf("%s", std[i].lname);
    }

    // Sorting using Bubble Sort (Ascending Order of Roll No)
    for (i = 0; i < 9; i++) {  // Outer loop runs 9 times
        for (j = 0; j < 9 - i; j++) {  // Inner loop runs 9-i times
            if (std[j].rollNo > std[j + 1].rollNo) {
                temp = std[j];
                std[j] = std[j + 1];
                std[j + 1] = temp;
            }
        }
    }

    // Display sorted student records
    printf("\nSorted Student Records (by Roll No):\n");
    for (i = 0; i < 10; i++) {
        printf("Roll No: %d\n", std[i].rollNo);
        printf("First Name: %s\n", std[i].fname);
        printf("Last Name: %s\n", std[i].lname); 
    }

    return 0;
}
