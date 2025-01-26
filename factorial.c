<<<<<<< HEAD
//  using ******function find factorial of a number
#include <stdio.h>
int factorial(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
int main() {
  int n;
  printf("Enter a number to find factorial: ");
  scanf("%d", &n);
  if (n < 0) {
    printf("Factorial of negative number is not possible");
  } else {
    printf("Factorial of %d is %d", n, factorial(n));
  }
  return 0;
}




















// // to calculate factorial
// #include <stdio.h>
// int main() {
//   int i, num, fact = 1;
//   printf("Enter a number: ");
//   scanf("%d", &num);
//   if (num <= 0) {
//     printf("Factorial of negative and zero number doesn't exist.");
//   } else {
//     for (i = 1; i <= num; i++) {
//       fact *= i;
//     }
//     printf("Factorial of %d is %d", num, fact);
//   }
// }

// // using recursion
//  #include <stdio.h>
//  int factorial(int n) {
//    if (n >= 1)
//      return n * factorial(n - 1);
//    else
//      return 1;
//  }
//  int main() {
//    int num;
//    printf("Enter a number: ");
//    scanf("%d", &num);
//    if (num < 0)
//      printf("Factorial of negative number doesn't exist");
//    else
//      printf("Factorial of %d is %d", num, factorial(num));
//    return 0;
//  }
=======
#include<stdio.h>
#include<conio.h>

int main(){
    int i, num, fact =1;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0){
        printf("Factorial of negative number doesn't exist.");
    }else{
        for(i=1; i<=num; i++){
            fact *= i;
        }
        printf("Factorial of %d is %d", num, fact);
    }
}
>>>>>>> f042e51 (space)
