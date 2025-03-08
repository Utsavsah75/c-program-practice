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
//  #include <stdio.h>
//  int main() {
//     int rows = 5; // Number of rows in the pattern       // 1
//         for (int i = 1; i <= rows; i++) {                // 22
//          for (int j = 1; j <= i; j++) {                  // 333
//            printf("%d", i);                              // 4444
//          }                                               // 55555
//            printf("\n"); // Move to the next line
//     }
//         return 0;
//    }
        
// //******************************************************************
#include <stdio.h>
int main() {
    int rows = 5; // Number of rows in the pattern
      for (int i = 1; i <= rows; i++) {              // 1            
        for (int j = 1; j <= i; j++) {               // 12            
             printf("%d", j);                        // 123           
            }                                        // 1234            
            printf("\n");                            // 12345         
            }
            return 0;
        }





     