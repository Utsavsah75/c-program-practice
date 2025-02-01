// WAPto find the largest number among three numbers using function.
#include <stdio.h>
int largest(int, int, int);

int main() {
  int a, b, c, l;
  printf("Enter the three numbers=");
  scanf("%d%d%d", &a, &b, &c);
  l = largest(a, b, c);
  printf("The largest number among %d,%d,%d is=%d", a, b, c, l);
  return 0;
}
int largest(int a, int b, int c) {
  if (a > b && a > c)
    return a;
  else if (b > a && b > c)
    return b;
  else
    return c;
}