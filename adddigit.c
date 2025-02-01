//wap to add digit of a number using function
#include <stdio.h>
int add(int);

int main(){
    int num,sum;
    printf("Enter a number: ");
    scanf("%d", &num);
    sum= add(num);
    printf("Sum of digits of %d = %d", num, sum);
    return 0;
}

int add(int num){
    int sum=0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
/*output
Enter a number: 12345
Sum of digits of 12345 = 15 */