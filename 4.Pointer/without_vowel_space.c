#include <stdio.h>

int isVowel(char c) {
    c = (c >= 'a' && c <= 'z') ? c : c + 32; // Convert to lowercase
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main() {
    char str[100];
    char *p = str; // Pointer to the input string
    char *r = str; // Pointer to store the r

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Loop through the string using pointer
    while (*p != '\0') {
        if (*p != ' ' && !isVowel(*p)) { // Skip space and vowels
            *r = *p; // Copy non-vowel, non-space character to r
            r++; // Move to next position in r
        }
        p++; // Move to next character in the input string
    }
    *r = '\0';
    printf("String without vowels and spaces: %s\n", str);
    return 0;
}
