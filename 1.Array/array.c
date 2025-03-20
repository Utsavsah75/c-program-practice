#include <stdio.h>

void sumAndAverage(int arr[], int size);
void copyArray(int source[], int destination[], int size);
void printReverse(int arr[], int size);
void countEvenOdd(int arr[], int size);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
void printArray(int arr[], int size);


int main() {
    int size, i;

    // Taking array size input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size], copiedArray[size];

    // Taking array elements input
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform various operations
    sumAndAverage(arr, size);
    copyArray(arr, copiedArray, size);

    printf("Copied array: ");
    printArray(copiedArray, size);

    printf("Array in reverse order: ");
    printReverse(arr, size);

    countEvenOdd(arr, size);

    sortAscending(arr, size);
    printf("Array in ascending order: ");
    printArray(arr, size);

    sortDescending(arr, size);
    printf("Array in descending order: ");
    printArray(arr, size);

    return 0;
}

// Function to calculate sum and average
void sumAndAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    float average = (float)sum / size;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
}

// Function to copy one array into another
void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

// Function to print array in reverse order
void printReverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to count and print even and odd numbers
void countEvenOdd(int arr[], int size) {
    int evenCount = 0, oddCount = 0;
    printf("Even numbers: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            evenCount++;
        }
    }
    printf("\nOdd numbers: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
            oddCount++;
        }
    }
    printf("\nTotal even numbers: %d\n", evenCount);
    printf("Total odd numbers: %d\n", oddCount);
}

// Function to sort array in ascending order
void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to sort array in descending order
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
