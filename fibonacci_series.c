// #include <stdio.h>

// int main() {
//   int n, i, f, f1 = 0, f2 = 1;
//   printf("Enter the number of Fibonacci series to generate: ");
//   scanf("%d", &n);
//   printf("Fibonacci series: %d %d", f1, f2);
//   for (i = 2; i < n; ++i) {
//     f = f1 + f2;
//     printf(" %d", f);
//     f1 = f2;
//     f2 = f;
//   }
//   return 0;
// }





// fabonnic series using function
#include <stdio.h>
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return (fibonacci(n - 1) + fibonacci(n - 2));
  }
}

int main(){
  int n, i;
  printf("Enter the number of Fibonacci series to generate: ");
  scanf("%d", &n);
  printf("Fibonacci series: ");
  for (i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
}