#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};
int main() {
    struct Student std[3]; // Array of 3 Student structures
    for (int i = 0; i < 3; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &std[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]", std[i].name); // To read full name including spaces
        printf("Marks: ");
        scanf("%f", &std[i].marks);
    }
    printf("\nStudent Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", 
               std[i].rollNo, std[i].name, std[i].marks);
    }
    return 0;
}
