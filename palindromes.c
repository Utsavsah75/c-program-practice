// WAP to check whether a number is palindrome or not using function.
#include <stdio.h>
int palindrome(int);
int palindrome(int num) {
  int rev = 0;
  while (num > 0) {
    rev = rev * 10 + num % 10;
    num /= 10;
  }
  return  rev;
}
int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  if (palindrome(n))
    printf("The number is a palindrome.\n" ); 
  else
    printf("The number is not a palindrome.\n");
  return 0;
}
/*output
Enter a number: 15644651
The number is a palindrome.*/













/*
#include<stdio.h>
int main(){
    int num, temp, rev = 0 ;
    printf("Enter a number: ");
    scanf("%d", &num);
 temp = num; // Preserve the temp number
    while(num > 0){
        rev *= 10;
        rev += num % 10;
        num /= 10;
    }
    if(temp == rev){
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
}
// */