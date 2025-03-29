#include <stdio.h>

int main() {
  int i,n;
  printf("Enter a number: -");
  scanf("%d",&n);
  printf("Number\tSquare\tCube\n");
  // printf("------------------------\n");

  for (i = 1; i <= n; i++) {
    printf(" %d\t %d\t %d\n", i, i * i, i * i * i);
  }

  return 0;

  
}
