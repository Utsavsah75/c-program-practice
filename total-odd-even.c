// wap to find the total number of odd and even numbers in an array of 10
// elements.
#include <stdio.h>
#define n 10
int main() {
  int a[n];
  int i, odd = 0, even = 0, esum = 0, osum = 0;
  printf("Enter the array of element:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) {
      even += 1;
      esum += a[i];
    } else {
      odd += 1;
      osum += a[i];
    }
  }
  printf("the total even numberr are=%d", even);
  printf("\nthe total odd numberr are=%d", odd);
  printf("\nthe sum of total even number is=%d", esum);
  printf("\nthe sum of total odd number is=%d", osum);

  return 0;
}