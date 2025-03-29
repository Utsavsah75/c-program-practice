// prime interval between two number using functions.
#include <stdio.h>
int isPrime(int num) {
    if (num <= 2) // 0 and 1 are not prime numbers
    return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i<= num/2; i++) {
        if (num % i == 0)
        return 0; // Not a prime number
    }
    return 1; // Prime number
}

// Function to print prime numbers in a given range
void printPrimesInRange(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

}
int main() {
    int start, end;
    printf("Enter the start of the interval: ");
    scanf("%d", &start);
    printf("Enter the end of the interval: ");
    scanf("%d", &end);    
    printf("Prime numbers between %d and %d are: ", start, end);
    printPrimesInRange(start, end);     // Calling the function 

    return 0;
}
/*output
Enter two numbers: 7    19
Prime numbers between 7 and 19 are: 7 11 13 17
*/

// // WAP to print all prime numbers between two intervals without using
// #include <stdio.h>
// int main() {
//     int start, end, i, j, isPrime;
//     printf("Enter the start of the interval: ");
//     scanf("%d", &start);
//     printf("Enter the end of the interval: ");
//     scanf("%d", &end);
//     printf("Prime numbers between %d and %d are: ", start, end);
//     for (i = start; i <= end; i++) {
//         if (i < 2) continue; // Skip numbers less than 2
//         isPrime = 1; // Assume i is prime
//         for (j = 2; j * j <= i; j++) {
//             if (i % j == 0) {
//                 isPrime = 0; // Not a prime number
//                 break;
//             }
//         }
//         if (isPrime) {
//             printf("%d ", i);
//         }
//     }
//     printf("\n");
//     return 0;
// }
