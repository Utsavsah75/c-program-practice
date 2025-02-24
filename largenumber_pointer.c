//WAP to find the large number of element in an array using function pointer by user defined function.
#include <stdio.h>

// Function to find the greatest number in an array
int greatestnumber(int arr[], int size) {
    int max = arr[0],i;
    for ( i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int num, i, Great;
    
    // Taking array size input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);
    
    int a[num];
    
    // Taking array elements input
    printf("Enter %d elements:\t", num);
    for ( i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    
    // Declaring function pointer
    int (*Ptr)(int[], int) = greatestnumber;
    
    // Calling function using function pointer
     Great = Ptr(a, num);
    
    // Displaying the result
    printf("The greatest element in the array is: %d\n", Great);
    
    return 0;
}
