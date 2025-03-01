
// WAP to print all prime numbers between two intervals without using functions. 
#include <stdio.h>
// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1)                           // Numbers less than or equal to 1are not prime
  
    return 0;
  for (int i = 2; i <= num / 2; i++) {    // Loop from 2 to half of the number
  
    if (num % i == 0)    {                // If number is divisible by anynumber other than 1 and itself
    
      return 0;                         // Not a prime number
  }
  return 1; // Prime number
}
int main() {
  int num1, num2, sum=0;
  printf("Enter two numbers: ");                                // Prompt user to enter two numbers 
  scanf("%d %d", &num1, &num2); // Read the two numbers
  printf("Prime numbers between %d and %d are: ", num1, num2); // Print the range while 
 while(num1 < num2) {                              // Loop  from num1 to num2
    if (isPrime(num1))                          // Check if the current number is prime
      printf("%d ", num1);                           // Print the primenumber
    ++num1;                       // Increment the number
  }
}
  // num1 += num1;
  // printf("\nthe sum of %d ", num1);
  return 0;
}