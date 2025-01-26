
#include <conio.h>
#include <stdio.h>
int main() {
  int totalItem, i;
  float totalCost = 0, price, quantity;

  printf("Enter the number of all the items: ");
  scanf("%d", &totalItem);

  for (i = 1; i <= totalItem; i++) {
    printf("\nEnter the price of the item %d: ", i);
    scanf("%f", &price);
    printf("Enter the quantity of the item %d:", i);
    scanf("%f", &quantity);

    totalCost += price * quantity;
  }
  printf("The total cost of the items is: %.2f", totalCost);
  return 0;
}
