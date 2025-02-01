#include <stdio.h>

int main() {
  int n, i, f, f1 = 0, f2 = 1;
  printf("Enter the number of Fibonacci series to generate: ");
  scanf("%d", &n);
  printf("Fibonacci series: %d %d", f1, f2);
  for (i = 2; i < n; ++i) {
    f = f1 + f2;
    printf(" %d", f);
    f1 = f2;
    f2 = f;
  }
  return 0;
}