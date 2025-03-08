/*wap to display the following operation using switch case
""menu""            1. add  2. subtract 3. multiply  4. divide   5. exit  */
#include <stdio.h>
int main() {
    int choice;
    float a, b;
    printf("\"Menu\"\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter two numbers for the operation: ");
    scanf("%f %f", &a, &b);
    switch(choice) {
        case 1:
            printf("Sum = %.2f", a + b);
            break;
        case 2:
            printf("Difference = %.2f", a - b);
            break;
        case 3:
            printf("Product = %.2f", a * b);
            break;
        case 4:
            printf("Quotient = %.2f", a / b);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}