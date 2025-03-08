#include <stdio.h>
int main() {
    int n, i, largest, sec_largest;
    // Input the array size
    printf("Enter the size of an elements: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr; // Pointer to the first element
    // Input array elements
    printf("Enter %d elements:\t", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i); // Using pointer arithmetic for input
    }

    // Initialize largest and second largest
        largest = *ptr;
        sec_largest = -1; // Assuming all elements are positive

    // Find the largest element
    for (i = 1; i < n; i++) {
        if (*(ptr + i) > largest) {
            sec_largest = largest; // Update second largest
            largest = *(ptr + i);     // Update largest
        } else if (*(ptr + i) > sec_largest && *(ptr + i) < largest) {
            sec_largest = *(ptr + i); // Update second largest
        }
    }

    // Check if there was no second largest element
    if (sec_largest == -1) {
        printf("No second largest element found.\n");
    } else {
        printf("The second largest element is: %d\n", sec_largest);
    }

    return 0;
}
