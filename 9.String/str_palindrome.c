#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int i, length, palindrome = 1;
    
    printf("Enter the string:");
    scanf("%s",str);
    
    //using library function
    length = strlen(str);


     //using without library function
    // while (str[length] != '\0') {
    //     length++;
    // }


    for(i=0;i<length/2;i++){
        if(str[i] != str[length-i-1]){
            palindrome = 0;
            break ;
    }
    if(palindrome){
        printf("%s is a palindrome.",str);
    }else{
        printf("%s is not a palindrome.",str);

    }
}
return 0;
}