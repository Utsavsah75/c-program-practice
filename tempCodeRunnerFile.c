#include<stdio.h>

int greatestnumber(int a[], int size){
int max =a[0],i;
for (i=0;i<size;i++){
    if(a[i]>max){
        max=a[i];
    }
}
return max;
}

int main(){
    int num, i, Great;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);
    int a[num];
    printf("Enter %d elements of the array:",num);
    for(i=0;i<num;i++){
        scanf("%d", &a[i]);
    }
    int (*ptr)(int[], int)=greatestnumber;
    Great = ptr(a, num);
    printf("The greatest number in the array is: %d", Great);
    return 0;
}