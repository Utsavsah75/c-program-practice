// using function find sum of odd number.
#include<stdio.h>
int sum(int n){
   int i,sum=0;
   printf("the odd number of %d are: ",n);
   for(i=1;i<=n;i++){
       if(i%2!=0){
           printf("%d\t",i);
           sum+=i;
       }
   }
   return sum;
}
int main(){
   int n;
   printf("enter the number:");
   scanf("%d",&n);
   printf("\nthe sum of odd number of %d is:%d",n,sum(n));
   return 0;
}






// #include<stdio.h>
// int main(){
//     int n,sum=0,i;
//     printf("enter the number:");
//     scanf("%d",&n);
//     printf("the odd number of %d are:",n);
//     for(i=1;i<=n;i++){
//         if(i%2!=0){
//             printf("%d ",i);
//             sum +=i;
//         }
//     }
// printf("\nthe total odd number are:%d",sum);
// }















/*
#include<stdio.h>
int main(){
    int n,sum=0,i;
    printf("enter the number:");
    scanf("%d",&n);
    printf("the odd number of %d are:",n);
    for(i=1;i<=n;i++){
            printf("%d ",2*i-1);
            sum+=2*i-1;
        }
    printf("\nthe sum of odd number of %d is:%d",n,sum);

}*/