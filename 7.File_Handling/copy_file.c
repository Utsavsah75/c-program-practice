/* Write a C program to read the contents of a data file named abc.doc 
and copy them in uppercase to another data file named xyz.doc.*/
#include <stdio.h>
#include <ctype.h> // for toupper()

int main() {
    FILE *source, *dest;
    char ch;

    // Open source file in read mode
    source = fopen("abc.doc", "r+");
    if (source == NULL) {
        printf("Error: Cannot open abc.doc\n");
        return 1;
    }

    // Open dest file in write mode
    dest = fopen("xyz.doc", "w");
    if (dest == NULL) {
        printf("Error: Cannot open xyz.doc\n");
        fclose(source);
        return 1;
    }

    // Read character by character and write in uppercase
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), dest);
    }
    fputs("Hello Utsav sah!................\n", source);
    fputs("Hi I am fine and what about you!................\n", source);
    rewind(source);
    
    printf("Content copied to xyz.doc in uppercase successfully.\n");

    fclose(source);
    fclose(dest);

    return 0;
}
