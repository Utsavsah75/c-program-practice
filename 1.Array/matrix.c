#include <stdio.h>

int main() {
  int a[2][2], b[2][2], c[2][2], i, j, k;
  int n, n1; // For 3x3 matrices

  printf("enter the size of matrix formate:");
  scanf("%d %d", &n, &n1); 
  
  printf("Enter the elements of the first matrix A:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n1; j++) {
      printf("Enter element a[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of the second matrix B:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n1; j++) {
      printf("Enter element b[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &b[i][j]);
    }
  }

  // Matrix multiplication
  printf("Multiplication of the two matrices:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n1; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}
