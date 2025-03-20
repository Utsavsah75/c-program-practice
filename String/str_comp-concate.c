#include <stdio.h>

int main() {
    char str1[100], str2[100], concat[200];
    int i, j, isEqual = 1;

    // Input two strings
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // **Compare Strings Without strcmp()**
    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            isEqual = 0;
            break;
        }
    }

    if (isEqual)
        printf("The two strings are equal.\n");
    else
        printf("The two strings are not equal.\n");

    // **Concatenate Strings Without strcat()**
    for (i = 0; str1[i] != '\0'; i++) {
        concat[i] = str1[i];
    }

    for (j = 0; str2[j] != '\0'; j++) {
        concat[i + j] = str2[j];
    }

    concat[i + j] = '\0';  // Null-terminate the concatenated string

    printf("Concatenated String: %s\n", concat);

    return 0;
}
/*
Enter first string: utsav 
Enter second string: sah
The two strings are not equal.
Concatenated String: utsavsah
        OR
Enter first string: utsav
Enter second string: utsav
The two strings are equal.
Concatenated String: utsavutsav

*/