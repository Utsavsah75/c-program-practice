// #include <stdio.h>
// #include <conio.h>

// int main() {
//   char ch;
//   printf("Enter a Letter:");
//   scanf("%c", &ch);

//   if (islower(ch)) {
//     printf("The Letter is lowercase. Converted to uppercase: %c \n",
//     toupper(ch));
//   } else if (isupper(ch)) {
//     printf("The Letter is uppercase. Converted to lowercase: %c \n",
//     tolower(ch));
//   } else {
//     printf("The Letter is not an alphabet \n");
//   }
// return 0;
// }

// code to conver a sentence ot word upper to lower vis versa

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[100];
  printf("Enter a sentence: ");
  gets(str);
  for (int i = 0; i < strlen(str); i++) {
    if (islower(str[i])) {
      str[i] = toupper(str[i]);
    } else if (isupper(str[i])) {
      str[i] = tolower(str[i]);
    }
  }
  printf("The converted sentence is: %s\n", str);
  return 0;
}

// #include<stdio.h>
// #include<conio.h>
// #include<string.h>
// int main(){
//   char str[100];
//   printf("Enter a sentence: ");
//   gets(str);
//   for (int i = 0; i < strlen(str); i++) {
//   str[i] = toupper(str[i]);
//   }
//   printf("The converted sentence is: %s\n", str);
//   return 0;
// }
<<<<<<< HEAD


// #include<stdio.h>

// int main(){
//     int n;
//     scanf("%d", &n);
//     int a[n];
//     for(int i = 0; i < n; i++){
//         scanf("%d", &a[i]);
//     }
//     int max = a[0];
//     for(int i = 1; i < n; i++){
//         if(a[i] > max){
//             max = a[i];
//         }
//     }
//     printf("%d", max);
//     return 0;
// }
=======
>>>>>>> f042e51 (space)
