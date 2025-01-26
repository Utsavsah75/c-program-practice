#include<stdio.h>
#include<conio.h>
#define pi 3.142857

int main(){
    float l ,b, area, peri;

    printf(" Enter the length and breath of the Rectangle: ");
    scanf("%f%f",&l,&b);

    area = l*b;
    peri = 2*(l+b);

    printf("The area of Rectangle is: %.2f", area);
    printf("\nThe perimeter of Rectangle is: %.2f", peri);
    return 0;
}