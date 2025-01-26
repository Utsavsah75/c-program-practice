#include <stdio.h>
#include <conio.h>


int main() {
  float salary, bonus, bonus_percentage;

  printf("Enter the salary of the employee: ");
  scanf("%f", &salary);
  printf("Enter the bonus percentage: ");
  scanf("%f", &bonus_percentage);

  bonus = (salary * bonus_percentage) / 100;
  printf("The bonus of the employee is: %.2f", bonus);

  salary += bonus;
  printf("\nThe total salary with bonus of the employee is: %.2f", salary);
  return 0;
  // find bonus percentage from bonus
  // printf("Enter the bonus: ");
  // scanf("%f", &bonus);

  // bonus_percentage = (bonus / salary) * 100;
  // printf("The bonus percentage of the employee is: %.2f", bonus_percentage);
  // return 0;
}