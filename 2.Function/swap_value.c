#include<stdio.h>
#include<conio.h>
int swap(int,int) ; // function declaration
int main()
{
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