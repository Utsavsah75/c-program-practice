#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_BOOKS 100
#define MAX_STUDENTS 100
#define MAX_BORROWS 100
#define USER_FILE "user.txt"

typedef struct {
  char username[50];
  char password[50];
  char role[10];
} User;

typedef struct {
  char name[100];
  char roll[20];
  char faculty[50];
} Student;

typedef struct {
  char title[100];
  char author[100];
  int book_number;
  int total_copies;
  int issued;
  char issued_to[20];
} Book;

typedef struct {
  int book_number;
  char roll[20];
  char issue_date[20];
} Borrow;

User users[MAX_USERS];
Student students[MAX_STUDENTS];
Book books[MAX_BOOKS];
Borrow borrows[MAX_BORROWS];

int user_count = 0, student_count = 0, book_count = 0, borrow_count = 0;

void save_all_data_to_file() {
  FILE *fp = fopen(USER_FILE, "w");
  if (!fp)
    return;

  for (int i = 0; i < user_count; i++)
    fprintf(fp, "USER,%s,%s,%s\n", users[i].username, users[i].password,
            users[i].role);

  for (int i = 0; i < student_count; i++)
    fprintf(fp, "STUDENT,%s,%s,%s\n", students[i].name, students[i].roll,
            students[i].faculty);

  for (int i = 0; i < book_count; i++)
    fprintf(fp, "BOOK,%s,%s,%d,%d,%d,%s\n", books[i].title, books[i].author,
            books[i].book_number, books[i].total_copies, books[i].issued,
            books[i].issued_to);

  for (int i = 0; i < borrow_count; i++)
    fprintf(fp, "BORROW,%d,%s,%s\n", borrows[i].book_number, borrows[i].roll,
            borrows[i].issue_date);

  fclose(fp);
}

void load_all_data_from_file() {
  FILE *fp = fopen(USER_FILE, "r");
  if (!fp)
    return;

  char line[256];
  while (fgets(line, sizeof(line), fp)) {
    if (strncmp(line, "USER", 4) == 0) {
      sscanf(line, "USER,%[^,],%[^,],%s", users[user_count].username,
             users[user_count].password, users[user_count].role);
      user_count++;
    } else if (strncmp(line, "STUDENT", 7) == 0) {
      sscanf(line, "STUDENT,%[^,],%[^,],%s", students[student_count].name,
             students[student_count].roll, students[student_count].faculty);
      student_count++;
    } else if (strncmp(line, "BOOK", 4) == 0) {
      sscanf(line, "BOOK,%[^,],%[^,],%d,%d,%d,%s", books[book_count].title,
             books[book_count].author, &books[book_count].book_number,
             &books[book_count].total_copies, &books[book_count].issued,
             books[book_count].issued_to);
      book_count++;
    } else if (strncmp(line, "BORROW", 6) == 0) {
      sscanf(line, "BORROW,%d,%[^,],%s", &borrows[borrow_count].book_number,
             borrows[borrow_count].roll, borrows[borrow_count].issue_date);
      borrow_count++;
    }
  }
  fclose(fp);
}

void mask_input(char *str) {
  int i = 0;
  char ch;
  while ((ch = _getch()) != 13) {
    if (ch == 8 && i > 0) {
      printf("\b \b");
      i--;
    } else if (ch != 8) {
      str[i++] = ch;
      printf("*");
    }
  }
  str[i] = '\0';
  printf("\n");
}

void register_user() {
  User newUser;
  printf("Enter username: ");
  fgets(newUser.username, 50, stdin);
  newUser.username[strcspn(newUser.username, "\n")] = '\0';

  printf("Enter password: ");
  mask_input(newUser.password);

  printf("Select role (1 = Admin, 2 = Student): ");
  char role_choice = getchar();
  getchar();
  if (role_choice == '1')
    strcpy(newUser.role, "admin");
  else if (role_choice == '2')
    strcpy(newUser.role, "student");
  else {
    printf("Invalid role!\n");
    return;
  }

  for (int i = 0; i < user_count; i++) {
    if (strcmp(users[i].username, newUser.username) == 0) {
      printf("Username already exists!\n");
      return;
    }
  }

  users[user_count++] = newUser;
  save_all_data_to_file();
  printf("Registration successful!\n");
}

void add_students() {
  int n;
  printf("Number of students to add: ");
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    Student s;
    printf("\nStudent: %d\n", i + 1);
    printf("Name: ");
    fgets(s.name, 100, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Roll No: ");
    fgets(s.roll, 20, stdin);
    s.roll[strcspn(s.roll, "\n")] = '\0';
    printf("Faculty: ");
    fgets(s.faculty, 50, stdin);
    s.faculty[strcspn(s.faculty, "\n")] = '\0';
    students[student_count++] = s;
  }
  save_all_data_to_file();
}

void view_students() {
  printf("\n--- Student List ---\n");
  for (int i = 0; i < student_count; i++)
    printf("%s - %s - %s\n", students[i].name, students[i].roll,
           students[i].faculty);
}

void add_books() {
  int n;
  printf("Number of books to add: ");
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    Book b;
    printf("\nBook %d\n", i + 1);
    printf("Title: ");
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    printf("Author: ");
    fgets(b.author, 100, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("Book Number: ");
    scanf("%d", &b.book_number);
    getchar();
    printf("Total copies: ");
    scanf("%d", &b.total_copies);
    getchar();
    b.issued = 0;
    strcpy(b.issued_to, "none");
    books[book_count++] = b;
  }
  save_all_data_to_file();
}

