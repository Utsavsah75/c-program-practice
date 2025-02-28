// wap in c to calculate ncr 
#include<stdio.h>
int main(){
    int n,c,r,i;
    long int ncr=2;
    printf("Enter the value of n and r:");
    scanf("%d%d",&n,&r);
    for(i=1;i<=r;i++){
        ncr=ncr*(n-i+1)/i;
    }
    printf("The value of ncr is %ld\n",ncr);
    return 0;
}