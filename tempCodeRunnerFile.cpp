#include <stdio.h>

int main() {
    int i, j;
    int a[3][3], *p[3];

    // Point each pointer to the corresponding row
    for(i = 0; i < 3; i++) {
        p[i] = a[i];
    }

    // Input matrix elements
    printf("Enter 3x3 matrix elements:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    // Display transpose of the matrix
    printf("\nTransposed Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", p[j][i]);
        }
        printf("\n");
    }

    return 0;
}