#include<stdio.h>
int main()
{
    int a[3][3],i,j;
    int (*p)[3];
    p=a;
    printf("enter elements:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("element[%d][%d]=",i,j);
            scanf("%d",(*(p+i)+j));
        }
    }
    printf("\nyour matrix");
    for(i=0;i<3;i++)
    {
        // printf("\n");
        for(j=0;j<3;j++)
        {
            printf("  %d",((p+i)+j));
        }
    }
    printf("\ntranspose matrix");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf("  %d",((p+j)+i));
        }
    }
    return 0;
}