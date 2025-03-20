
//  find the maximum element in an array
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1; 
    }
    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("Maximum element: %d\n", max);

    return 0;
}
/* OUTPUT
Enter the number of elements: 5
Enter 5 elements: 1 7 8 2 6
Maximum element: 8

*/

