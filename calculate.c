#include <stdio.h>

int main() {
  int i, n = 3, roll_number;
  float sum, avg, per, marks;
  char name[50];
  printf("Enter the name of the student: ");
  gets(name);
  printf("Enter the roll number of the student: ");
  scanf("%d", &roll_number);
  for (i = 0; i < n; i++) {
    printf("Enter the marks of subject %d: ", i + 1);
    scanf("%f", &marks);
    sum += marks;
  }
  avg = sum / n;
  per = (sum / (n * 100)) * 100;
  printf("---------------------------------------------\n");
  //   printf("The name of the student is: %s\n", name);//   printf("The roll number of the student is: %d\n", roll_number);
  printf("The total marks obtained by the student is: %.2f\n", sum);
  printf("The average marks obtained by the student is: %.2f\n", avg);
  printf("The percentage of the student is: %.2f\n", per);

  return 0;
}