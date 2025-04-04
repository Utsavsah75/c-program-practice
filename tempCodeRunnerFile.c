#include <stdio.h>

int main() {
    int r, c, i, j, a[10][10], t[10][10];
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input matrix with labeled elements
    printf("Enter elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++) {
            printf("a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    // Display matrix
    printf("Matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    // Transpose and display
    printf("Transpose:\n");
    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++)
            printf("%d\t", a[j][i]);
        printf("\n");
    }

    return 0;
}
