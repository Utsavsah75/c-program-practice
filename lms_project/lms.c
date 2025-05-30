#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>  // For _getch()

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

// === FUNCTION PROTOTYPES ===
void add_student();
void add_staff();
void add_admin();
void staff_register();
int staff_login(char *username);
void staff_dashboard();
void admin_dashboard();
void view_issued_books();
void show_issued_record();
int login();
void get_password(char *password, int max_len);

// === MASKED PASSWORD FUNCTION ===
void get_password(char *password, int max_len) {
    int i = 0;
    char ch;
    while ((ch = _getch()) != '\r' && i < max_len - 1) {
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

// === FUNCTIONS ===

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
    get_password(s.password, sizeof(s.password));

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

    fprintf(f, "Name:-%s|ID:-%s|Username:-%s|Pwd:-%s|E-mail:%s|Phone:-%s|Add:-%s|Age:-%d\n",
            s.name, s.id, s.username, s.password, s.email, s.phone, s.address, s.age);
    fprintf(u, "%s %s student\n", s.username, s.password);
    printf("Student registered successfully with ID: %s\n", s.id);
  }

  fclose(f);
  fclose(u);
}

void staff_register() {
    FILE *f = fopen("staff.txt", "a");
    FILE *u = fopen("users.txt", "a");

    if (!f || !u) {
        printf("Error opening files.\n");
        return;
    }

    char username[50], password[50];
    printf("Register Staff Username: ");
    scanf("%s", username);
    printf("Register Staff Password: ");
    get_password(password, sizeof(password));

    // Check if username already exists
    FILE *check = fopen("staff.txt", "r");
    char file_user[50], file_pass[50];
    while (fscanf(check, "%s %s", file_user, file_pass) != EOF) {
        if (strcmp(username, file_user) == 0) {
            printf("Username already exists. Please choose another.\n");
            fclose(f);
            fclose(u);
            fclose(check);
            return;
        }
    }
    fclose(check);

    // Save to both files
    fprintf(f, "%s %s\n", username, password);
    fprintf(u, "%s %s staff\n", username, password);

    printf("Staff registered successfully.\n");
    fclose(f);
    fclose(u);
}

