
void staff_register() {
    FILE *f = fopen("staff.txt", "a");
    if (!f) {
        printf("Error opening staff file.\n");
        return;
    }

    char username[50], password[50];
    printf("Register Staff Username: ");
    scanf("%s", username);
    printf("Register Staff Password: ");
    scanf("%s", password);
    // Check if username already exists
    char file_user[50], file_pass[50];
    while (fscanf(f, "%s %s", file_user, file_pass) != EOF) {
        if (strcmp(username, file_user) == 0) {
            printf("Username already exists. Please choose another.\n");
            fclose(f);
            return;
        }
    }
    // If username is unique, write to file
    fclose(f);


    fprintf(f, "%s %s\n", username, password);
    fclose(f);

    printf("Staff registered successfully.\n");
}

int staff_login(char *username) {
    char input_user[50], input_pass[50];
    printf("Staff Login\nUsername: ");
    scanf("%s", input_user);
    printf("Password: ");
    scanf("%s", input_pass);

    FILE *f = fopen("staff.txt", "r");
    if (!f) {
        printf("No staff registered yet.\n");
        return 0;
    }

    char file_user[50], file_pass[50];
    while (fscanf(f, "%s %s", file_user, file_pass) != EOF) {
        if (strcmp(input_user, file_user) == 0 && strcmp(input_pass, file_pass) == 0) {
            strcpy(username, input_user);
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;
    char staff_username[50];

    printf("Library Management System\n");
    printf("Logged in as Admin automatically.\n");

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Admin Dashboard\n");
        printf("2. Staff Register\n");
        printf("3. Staff Login\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                admin_dashboard();
                break;
            case 2:
                staff_register();
                break;
            case 3:
                if (staff_login(staff_username)) {
                    printf("Welcome, %s (Staff)!\n", staff_username);
                    staff_dashboard();
                }
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
