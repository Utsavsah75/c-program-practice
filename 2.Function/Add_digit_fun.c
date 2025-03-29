// wap to add digit of a number using function
#include <stdio.h>
int addDigits(int num);
int addDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10; // Extract last digit and add to sum
    num /= 10;       // Remove last digit
  }
  return sum;
}
int main() {
  int num, sum;
  printf("Enter a number: ");
  scanf("%d", &num);
  
  sum = addDigits(num);// Function to call........
  printf("Sum of digits of %d = %d\n", num, sum);
  return 0;
}

/*output
Enter a number: 12345
Sum of digits of 12345 = 15 */


// //wap to add digit of a number using function method 2------------
// #include <stdio.h>
// int add(int);
// int add(int num) {
//   int sum = 0;
//   while (num > 0) {
//     sum += num % 10;
//     num /= 10;
//   }
//   return sum;
// }
// int main() {
//   int num, sum;
//   printf("Enter a number: ");
//   scanf("%d", &num);
//   sum = add(num);
//   printf("Sum of digits of %d is = %d", num, sum);
//   return 0;
// }


// //wap to add digit of a number without using function
// #include<stdio.h>
// int main(){
//     int num, sum=0;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     while(num > 0){
//         sum += num % 10;
//         num /= 10;
//     }
//     printf("Sum of digits of %d is = %d", num, sum);
//     return 0;
// }
/*output
Enter a number: 12345
Sum of digits of 12345 is = 15 */