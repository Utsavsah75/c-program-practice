#include <conio.h>
#include <stdio.h>


int main() {
  int i, num, fact = 1;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num < 0) {
    printf("Factorial of negative number doesn't exist.");
  } else {
    for (i = 1; i <= num; i++) {
      fact *= i;
    }
    printf("Factorial of %d is %d", num, fact);
  }
}