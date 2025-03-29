#include <stdio.h>
// Function to check if a number is prime
int isPrime(int);
int isPrime(int num) {
  if (num <= 1)
    return 0;
  for (int i = 2; i <= num / 2; i++) { // Optimized loop up to sqrt(num)
    if (num % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int num, isPrimeNum;
  printf("Enter a number: ");
  scanf("%d", &num);

  isPrimeNum = isPrime(num); // Call the function to check if num is prime
  if (isPrimeNum == 0) {
    printf("%d is not a prime number.\n", num);
  } else {
    printf("%d is a prime number.\n", num);
  }

  return 0;
}

// #include <stdio.h>
// int main() {
//   int i, num, isPrime = 2; // Assume the number is prime initially
//   printf("Enter a number: ");
//   scanf("%d", &num);
//   if (num <= 1) {
//     return 0;
//   }
//   // Check divisors from 2 to num/2
//   for (i = 2; i <= num / 2; i++) {
//     if (num % i == 0) { // If num is divisible by i
//       isPrime = 0;      // Set isPrime to false
//       break;            // No need to check further
//     }
//   }
//   // Output the result
//   if (isPrime) {
//     printf("%d is a prime number.\n", num);
//   } else {
//     printf("%d is a composite number.\n", num);
//   }
//   return 0;
// }

// #include <stdio.h>
// int main() {
//     int i, num, isPrime = 1; // Assume the number is prime initially
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     // Edge case: numbers less than or equal to 1 are not prime
//     if (num <= 1) {
//         printf("%d enter a +ve or greater than 1.\n", num);
//         return 0;
//     }
//     // Check divisors from 2 to num/2
//     for (i = 2; i <= num / 2; i++) {
//         if (num % i == 0) {  // If num is divisible by i
//             isPrime = 0;     // Set isPrime to false
//             break;           // No need to check further
//         }
//     }
//     // Output the result
//     if (isPrime) {
//         printf("%d is a prime number.\n", num);
//     } else {
//         printf("%d is not a prime number.\n", num);
//     }
//     return 0;
// }
