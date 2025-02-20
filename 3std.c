#include <stdio.h>
int main() {
  int i, j, n = 3;
  float sum, avg, per, marks;
  char name[50];
  int roll_number;

  for (j = 0; j < n; j++) {
    sum = 0;
    printf("Enter the name of student %d: ", j + 1);
    scanf("%s", name);
    printf("Enter the roll number of student %d: ", j + 1);
    scanf("%d", &roll_number);

    for (i = 0; i < 5; i++) { // Assuming 5 subjects for each student
      printf("Enter the marks of subject %d: ", i + 1);
      scanf("%f", &marks);
      sum += marks;
    }
    avg = sum / 5;
    per = (sum / 500) * 100; // Assuming each subject is out of 100 marks
    printf("The average marks of %s (Roll No: %d) is: %.2f\n", name,
           roll_number, avg);
    printf("The percentage of %s (Roll No: %d) is: %.2f\n", name, roll_number,
           per);
  }
  return 0;
}