// WAP to find the sum of first and last digit of a number using function.
#include <stdio.h>
int sumfirstlast(int);

int sumfirstlast(int num) {
  int last, first;
  last = num % 10;
  while (num >= 10) {
    num /= 10;
    first = num;
  }
  return first+ last;
}

int main() {
  int num, sum;
  printf("Enter a number: ");
  scanf("%d", &num);
  sum = sumfirstlast(num);
  printf("The sum of first and last digit of %d is: %d\n", num, sum);
  return 0;
}
/*output
Enter a number: 12345
The sum of first and last digit of 12345 is 6
*/