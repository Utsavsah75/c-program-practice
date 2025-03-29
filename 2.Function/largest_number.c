
// //using ternary operator *****************
// #include<stdio.h>
// int main(){
//     int a, b, c;
//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &a, &b, &c);
//     int largest = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
//     printf("The largest number is %d\n", largest);
//     return 0;
// }


// find largest among three numbers using function.
#include<stdio.h>
int largest(int,int,int);
int largest(int a, int b, int c){
if(a>b && a>c)
    return a;
else if(b>a && b>c )
    return b;
else
    return c;
}
int main(){
    int a,b,c,l;
    printf("Enter the three numbers=");
    scanf("%d%d%d",&a,&b,&c);
    l=largest(a,b,c);
    printf("The largest number among %d,%d,%d is=%d",a,b,c,l);
    return 0;
}
