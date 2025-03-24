// c0nvert a letter to upper to lower and vice versa
#include <stdio.h>
#include <ctype.h>

int main() {
  char ch ;
  printf("Enter a single Letter:");
  scanf("%c", &ch);

  if (islower(ch)) {
    printf("The Letter is lowercase and onverted to uppercase: %c \n",
    toupper(ch));
  } else if (isupper(ch)) {
    printf("The Letter is uppercase and converted to lowercase: %c \n",
    tolower(ch));
  } else {
    printf("The Letter is not an alphabet \n");
  }
return 0;
}
/*    OUTPUT
Enter a Letter:U
The Letter is uppercase. Converted to lowercase: u 

Enter a Letter:u
The Letter is lowercase. Converted to uppercase: U 

*/


// // convert a sentence to upper to lower and vice versa
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// int main() {
//   char str[100];
//   printf("Enter a sentence: ");
//   gets(str);
//   for (int i = 0; i < strlen(str); i++) {
//     if (islower(str[i])) {
//       str[i] = toupper(str[i]);
//     } else if (isupper(str[i])) {
//       str[i] = tolower(str[i]);
//     }
//   }
//   printf("The converted sentence is: %s\n", str);
//   return 0;
// }
/*    output
Enter a sentence: a man in the middle
The converted sentence is: A MAN IN THE MIDDLE*/


// // convert a sentence to upper to lower and vice versa
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {
//   char str[100];
//   printf("Enter a sentence: ");
//   fgets(str, sizeof(str), stdin);
//   for (int i = 0; i < strlen(str); i++) {
//     str[i] = toupper(str[i]);
//   }
//   printf("The converted sentence is: %s\n", str);
//   return 0;
// }
/*   OUTPUT
Enter a sentence:utsavsah
The converted sentence is: UTSAVSAH
 */
