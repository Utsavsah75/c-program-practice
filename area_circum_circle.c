#include <stdio.h>
#include <conio.h>

#define pi 3.142857

int main() {
  float r, area, circum;

  printf(" Enter the radius of the circle: ");
  scanf("%f", &r);

  area = pi * r * r;
  circum = 2 * pi * r;

  printf("The area of circle with the radius %.2f is: %.2f", r, area);
  printf("\nThe Circumference of circle with the radius %.2f is: %.2f", r,
         circum);
}