#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
struct User {
  char username[50];
  char password[50];
  char role[10]; // admin/student
};

struct Student {
  char name[50], id[10], username[50], password[50];
  char email[50], phone[15], address[100];
  int age;
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
};

struct User currentUser;

// Prototypes
void add_student();
void add_admin();
void add_book();
void issue_book();
void return_book();
void view_issued_books();
void check_student_issue_record();
void save_issue(const struct issue *b);
int login();
void dashboard();

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

    sprintf(s.id, "%d", 100 + i); // Auto ID from 100

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

void add_admin() {
  struct Admin a;
  FILE *f = fopen("admins.txt", "a+");
  FILE *u = fopen("users.txt", "a+");

  printf("Enter admin name: ");
  getchar();
  fgets(a.name, sizeof(a.name), stdin);
  a.name[strcspn(a.name, "\n")] = '\0';

  sprintf(a.id, "%d", rand() % 1000 + 100); // Auto ID

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
  fprintf(f, "%s|%s|%s|%s|%ld|%ld\n", b->student_id, b->student_name,
          b->student_phone, b->book_isbn, b->issue_date, b->return_date);
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

  save_issue(&b);
  printf("Book issued!\n");
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

  while (fscanf(in, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date) == 6) {
    if (strcmp(b.student_id, student_id) == 0 &&
        strcmp(b.book_isbn, book_isbn) == 0 && b.return_date == 0) {
      time(&now);
      b.return_date = now;
      updated = 1;
    }
    fprintf(out, "%s|%s|%s|%s|%ld|%ld\n", b.student_id, b.student_name,
            b.student_phone, b.book_isbn, b.issue_date, b.return_date);
  }

  fclose(in);
  fclose(out);
  remove("issue.txt");
  rename("temp.txt", "issue.txt");

  if (updated)
    printf("Book returned!\n");
  else
    printf("No matching issue record found or already returned.\n");
}

void view_issued_books() {
  FILE *f = fopen("issue.txt", "r");
  struct issue b;
  printf("\nIssued Books:\n");

  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date) == 6) {
    printf("Student ID: %s | Name: %s | Phone: %s | ISBN: %s\n", b.student_id,
           b.student_name, b.student_phone, b.book_isbn);
    printf("Issued on: %s", ctime(&b.issue_date));
    if (b.return_date != 0)
      printf("Returned on: %s", ctime(&b.return_date));
    else
      printf("Not returned yet.\n");
    printf("-----\n");
  }

  fclose(f);
}

void check_student_issue_record() {
  char sid[10], name[50], phone[20], isbn[20];
  int found = 0;
  printf("Enter Student ID: ");
  scanf("%s", sid);
  getchar();
  printf("Enter Name: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0';
  printf("Enter Phone: ");
  scanf("%s", phone);
  printf("Enter Book ISBN: ");
  scanf("%s", isbn);

  FILE *f = fopen("issue.txt", "r");
  struct issue b;
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date) == 6) {
    if (strcmp(b.student_id, sid) == 0 && strcmp(b.student_name, name) == 0 &&
        strcmp(b.student_phone, phone) == 0 && strcmp(b.book_isbn, isbn) == 0) {
      found = 1;
      break;
    }
  }
  fclose(f);

  if (found)
    printf("Student record found in issued list.\n");
  else
    printf("Student not found.\n");
}

int login() {
  char uname[50], pass[50], u[50], p[50], role[10];
  FILE *f = fopen("users.txt", "r");

  printf("Username: ");
  scanf("%s", uname);
  printf("Password: ");
  scanf("%s", pass);

  while (fscanf(f, "%s %s %s", u, p, role) != EOF) {
    if (strcmp(uname, u) == 0 && strcmp(pass, p) == 0) {
      strcpy(currentUser.username, u);
      strcpy(currentUser.password, p);
      strcpy(currentUser.role, role);
      fclose(f);
      return 1;
    }
  }

  fclose(f);
  return 0;
}

void dashboard() {
  int choice;
  while (1) {
    printf("\n--- %s Dashboard ---\n", currentUser.role);
    if (strcmp(currentUser.role, "admin") == 0) {
      printf("1. Add Book\n2. Add Student\n3. View Issued\n4. Issue Book\n5. "
             "Return Book\n6. Check Issued Record\n7. Logout\nChoice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        add_book();
        break;
      case 2:
        add_student();
        break;
      case 3:
        view_issued_books();
        break;
      case 4:
        issue_book();
        break;
      case 5:
        return_book();
        break;
      case 6:
        check_student_issue_record();
        break;
      case 7:
        return;
      default:
        printf("Invalid!\n");
      }
    } else {
      printf("1. Issue Book\n2. Return Book\n3. View Issued\n4. Check Issued "
             "Record\n5. Logout\nChoice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        issue_book();
        break;
      case 2:
        return_book();
        break;
      case 3:
        view_issued_books();
        break;
      case 4:
        check_student_issue_record();
        break;
      case 5:
        return;
      default:
        printf("Invalid!\n");
      }
    }
  }
}

int main() {
  srand(time(NULL));
  int choice;
  while (1) {
    printf("\n=== Library Management ===\n");
    printf("1. Login\n2. Register\n3. Exit\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      if (login())
        dashboard();
      else
        printf("Login failed!\n");
      break;
    case 2:
      printf("1. Admin\n2. Student\nChoice: ");
      scanf("%d", &choice);
      if (choice == 1)
        add_admin();
      else if (choice == 2)
        add_student();
      else
        printf("Invalid!\n");
      break;
    case 3:
      printf("Goodbye!\n");
      exit(0);
    default:
      printf("Invalid!\n");
    }
  }
}
