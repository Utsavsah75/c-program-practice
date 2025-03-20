#include<stdio.h>
int main(){
    int r,c,i,j,a[10][10],transpose[10][10];
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d %d",&r,&c);

    // Storing elements of the matrix
    printf("Enter the elements of the matrix: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter element a%d%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    // Displaying the matrix
    printf("The matrix is: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",a[i][j]);
            if(j==c-1){
                printf("\n");
            }
        }
    }
    // Finding the transpose of the matrix
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            transpose[j][i]=a[i][j];
        }
    }
    // Displaying the transpose of the matrix
    printf("The transpose of the matrix is: \n");
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            printf("%d\t",transpose[i][j]);
            if(j==r-1){
                printf("\n");
            }
        }
    }
}