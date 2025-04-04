#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *ptr;
    char  ch;
    ptr=fopen("users.txt","w+");
    if(ptr==NULL)
    {
        printf("Error! File not found");
        exit(1);
    }
    
    fprintf(ptr,"Hello Utsav sah!................\n");
    fprintf(ptr,"Hi i am fine!................\n");
    // //rewind(ptr); 
    // fseek(ptr, 0, SEEK_SET); 
    // while((ch = fgetc(ptr)) != EOF) {
    //             putchar(ch);
    //         }
    fclose(ptr);
    rewind(ptr);
    return 0;
    

 }