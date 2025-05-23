#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct User {
  char username[50];
  char password[50];
  char role[10]; // admin/staff
};

struct Student {
  char name[50], id[10], username[50], password[50];
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

struct issue {
  char student_id[10], student_name[50], student_phone[20], book_isbn[20];
  time_t issue_date, return_date;
  double fine;
};

struct User currentUser;

// === PROTOTYPES ===
void add_student();
void add_staff();
void add_admin();
void add_book();
void issue_book();
void return_book();
void view_issued_books();
void collect_fine();
void remove_book();
void update_book();
void show_details();
void search_records();
void show_issued_record();

void save_issue(const struct issue *b);
int login();
void admin_dashboard();
void staff_dashboard();

// === IMPLEMENTATION ===

void add_student() {
  int n;
  printf("Number of students to add: ");
  scanf("%d", &n);
  getchar();
  FILE *f = fopen("students.txt", "a+");
  FILE *u = fopen("users.txt", "a+");

  for (int i = 0; i < n; i++) {
    struct Student s;
    printf("\nStudent %d:\n", i + 1);

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    sprintf(s.id, "%d", 1000 + rand() % 9000);

    printf("Enter username: ");
    scanf("%s", s.username);
    printf("Enter password: ");
    scanf("%s", s.password);
    printf("Enter email: ");
    scanf("%s", s.email);
    printf("Enter phone: ");
    scanf("%s", s.phone);
    getchar();
    printf("Enter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%d", &s.age);
    getchar();

    fprintf(f, "%s|%s|%s|%s|%s|%s|%s|%d\n", s.name, s.id, s.username,
            s.password, s.email, s.phone, s.address, s.age);
    fprintf(u, "%s %s student\n", s.username, s.password);
    printf("Student registered successfully with ID: %s\n", s.id);
  }

  fclose(f);
  fclose(u);
}
 






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


void add_staff() {
  int n;
  printf("Number of staff to add: ");
  scanf("%d", &n);
  getchar();

  FILE *f = fopen("staff.txt", "a+");
  FILE *u = fopen("users.txt", "a+");

  for (int i = 0; i < n; i++) {
    struct Staff s;
    printf("\nStaff %d:\n", i + 1);

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    sprintf(s.id, "%d", 2000 + rand() % 9000);

    printf("Enter username: ");
    scanf("%s", s.username);
    printf("Enter password: ");
    scanf("%s", s.password);
    printf("Enter email: ");
    scanf("%s", s.email);
    printf("Enter phone: ");
    scanf("%s", s.phone);
    getchar();
    printf("Enter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    fprintf(f, "%s|%s|%s|%s|%s|%s|%s\n", s.name, s.id, s.username, s.password,
            s.email, s.phone, s.address);
    fprintf(u, "%s %s staff\n", s.username, s.password);
    printf("Staff registered successfully with ID: %s\n", s.id);
  }

  fclose(f);
  fclose(u);
}

void add_admin() {
  struct Admin a;
  FILE *f = fopen("admins.txt", "a+");
  FILE *u = fopen("users.txt", "a+");

  printf("Enter admin name: ");
  getchar();
  fgets(a.name, sizeof(a.name), stdin);
  a.name[strcspn(a.name, "\n")] = '\0';

  sprintf(a.id, "%d", 100 + rand() % 900);

  printf("Enter username: ");
  scanf("%s", a.username);
  printf("Enter password: ");
  scanf("%s", a.password);
  printf("Enter email: ");
  scanf("%s", a.email);
  printf("Enter phone: ");
  scanf("%s", a.phone);
  getchar();
  printf("Enter address: ");
  fgets(a.address, sizeof(a.address), stdin);
  a.address[strcspn(a.address, "\n")] = '\0';

  fprintf(f, "%s|%s|%s|%s|%s|%s|%s\n", a.name, a.id, a.username, a.password,
          a.email, a.phone, a.address);
  fprintf(u, "%s %s admin\n", a.username, a.password);

  printf("Admin registered successfully with ID: %s\n", a.id);
  fclose(f);
  fclose(u);
}

void add_book() {
  int n;
  printf("Number of books to add: ");
  scanf("%d", &n);
  getchar();

  FILE *f = fopen("books.txt", "a+");
  if (!f) {
    printf("Error opening books.txt\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Book b, temp;
    int exists = 0;

    printf("\nBook %d:\n", i + 1);
    printf("Enter title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter publisher: ");
    fgets(b.publisher, sizeof(b.publisher), stdin);
    b.publisher[strcspn(b.publisher, "\n")] = '\0';

    printf("Enter ISBN: ");
    scanf("%s", b.isbn);
    printf("Enter year: ");
    scanf("%d", &b.year);
    printf("Enter copies: ");
    scanf("%d", &b.copies);
    getchar();

    rewind(f);
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", temp.title, temp.author,
                  temp.publisher, temp.isbn, &temp.year, &temp.copies) == 6) {
      if (strcmp(temp.isbn, b.isbn) == 0) {
        exists = 1;
        break;
      }
    }

    if (exists) {
      printf("Book with ISBN %s already exists.\n", b.isbn);
    } else {
      fprintf(f, "%s|%s|%s|%s|%d|%d\n", b.title, b.author, b.publisher, b.isbn,
              b.year, b.copies);
      printf("Book added successfully!\n");
    }
  }

