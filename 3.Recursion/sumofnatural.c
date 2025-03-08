// sum of n natural number using recursion function.
#include <stdio.h>
int sum(int n) {
  if (n > 0) {
    return n + sum(n - 1);
  } else {
    return n;
  }
}
int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("Sum = %d", sum(n));
  return 0;
}
/*output
Enter a positive integer: 5
Sum = 15
*/

// #include <stdio.h>

// // Function to sort an array in ascending order
// void sortArray(int arr[], int n) {
//     int temp;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 // Swap elements
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// // Function to display the array
// void displayArray(int arr[], int n) {
//     printf("Sorted array in ascending order: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int n;

//     // Input: number of elements
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int arr[n];

//     // Input: array elements
//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Sorting the array
//     sortArray(arr, n);

//     // Displaying the sorted array
//     displayArray(arr, n);

//     return 0;
// }
// //output
// // Enter the number of elements: 5
// // Enter 5 elements:
// // 5
// // 4
// // 3
// // 2
// // 1
