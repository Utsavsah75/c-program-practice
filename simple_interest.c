<<<<<<< HEAD
#include <conio.h>
#include <stdio.h>
=======
#include <stdio.h>
#include <conio.h>

>>>>>>> f042e51 (space)

int main() {
  float p, r, t, si;

  printf("Enter the principal amounts: ");
  scanf("%f", &p);
  printf("Enter the rate of interest: ");
  scanf("%f", &r);
  printf("Enter the time period: ");
  scanf("%f", &t);

  si = (p * t * r) / 100;
  printf("The simple interest for %.2f at a rate of %.2f over %.2f years is: "
         "%.2f\n",
         p, r, t, si);

  return 0;
}
<<<<<<< HEAD

// -------------------------using function-------------------------

// #include <conio.h>
// #include <stdio.h>

// float simpleinterest(float a, float b, float c);
// int main() {
//   float p, t, r, si;
//   printf("Enter the principal, time and rate:");
//   scanf("%f%f%f", &p, &t, &r);
//   si = simpleinterest(p, t, r);
//   printf("The simple interest is %.2f", si);
//   return 0;
// }

// float simpleinterest(float p, float t, float r) {
//   float z;
//   z = (p * t * r) / 100;
//   return z;
// }
=======
>>>>>>> f042e51 (space)
