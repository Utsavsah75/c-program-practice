// fabonnic series using recursion.
#include <stdio.h>
int fabonnic(int);
int fabonnic(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    } else {
        return fabonnic(n - 1) + fabonnic(n - 2);
    }
}
int main() {
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    for (i = 0; i < n; i++)    {
        printf("%d ", fabonnic(i));
    }
    return 0;
}