  fclose(f);
}

void save_issue(const struct issue *b) {
  FILE *f = fopen("issue.txt", "a");
  fprintf(f, "%s|%s|%s|%s|%ld|%ld|%.2f\n", b->student_id, b->student_name,
          b->student_phone, b->book_isbn, b->issue_date, b->return_date,
          b->fine);
  fclose(f);
}

void issue_book() {
  struct issue b;
  printf("Enter student ID: ");
  scanf("%s", b.student_id);
  getchar();
  printf("Enter student name: ");
  fgets(b.student_name, sizeof(b.student_name), stdin);
  b.student_name[strcspn(b.student_name, "\n")] = '\0';
  printf("Enter phone: ");
  scanf("%s", b.student_phone);
  printf("Enter book ISBN: ");
  scanf("%s", b.book_isbn);
  time(&b.issue_date);
  b.return_date = 0;
  b.fine = 0.0;

  save_issue(&b);
  printf("Book issued successfully!\n");
}

void return_book() {
  char student_id[10], book_isbn[20];
  printf("Enter student ID: ");
  scanf("%s", student_id);
  printf("Enter book ISBN: ");
  scanf("%s", book_isbn);

  FILE *in = fopen("issue.txt", "r");
  FILE *out = fopen("temp.txt", "w");
  struct issue b;
  time_t now;
  int updated = 0;

  while (fscanf(in, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    if (strcmp(b.student_id, student_id) == 0 &&
        strcmp(b.book_isbn, book_isbn) == 0 && b.return_date == 0) {
      time(&now);
      b.return_date = now;

      // Calculate fine: For example, 2$ per day after 14 days
      double days = difftime(now, b.issue_date) / (60 * 60 * 24);
      if (days > 14)
        b.fine = (days - 14) * 2.0;
      else
        b.fine = 0.0;

      updated = 1;
    }
    fprintf(out, "%s|%s|%s|%s|%ld|%ld|%.2f\n", b.student_id, b.student_name,
            b.student_phone, b.book_isbn, b.issue_date, b.return_date, b.fine);
  }

  fclose(in);
  fclose(out);
  remove("issue.txt");
  rename("temp.txt", "issue.txt");

  if (updated)
    printf("Book returned! Fine due: $%.2f\n", b.fine);
  else
    printf("No matching issue record found or already returned.\n");
}

void view_issued_books() {
  FILE *f = fopen("issue.txt", "r");
  if (!f) {
    printf("No issued books records found.\n");
    return;
  }
  struct issue b;
  printf("\nIssued Books:\n");

  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    printf("Student ID: %s | Name: %s | Phone: %s | ISBN: %s\n", b.student_id,
           b.student_name, b.student_phone, b.book_isbn);
    printf("Issued on: %s", ctime(&b.issue_date));
    if (b.return_date != 0)
      printf("Returned on: %s", ctime(&b.return_date));
    else
      printf("Not returned yet.\n");
    printf("Fine: $%.2f\n", b.fine);
    printf("-----\n");
  }

  fclose(f);
}

