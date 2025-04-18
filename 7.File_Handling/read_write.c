#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

struct student {
  int roll;
  char name[50];
  float marks;
} std;

int main() {
  FILE *ptr;
  // struct student std;
  int n, i;

  ptr = fopen("users.txt", "w");
  if (ptr == NULL) {
    printf("The file does not exist\n");
    exit(1);
  }

  printf("Enter the number of students:");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    // printf("Enter detail for student %d:\n", i + 1);
    printf("\nEnter the detail of students: - %d:", i + 1);
    printf("\nEnter the Name of the student:");
    scanf("%s", std.name);
    printf("Enter the Roll No.:");
    scanf("%d", &std.roll);
    printf("Enter the marks of the student:");
    scanf("%f", &std.marks);
    fprintf(ptr, "Name: %s\nRoll No: %d\nMarks: %.2f\n", std.name, std.roll,
            std.marks);
  }
  fclose(ptr);

  ptr = fopen("users.txt", "r");
  if (ptr == NULL) {
    printf("The file does not exist\n");
    exit(1);
  }
  printf("\nThe Details of the students with marks > 40:\n");
  for (i = 0; i < n; i++) {
    fscanf(ptr, "Name: %[^\n]\n", std.name); // Read name with spaces
    fscanf(ptr, "Roll No: %d\n", &std.roll);
    fscanf(ptr, "Marks: %f\n", &std.marks);
    if (std.marks > 40) {//----------------------
      printf("Name: %s\nRoll No: %d\nMarks: %.2f\n\n", std.name, std.roll,
             std.marks);
    }
  }
  printf("The file is opened\n");
  fclose(ptr);
}