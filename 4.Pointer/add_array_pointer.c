#include<stdio.h>
int *addarraypointer(int *a, int *b, int n, int *c, int i, int size){
    for(i=0; i<size; i++){
        *(c+i) = *(a+i) + *(b+i);
    }
    return c;
}
int main(){
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size], b[size], c[size];

    printf("Enter First Array Elements:\n");
    for(i=0; i<size; i++){
        printf("a%d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter Second Array Elements:\n");
    for(i=0; i<size; i++){
        printf("b%d: ", i+1);
        scanf("%d", &b[i]);
    }
    int *ptr = addarraypointer(a, b, size, c, i, size);

    printf("The sum of the two arrays in matrix format is:\n");
    for(i=0; i<size; i++){
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
    }
    return 0;
}
   