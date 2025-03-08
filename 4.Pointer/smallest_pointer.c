#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the number of elements: ");  // Input the size of the array
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size.\n");
        return 0;
    }
    int a[n];
    int *ptr = a; // Pointer to the first element
    printf("Enter %d elements:\n", n); // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Using pointer arithmetic for input
    }
    // Finding the smallest element
    int smallest = *ptr; // Assume the first element is the smallest

    for (i = 1; i < n; i++) {
        if (*(ptr + i) < smallest) { // Compare using pointer arithmetic
            smallest = *(ptr + i);
        }
    }
    printf("The smallest element is: %d\n", smallest);   // Output the smallest element
    return 0;
}
