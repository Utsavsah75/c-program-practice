// // wap to add two arrays of 3 elements.
// #include <stdio.h>
// int main() {
//   int a[3] = {2, 3, 4}, sum = 0;
//   {
//     for (int i = 0; i <=2; i++) {
//        sum += a[i];
//     }
//     printf("the sum is %d", sum);
//   }
// }


// // wap to find the sum of an array of 3 elements.
#include<stdio.h>
int main(){
  int a[3],sum=0,i;
  printf("enter the size of an array");
  for(i=0;i<3;i++){
    scanf("%d",&a[i]);
    sum +=a[i];
  }
  printf("sum is %d",sum);
    return 0;
}


// // wap to find the sum of an array of 5 elements.
// #include<stdio.h>
// int main(){
//     int a[5],i;
//     printf("Enter the size of an array: ");
//     for(i=0;i<5;i++){
//         scanf("%d",&a[i]);
//     }
//     for(i=0;i<5;i++){
//         printf("the value of a[%d] is %d\n",i,a[i]);
    
//      for(i=4;i>=0;i--)
//         printf("the value of a[%d] is %d\n",i,a[i]);
//     }
//     return 0;

// }