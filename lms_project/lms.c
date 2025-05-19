#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 50
#define MAX_BOOKS 100
#define MAX_LEN 50

typedef enum { ROLE_NONE, ROLE_ADMIN, ROLE_STUDENT } Role;

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    Role role;
} User;

typedef struct {
    char name[MAX_LEN];
    char roll[MAX_LEN];
    char faculty[MAX_LEN];
} StudentInfo;

typedef struct {
    char bookName[MAX_LEN];
    char author[MAX_LEN];
    int bookNumber;
} Book;

typedef struct {
    char username[MAX_LEN];
    StudentInfo info;
    char borrowed[10][MAX_LEN];
    int borrowCount;
    float fine;
} StudentRecord;

// Globals
User users[MAX_USERS];
int userCount = 0;

Book books[MAX_BOOKS];
int bookCount = 0;

StudentRecord students[MAX_USERS];
int studentCount = 0;

// Function prototypes
int authenticate(Role *outRole, char *outUser);
int registerUser();
void adminMenu();
void studentMenu(const char *username);
void addBook();
void issueBook();
void showBookList();
void addStudent();
void showStudentInfo();
void collectFine();
void borrowBook(const char *username);
void payFine(const char *username);
void showBorrowed(const char *username);
void saveAllData();
void loadAllData();

int main() {
    printf("=== Library Management System ===\n");

    loadAllData();

    while (1) {
        printf("\n1. Login\n2. Register\n0. Exit\nChoose: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // clear newline

        if (choice == 0) {
            printf("Exiting program.\n");
            break;
        }
        else if (choice == 1) {
            Role role = ROLE_NONE;
            char currentUser[MAX_LEN] = {0};
            if (authenticate(&role, currentUser)) {
                if (role == ROLE_ADMIN) adminMenu();
                else if (role == ROLE_STUDENT) studentMenu(currentUser);
            } else {
                printf("Invalid credentials.\n");
            }
        }
        else if (choice == 2) {
            if (registerUser()) {
                printf("Registration successful! You can now login.\n");
            } else {
                printf("Registration failed.\n");
            }
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    saveAllData();
    return 0;
}

int authenticate(Role *outRole, char *outUser) {
    char uname[MAX_LEN], pass[MAX_LEN];
    printf("Username: ");
    scanf("%s", uname);
    printf("Password: ");
    scanf("%s", pass);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(uname, users[i].username) == 0 &&
            strcmp(pass, users[i].password) == 0) {
            *outRole = users[i].role;
            strcpy(outUser, uname);
            printf("Login successful. Welcome, %s!\n", uname);
            return 1;
        }
    }
    return 0;
}

int registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return 0;
    }
    char uname[MAX_LEN], pass[MAX_LEN], roleStr[10];
    printf("Enter new username: ");
    scanf("%s", uname);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, uname) == 0) {
            printf("Username already exists.\n");
            return 0;
        }
    }

    printf("Enter password: ");
    scanf("%s", pass);

    printf("Role (admin/student): ");
    scanf("%s", roleStr);


    Role newRole = ROLE_NONE;
    if (strcmp(roleStr, "admin") == 0) newRole = ROLE_ADMIN;
    else if (strcmp(roleStr, "student") == 0) newRole = ROLE_STUDENT;
    else {
        printf("Invalid role.\n");
        return 0;
    }

    strcpy(users[userCount].username, uname);
    strcpy(users[userCount].password, pass);
    users[userCount].role = newRole;
    userCount++;

    if (newRole == ROLE_STUDENT) {
        strcpy(students[studentCount].username, uname);
        students[studentCount].borrowCount = 0;
        students[studentCount].fine = 0.0f;
        strcpy(students[studentCount].info.name, "");
        strcpy(students[studentCount].info.roll, "");
        strcpy(students[studentCount].info.faculty, "");
        studentCount++;
    }

    saveAllData();
    return 1;
}

