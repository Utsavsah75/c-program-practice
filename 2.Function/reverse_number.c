// find the reverse of a number using a function.
#include <stdio.h>
int reverse(int);
int reverse(int num) {
  int rev = 0;
  while (num > 0) {
    // rem = num % 10;
    rev = rev * 10 + num %10;
    num /= 10;
  }
  return rev;
}
int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("The reverse of the number is: %d\n", reverse(n));
  return 0;
}
// /*output
// Enter a number: 12345








// // write a program to find the reverse of a number.
// #include <stdio.h>
// int main() {
//   int num, rev = 0, rem;
//   printf("Enter a number: ");
//   scanf("%d", &num);
//   while (num > 0) {
//     rem = num % 10;
//     rev = rev * 10 + rem;
//     num /= 10;
//   }
//   printf("The reverse of the number is: %d\n", rev);
//   return 0;
// }
// The reverse of the number is: 54321*/
=======
// write a program to find the reverse of a number.
#include <conio.h>
#include <stdio.h>

int main() {
  int num, rev = 0, rem;
  printf("Enter a number: ");
  scanf("%d", &num);
  while (num != 0) {
    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
  }
  printf("The reverse of the number is: %d\n", rev);
  return 0;
}
>>>>>>> f042e51 (space)
