#include <conio.h>
#include <stdio.h>


int main() {
  int i, number, totalMarks;
  float percentage, obtainMarks, avg, sum = 0;

  printf("Enter the number of Subjects: "); // Input the number of subjects
  scanf("%d", &number);

  printf("Enter the Total mark of all subject: "); // Input the total marks of
                                                   // all subjects
  scanf("%d", &totalMarks);
  printf("\n------------------------\n");

  for (i = 0; i < number;
       i++) { // Loop to input the obtained marks of each subject
    printf("Enter the obtained marks of subject %d: ", i + 1);
    scanf("%f", &obtainMarks);
    sum += obtainMarks;
  }
  if (sum > totalMarks) { // check if the obtained marks is greater than or
                          // equal to total marks then
    printf("Error: Obtained marks is greater than total marks please check the "
           "number \n");
    exit(0);
  }
  printf("\n-------- Results --------\n"); // Display the results
  printf("Total Marks: %.2f\n", sum);
  avg = sum / number;
  printf("Average Marks: %.2f\n", avg);
  percentage = (sum / totalMarks) * 100;
  printf("Percentage: %.2f%%\n", percentage);

  if (percentage >= 80) { // Check the percentage and display the division
    printf("Division: First\n");
  } else if (percentage >= 60) {
    printf("Division: Second\n");
  } else if (percentage >= 40) {
    printf("Division: Third\n");
  } else {
    printf("Division: Fail\n");
  }
  return 0;
}
