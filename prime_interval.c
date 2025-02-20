// // WAP to print all prime numbers between two intervals using functions.
// #include <stdio.h>
// int primenumber(int, int);
// int main() {
//   int num1, num2;
//   printf("Enter two numbers: ");
//   scanf("%d %d", &num1, &num2);
//   printf("Prime numbers between %d and %d are: ", num1, num2);
//   primenumber(num1, num2);
//   return 0;
// }
// int primenumber(int prime1, int prime2) {
//   while (prime1 < prime2) {
//     int sum = 0;
//     for (int i = 2; i <= prime1 / 2; ++i) {
//       if (prime1 % i == 0) {
//         sum = 1;
//         break;
//       }
//     }
//     if (sum == 0)
//       printf("%d ", prime1);
//     ++prime1;
//   }
//   return 0;
// }
// /*output
// Enter two numbers: 7    19
// Prime numbers between 7 and 19 are: 7 11 13 17
// */

// WAP to print all prime numbers between two intervals without using functions.
#include <stdio.h>
// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1) // Numbers less than or equal to 1 are not prime
    return 0;
  for (int i = 2; i <= num / 2; i++) { // Loop from 2 to half of the number
    if (num % i ==
        0)      // If number is divisible by any number other than 1 and itself
      return 0; // Not a prime number
  }
  return 1; // Prime number
}
int main() {
  int num1, num2;
  printf("Enter two numbers: "); // Prompt user to enter two numbers
  scanf("%d %d", &num1, &num2);  // Read the two numbers
  printf("Prime numbers between %d and %d are: ", num1,
         num2);            // Print the range
  while (num1 < num2) {    // Loop from num1 to num2
    if (isPrime(num1))     // Check if the current number is prime
      printf("%d ", num1); // Print the prime number
    ++num1;                // Increment the number
  }
  return 0;
}