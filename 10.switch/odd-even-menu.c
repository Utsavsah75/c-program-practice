/*wap to display the following operation using switch case
""menu""            1. odd/even  2.square  3. Exit  */
#include <stdio.h>
#include <stdlib.h> // for exit function
int main()
{
    int choice;
    int num;
    printf("menu\n");
    printf("1. odd/even\n");
    printf("2. square\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter a number: ");
    scanf("%d", &num);
    switch (choice)
    {
        case 1:
            if (num % 2 == 0)
                printf("%d is even\n", num);
            else
                printf("%d is odd\n", num);
            break;
        case 2:
            printf("Square of %d is %d\n", num, num * num);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
    return 0;
}