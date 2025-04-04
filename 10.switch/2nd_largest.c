#include <stdio.h>

// Function to find the second largest number in an array
int SecondLargest(int arr[], int size) {
    int largest = arr[0];
    int sec_largest = -1;

    // Loop through the array
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            sec_largest = largest;
            largest = arr[i];
        } else if (arr[i] > sec_largest && arr[i] != largest) {
            sec_largest = arr[i];
        }
    }

    return sec_largest;
}

int main() {
    int n;

    // Ask for array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take array input
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the second largest number
    int sec_largest = SecondLargest(arr, n);
    if (sec_largest == -1) {
        printf("There is no second largest number in the array.\n");
    } else {
        printf("The second largest number is: %d\n", sec_largest);
    }

    return 0;
}