void view_books() {
  printf("\n\t\t==== Book List ====\n");
  for (int i = 0; i < book_count; i++) {
    printf("%s \t| %s \t| #%d \t| Available: %d/%d\n", books[i].title,
           books[i].author, books[i].book_number,
           books[i].total_copies - books[i].issued, books[i].total_copies);
  }
}

void get_current_date(char *buf) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(buf, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday); // 
}

void issue_book() {
  view_books();
  int num;
  char roll[20];
  printf("Enter Book Number: ");
  scanf("%d", &num);
  getchar();
  printf("Enter Student Roll No: ");
  fgets(roll, 20, stdin);
  roll[strcspn(roll, "\n")] = '\0';

  for (int i = 0; i < book_count; i++) {
    if (books[i].book_number == num &&
        books[i].issued < books[i].total_copies) {
      books[i].issued++;
      strcpy(books[i].issued_to, roll);
      borrows[borrow_count].book_number = num;
      strcpy(borrows[borrow_count].roll, roll);
      get_current_date(borrows[borrow_count].issue_date);
      borrow_count++;
      printf("Book issued.\n");
      save_all_data_to_file();
      return;
    }
  }
  printf("Book not available.\n");
}

void return_book() {
  int num;
  printf("Enter Book Number to return: ");
  scanf("%d", &num);
  getchar();
  for (int i = 0; i < book_count; i++) {
    if (books[i].book_number == num && books[i].issued > 0) {
      books[i].issued--;
      printf("Book returned.\n");
      save_all_data_to_file();
      return;
    }
  }
  printf("Book not found or not issued.\n");
}

void borrow_book_student(const char *roll) {
  issue_book(); // reuse
}

void return_book_student(const char *roll) {
  return_book(); // reuse
}

void search_book() {
  char search[100];
  printf("Enter title/author: ");
  fgets(search, 100, stdin);
  search[strcspn(search, "\n")] = '\0';
  for (int i = 0; i < book_count; i++) {
    if (strstr(books[i].title, search) || strstr(books[i].author, search)) {
      printf("%s by %s - #%d\n", books[i].title, books[i].author,
             books[i].book_number);
    }
  }
}

void search_borrowed_book(const char *roll) {
  printf("Borrowed Books:\n");
  for (int i = 0; i < borrow_count; i++) {
    if (strcmp(borrows[i].roll, roll) == 0) {
      printf("Book #%d issued on %s\n", borrows[i].book_number,
             borrows[i].issue_date);
    }
  }
}

void show_statistics() {
  int total_issued = 0;
  for (int i = 0; i < book_count; i++)
    total_issued += books[i].issued;
  printf("Total Books: %d\nBooks Issued: %d\nStudents: %d\n", book_count,
         total_issued, student_count);
}

void dashboard(const char *role, const char *username) {
  int choice;
  char roll[20];
  if (strcmp(role, "student") == 0)
    strcpy(roll, username);
  while (1) {
    printf("\n=== %s Dashboard ===\n", role);
    if (strcmp(role, "admin") == 0) {
      printf("1. Add Book(s)\n2. View Books\n3. Issue Book\n4. Return Book\n");
      printf("5. Add Student(s)\n6. View Students\n7. Search Book\n8. "
             "Stats\n0. Logout\nChoice: ");
      scanf("%d", &choice);
      getchar();
      switch (choice) {
      case 1:
        add_books();
        break;
      case 2:
        view_books();
        break;
      case 3:
        issue_book();
        break;
      case 4:
        return_book();
        break;
      case 5:
        add_students();
        break;
      case 6:
        view_students();
        break;
      case 7:
        search_book();
        break;
      case 8:
        show_statistics();
        break;
      case 0:
        return;
      default:
        printf("Invalid!\n");
      }
    } else {
      printf("1. Borrow Book(s)\n2. View Total Books\n3. Returning Books\n4. Search Borrowed Book\n0. Logout\nChoice: ");
      scanf("%d", &choice);
      getchar();
      switch (choice) {
      case 1:
        borrow_book_student(roll);
        break;
      case 2:
        view_books();
        break;
      case 3:
        return_book_student(roll);
        break;
      case 4:
        search_borrowed_book(roll);
        break;
      case 0:
        return;
      default:
        printf("Invalid!\n");
      }
    }
  }
}

void login_user() {
  char username[50], password[50];
  printf("Username: ");
  fgets(username, 50, stdin);
  username[strcspn(username, "\n")] = '\0';
  printf("Password: ");
  mask_input(password);
  for (int i = 0; i < user_count; i++) {
    if (strcmp(users[i].username, username) == 0 &&
        strcmp(users[i].password, password) == 0) {
      dashboard(users[i].role, username);
      return;
    }
  }
  printf("Invalid login.\n");
}

int main() {
  load_all_data_from_file();
  int choice;
  while (1) {
    printf("\nLibrary Management System\n1. Register\n2. Login\n3. "
           "Exit\nChoice: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1)
      register_user();
    else if (choice == 2)
      login_user();
    else if (choice == 3)
      break;
    else
      printf("Invalid!\n");
  }
  return 0;
}
