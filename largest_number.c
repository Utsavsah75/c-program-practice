
//using ternary operator
#include<stdio.h>
int main(){
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int largest = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    printf("The largest number is %d\n", largest);
    return 0;
}


