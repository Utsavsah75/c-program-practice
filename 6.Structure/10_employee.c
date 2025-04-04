#include <stdio.h>

// Define the structure for a bank customer
struct bank {
    char name[50];
    char phone[15];
    float balance;
}B[10];

int main() {
    struct bank ;
    int i, high_balance = 0;
    
    // Input details for 10 customers
    for (i = 0; i < 10; i++) {
        printf("Enter details for customer %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", B[i].name);
        printf("Phone: ");
        scanf("%s", B[i].phone);
        printf("Balance: ");
        scanf("%f", &B[i].balance);
    }
    
    // Find the customer with the highest balance
    for (i = 1; i < 10; i++) {
        if (B[i].balance > B[high_balance].balance) {
            high_balance = i;
        }
    }
    
    // Display the customer with the highest balance
    printf("\nCustomer with the highest balance:\n");
    printf("Name: %s\n", B[high_balance].name);
    printf("Phone: %s\n", B[high_balance].phone);
    printf("Balance: %.2f\n", B[high_balance].balance);
    
    return 0;
}
