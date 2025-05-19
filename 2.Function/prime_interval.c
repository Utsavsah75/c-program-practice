// prime interval between two number using functions.
#include <stdio.h>
int isPrime(int num) {
    if (num <= 1) // 0 and 1 are not prime numbers
    return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i<= num/2; i++) {
        if (num % i == 0)
        return 0; // Not a prime number
    }
    return 1; // Prime number
}

// Function to print prime numbers in a given range
int printPrimesInRange(int start, int end) {
    int sum = 0;    // Initialize sum to 0-------------------
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) { // Check if i is prime
            printf("%d ", i);
            sum += i; // Add prime number to sum-------------------
        }
    }
    printf("\n");
    return sum;  // Return sum to main
}
int main() {
    int start, end,sum;
     printf("Enter a two number interval: ");
    scanf("%d%d", &start, &end);    
    printf("Prime numbers between %d and %d are: ", start, end);
    sum = printPrimesInRange(start, end);     // Calling the function //sum added in function-----------
     printf("The sum of prime numbers is: %d\n", sum);//----------------

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
