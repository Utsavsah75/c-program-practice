//wap to add array of pointer elements
#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    printf("Enter the size of array of an elements: ");
    scanf("%d", &n);
    int a[n], *p[n];
    //p = a;
    for(i = 0; i < n; i++)  {
        printf("Enter %d elements:",n-i);
        scanf("%d", &a[i]);
        p[i] = &a[i];
    }
    for(i = 0; i < n; i++) {
        sum = sum + *p[i];
    }
    printf("The Sum of elements of array:%d.", sum);
    return 0;
}