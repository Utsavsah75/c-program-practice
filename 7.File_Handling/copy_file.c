#include <ctype.h> // For toupper function
#include <stdio.h>
#include <stdlib.h> // For file handling functions
int main() {
  char ch;
  FILE *source; 
  source = fopen("abc.doc", "r+"); // Open in read+write mode
  if (source==NULL) {
    printf("Error opening abc.doc\n");
    return 1;
  }
  FILE *dest;
  dest = fopen("xyz.doc", "w"); // Open destination file in write mode
  if (dest==NULL) {
    printf("Error opening xyz.doc\n");
    fclose(source);
    return 1;
  }
  // Convert to uppercase and write to destination file
  while ((ch = fgetc(source)) != EOF) {
    fputc(toupper(ch), dest);
  }
  // Write sample content to source file
  fputs("Hello Utsav sah!................\n", source);
  fputs("Hi I am fine and what about you!................\n", source);
  rewind(source); // Move file pointer to the beginning for reading

  printf("File copied successfully with uppercase conversion.\n");
  fclose(source);
  fclose(dest);
  return 0;
}
     