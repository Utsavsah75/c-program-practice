#include <stdio.h>

int main() {
  int r, c, i, j, t[10][10];
  printf("Enter rows and columns: ");
  scanf("%d %d", &r, &c);

  printf("Enter elements:\n"); // Input matrix with labeled elements
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++) {
      printf("a%d%d: ", i + 1, j + 1);
      scanf("%d", &t[i][j]);
    }

  printf("Matrix:\n"); // Display matrix
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++)
      printf("%d\t", t[i][j]);
    printf("\n");
  }

  printf("Transpose:\n"); // Transpose and display
  for (i = 0; i < c; i++) {
    for (j = 0; j < r; j++)
      printf("%d\t", t[j][i]);
    printf("\n");
  }
  return 0;
}
