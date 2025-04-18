#include <stdio.h>

int main() {
    int r, c, i, j;
    int t[10][10]; // still using 2D array memory, but accessing via pointer

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            printf("a%d%d: ", i + 1, j + 1);
            // *(*(t + i) + j) = 0; // just initializing (optional)
            scanf("%d", (*(t + i) + j));
        }

    printf("Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d\t", *(*(t + i) + j));
        printf("\n");
    }

    printf("Transpose:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d\t", *(*(t + j) + i));
        printf("\n");
    }

    return 0;
}
