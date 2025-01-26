#include <stdio.h>
#include <conio.h>


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
