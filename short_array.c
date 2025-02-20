// Function to sort an array in ascending order
#include <stdio.h>
void sortArray(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i]; // Swap elements
                a[i] = a[j];
                a[j] = temp;
            }  }
    }  }
void displayArray(int a[], int n) {     // Function to display the array
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d \t", a[i]);
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");   // Input: number of elements
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:", n);   // Input: array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sortArray(a, n);    // Sorting the array
    displayArray(a, n);   // Displaying the sorted array
    return 0;
}
//output
// Enter the number of elements: 5
// Enter 5 elements:
// 5
// 4
// 3
// 2
// 1
