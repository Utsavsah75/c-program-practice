#include<stdio.h>
#include<conio.h>
int swap(int,int) ; // function declaration
int main() {
 int num1, num2 ;
 num1 = 10 ;
 num2 = 20 ;
 printf("Before swapping: num1 = %d\t num2 = %d\n", num1, num2) ;
 swap(num1, num2) ; // calling function
 printf("After swapping: num1 = %d\t num2 = %d", num1, num2);
}
int swap(int a, int b) // called function
{
 int temp ;
 temp = a ;
 a = b ;
 b = temp ;
}

// // by user input------------------
// #include <stdio.h>
// void swapnumber(int, int);
// void swapnumber(int a, int b) {
//   int temp;
//   temp = a;
//   a = b;
//   b = temp;
//   printf("\nAfter n1=%d and n2=%d", a, b);
// }
// int main() {
//   int n1, n2, swap;
//   printf("Enter two number:");
//   scanf("%d%d", &n1, &n2);
//   printf("Before n1=%d and n2=%d", n1, n2);
//   swapnumber(n1, n2);
// }
