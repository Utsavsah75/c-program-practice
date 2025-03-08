#include <stdio.h>

// Structure to store student details
struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    
    // Taking input
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Sorting students whose age > 25
    printf("\nStudents with age greater than 25:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].age > 25) {
            printf("Name: %s, Age: %d, Marks: %.2f\n", students[i].name, students[i].age, students[i].marks);
        }
    }
    
    return 0;
}
