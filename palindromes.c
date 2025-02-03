// #include<stdio.h>
// int main(){
//     int num, temp = num, rev = 0 ;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//  //temp = num; // Preserve the temp number
//     while(num > 0){
//         rev *= 10;
//         rev += num % 10;
//         num /= 10;
//     }
//     if(temp == rev){
//         printf("The number is a palindrome.\n");
//     } else {
//         printf("The number is not a palindrome.\n");
//     }
// }

// WAP to check whether a number is palindrome or not using function.
#include <stdio.h>
int palindrome(int num);
int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  if (palindrome(num))
    printf("The number is a palindrome.\n");
  else
    printf("The number is not a palindrome.\n");
  return 0;
}
int palindrome(int nums) {
  int temp = nums, rev = 0;
  while (nums > 0) {
    rev = rev * 10 + nums % 10;
    nums /= 10;
  }
  return temp == rev;
}
/*output
Enter a number: 15644651
The number is a palindrome.
*/