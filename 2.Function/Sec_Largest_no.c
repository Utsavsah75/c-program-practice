#include <stdio.h>

int secondLargest(int arr[], int n) {   // Function to find the second largest number
    int largest = arr[0];
    int secondLargest = -1;  // Assuming negative numbers aren't present
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    return secondLargest;
}
int main() {
    int n;
 
    printf("Enter number of elements in the array: ");   // Input size of array
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = secondLargest(arr, n);   // Call the function to find the second largest number
    
    if (result == -1) {
        printf("No second largest element found.\n");
    } else {
        printf("The second largest number is: %d\n", result);
    }

    return 0;
}
