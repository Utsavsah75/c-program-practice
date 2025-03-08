// fibonacci series using recursion.

#include <stdio.h>
int fibonacci(int);
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call

  }
}
int main() {
  int num, i;
  printf("Enter a number: ");
  scanf("%d", &num);
  if(num<0){
    printf("Fibonacci of negative number doesn't exist");
  }else{
    printf("Fibonacci series: ");
    for (i = 0; i < num; i++) {
      printf("%d ", fibonacci(i));// Recursive call to fibonacci function 
    }
  }
  return 0;
}