void adminMenu() {
    int choice;
    do {
        printf("\n--- Admin Dashboard ---\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Show Book List\n");
        printf("4. Add Student\n");
        printf("5. Show Student Info\n");
        printf("6. Collect Fine\n");
        printf("0. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        
        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: showBookList(); break;
            case 4: addStudent(); break;
            case 5: showStudentInfo(); break;
            case 6: collectFine(); break;
            case 0: printf("Logging out...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

void studentMenu(const char *username) {
    int choice;
    do {
        printf("\n--- Student Dashboard (%s) ---\n", username);
        printf("1. Borrow Book\n");
        printf("2. Pay Fine\n");
        printf("3. Show Borrowed List\n");
        printf("0. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: borrowBook(username); break;
            case 2: payFine(username); break;
            case 3: showBorrowed(username); break;
            case 0: printf("Logging out...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

void addBook() {
    int n;
    printf("How many books do you want to add? ");
    scanf("%d", &n);
    getchar(); // clear newline

    for (int k = 0; k < n; k++) {
        if (bookCount >= MAX_BOOKS) {
            printf("Reached maximum number of books.\n");
            break;
        }

        char name[MAX_LEN], author[MAX_LEN];
        int bookNum;

        printf("\nEnter book name #%d: ", k + 1);
        fgets(name, MAX_LEN, stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter author name: ");
        fgets(author, MAX_LEN, stdin);
        author[strcspn(author, "\n")] = 0;

        printf("Enter book number: ");
        scanf("%d", &bookNum);
        getchar();

        int exists = 0;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookNumber == bookNum) {
                printf("Book number already exists. Skipping.\n");
                exists = 1;
                break;
            }
        }
        if (exists) continue;

        strcpy(books[bookCount].bookName, name);
        strcpy(books[bookCount].author, author);
        books[bookCount].bookNumber = bookNum;
        bookCount++;

        printf("Book \"%s\" by %s (Number: %d) added.\n", name, author, bookNum);
    }
    saveAllData();
}






void issueBook() {
    char uname[MAX_LEN], bookName[MAX_LEN];
    printf("Enter student username: ");
    scanf("%s", uname);
    getchar();
    printf("Enter book name to issue: ");
    fgets(bookName, MAX_LEN, stdin);
    bookName[strcspn(bookName, "\n")] = 0;

    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, uname) == 0) {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    int bookExists = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookName, bookName) == 0) {
            bookExists = 1;
            break;
        }
    }
    if (!bookExists) {
        printf("Book not found.\n");
        return;
    }

    for (int i = 0; i < students[studentIndex].borrowCount; i++) {
        if (strcmp(students[studentIndex].borrowed[i], bookName) == 0) {
            printf("Book already issued to student.\n");
            return;
        }
    }

    if (students[studentIndex].borrowCount < 10) {
        strcpy(students[studentIndex].borrowed[students[studentIndex].borrowCount++], bookName);
        saveAllData();
        printf("Book \"%s\" issued to %s.\n", bookName, uname);
    } else {
        printf("Student has reached max borrowed books.\n");
    }
}

void showBookList() {
    printf("\n-- Book List --\n");
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s (Number: %d)\n", i + 1, books[i].bookName, books[i].author, books[i].bookNumber);
    }
}

void addStudent() {
    int n;
    printf("How many students do you want to add? ");
    scanf("%d", &n);
    getchar(); // clear newline

    for (int k = 0; k < n; k++) {
        if (studentCount >= MAX_USERS || userCount >= MAX_USERS) {
            printf("Reached maximum number of users or students.\n");
            break;
        }

        char uname[MAX_LEN], pass[MAX_LEN];
        char name[MAX_LEN], roll[MAX_LEN], faculty[MAX_LEN];

        printf("\nEnter student username #%d: ", k + 1);
        scanf("%s", uname);

        int exists = 0;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, uname) == 0) {
                printf("Username already exists. Skipping.\n");
                exists = 1;
                break;
            }
        }
        if (exists) {
            getchar(); // clear newline
            continue;
        }

        printf("Enter password for student: ");
        scanf("%s", pass);
        getchar();

        printf("Enter student full name: ");
        fgets(name, MAX_LEN, stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter roll number: ");
        fgets(roll, MAX_LEN, stdin);
        roll[strcspn(roll, "\n")] = 0;

        printf("Enter faculty: ");
        fgets(faculty, MAX_LEN, stdin);
        faculty[strcspn(faculty, "\n")] = 0;

        strcpy(users[userCount].username, uname);
        strcpy(users[userCount].password, pass);
        users[userCount].role = ROLE_STUDENT;
        userCount++;

        strcpy(students[studentCount].username, uname);
        strcpy(students[studentCount].info.name, name);
        strcpy(students[studentCount].info.roll, roll);
        strcpy(students[studentCount].info.faculty, faculty);
        students[studentCount].borrowCount = 0;
        students[studentCount].fine = 0.0f;
        studentCount++;

        printf("Student \"%s\" added successfully.\n", uname);
    }
    saveAllData();
}






void showStudentInfo() {
    char uname[MAX_LEN];
    printf("Enter student username: ");
    scanf("%s", uname);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, uname) == 0) {
            printf("\n-- Info for %s --\n", uname);
            printf("Name: %s\n", students[i].info.name);
            printf("Roll: %s\n", students[i].info.roll);
            printf("Faculty: %s\n", students[i].info.faculty);
            printf("Borrowed books (%d):\n", students[i].borrowCount);
            for (int j = 0; j < students[i].borrowCount; j++) {
                printf(" - %s\n", students[i].borrowed[j]);
            }
            printf("Fine: %.2f\n", students[i].fine);
            return;
        }
    }
    printf("Student not found.\n");
}

void collectFine() {
    char uname[MAX_LEN];
    printf("Enter student username: ");
    scanf("%s", uname);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, uname) == 0) {
            printf("Current fine: %.2f\n", students[i].fine);
            printf("Enter amount to collect: ");
            float amount;
            scanf("%f", &amount);
            if (amount <= students[i].fine && amount >= 0) {
                students[i].fine -= amount;
                printf("Fine updated. Remaining: %.2f\n", students[i].fine);
                saveAllData();
            } else {
                printf("Invalid amount.\n");
            }
            return;
        }
    }
    printf("Student not found.\n");
}

