#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
}std;

int main() {
    FILE *ptr;
    int n, i;
    struct student std;

    ptr = fopen("users.txt", "w");
    if (ptr == NULL) {
        printf("The file does not exist\n");
        exit(1);
    }

    printf("Enter the number of students");
    scanf("%d", &n);
  
    for (i = 0; i < n; i++) {
      // printf("Enter detail for student %d:\n", i + 1);
      printf("Enter the Name of students %d:", i + 1);
      printf("Enter the Name of the student:");
      scanf("%s", std.name);
      printf("Enter the Roll No.:");
      scanf("%d", &std.roll);
      printf("Enter the marks of the student:");
      scanf("%f", &std.marks);
      fprintf(ptr, "Name: %s\nRoll No: %d\nMarks: %.2f\n", std.name, std.roll,std.marks);
    }
    fclose(ptr);

    ptr = fopen("users.txt", "r");
    if (ptr == NULL) {
        printf("The file does not exist\n");
        exit(1);
    }
    printf("\nThe Details of the students are:\n");
    for (i = 0; i < n; i++) {
      fscanf(ptr, "Name: %s", std.name);
      fscanf(ptr, "Roll No.: %s", std.roll);
      fscanf(ptr, "Marks: %s", std.marks);
      printf("Name: %s\nRoll No: %d\nMarks: %.2f\n", std.name, std.roll,
             std.marks);
    }
    printf("The file is opened\n");
    fclose(ptr);
  }