#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[50];
  int id;
  float marks;
} std;

int main() {
  int i, n;
  printf("Enter the number of student:");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("\nEnter the detail of student:");
    printf("\nEnter the name of %d student: ", i + 1);
    getchar();
    fgets(std.name, 50, stdin);
    printf("Enter the id: ");
    scanf("%d", &std.id);
    printf("Enter the marks: ");
    scanf("%f", &std.marks);
    printf("\n");
  }
  for (i = 0; i < n; i++) {
    printf("Information of %d student:-", i + 1);
    printf("\nName: %s", std.name);
    printf("ID: %d\n", std.id);
    printf("Marks: %.2f\n", std.marks);
  }
}