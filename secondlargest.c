#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int largest, second_largest;

    // Taking input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize largest and second largest
    if (n < 2) {
        printf("At least two elements are required!\n");
        free(arr);
        return 1;
    }

    largest = second_largest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    if (largest == second_largest) {
        printf("No second largest number found!\n");
    } else {
        printf("The second largest number is: %d\n", second_largest);
    }

    // Free allocated memory
    free(arr);
    
    return 0;
}
