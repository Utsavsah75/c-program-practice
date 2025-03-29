// using function find sum of odd number.
#include<stdio.h>
int addodd(int n){
   int i,sum=0;
   for(i=1;i<=n;i++){
       if(i%2>0){
           printf("%d\t",i);
           sum+=i;
       }
   }
   return sum;
}
int main()
{
   int n, sumodd;
   printf("enter the number:");
   scanf("%d",&n);
   printf("the odd number of %d are: ",n);
    sumodd=addodd(n);
   printf("\nthe sum of odd number of %d is:%d",n,sumodd);
   return 0;
}







// // without using function find sum of odd number.
// #include <stdio.h>
// int main() {
//   int n, sum = 0, i;
//   printf("enter the number:");
//   scanf("%d", &n);
//   printf("the odd number of %d are:", n);


//   for (i = 1; i <= n; i++) {
    
    
//     if (i % 2 != 0) {
//       printf("%d ", i);
//       sum += i;
//     } 

//     //      // OR

//     //   printf("%d ",2*i-1);
//     //   sum+=2*i-1;


//   }
//   printf("\nthe total odd number are:%d", sum);
// }
