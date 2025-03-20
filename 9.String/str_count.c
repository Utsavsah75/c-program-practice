#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
//   char *p = str; 
  int digit, length, space, special, tab, alphabet, uppercase, lowercase, i;
  digit = length = space = special = tab = alphabet = uppercase = lowercase= i = 0;
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);


  //kee *p where str[i] is used while using pointer.
  while (str[i] != '\0') {
    if (str[i] >= '0' && str[i] <= '9') {
        digit++;
    } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            lowercase++;
        } else {
            uppercase++;
        }
        alphabet++;
    } else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
        space++;
    } else {
        special++;
    }
    i++;
}
printf("Digits: %d\n", digit);
printf("Uppercases: %d\n", uppercase);
printf("Lowercases: %d\n", lowercase);
printf("Alphabets: %d\n", alphabet);
printf("Spaces: %d\n", space);
printf("Special characters: %d\n", special);

  return 0;
}