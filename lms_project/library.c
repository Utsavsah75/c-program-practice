#include <conio.h> // For getch()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
struct User {
  char username[50];
//   char password[50];
  char role[10]; // "admin" or "staff"
};

struct Student {
  char name[50], id[10], username[50];
  char email[50], phone[15], address[100];
  int age;
};

struct Staff {
  char name[50], id[10], username[50], password[50];
  char email[50], phone[15], address[100];
};

struct Admin {
  char name[50], id[10], username[50], password[50];
  char email[50], phone[15], address[100];
};

struct Book {
  char title[100], author[50], publisher[50], isbn[20];
  int year, copies;
};

struct ReturnRecord {
  char student_id[10], student_name[50], student_phone[20];
  char book_isbn[20], book_title[100], book_author[50];
  time_t return_date;
  double fine;
};

struct IssueRecord {
  char student_id[10], student_name[50], student_phone[20];
  char book_isbn[20], book_title[100], book_author[50];
  time_t issue_date, return_date;
  double fine;
};

// Global
struct User current_user;

// Prototypes
int login();
void add_admin();
void admin_dashboard();
void staff_register();
void staff_login(const char *username);
void staff_dashboard();

void add_staff();
void add_student();
void add_book();

void remove_record();
void remove_book();
void remove_staff();
void remove_student();

void update_record();
void update_book();
void update_staff();
void update_student();

void show_record();
void show_book();
void show_staff();
void show_student();

void search_record();
void search_books(const char *keyword);
void search_staffs(const char *keyword);
void search_students(const char *keyword);

void issue_book();
void return_book();
void save_issue(const struct IssueRecord *b);
void save_return(const struct ReturnRecord *r);
void fine_collect();

// void view_issued_books();
void show_issued_record();
void search_records();

void get_password(char *password, int max_len);

// Simple masked password input
void get_password(char *password, int max_len) {
  int i = 0;
  char ch;
  while ((ch = getch()) != '\r' && i < max_len - 1) {
    if (ch == '\b') {
      if (i > 0) {
        i--;
        printf("\b \b");
      }
    } else {
      password[i++] = ch;
      printf("*");
    }
  }
  password[i] = '\0';
  printf("\n");
}

int main() {
  const char *admin_username = "a";
  const char *admin_password = "a";
  char username[50], password[50];
  int attempts = 3;

  printf("Welcome to the Library Management System\n");
  while (attempts-- > 0) {
    printf("Admin Login\nUsername: ");
    scanf("%49s", username);
    printf("Password: ");
    getchar(); // clear newline
    get_password(password, sizeof(password));

    if (strcmp(username, admin_username) == 0 &&
        strcmp(password, admin_password) == 0) {
      printf("Login successful!\n");
      strcpy(current_user.username, username);
      strcpy(current_user.role, "admin");
      admin_dashboard();
      return 0;
    }
    printf("Invalid credentials. You have %d attempts left.\n", attempts);
  }

  printf("Too many failed attempts. Exiting...\n");
  return 1;
}

void admin_dashboard() {
  int choice;

  while (1) {
    printf("\n=== Admin Dashboard ===\n");
    printf("1.  Add Book\n");
    printf("2.  Add Student\n");
    printf("3.  Add Staff\n");
    printf("4.  Remove Record\n");
    printf("5.  Update Record\n");
    printf("6.  Search Record\n");
    printf("7.  Show Records\n");
    printf("8.  Fine Collected\n");
    printf("9.  Issue Book\n");
    printf("10. Return Book\n");
    printf("11. Show Issued Records\n");
    printf("12. Logout\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      while (getchar() != '\n')
        ;
      printf("Invalid input. Please enter a number.\n");
      continue;
    }
    getchar(); // clear newline

    switch (choice) {
    case 1:
      add_book();
      break;
    case 2:
      add_student();
      break;
    case 3:
      add_staff();
      break;
    case 4:
      remove_record();
      break;
    case 5:
      update_record();
      break;
    case 6:
      search_record();
      break;
    case 7:
      show_record();
      break;
    case 8:
      fine_collect();
      break;
    case 9:
      issue_book();
      break;
    case 10:
      return_book();
      break;
    case 11:
      show_issued_record();
      break;
    case 12:
      printf("Logging out...\n");
      return;
    default:
      printf("Invalid choice. Try again.\n");
    }
  }
}

