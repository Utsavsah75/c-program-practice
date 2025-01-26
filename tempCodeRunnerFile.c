<<<<<<< HEAD
//wap in c to convert decimal to binary.
#include<stdio.h>
int main(){
    int n,a[10],i,j;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(i=0;n>0;i++){
        a[i]=n%2;
        n=n/2;
    }
    printf("Binary of the given number= ");
    for(j=i-1;j>=0;j--){
        printf("%d",a[j]);
    }
    return 0;
}
=======

void pizza();
void burger();
void sandwich();
void french_fries();
void ice_cream();
int main()
{
    int choice;
    printf("Enter your choice\n");
    printf("1. Pizza\n");
    printf("2. Burger\n");
    printf("3. Sandwich\n");
    printf("4. French Fries\n");
    printf("5. Ice Cream\n");
    scanf
>>>>>>> f042e51 (space)