void collect_fine() {
  char student_id[10], book_isbn[20];
  printf("Enter student ID for fine collection: ");
  scanf("%s", student_id);
  printf("Enter book ISBN: ");
  scanf("%s", book_isbn);

  FILE *in = fopen("issue.txt", "r");
  FILE *out = fopen("temp.txt", "w");
  struct issue b;
  int found = 0;

  while (fscanf(in, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    if (strcmp(b.student_id, student_id) == 0 &&
        strcmp(b.book_isbn, book_isbn) == 0) {
      if (b.fine > 0) {
        printf("Collected fine $%.2f from student %s.\n", b.fine,
               b.student_name);
        b.fine = 0.0;
        found = 1;
      } else {
        printf("No fine due for this record.\n");
      }
    }
    fprintf(out, "%s|%s|%s|%s|%ld|%ld|%.2f\n", b.student_id, b.student_name,
            b.student_phone, b.book_isbn, b.issue_date, b.return_date, b.fine);
  }
  fclose(in);
  fclose(out);
  remove("issue.txt");
  rename("temp.txt", "issue.txt");

  if (!found)
    printf("No matching record found.\n");
}

void remove_book() {
  char isbn[20];
  printf("Enter ISBN of book to remove: ");
  scanf("%s", isbn);

  FILE *f = fopen("books.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  struct Book b;
  int found = 0;

  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", b.title, b.author,
                b.publisher, b.isbn, &b.year, &b.copies) == 6) {
    if (strcmp(b.isbn, isbn) == 0) {
      found = 1;
      continue; // skip writing this book to temp file
    }
    fprintf(temp, "%s|%s|%s|%s|%d|%d\n", b.title, b.author, b.publisher, b.isbn,
            b.year, b.copies);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("books.txt");
    rename("temp.txt", "books.txt");
    printf("Book with ISBN %s removed successfully.\n", isbn);
  } else {
    printf("Book with ISBN %s not found.\n", isbn);
    remove("temp.txt");
  }
}

void update_book() {
  char isbn[20];
  printf("Enter ISBN of book to update: ");
  scanf("%s", isbn);

  FILE *f = fopen("books.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  struct Book b;
  int found = 0;

  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", b.title, b.author,
                b.publisher, b.isbn, &b.year, &b.copies) == 6) {
    if (strcmp(b.isbn, isbn) == 0) {
      found = 1;
      printf("Updating book: %s\n", b.title);
      getchar();
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

      printf("Enter new copies: ");
      scanf("%d", &b.copies);
      getchar();
    }
    fprintf(temp, "%s|%s|%s|%s|%d|%d\n", b.title, b.author, b.publisher, b.isbn,
            b.year, b.copies);
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

void show_details() {
  printf("Books:\n");
  FILE *f = fopen("books.txt", "r");
  struct Book b;
  if (f) {
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", b.title, b.author,
                  b.publisher, b.isbn, &b.year, &b.copies) == 6) {
      printf("%s | %s | %s | %s | %d | Copies: %d\n", b.title, b.author,
             b.publisher, b.isbn, b.year, b.copies);
    }
    fclose(f);
  } else {
    printf("No books available.\n");
  }

  printf("\nStudents:\n");
  f = fopen("students.txt", "r");
  struct Student s;
  if (f) {
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d\n", s.name,
                  s.id, s.username, s.password, s.email, s.phone, s.address,
                  &s.age) == 8) {
      printf("%s | ID: %s | Email: %s | Phone: %s | Age: %d\n", s.name, s.id,
             s.email, s.phone, s.age);
    }
    fclose(f);
  } else {
    printf("No students available.\n");
  }

  printf("\nAdmins:\n");
  f = fopen("admins.txt", "r");
  struct Admin a;
  if (f) {
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n", a.name,
                  a.id, a.username, a.password, a.email, a.phone,
                  a.address) == 7) {
      printf("%s | ID: %s | Email: %s | Phone: %s\n", a.name, a.id, a.email,
             a.phone);
    }
    fclose(f);
  } else {
    printf("No admins available.\n");
  }
}

