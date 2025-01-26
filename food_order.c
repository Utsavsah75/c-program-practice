#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define FILE_NAME "users.txt"

// Function to check if a username already exists in the file
int username_exists(const char *username) {
    char file_username[MAX_LENGTH], file_password[MAX_LENGTH];
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return 0;

    while (fscanf(file, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(file_username, username) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

// Function to handle user signup
void signup() {
    char username[MAX_LENGTH], password[MAX_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    // Check if the username already exists
    if (username_exists(username)) {
        printf("Username already exists. Please try another one.\n");
        return;
    }

    printf("Enter a password: ");
    scanf("%s", password);

    // Save the new user credentials to the file
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Signup successful!\n");
}

// Function to display food items after login
void display_food_items() {
    printf("\nHere is a list of 15 food items:\n");
    printf("1. Pizza\n");
    printf("2. Burger\n");
    printf("3. Pasta\n");
    printf("4. Sandwich\n");
    printf("5. Salad\n");
    printf("6. Sushi\n");
    printf("7. Tacos\n");
    printf("8. Fried Rice\n");
    printf("9. Noodles\n");
    printf("10. Pancakes\n");
    printf("11. Ice Cream\n");
    printf("12. Steak\n");
    printf("13. Soup\n");
    printf("14. Dumplings\n");
    printf("15. Smoothies\n");
    printf("\nEnter the number of the food item you want to order: ");
    int choice;
    scanf("%d", &choice);
    // Function to display order summary after login
    void display_order_summary() {
        const char *food_items[] = {
            "Pizza", "Burger", "Pasta", "Sandwich", "Salad", "Sushi", "Tacos", "Fried Rice", "Noodles", "Pancakes",
            "Ice Cream", "Steak", "Soup", "Dumplings", "Smoothies"
        };
        int prices[] = {10, 8, 12, 6, 5, 15, 7, 9, 8, 5, 4, 20, 7, 10, 6};
        int delivery_fee = 3;
        printf("\nHere is a summary of your order:\n");
        printf("Food Item: %s\n", food_items[choice - 1]);
        printf("Price: $%d\n", prices[choice - 1]);
        printf("Delivery Fee: $%d\n", delivery_fee);
        printf("Total Amount: $%d\n", prices[choice - 1] + delivery_fee);
    }
    display_order_summary();
}

// Function to handle user login
void login() {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    char file_username[MAX_LENGTH], file_password[MAX_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Validate credentials from the file
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int login_successful = 0;
    while (fscanf(file, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(file_username, username) == 0 && strcmp(file_password, password) == 0) {
            login_successful = 1;
            break;
        }
    }

    fclose(file);

    if (login_successful) {
        printf("Login successful! Welcome, %s.\n", username);
        display_food_items();
    } else {
        printf("Invalid username or password.\n");
    }
}

// Function to edit user password
void edit_user() {
    char username[MAX_LENGTH], new_password[MAX_LENGTH];
    char file_username[MAX_LENGTH], file_password[MAX_LENGTH];
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");

    if (!file || !temp_file) {
        perror("Error opening file");
        return;
    }

    printf("Enter the username to edit: ");
    scanf("%s", username);

    int user_found = 0;
    while (fscanf(file, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(file_username, username) == 0) {
            user_found = 1;
            printf("Enter the new password: ");
            scanf("%s", new_password);
            fprintf(temp_file, "%s %s\n", file_username, new_password);
        } else {
            fprintf(temp_file, "%s %s\n", file_username, file_password);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (user_found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Password updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("Username not found.\n");
    }
}

// Function to delete user account
void delete_user() {
    char username[MAX_LENGTH];
    char file_username[MAX_LENGTH], file_password[MAX_LENGTH];
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");

    if (!file || !temp_file) {
        perror("Error opening file");
        return;
    }

    printf("Enter the username to delete: ");
    scanf("%s", username);

    int user_found = 0;
    while (fscanf(file, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(file_username, username) == 0) {
            user_found = 1;
        } else {
            fprintf(temp_file, "%s %s\n", file_username, file_password);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (user_found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("Username not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Signup\n");
        printf("2. Login\n");
        printf("3. Edit User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                edit_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
