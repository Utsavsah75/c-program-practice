#include<stdio.h>
int main(){
int i,j;
    for(i=0; i<5; i++){                //  *
        for(j=0; j<=i; j++){           //  **
            printf("*");               //  ***
        }                              //  ****
        printf("\n");                  //  *****
    }
    return 0;
}
// //********************************************************************************

// #include<stdio.h>
// int main() {
//     int i, j;
//     for(i=1; i<=5; i++) {               //  *****
//         for(j=1; j<=5; j++) {           //  *****  
//             printf("*");                //  *****
//         }                               //  *****
//         printf("\n");                   //  *****          
//     }
//     return 0;
// }


// //********************************************************************************
// #include<stdio.h>
// int main() {
//     int i, j,row=5;
//     for(i=row; i>1; i--) {              //  *****
//         for(j=1; j<=i; j++) {           //  ****
//             printf("*");                //  ***
//         }                               //  **
//         printf("\n");                   //  *
//     }
//     return 0;
// }


// //********************************************************************************
// #include <stdio.h>
// int main() {
//     int i, j ,k, rows = 5; 
//     for (i = rows; i >= 1; i--) {
//         for (j = 0; j < rows - i; j++) {           //   *****
//             printf(" ");                           //    ****
//         }                                          //     ***                                                 
//         //Printing stars                           //      **
//         for (k = 0; k < i; k++) {                  //       *
//             printf("*");
//         }
//         printf("\n"); // Move to the next line
//     }
//     return 0;
// }


