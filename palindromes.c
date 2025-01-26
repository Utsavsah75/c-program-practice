#include <stdio.h>

int main(){
    int num, temp, reverse = 0 ;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num; // Preserve the temp number

    while(num != 0){
        reverse *= 10;
        reverse += num % 10;
        num /= 10;
    }
    if(temp == reverse){
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
}