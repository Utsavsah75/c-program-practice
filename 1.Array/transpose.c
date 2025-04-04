#include <stdio.h>

int main() {
    int a11, a12, a21, a22;

    printf("Enter elements of 2x2 matrix:\n");

    printf("Enter a11: ");
    scanf("%d", &a11);
    printf("Enter a12: ");
    scanf("%d", &a12);
    printf("Enter a21: ");
    scanf("%d", &a21);
    printf("Enter a22: ");
    scanf("%d", &a22);

    printf("Original matrix:\n");
    printf("%d\t%d\n", a11, a12);
    printf("%d\t%d\n", a21, a22);

    printf("Transpose of the matrix:\n");
    printf("%d\t%d\n", a11, a21);
    printf("%d\t%d\n", a12, a22);

    return 0;
}
