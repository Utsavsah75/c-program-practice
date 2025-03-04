#include <stdio.h>
int main() {
    int n,i,larg;
    // Input the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    int *ptr = a; // Pointer to the first element
    // Input array elements
    printf("Enter %d elements:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i); // Using pointer arithmetic for input
    }
    // Finding the largest element
     larg = *ptr; // Assume the first element is the largest

    for ( i = 1; i < n; i++) {
        if (*(ptr + i) > larg) { // Compare using pointer arithmetic
            larg = *(ptr + i);
        }
    }
    // Output the largest element
    printf("The largest element is: %d\n", larg);

    return 0;
}
