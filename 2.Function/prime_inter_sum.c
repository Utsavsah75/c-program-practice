#include <stdio.h>
int main() {
    int num1, num2, i, isPrime ,sum = 0; // Initialize sum to 0--------------

    printf("Enter a two number interval: ");
    scanf("%d%d", &num1, &num2);
    printf("Prime numbers between %d and %d are:\n", num1, num2);

    while (num1 < num2) {
        isPrime = 1; // Initialize isPrime to 1 for each number
        
        for (i = 2; i <=num1 / 2; i++) {
            if (num1 % i == 0) {
                isPrime = 0;
                break;
                }
            }
            if (isPrime && num1 > 1) {
       
            printf("%d ", num1);
            sum += num1; // Add prime number to sum------------
        }
        num1++;
    }
    printf("\nThe sum of prime numbers is: %d\n", sum);//--------
    return 0;
}
