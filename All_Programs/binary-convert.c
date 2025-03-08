//wap in c to convert decimal to binary.
#include<stdio.h>
int main(){
    int n,a[10],i,j;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(i=0;n>0;i++){
        a[i]=n%2;
        n=n/2;
    }
    printf("After converting into Binary=\t ");
    for(j=i-1;j>=0;j--){
        printf("%d",a[j]);
    }
    return 0;
}