#include <stdio.h>
#include <math.h>

// Function to count the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int num1 = num, sum = 0, n, digit;
    n = countDigits(num);
    while (num1 > 0) {
        digit = num1 % 10;
        sum += pow(digit, n);
        num1 /= 10;
    }
    return (sum == num);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}