#include <stdio.h>
int findLargest(int *arr, int size) {
    int *ptr = arr;                                                 // Pointer to the first element
    int larg = *ptr;                                                // Assume the first element is the largest
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) > larg) {                                    // Compare using pointer arithmetic
            larg = *(ptr + i);
        }
    }
    return larg;
}
int main() {
    int n;
                                                    // Input the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
                                                    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }                                               // Find and print the largest element
    int largest = findLargest(arr, n);
    printf("The largest element is: %d\n", largest);
    return 0;
}
