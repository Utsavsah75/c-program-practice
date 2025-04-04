#include <stdio.h>

int main() {
    int n, i, j;
    int a[100][100], b[100][100], sum[100][100], sub[100][100];
    
    // Input matrix size
    printf("Enter the Matrix size: ");
    scanf("%d", &n);
    
    // Input first matrix A
    printf("Enter the first matrix A: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter Element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    // Input second matrix B
    printf("Enter the second matrix B: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter Element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    
    // Performing addition and subtraction
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
    
    // Display sum of matrices
    printf("Sum of the two matrices: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    
    // Display subtraction of matrices
    printf("Subtraction of the two matrices: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
