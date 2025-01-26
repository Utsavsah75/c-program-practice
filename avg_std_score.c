#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, i, sum = 0;
  float avg, score[num];
  printf("Enter the number of subjects: ");
  scanf("%d", &num);
  if (num <= 0) {
    printf("Invalid number of subject. Please enter a +ve number");
    return 0;
  }
  for (i = 0; i < num; i++) {
    printf("Enter the score of subject %d: ", i + 1);
    scanf("%f", &score[i]);
    sum = sum +score[i];
  }
  avg = (float)sum / num;
  printf("The average score of each subject is %.2f", avg);
}
