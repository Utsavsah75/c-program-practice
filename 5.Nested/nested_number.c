// #include <stdio.h>
// int main() {
//   int i, j, rows = 5;   // Number of rows in the pattern
//   for (i = 1; i <= rows; i++) {       // 1
//     for (j = 1; j <= i; j++) {        // 1   2
//       printf("%d\t", i);              // 1   2   3
//     }                                 // 1   2   3   4
//     printf("\n");                     // 1   2   3   4   5
//   }
//   return 0;
// }        
// //******************************************************************  
//  #include <stdio.h>
//  int main() {
//  int i, j, rows = 5;                                 // 1
//         for (i = 1; i <= rows; i++) {                // 22
//          for (j = 1; j <= i; j++) {                  // 333
//            printf("%d", i);                          // 4444
//          }                                           // 55555
//            printf("\n"); // Move to the next line
//     }
//         return 0;
//    }
// //******************************************************************
// #include <stdio.h>
// int main() {
//         int i, j, rows = 5;
//         for (i = 1; i <= rows; i++) {
//                 for (j = 1; j <= rows - i; j++) {       //      1
//                     printf(" ");                        //     22
//                 }                                       //    333
//                 for (j = 1; j <= i; j++) {              //   4444
//                     printf("%d", i);                    //  55555
//                 }
//                 printf("\n");
//             }
//             return 0;
//         }
// //******************************************************************
#include <stdio.h>
int main() {
        int i, j, rows = 5;
        for (i = 1; i <= rows; i++) {
                for (j = 1; j <= rows - i; j++) {       //      1
                    printf(" ");                        //     12
                }                                       //    123
                for (j = 1; j <= i; j++) {              //   1234
                    printf("%d", j);                    //  12345
                }
                printf("\n");
            }
            return 0;
        }
    
    