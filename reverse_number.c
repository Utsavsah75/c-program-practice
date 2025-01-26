// write a program to find the reverse of a number.
#include <conio.h>
#include <stdio.h>

int main() {
  int num, rev = 0, rem;
  printf("Enter a number: ");
  scanf("%d", &num);
  while (num != 0) {
    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
  }
  printf("The reverse of the number is: %d\n", rev);
  return 0;
}
