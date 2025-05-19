// Write a program to reverse a string using loop**********.

#include <stdio.h>

int main() {
  char str[100];
  int i, len;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin); // Reads the full line including spaces

  while (str[len] != '\0' && str[len] != '\n') {
    len++;
  }
  // len = strlen(str);
  printf("Reverse string is: ");
  for (i = len - 1; i >= 0; i--) {
    printf("%c", str[i]);
  }

  return 0;
}

// // Write a program to reverse a string using pointer**********.
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int stringrev(char *);
// int main(){
//     char str[100];
//     printf("Enter a string: ");
//     scanf("%s",str);
//     stringrev(str);

//     printf("Reverse string is: %s",str);
//     return 0;
// }
// int stringrev(char *s){
//     char *start = s;
//     char *end = s + strlen(s) - 1;
//     char temp;
//     while (end > start)
//     {
//         temp = *start;
//         *start = *end;
//         *end = temp;
//         start++;
//         end--;
//     }
//     return 0;
// }

/*
Enter a string: utsav sah
Reverse string is: has vastu
*/