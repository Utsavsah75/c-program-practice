#include <stdio.h>

int main() {
    int i;

    printf("Number\tSquare\tCube\n");
    // printf("------------------------\n");

    for (i = 1; i <= 500; i++) {
        printf(" %d\t %d\t %d\n", i, i * i, i * i * i);
    }

    return 0;
}
