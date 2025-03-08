#include<stdio.h>
int *addarraypointer(int *a, int *b, int n,int *c, int i,int size){
    for(i=0;i<size;i++){
    *(c+i) = *(a+i) + *(b+i);
}
    return c;
}
int main(){
    int size,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int a[size],b[size],c[size];

    printf("Enter the elements of the first array: ");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the second elements of the array: ");
    for(i=0;i<size;i++){
        scanf("%d",&b[i]);
    }
    int *ptr = addarraypointer(a,b,size,c,i,size);
    // addarraypointer(a,b,size,c,i,size);
    printf("The sum of the two arrays is: ");
    for(i=0;i<size;i++){
        printf("%d/t ",c[i]);
    }
    return 0;
}