#include <conio.h>
#include <stdio.h>


int main() {
  float p, t, r, frequency, CI;
  printf("Enter the principal amount: ");
  scanf("%f", &p);
  printf("Enter the time of year : ");
  scanf("%f", &t);
  printf("Enter the  rate of interest (in per): ");
  scanf("%f", &r);
  printf("Enter the number of times interest is compounded per year: ");
  scanf("%f", &frequency);

  CI = p * pow((1 + r / (frequency * 100)), frequency * t);

  printf("Compound Interest after %.2f years: %.2f\n", t, CI - p);
  printf("Total Amount after %.2f years: %.2f\n", t, CI);

    return 0;
}