void show_books() {
    FILE *f = fopen("books.txt", "r");
    struct Book b;
    printf("\nBooks:\n");
    if (f) {
        while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", b.title, b.author,
                      b.publisher, b.isbn, &b.year, &b.copies) == 6) {
            printf("%s | %s | %s | %s | %d | Copies: %d\n", b.title, b.author,
                   b.publisher, b.isbn, b.year, b.copies);
        }
        fclose(f);
    } else {
        printf("No books available.\n");
    }
}

void show_students() {
    FILE *f = fopen("students.txt", "r");
    struct Student s;
    printf("\nStudents:\n");
    if (f) {
        while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d\n", s.name,
                      s.id, s.username, s.password, s.email, s.phone, s.address,
                      &s.age) == 8) {
            printf("%s | ID: %s | Email: %s | Phone: %s | Age: %d\n", s.name, s.id,
                   s.email, s.phone, s.age);
        }
        fclose(f);
    } else {
        printf("No students available.\n");
    }
}

void show_admins() {
    FILE *f = fopen("admins.txt", "r");
    struct Admin a;
    printf("\nAdmins:\n");
    if (f) {
        while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n", a.name,
                      a.id, a.username, a.password, a.email, a.phone,
                      a.address) == 7) {
            printf("%s | ID: %s | Email: %s | Phone: %s\n", a.name, a.id, a.email,
                   a.phone);
        }
        fclose(f);
    } else {
        printf("No admins available.\n");
    }
}

void search_records() {
  int choice;
  printf("Search for:\n1. Books\n2. Admins\n3. Students\nChoice: ");
  scanf("%d", &choice);
  getchar();

  char keyword[100];
  printf("Enter keyword: ");
  fgets(keyword, sizeof(keyword), stdin);
  keyword[strcspn(keyword, "\n")] = '\0';

  FILE *f;
  int found = 0;
  if (choice == 1) {
    f = fopen("books.txt", "r");
    struct Book b;
    if (!f) {
      printf("No books available.\n");
      return;
    }
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", b.title, b.author,
                  b.publisher, b.isbn, &b.year, &b.copies) == 6) {
      if (strstr(b.title, keyword) || strstr(b.author, keyword) ||
          strstr(b.isbn, keyword)) {
        printf("%s | %s | %s | %s | %d | Copies: %d\n", b.title, b.author,
               b.publisher, b.isbn, b.year, b.copies);
        found = 1;
      }
    }
    fclose(f);
  } else if (choice == 2) {
    f = fopen("admins.txt", "r");
    struct Admin a;
    if (!f) {
      printf("No admins available.\n");
      return;
    }
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n", a.name,
                  a.id, a.username, a.password, a.email, a.phone,
                  a.address) == 7) {
      if (strstr(a.name, keyword) || strstr(a.id, keyword) ||
          strstr(a.username, keyword)) {
        printf("%s | ID: %s | Email: %s | Phone: %s\n", a.name, a.id, a.email,
               a.phone);
        found = 1;
      }
    }
    fclose(f);
  } else if (choice == 3) {
    f = fopen("students.txt", "r");
    struct Student s;
    if (!f) {
      printf("No students available.\n");
      return;
    }
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d\n", s.name,
                  s.id, s.username, s.password, s.email, s.phone, s.address,
                  &s.age) == 8) {
      if (strstr(s.name, keyword) || strstr(s.id, keyword) ||
          strstr(s.username, keyword)) {
        printf("%s | ID: %s | Email: %s | Phone: %s | Age: %d\n", s.name, s.id,
               s.email, s.phone, s.age);
        found = 1;
      }
    }
    fclose(f);
  } else {
    printf("Invalid choice.\n");
    return;
  }

  if (!found) {
    printf("No records found matching \"%s\".\n", keyword);
  }
}

