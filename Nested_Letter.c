 #include <stdio.h>
 int main() {
    for (int i = 0; i < 5; i++) {                           //  A
        for (int j = 0; j <= i; j++) {                                  //  AB
            printf("%c", 'A' + j);                                      //  ABC
        }                                                               //  ABCD
        printf("\n");                                                   //  ABCDE
    }  
    return 0;
}

//**************************************** */
// #include <stdio.h>
// #include <string.h>
// int main() {
//     char str[] = "Utsav"; // Define the string
//     int length = strlen(str); // Get the length of the string           //  u
//     for (int i = 0; i < length; i++) {                                  //  ut
//         // Print characters from index 0 to i                           //  uts
//         for (int j = 0; j <= i; j++) {                                  //  utsa
//             printf("%c", str[j]);                                       //  utsav
//         }
//         printf("\n"); // Move to the next line
//     }
//     return 0;
// }