// using a function.************
#include <stdio.h>

int fibonacci(int num); // Function prototype
int fibonacci(int num) {
  int first = 0, second = 1, next;

  for (int i = 0; i < num; i++) {
    printf("%d ", first);
    next = first + second;
    first = second;
    second = next;
  }
  printf("\n");
}

int main() {
  int num;
  printf("Enter the number of terms: ");
  scanf("%d", &num);
  if(fibonacci(num))
    printf("Fibonacci Series: ");
  return 0;
}




// //  fibonacci series without function.
// #include <stdio.h>
// int main() {
//   int n, f, f1 = 0, f2 = 1;
//   int i = 2;
//   printf("Enter the number of Fibonacci series to generate: ");
//   scanf("%d", &n);
//   printf("Fibonacci series: %d %d", f1, f2);
//   // for (int i = 2; i < n; ++i)
//   while (i < n){
//     f = f1 + f2;
//     printf(" %d", f);
//     f1 = f2;
//     f2 = f;
//     i++;
//   }
//   return 0;
// }




// // fabonnic series using function
// #include <stdio.h>
// int fibonacci(int n) {
//   if (n == 0) {
//     return 0;
//   } else if (n == 1) {
//     return 1;
//   } else {
//     return (fibonacci(n - 1) + fibonacci(n - 2));
//   }
// }
// int main() {
//   int n, i;
//   printf("Enter the number : ");
//   scanf("%d", &n);
//   if (n < 0) {
//     printf("Factorial of -ve number doesn't exist");
//   } else {
//     printf("Fibonacci series: ");
//     for (i = 0; i < n; i++) {
//       printf("%d ", fibonacci(i));
//     }
//   }
// }