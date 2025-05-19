// WAP to check whether a number is palindrome or not using function.
#include <stdio.h>
int palindrome(int);
int palindrome(int num) {
  int temp=num, rev = 0;
  while (num > 0) {
    rev = rev * 10 + num % 10;
    num /= 10;
  }   
  return temp== rev;
}
int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  if (palindrome(n))
    printf("%d is a palindrome.\n",n ); 
 else
    printf("%d is not a palindrome.\n",n);
  return 0;
}

/*output
Enter a number: 15644651
The number is a palindrome.*/




/*
// // WAP to check whether a number is palindrome or not using function.*/
// #include <stdio.h>
// int palindrome(int num);
// int main() {
//   int num;
//   printf("Enter a number: ");
//   scanf("%d", &num);
//   if (palindrome(num))
//     printf("The number is a palindrome.\n");
//   else
//     printf("The number is not a palindrome.\n");
//   return 0;
// }
// int palindrome(int num) {
//   int temp = num, rev = 0;
//   while (num > 0) {
//     rev = rev * 10 + num % 10;
//     num /= 10;
//   }
//   return temp == rev;
// }








/*output
Enter a number: 15644651
The number is a palindrome.
*/