#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *ptr;
    char filename[20];
    ptr=fopen("users.txt","w");
    if(ptr==NULL)
    {
        printf("Error! File not found");
        exit(1);
    }
    fclose(ptr);
    return 0;

    fscanf(ptr,"Hello World");
    fclose(ptr);


}