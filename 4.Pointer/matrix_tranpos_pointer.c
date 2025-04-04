#include <stdio.h>
int main() {
    int a[3][3], i, j;
    int (*p)[3];
    p = a;

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < 3; i++)   
        for (j = 0; j < 3; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", (*(p + i) + j));  // Correct way to access using pointer
        }
    printf("\nThe matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("  %d", *(*(p + i) + j));  // Dereferencing to get value
        printf("\n"); // Move to next line after printing a row
    }
    printf("\nTranspose matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
            printf("  %d", *(*(p + j) + i));  // Switching rows and columns
        printf("\n"); // Move to next line after printing a row
    }
    return 0;
}