void borrowBook(const char *username) {
    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0) {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex == -1) {
        printf("Student record not found.\n");
        return;
    }

    if (students[studentIndex].fine > 0) {
        printf("You have unpaid fines (%.2f). Please pay before borrowing.\n", students[studentIndex].fine);
        return;
    }

    char bookName[MAX_LEN];
    printf("Enter book name to borrow: ");
    fgets(bookName, MAX_LEN, stdin);
    bookName[strcspn(bookName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookName, bookName) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
        return;
    }

    for (int i = 0; i < students[studentIndex].borrowCount; i++) {
        if (strcmp(students[studentIndex].borrowed[i], bookName) == 0) {
            printf("You already borrowed this book.\n");
            return;
        }
    }

    if (students[studentIndex].borrowCount >= 10) {
        printf("You have reached max borrowed books.\n");
        return;
    }

    strcpy(students[studentIndex].borrowed[students[studentIndex].borrowCount++], bookName);
    printf("Book \"%s\" borrowed.\n", bookName);
    saveAllData();
}

void payFine(const char *username) {
    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0) {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex == -1) {
        printf("Student record not found.\n");
        return;
    }
    printf("Current fine: %.2f\n", students[studentIndex].fine);
    if (students[studentIndex].fine == 0) {
        printf("No fines to pay.\n");
        return;
    }
    printf("Enter amount to pay: ");
    float amount;
    scanf("%f", &amount);
    if (amount <= 0 || amount > students[studentIndex].fine) {
        printf("Invalid amount.\n");
        return;
    }
    students[studentIndex].fine -= amount;
    printf("Fine updated. Remaining: %.2f\n", students[studentIndex].fine);
    saveAllData();
}

void showBorrowed(const char *username) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0) {
            printf("\n-- Borrowed Books --\n");
            if (students[i].borrowCount == 0) {
                printf("No borrowed books.\n");
                return;
            }
            for (int j = 0; j < students[i].borrowCount; j++) {
                printf("%d. %s\n", j + 1, students[i].borrowed[j]);
            }
            return;
        }
    }
    printf("Student not found.\n");
}

// File saving/loading in text mode

void saveAllData() {
    // Save users
    FILE *f = fopen("users.txt", "w");
    if (!f) {
        perror("Error saving users");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        fprintf(f, "%s %s %d\n", users[i].username, users[i].password, users[i].role);
    }
    fclose(f);

    // Save students
    f = fopen("students.txt", "w");
    if (!f) {
        perror("Error saving students");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(f, "%s %s %s %s %d %.2f\n",
                students[i].username,
                students[i].info.name,
                students[i].info.roll,
                students[i].info.faculty,
                students[i].borrowCount,
                students[i].fine);
        for (int j = 0; j < students[i].borrowCount; j++) {
            fprintf(f, "%s\n", students[i].borrowed[j]);
        }
    }
    fclose(f);

    // Save books
    f = fopen("books.txt", "w");
    if (!f) {
        perror("Error saving books");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        fprintf(f, "%s %s %d\n", books[i].bookName, books[i].author, books[i].bookNumber);
    }
    fclose(f);
}

void loadAllData() {
    // Load users
    FILE *f = fopen("users.txt", "r");
    if (f) {
        userCount = 0;
        while (userCount < MAX_USERS &&
               fscanf(f, "%s %s %d", users[userCount].username, users[userCount].password, (int*)&users[userCount].role) == 3) {
            userCount++;
        }
        fclose(f);
    } else {
        // If no users file, add default admin
        strcpy(users[0].username, "admin");
        strcpy(users[0].password, "123");
        users[0].role = ROLE_ADMIN;
        userCount = 1;
    }

    // Load students
    f = fopen("students.txt", "r");
    if (f) {
        studentCount = 0;
        while (studentCount < MAX_USERS) {
            StudentRecord *s = &students[studentCount];
            char borrowedName[MAX_LEN];
            int readCount = fscanf(f, "%s %s %s %s %d %f",
                                   s->username,
                                   s->info.name,
                                   s->info.roll,
                                   s->info.faculty,
                                   &s->borrowCount,
                                   &s->fine);
            if (readCount != 6) break;
            for (int i = 0; i < s->borrowCount; i++) {
                if (!fgets(borrowedName, MAX_LEN, f)) {
                    s->borrowCount = i;
                    break;
                }
                borrowedName[strcspn(borrowedName, "\n")] = 0;
                strcpy(s->borrowed[i], borrowedName);
            }
            studentCount++;
        }
        fclose(f);
    }

    // Load books
    f = fopen("books.txt", "r");
    if (f) {
        bookCount = 0;
        while (bookCount < MAX_BOOKS) {
            int readCount = fscanf(f, "%s %s %d", books[bookCount].bookName, books[bookCount].author, &books[bookCount].bookNumber);
            if (readCount != 3) break;
            bookCount++;
        }
        fclose(f);
    }
}
