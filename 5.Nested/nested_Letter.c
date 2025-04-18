//  #include <stdio.h>
//  int main() {
//     for (int i = 0; i < 5; i++) {            //  A
//         for (int j = 0; j <= i; j++) {       //  A  B
//             printf("%c\t", 'A' + j);         //  A  B   C
//         }                                    //  A  B   C   D
//         printf("\n");                        //  A  B   C   D   E
//     }  
//     return 0;
// }

// //**************************************** 
#include <stdio.h>
#include <string.h>
int main() {
    int i, j,len;
    char str[] = "Hello"; // Define the string                          //  u
     len = strlen(str); // Get the length of the string                 //  ut
    for (i = 0; i < len; i++) {                                         //  uts
        for (j = 0; j <=i; j++) {                                      //  utsa
            printf("%c\t", str[j]);                                     //  utsav
        }
        printf("\n"); // Move to the next line
    }
    return 0;
}