// Search Menu
void search_record() {
  int choice;
  char keyword[50];

  printf("\n--- Search Record Menu ---\n");
  printf("1. Search Book\n");
  printf("2. Search Student\n");
  printf("3. Search Staff\n");
  printf("0. Cancel\n");
  printf("Enter your choice: ");
  if (scanf("%d", &choice) != 1) {
    while (getchar() != '\n')
      ;
    printf("Invalid input.\n");
    return;
  }
  getchar(); // clear newline

  if (choice == 0)
    return;

  printf("Enter keyword to search  : ");
  fgets(keyword, sizeof(keyword), stdin);
  keyword[strcspn(keyword, "\n")] = '\0';

  switch (choice) {
  case 1:
    search_books(keyword);
    break;
  case 2:
    search_students(keyword);
    break;
  case 3:
    search_staffs(keyword);
    break;
  default:
    printf("Invalid choice. Try again.\n");
  }
}

// Search Books
void search_books(const char *keyword) {
  FILE *f = fopen("books.txt", "r");
  if (!f) {
    printf("No books available.\n");
    return;
  }

  struct Book b;
  char line[512];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    if (sscanf(line,
               "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%"
               "d|Copies:-%d",
               b.title, b.author, b.publisher, b.isbn, &b.year,
               &b.copies) == 6) {

      if (strstr(b.title, keyword) || strstr(b.author, keyword) ||
          strstr(b.publisher, keyword) || strstr(b.isbn, keyword)) {

        printf("Title: %s | Author: %s | Publisher: %s | ISBN: %s | Year: %d | "
               "Copies: %d\n",
               b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("No book found matching \"%s\".\n", keyword);
  }

  fclose(f);
}

// Search Students
void search_students(const char *keyword) {
  FILE *f = fopen("students.txt", "r");
  if (!f) {
    printf("No students available.\n");
    return;
  }

  struct Student {
    char name[50];
    char id[10];
    char username[30];
    char email[50];
    char phone[15];
    char address[100];
    int age;
  } s;

  int found = 0;
  char line[512];

  while (fgets(line, sizeof(line), f)) {
    if (sscanf(line,
               "Name:-%[^|]|ID:-%[^|]|UserName:-%[^|]|Email:-%[^|]|Phone:-%[^|]|Address:-%[^|]|Age:-%d",
               s.name, s.id, s.username, s.email, s.phone, s.address, &s.age) == 7) {

      if (strstr(s.name, keyword) || strstr(s.id, keyword) ||
          strstr(s.username, keyword) || strstr(s.email, keyword)) {
        printf("Name: %s | ID: %s | Username: %s | Email: %s | Phone: %s | Address: %s | Age: %d\n",
               s.name, s.id, s.username, s.email, s.phone, s.address, s.age);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("No student found with \"%s\".\n", keyword);
  }

  fclose(f);
}


// Search Staff
void search_staffs(const char *keyword) {
  FILE *f = fopen("staff.txt", "r");
  if (!f) {
    printf("No staff available.\n");
    return;
  }

  struct Staff {
    char name[50];
    char id[10];
    char username[30];
    char email[50];
    char phone[15];
  } s;

  int found = 0;
  char line[512];

  while (fgets(line, sizeof(line), f)) {
    if (sscanf(line,
               "Name:-%[^|]|ID:-%[^|]|UserName:-%[^|]|Email:-%[^|]|Phone:-%[^\n]",
               s.name, s.id, s.username, s.email, s.phone) == 5) {

      if (strstr(s.name, keyword) || strstr(s.id, keyword) ||
          strstr(s.username, keyword) || strstr(s.email, keyword)) {

        printf("Name: %s | ID: %s | Username: %s | Email: %s | Phone: %s\n",
               s.name, s.id, s.username, s.email, s.phone);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("No staff found with \"%s\".\n", keyword);
  }

  fclose(f);
}




// ==================== Submenus ====================

void remove_record() {
  int choice;
  printf("\n--- Remove Record Menu ---\n");
  printf("1. Remove Book\n");
  printf("2. Remove Student\n");
  printf("3. Remove Staff\n");
  printf("0. Cancel\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  getchar(); // clear newline

  switch (choice) {
  case 1:
    remove_book();
    break;
  case 2:
    remove_student();
    break;
  case 3:
    remove_staff();
    break;
  case 0:
    return;
  default:
    printf("Invalid choice. Try again.\n");
  }
}

void update_record() {
  int choice;
  printf("\n--- Update Record Menu ---\n");
  printf("1. Update Book\n");
  printf("2. Update Student\n");
  printf("3. Update Staff\n");
  printf("0. Cancel\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  getchar(); // clear newline

  switch (choice) {
  case 1:
    update_book();
    break;
  case 2:
    update_student();
    break;
  case 3:
    update_staff();
    break;
  case 0:
    return;
  default:
    printf("Invalid choice. Try again.\n");
  }
}

void show_record() {
  int choice;
  printf("\n--- Show Record Menu ---\n");
  printf("1. Show Books\n");
  printf("2. Show Students\n");
  printf("3. Show Staff\n");
  printf("0. Cancel\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  getchar(); // clear newline

  switch (choice) {
  case 1:
    show_book();
    break;
  case 2:
    show_student();
    break;
  case 3:
    show_staff();
    break;
  case 0:
    return;
  default:
    printf("Invalid choice. Try again.\n");
  }
}

void add_staff() {
  int n;
  printf("Number of staff to add: ");
  scanf("%d", &n);
  getchar(); // clear newline

  FILE *f = fopen("staff.txt", "a+");
  if (!f) {
    perror("Failed to open staff file");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Staff s;
    printf("\nStaff %d:\n", i + 1);

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    sprintf(s.id, "STF%d", 1000 + rand() % 9000);

    printf("Enter username: ");
    fgets(s.username, sizeof(s.username), stdin);
    s.username[strcspn(s.username, "\n")] = '\0';

    printf("Enter password: ");
    get_password(s.password, sizeof(s.password));

    printf("Enter email: ");
    fgets(s.email, sizeof(s.email), stdin);
    s.email[strcspn(s.email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(s.phone, sizeof(s.phone), stdin);
    s.phone[strcspn(s.phone, "\n")] = '\0';

    printf("Enter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    fprintf(f,
            "Name:-%s|ID:-%s|UserName:-%s|Password:-%s|Email:-%s|Phone:-%s\n",
            s.name, s.id, s.username, s.password, s.email, s.phone);
    printf("Staff added successfully with ID: %s\n", s.id);
  }

  fclose(f);
}
void add_book() {
  int n;
  printf("Number of books to add: ");
  scanf("%d", &n);
  getchar(); // clear newline

  FILE *f = fopen("books.txt", "a+");
  if (!f) {
    perror("Failed to open books file");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Book b;
    printf("\nBook %d:\n", i + 1);

    printf("Enter title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // remove newline

    printf("Enter author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter publisher: ");
    fgets(b.publisher, sizeof(b.publisher), stdin);
    b.publisher[strcspn(b.publisher, "\n")] = '\0';

    printf("Enter ISBN: ");
    fgets(b.isbn, sizeof(b.isbn), stdin);
    b.isbn[strcspn(b.isbn, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &b.year);
    getchar(); // clear newline

    printf("Enter copies: ");
    scanf("%d", &b.copies);
    getchar(); // clear newline

    fprintf(f,
            "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Copies:-%d\n",
            b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
  }

  fclose(f);
  printf("Books added successfully.\n");
}
void add_student() {
  int n;
  printf("Number of students to add: ");
  scanf("%d", &n);
  getchar(); // Clear newline left by scanf

  FILE *f = fopen("students.txt", "a+");
  FILE *u = fopen("users.txt", "a+");

  if (f == NULL || u == NULL) {
    printf("Error opening file.\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Student s;

    printf("\nStudent %d:\n", i + 1);

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    // Generate random ID
    sprintf(s.id, "STD%d", 1000 + rand() % 9000);

    printf("Enter username: ");
    fgets(s.username, sizeof(s.username), stdin);
    s.username[strcspn(s.username, "\n")] = '\0';

    // printf("Enter password: ");
    // get_password(s.password, sizeof(s.password));

    printf("Enter email: ");
    scanf("%s", s.email);

    printf("Enter phone: ");
    scanf("%s", s.phone);
    getchar(); // Clear newline

    printf("Enter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &s.age);
    getchar(); // Clear newline

    // Write student record
    fprintf(f,
            "Name:-%s|ID:-%s|UserName:-%s|Email:-%s|Phone:-%s|"
            "Address:-%s|Age:-%d\n",
            s.name, s.id, s.username, s.email, s.phone, s.address,
            s.age);

    // Save to user credentials file (optional)
    fprintf(u, "%s|%s|student\n", s.username);

    printf("Student added successfully with ID: %s\n", s.id);
  }

  fclose(f);
  fclose(u);
}
//**********remove books */
void remove_book() {
  char isbn[20];
  printf("Enter ISBN of the book to remove: ");
  fgets(isbn, sizeof(isbn), stdin);
  isbn[strcspn(isbn, "\n")] = '\0'; // Remove newline

  FILE *f = fopen("books.txt", "r");
  if (!f) {
    perror("Error opening books.txt");
    return;
  }

  FILE *temp = fopen("temp.txt", "w");
  if (!temp) {
    perror("Error opening temp.txt");
    fclose(f);
    return;
  }

  char line[512];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    char file_isbn[20];
    // Extract ISBN from the line
    char *isbn_ptr = strstr(line, "ISBN:-");
    if (isbn_ptr) {
      sscanf(isbn_ptr, "ISBN: -%19[^|]", file_isbn);
      if (strcmp(file_isbn, isbn) == 0) {
        found = 1; // Book to remove found, skip writing
        continue;
      }
    }
    fputs(line, temp); // Write the line back if it's not the target book
  }

  fclose(f);
  fclose(temp);

  if (found) {
    if (remove("books.txt") != 0) {
      perror("Failed to delete old books.txt");
    } else if (rename("temp.txt", "books.txt") != 0) {
      perror("Failed to rename temp.txt");
    } else {
      printf("Book with ISBN %s removed successfully.\n", isbn);
    }
  } else {
    printf("No book found with ISBN %s.\n", isbn);
    remove("temp.txt");
  }
}
//**********remove staff **********/
void remove_staff() {
  char id[10];
  printf("Enter ID of the staff to remove: ");
  fgets(id, sizeof(id), stdin);
  id[strcspn(id, "\n")] = '\0'; // remove newline

  FILE *f = fopen("staff.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    return;
  }

  char line[512];
  int found = 0;
  while (fgets(line, sizeof(line), f)) {
    char *id_ptr = strstr(line, "ID:-");
    if (id_ptr) {
      char current_id[10];
      sscanf(id_ptr, "ID:-%[^|]", current_id);
      if (strcmp(current_id, id) == 0) {
        found = 1;
        continue; // Skip this line
      }
    }
    fputs(line, temp);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
    printf("Staff with ID %s removed successfully.\n", id);
  } else {
    remove("temp.txt");
    printf("No staff found with ID %s.\n", id);
  }
}

//**********remove student **********/
void remove_student() {
  char id[10];
  printf("Enter ID of the students to remove: ");
  fgets(id, sizeof(id), stdin);
  id[strcspn(id, "\n")] = '\0'; // remove newline

  FILE *f = fopen("students.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    return;
  }

  char line[512];
  int found = 0;
  while (fgets(line, sizeof(line), f)) {
    char *id_ptr = strstr(line, "ID:-");
    if (id_ptr) {
      char current_id[10];
      sscanf(id_ptr, "ID:-%[^|]", current_id);
      if (strcmp(current_id, id) == 0) {
        found = 1;
        continue; // Skip this line
      }
    }
    fputs(line, temp);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("student with ID %s removed successfully.\n", id);
  } else {
    remove("temp.txt");
    printf("No students found with ID %s.\n", id);
  }
}

//**********update book **********/
void update_book() {
  char isbn[20];
  printf("Enter ISBN of the book to update: ");
  fgets(isbn, sizeof(isbn), stdin);

  isbn[strcspn(isbn, "\n")] = '\0'; // remove newline

  FILE *f = fopen("books.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    if (f)
      fclose(f);
    if (temp)
      fclose(temp);
    return;
  }

  char line[512];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    struct Book b;

    // Parse line with label prefixes
    if (sscanf(line,
               "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%"
               "d|Copies:-%d",
               b.title, b.author, b.publisher, b.isbn, &b.year,
               &b.copies) == 6) {

      if (strcmp(b.isbn, isbn) == 0) {
        found = 1;
        printf("Updating book with ISBN %s:\n", b.isbn);

        printf("Enter new title: ");
        fgets(b.title, sizeof(b.title), stdin);
        b.title[strcspn(b.title, "\n")] = '\0';

        printf("Enter new author: ");
        fgets(b.author, sizeof(b.author), stdin);
        b.author[strcspn(b.author, "\n")] = '\0';

        printf("Enter new publisher: ");
        fgets(b.publisher, sizeof(b.publisher), stdin);
        b.publisher[strcspn(b.publisher, "\n")] = '\0';

        printf("Enter new year: ");
        scanf("%d", &b.year);
        getchar(); // clear newline

        printf("Enter new copies: ");
        scanf("%d", &b.copies);
        getchar(); // clear newline
      }

      // Write either updated or original book
      fprintf(
          temp,
          "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Copies:-%d\n",
          b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
    }
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("books.txt");
    rename("temp.txt", "books.txt");
    printf("Book updated successfully.\n");
  } else {
    printf("Book with ISBN %s not found.\n", isbn);
    remove("temp.txt");
  }
}
//**********update staff **********/
void update_staff() {
  char id[10];
  printf("Enter ID of the staff to update: ");
  fgets(id, sizeof(id), stdin);
  id[strcspn(id, "\n")] = '\0'; // remove newline

  FILE *f = fopen("staff.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    return;
  }

  char line[512];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    char *id_ptr = strstr(line, "ID:-");
    if (id_ptr) {
      char current_id[10];
      sscanf(id_ptr, "ID:-%[^|]", current_id);

      if (strcmp(current_id, id) == 0) {
        found = 1;
        struct Staff s;
        strcpy(s.id, id); // reuse the same ID

        printf("Updating staff with ID %s:\n", s.id);

        printf("Enter new name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';

        printf("Enter new username: ");
        fgets(s.username, sizeof(s.username), stdin);
        s.username[strcspn(s.username, "\n")] = '\0';

        printf("Enter new email: ");
        fgets(s.email, sizeof(s.email), stdin);
        s.email[strcspn(s.email, "\n")] = '\0';

        printf("Enter new phone: ");
        fgets(s.phone, sizeof(s.phone), stdin);
        s.phone[strcspn(s.phone, "\n")] = '\0';

        fprintf(temp,
                "Name:-%s|ID:-%s|UserName:-%s|Email:-%s|Phone:-%s\n",
                s.name, s.id, s.username, s.email, s.phone);
        continue; // skip writing original line
      }
    }
    fputs(line, temp);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
    printf("Staff with ID %s updated successfully.\n", id);
  } else {
    remove("temp.txt");
    printf("Staff with ID %s not found.\n", id);
  }
}


//**********update student **********/
void update_student() {
  char id[10];
  printf("Enter ID of the student to update: ");
  fgets(id, sizeof(id), stdin);
  id[strcspn(id, "\n")] = '\0';

  FILE *f = fopen("students.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    return;
  }

  char line[1024];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    char current_id[20];

    char *id_ptr = strstr(line, "ID:-");
    if (id_ptr) {
      sscanf(id_ptr, "ID:-%[^|]", current_id);
      if (strcmp(current_id, id) == 0) {
        found = 1;
        struct Student s;
        sscanf(line,
               "Name:-%[^|]|ID:-%[^|]|UserName:-%[^|]|Email:-%[^|]|Phone:-%[^|]|Address:-%[^|]|Age:-%d",
               s.name, s.id, s.username, s.email, s.phone,
               s.address, &s.age);

        char input[100];

        printf("Updating student with ID %s:\n", s.id);

        printf("Enter new name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';

        printf("Enter new username: ");
        fgets(s.username, sizeof(s.username), stdin);
        s.username[strcspn(s.username, "\n")] = '\0';

        printf("Enter new email: ");
        fgets(s.email, sizeof(s.email), stdin);
        s.email[strcspn(s.email, "\n")] = '\0';

        printf("Enter new phone: ");
        fgets(s.phone, sizeof(s.phone), stdin);
        s.phone[strcspn(s.phone, "\n")] = '\0';

        printf("Enter new address: ");
        fgets(s.address, sizeof(s.address), stdin);
        s.address[strcspn(s.address, "\n")] = '\0';

        printf("Enter new age: ");
        fgets(input, sizeof(input), stdin);
        s.age = atoi(input);

        // Write updated record
        fprintf(temp,
                "Name:-%s|ID:-%s|UserName:-%s|Email:-%s|Phone:-%s|Address:-%s|Age:-%d\n",
                s.name, s.id, s.username, s.email, s.phone,
                s.address, s.age);
        continue;
      }
    }
    fputs(line, temp);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("Student updated successfully.\n");
  } else {
    remove("temp.txt");
    printf("Student with ID %s not found.\n", id);
  }
}


//**********show books **********/
void show_book() {
  FILE *f = fopen("books.txt", "r");
  if (!f) {
    printf("No books available.\n");
    return;
  }

  struct Book b;
  printf("\nBooks:\n");
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", b.title, b.author,
                b.publisher, b.isbn, &b.year, &b.copies) == 6) {
    printf("Title: %s | Author: %s | Publisher: %s | ISBN: %s | Year: %d | "
           "Copies: %d\n",
           b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
  }
  fclose(f);
}
/********show staff****** */
void show_staff() {
  FILE *f = fopen("staff.txt", "r");
  if (!f) {
    printf("No staff available.\n");
    return;
  }

  struct Staff s;
  printf("\nStaff:\n");
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n", s.name, s.id,
                s.username, s.password, s.email, s.phone) == 6) {
    printf("Name: %s | ID: %s | Username: %s | Email: %s | Phone: %s\n", s.name,
           s.id, s.username, s.email, s.phone);
  }
  fclose(f);
}
/***************show student************ */
void show_student() {
  FILE *f = fopen("students.txt", "r");
  if (!f) {
    printf("No students available.\n");
    return;
  }

  struct Student s;
  printf("\nStudents:\n");
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d\n", s.name,
                s.id, s.username, s.email, s.phone, s.address,
                &s.age) == 8) {
    printf(
        "Name: %s | ID: %s | Username: %s | Email: %s | Phone: %s | Age: %d\n",
        s.name, s.id, s.username, s.email, s.phone, s.age);
  }
  fclose(f);
}

/*************issue book************* */
// issue book by book name, author, isbn,student name, id,phone.
void issue_book() {
  char book_title[100], book_author[50], book_isbn[20];
  char student_name[50], student_id[10], student_phone[20];

  printf("Enter Book Title: ");
  fgets(book_title, sizeof(book_title), stdin);
  book_title[strcspn(book_title, "\n")] = '\0';

  printf("Enter Book Author: ");
  fgets(book_author, sizeof(book_author), stdin);
  book_author[strcspn(book_author, "\n")] = '\0';

  printf("Enter Book ISBN: ");
  fgets(book_isbn, sizeof(book_isbn), stdin);
  book_isbn[strcspn(book_isbn, "\n")] = '\0';

  printf("Enter Student Name: ");
  fgets(student_name, sizeof(student_name), stdin);
  student_name[strcspn(student_name, "\n")] = '\0';

  printf("Enter Student ID: ");
  fgets(student_id, sizeof(student_id), stdin);
  student_id[strcspn(student_id, "\n")] = '\0';

  printf("Enter Student Phone: ");
  fgets(student_phone, sizeof(student_phone), stdin);
  student_phone[strcspn(student_phone, "\n")] = '\0';

  // --- Validate Book ---
  FILE *f_book = fopen("books.txt", "r");
  FILE *temp_book = fopen("temp_books.txt", "w");
  if (!f_book || !temp_book) {
    printf("Error opening books file.\n");
    return;
  }

  struct Book b;
  int book_found = 0;

  while (fscanf(f_book,
                "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%d|Copies:-%d\n",
                b.title, b.author, b.publisher, b.isbn, &b.year, &b.copies) == 6) {
    if (strcmp(b.title, book_title) == 0 &&
        strcmp(b.author, book_author) == 0 &&
        strcmp(b.isbn, book_isbn) == 0 &&
        b.copies > 0) {
      b.copies--;
      book_found = 1;
    }
    fprintf(temp_book,
            "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Copies:-%d\n",
            b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
  }

  fclose(f_book);
  fclose(temp_book);

  if (!book_found) {
    remove("temp_books.txt");
    printf("Book not found or no copies available.\n");
    return;
  }

  remove("books.txt");
  rename("temp_books.txt", "books.txt");

  // --- Validate Student ---
  FILE *f_student = fopen("students.txt", "r");
  if (!f_student) {
    printf("Error opening students file.\n");
    return;
  }

  struct Student s;
  int student_found = 0;

  while (fscanf(f_student,
                "Name:-%[^|]|ID:-%[^|]|UserName:-%[^|]|Email:-%[^|]|Phone:-%[^|]|Address:-%[^|]|Age:-%d\n",
                s.name, s.id, s.username, s.email, s.phone, s.address, &s.age) == 8) {
    if (strcmp(s.name, student_name) == 0 &&
        strcmp(s.id, student_id) == 0 &&
        strcmp(s.phone, student_phone) == 0) {
      student_found = 1;
      break;
    }
  }

  fclose(f_student);

  if (!student_found) {
    printf("Student not found.\n");
    return;
  }

  // --- Save Issue Record ---
  FILE *f_issue = fopen("issue.txt", "a");
  if (!f_issue) {
    printf("Error opening issue.txt.\n");
    return;
  }

  time_t now = time(NULL);
  fprintf(f_issue, "%s|%s|%s|%s|%s|%s|%ld\n",
          student_name, student_id, student_phone,
          book_title, book_author, book_isbn, now);

  fclose(f_issue);
  printf("Book issued successfully!\n");
}



/***********return book******* */
void return_book() {
  char student_name[50], student_id[10], student_phone[20];
  char book_title[100], book_author[50], book_isbn[20];

  printf("Enter Student Name: ");
  fgets(student_name, sizeof(student_name), stdin);
  student_name[strcspn(student_name, "\n")] = '\0';

  printf("Enter Student ID: ");
  fgets(student_id, sizeof(student_id), stdin);
  student_id[strcspn(student_id, "\n")] = '\0';

  printf("Enter Student Phone: ");
  fgets(student_phone, sizeof(student_phone), stdin);
  student_phone[strcspn(student_phone, "\n")] = '\0';

  printf("Enter Book Title: ");
  fgets(book_title, sizeof(book_title), stdin);
  book_title[strcspn(book_title, "\n")] = '\0';

  printf("Enter Book Author: ");
  fgets(book_author, sizeof(book_author), stdin);
  book_author[strcspn(book_author, "\n")] = '\0';

  printf("Enter Book ISBN: ");
  fgets(book_isbn, sizeof(book_isbn), stdin);
  book_isbn[strcspn(book_isbn, "\n")] = '\0';

  FILE *f = fopen("issue.txt", "r");
  FILE *temp = fopen("temp_issue.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    return;
  }

  struct IssueRecord ir;
  int found = 0;

  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%ld\n",
                ir.student_name, ir.student_id, ir.student_phone,
                ir.book_title, ir.book_author, ir.book_isbn, &ir.issue_date) == 7) {

    if (strcmp(ir.student_name, student_name) == 0 &&
        strcmp(ir.student_id, student_id) == 0 &&
        strcmp(ir.student_phone, student_phone) == 0 &&
        strcmp(ir.book_title, book_title) == 0 &&
        strcmp(ir.book_author, book_author) == 0 &&
        strcmp(ir.book_isbn, book_isbn) == 0) {

      found = 1;
      time_t return_time = time(NULL);
      long days = (return_time - ir.issue_date) / (60 * 60 * 24);
      double fine = (days > 14) ? (days - 14) * 1.0 : 0.0;

      printf("Book returned successfully.\n");
      if (fine > 0) {
        printf("Fine incurred: $%.2f\n", fine);
      } else {
        printf("No fine.\n");
      }

      // Restore book copy
      FILE *fb = fopen("books.txt", "r");
      FILE *ftb = fopen("temp_books.txt", "w");
      struct Book b;
      while (fscanf(fb,
                    "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%d|Copies:-%d\n",
                    b.title, b.author, b.publisher, b.isbn, &b.year, &b.copies) == 6) {
        if (strcmp(b.title, book_title) == 0 &&
            strcmp(b.author, book_author) == 0 &&
            strcmp(b.isbn, book_isbn) == 0) {
          b.copies++;
        }
        fprintf(ftb,
                "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Copies:-%d\n",
                b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
      }
      fclose(fb);
      fclose(ftb);
      remove("books.txt");
      rename("temp_books.txt", "books.txt");

    } else {
      // Keep unmatched records
      fprintf(temp, "%s|%s|%s|%s|%s|%s|%ld\n",
              ir.student_name, ir.student_id, ir.student_phone,
              ir.book_title, ir.book_author, ir.book_isbn, ir.issue_date);
    }
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("issue.txt");
    rename("temp_issue.txt", "issue.txt");
  } else {
    remove("temp_issue.txt");
    printf("Issue record not found.\n");
  }
}

/*************view issue book */
void view_issued_books() {
  FILE *f = fopen("issue.txt", "r");
  if (!f) {
    printf("No issued books available.\n");
    return;
  }

  struct IssueRecord b;
  printf("\nIssued Books:\n");
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    printf("Student ID: %s | Name: %s | Phone: %s | Book ISBN: %s | Issue "
           "Date: %ld | Return Date: %ld | Fine: %.2f\n",
           b.student_id, b.student_name, b.student_phone, b.book_isbn,
           b.issue_date, b.return_date, b.fine);
  }
  fclose(f);
}
/*************show issued record */
void show_issued_record() {
  FILE *f = fopen("issue.txt", "r");
  if (!f) {
    printf("No issued records available.\n");
    return;
  }

  struct IssueRecord b;
  printf("\nIssued Records:\n");
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    printf("Student ID: %s | Name: %s | Phone: %s | Book ISBN: %s | Issue "
           "Date: %ld | Return Date: %ld | Fine: %.2f\n",
           b.student_id, b.student_name, b.student_phone, b.book_isbn,
           b.issue_date, b.return_date, b.fine);
  }
  fclose(f);
}

/*************save issue record */
void save_issue(const struct IssueRecord *b) {
  FILE *f = fopen("issue.txt", "a+");
  if (!f) {
    perror("Failed to open issue file");
    return;
  }
  fprintf(f, "%s|%s|%s|%s|%ld|%ld|%.2f\n", b->student_id, b->student_name,
          b->student_phone, b->book_isbn, b->issue_date, b->return_date,
          b->fine);
  fclose(f);
}
/*************save return record */
void save_return(const struct ReturnRecord *r) {
  FILE *f = fopen("return.txt", "a+");
  if (!f) {
    perror("Failed to open return file");
    return;
  }
  fprintf(f, "%s|%s|%s|%s|%s|%s|%ld|%.2f\n", r->student_id, r->book_isbn,
          r->student_name, r->student_phone, r->book_title, r->book_author,
          r->return_date, r->fine);
  fclose(f);
}
/*************collect fine */
void fine_collect() {
  char student_id[10];
  printf("Enter Student ID to collect fine: ");
  fgets(student_id, sizeof(student_id), stdin);
  student_id[strcspn(student_id, "\n")] = '\0'; // remove newline

  FILE *f = fopen("issue.txt", "r");
  FILE *temp = fopen("temp_issue.txt", "w");
  if (!f || !temp) {
    perror("Failed to open files");
    return;
  }

  struct IssueRecord b;
  int found = 0;
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    if (strcmp(b.student_id, student_id) == 0 && b.fine > 0) {
      found = 1;
      printf("Collecting fine for Student ID %s: $%.2f\n", b.student_id,
             b.fine);
      // Here you can implement the logic to collect the fine
      // For now, we just reset the fine to 0
      b.fine = 0.0;
    }
    fprintf(temp, "%s|%s|%s|%s|%ld|%ld|%.2f\n", b.student_id, b.student_name,
            b.student_phone, b.book_isbn, b.issue_date, b.return_date, b.fine);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("issue.txt");
    rename("temp_issue.txt", "issue.txt");
    printf("Fine collected successfully.\n");
  } else {
    printf("No issue record found for Student ID %s with outstanding fine.\n",
           student_id);
    remove("temp_issue.txt");
  }
}
/*************search records */
void search_records() {
  char keyword[50];
  printf("Enter keyword to search (book title, author, ISBN, student name, ID, "
         "phone): ");
  fgets(keyword, sizeof(keyword), stdin);
  keyword[strcspn(keyword, "\n")] = '\0'; // remove newline

  printf("\nSearching books...\n");
  search_books(keyword);

  printf("\nSearching students...\n");
  search_students(keyword);

  printf("\nSearching staff...\n");
  search_staffs(keyword);
}
