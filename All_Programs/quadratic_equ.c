#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c,det,root1,root2,img,real;
    printf("Enter the value of cofficients a,b,c\n");
    scanf("%f%f%f",&a,&b,&c);
    det =b*b-4*a*c;
    if(det>0){
        root1 = (-b+sqrt(det))/(2*a);
        root2 = (-b-sqrt(det))/(2*a);
        printf("Root1 = %.2f and Root2 = %.2f",root1,root2);
    } else if(det == 0){
        root1 = root2 = -b/(2*a);
        printf("Root1 = Root2 = %.2f",root1);
    } else {
        real = -b/(2*a);
        img = sqrt(-det)/(2*a);
        printf("Root1 = %.2f + %.2fi and Root2 = %.2f - %.2fi",real,img,real,img);
    }
    return 0;
}