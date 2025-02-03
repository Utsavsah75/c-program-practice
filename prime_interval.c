// WAP to print all prime numbers between two intervals using functions.
#include <stdio.h>
int primenumber(int, int);
int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  printf("Prime numbers between %d and %d are: ", num1, num2);
  primenumber(num1, num2);
  return 0;
}
int primenumber(int prime1, int prime2) {
  while (prime1 < prime2) {
    int sum = 0;
    for (int i = 2; i <= prime1 / 2; ++i) {
      if (prime1 % i == 0) {
        sum = 1;
        break;
      }
    }
    if (sum == 0) 
      printf("%d ", prime1);
    ++prime1;
  }
  return 0;
}
/*output
Enter two numbers: 7    19
Prime numbers between 7 and 19 are: 7 11 13 17 
*/