int staff_login(char *username) {
    char input_user[50], input_pass[50], role[10];
    char stored_user[50], stored_pass[50];

    printf("Staff Login\nUsername: ");
    scanf("%s", input_user);
    printf("Password: ");
    get_password(input_pass, sizeof(input_pass));

    FILE *f = fopen("users.txt", "r");
    if (!f) {
        printf("No users registered yet.\n");
        return 0;
    }

    while (fscanf(f, "%s %s %s", stored_user, stored_pass, role) != EOF) {
        if (strcmp(input_user, stored_user) == 0 &&
            strcmp(input_pass, stored_pass) == 0 &&
            strcmp(role, "staff") == 0) {
            strcpy(username, input_user);
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    printf("Invalid UserName or Password.\n");
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
    get_password(s.password, sizeof(s.password));
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
  get_password(a.password, sizeof(a.password));
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
    getchar();  // Clear newline from input buffer

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
        getchar();  // Clear buffer after reading int

        // Rewind and check if ISBN already exists
        rewind(f);
        while (fscanf(f,"Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%d|Copies:-%d\n",
                      temp.title, temp.author, temp.publisher, temp.isbn,
                      &temp.year, &temp.copies) == 6) {
            if (strcmp(temp.isbn, b.isbn) == 0) {
                exists = 1;
                break;
            }
        }

        if (exists) {
            printf("Book with ISBN %s already exists.\n", b.isbn);
        } else {
            fprintf(f, "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Copies:-%d\n",
                    b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
            printf("Book added successfully!\n");
        }
    }

    fclose(f);
}


void save_issue(const struct issue *b) {
    FILE *f = fopen("issue.txt", "a");
    if (!f) {
        printf("Error opening issue.txt\n");
        return;
    }
    // Consistent save format
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

    time(&b.issue_date); // current time
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
    printf("*****\n");
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
    fprintf(out, "StdID:-%s|StdName:-%s|Phione:-%s|isbn:-%s|I_Date:-%ld|R_Date%ld|Fine%.2f\n", b.student_id, b.student_name,
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


void show_books() {
    FILE *f = fopen("books.txt", "r");
    struct Book b;
    printf("\nBooks:\n");
    if (f) {
        while (fscanf(f, "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%d|Copies:-%d\n",
                      b.title, b.author, b.publisher, b.isbn, &b.year, &b.copies) == 6) {
            printf("Title: %s | Author: %s | Publisher: %s | ISBN: %s | Year: %d | Copies: %d\n",
                   b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
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
        while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d\n",
                      s.name, s.id, s.username, s.password, s.email, s.phone, s.address, &s.age) == 8) {
            printf("Name: %s | ID: %s | Email: %s | Phone: %s | Age: %d\n",
                   s.name, s.id, s.email, s.phone, s.age);
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
        while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n",
                      a.name, a.id, a.username, a.password, a.email, a.phone, a.address) == 7) {
            printf("Name: %s | ID: %s | Email: %s | Phone: %s\n",
                   a.name, a.id, a.email, a.phone);
        }
        fclose(f);
    } else {
        printf("No admins available.\n");
    }
}

void show_details() {
    show_books();
    show_students();
    show_admins();
}


void search_books(const char *keyword) {
    FILE *f = fopen("books.txt", "r");
    if (!f) {
        printf("No books available.\n");
        return;
    }

    struct Book b;
    int found = 0;
    while (fscanf(f, "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%d|Copies:-%d\n",
                  b.title, b.author, b.publisher, b.isbn, &b.year, &b.copies) == 6) {
        if (strstr(b.title, keyword) || strstr(b.author, keyword) || strstr(b.isbn, keyword)) {
            printf("Title: %s | Author: %s | Publisher: %s | ISBN: %s | Year: %d | Copies: %d\n",
                   b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
            found = 1;
        }
    }
    if (!found) {
        printf("No book found with \"%s\".\n", keyword);
    }
    fclose(f);
}

void search_students(const char *keyword) {
    FILE *f = fopen("students.txt", "r");
    if (!f) {
        printf("No students available.\n");
        return;
    }

    struct Student s;
    int found = 0;
    while (fscanf(f, "Name:-%[^|]|ID:-%[^|]|Username:-%[^|]|Pwd:-%[^|]|E-mail:%[^|]|Phone:-%[^|]|Add:-%[^|]|Age:-%d\n",
                  s.name, s.id, s.username, s.password, s.email, s.phone, s.address, &s.age) == 8) {
        if (strstr(s.name, keyword) || strstr(s.id, keyword) ||
            strstr(s.username, keyword) || strstr(s.email, keyword)) {
            printf("Name: %s | ID: %s | Username: %s | Email: %s | Phone: %s | Age: %d\n",
                   s.name, s.id, s.username, s.email, s.phone, s.age);
            found = 1;
        }
    }
    if (!found) {
        printf("No student found with \"%s\".\n", keyword);
    }
    fclose(f);
}

void search_records() {
    int choice;
    printf("\nSearch for:\n1. Books\n2. Students\nChoice: ");
    scanf("%d", &choice);
    getchar(); // consume newline

    char keyword[100];
    if (choice == 1) {
        printf("Search Book by keyword (title, author, or ISBN): ");
    } else if (choice == 2) {
        printf("Search Student by keyword (name, ID, username, or email): ");
    } else {
        printf("Invalid choice.\n");
        return;
    }

    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // remove newline

    if (choice == 1) {
        search_books(keyword);
    } else if (choice == 2) {
        search_students(keyword);
    }
}





void show_issued_record() {
    view_issued_books();
}

int login() {
  char username[50], password[50];
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  get_password(password, sizeof(password));

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
printf("9. Show Books\n10. Show Students\n11. Search Records\n12. Logout\nChoice: ");

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
        search_records();
      return;
    // case 12:
    //     show_issued_record();
    //     break;
    case 12:
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
           "Books\n5. Collect Fine\n6. Show Books\n7. Show Students\n8. Search Records\n9. Show Issued Record\n10. Logout\nChoice: ");

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
      show_books();
      break;
    case 7:
      
      show_students();
      break;
    // case 8:
    //   show_admins();
    //   break;
    case 8: 
      search_records();
      break;
    case 9:
        show_issued_record();
        break;
    case 10:
      printf("\nLogging out.....\n");
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




// void staff_dashboard() {
//     printf("Welcome to the Staff Dashboard!\n");
// }

// void admin_dashboard() {
//     printf("Welcome to the Admin Dashboard!\n");
// }

// === MAIN FUNCTION ===

int main() {
    const char admin_username[] = "admin";
    const char admin_password[] = "admin123";

    char input_username[50], input_password[50];
    int attempts = 3;

    printf("\n********** Library Management System **********\n");

    // Admin login loop
    while (attempts > 0) {
        printf("Admin Login\nUsername: ");
        scanf("%s", input_username);
        printf("Password: ");
        get_password(input_password, sizeof(input_password));

        if (strcmp(input_username, admin_username) == 0 && strcmp(input_password, admin_password) == 0) {
            printf("Admin logged in successfully......!!.\n");
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
