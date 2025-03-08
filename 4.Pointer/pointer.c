#include<stdio.h>
int main(){
    int a=10,b=10,c=10,d=10;
    int *p1=&a,*p2=&b;

    printf("%d %d\n",a,b);
    c--; --d;
    printf("%d %d",c,d);
    c=*p1+*p2+c;
    printf("\nThe sum is %d",c);
    b=*p1+*p2;
    printf("\nThe sum is %d",b);
    c=p1-p2;
    printf("\nThe sum is %d",c);
    return 0;
}