void show_issued_record() { view_issued_books(); }

int login() {
  char username[50], password[50];
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  FILE *f = fopen("users.txt", "r");
  if (!f) {
    printf("No users registered yet.\n");
    return 0;
  }

  char user[50], pass[50], role[10];
  while (fscanf(f, "%s %s %s\n", user, pass, role) != EOF) {
    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
      strcpy(currentUser.username, username);
      strcpy(currentUser.password, password);
      strcpy(currentUser.role, role);
      fclose(f);
      return 1;
    }
  }
  fclose(f);
  printf("Invalid username or password.\n");
  return 0;
}

void admin_dashboard() {
  int choice;
  while (1) {
    printf("\n--- Admin Dashboard ---\n");
    printf("1. Add Book\n2. Issue Book\n3. Return Book\n4. View All Issued "
           "Books\n");
    printf("5. Add Staff\n6. Add Student\n7. Remove Book\n8. Update Book\n");
// Inside admin_dashboard()
printf("9. Show Books\n10. Show Students\n11. Show Admins\n12. Search Records\n13. Show Issued Record\n14. Logout\nChoice: ");

    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1:
      add_book();
      break;
    case 2:
      issue_book();
      break;
    case 3:
      return_book();
      break;
    case 4:
      view_issued_books();
      break;
    case 5:
      add_staff();
      break;
    case 6:
      add_student();
      break;
    case 7:
      remove_book();
      break;
    case 8:
      update_book();
      break;
    case 9:
      show_books();
      break;
    case 10:
      show_students();
      break;
    case 11:
      show_admins();
      break;
    case 12:
        search_records();
      return;
    case 13:
        show_issued_record();
        break;
    case 14:
      printf("Logging out...\n");
      return;
    default:
      printf("Invalid choice.\n");
    }
  }
}

void staff_dashboard() {
  int choice;
  while (1) {
    printf("\n--- Staff Dashboard ---\n");
    printf("1. Add Book\n2. Issue Book\n3. Return Book\n4. View All Issued "
           "Books\n5. Collect Fine\n6. Show Books\n7. Show Students\n8. Show Admins\n9. Search Records\n10. Show Issued Record\n11. Logout\nChoice: ");

    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1:
      add_book();
      break;
    case 2:
      issue_book();
      break;
    case 3:
      return_book();
      break;
    case 4:
      view_issued_books();
      break;
    case 5:
      collect_fine();
      break;
    case 6:
      show_details();
      break;
    case 7:
      search_records();
      break;
    case 8:
      show_issued_record();
      break;
    case 9:
      return;
    default:
      printf("Invalid choice.\n");
    }
  }
}
// void admin_dashboard();
void staff_register();
int staff_login(char *username);
void staff_dashboard();

int main() {
    const char admin_username[] = "admin";
    const char admin_password[] = "admin123";

    char input_username[50], input_password[50];
    int attempts = 3;

    printf("=== Library Management System ===\n");

    // Admin login loop
    while (attempts > 0) {
        printf("Admin Login\nUsername: ");
        scanf("%s", input_username);
        printf("Password: ");
        scanf("%s", input_password);

        if (strcmp(input_username, admin_username) == 0 && strcmp(input_password, admin_password) == 0) {
            printf("Admin logged in successfully.\n");
            break;
        } else {
            attempts--;
            printf("Invalid credentials. Attempts left: %d\n", attempts);
        }
    }

    if (attempts == 0) {
        printf("Too many failed attempts. Exiting...\n");
        return 1;
    }

    int choice;
    char staff_username[50];

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
