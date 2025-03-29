#include<stdio.h>
// void swapnumber(int, int);
void  swapnumber(int *a, int *b){
    int temp;
   temp = *a;
    *a = *b;
    *b = temp;
    printf("\nAfter n1=%d and n2=%d",*a,*b);
}
int main(){
    int n1, n2,swap;
    printf("Enter two number:");
    scanf("%d%d",&n1,&n2);
    printf("Before n1=%d and n2=%d",n1,n2);
    swapnumber(&n1,&n2);
}
