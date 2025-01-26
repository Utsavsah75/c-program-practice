#include<stdio.h>
#include<string.h>

int main(){
    char text[100];
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    printf("The text you have entered is: %s", text);
}