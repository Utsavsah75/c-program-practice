#include <stdio.h>

int main() {
    char str[100];
    int digit, length, space, special, tab, alphabet, uppercase, lowercase, i;
    digit = length = space = special = tab = alphabet = uppercase = lowercase = i = 0;


    printf("Enter a string: ");
    fgets(str, sizeof str, stdin);

    // Loop through each character
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            digit++;
        } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            alphabet++;
            if (str[i] >= 'a' && str[i] <= 'z') {
                lowercase++;
            } else {
                uppercase++;
            }
        } else if (str[i] == ' ') {
            space++;
        } else if (str[i] == '\t') {
            tab++;
        } else if (str[i] == '\n') {
            // newline++;
            // Ignore newline added by fgets in space/special counting
        } else {
            special++;
        }
        i++;
    }
    length = i; // Total number of characters including newline (if any)

    printf("Digits: %d\n", digit);
    printf("Tabs: %d\n", tab);
    // printf("newline: %d\n", newline);
    printf("Length: %d\n", length);
    printf("Alphabets: %d\n", alphabet);
    printf("Uppercase Letters: %d\n", uppercase);
    printf("Lowercase Letters: %d\n", lowercase);
    printf("Spaces: %d\n", space);
    printf("Special characters: %d\n", special);

    return 0;
}
