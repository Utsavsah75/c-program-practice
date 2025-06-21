#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct User {
  char username[50];
  char role[10];
};
struct Student {
  char name[50], id[10];
  char email[50], phone[15], address[100];
  int age;
};
struct Staff {
  int age;
  char name[50], id[10], password[50];
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
        printf("\t\t\t\t\b \b");
      }
    } else {
      password[i++] = ch;
      printf("*");
    }
  }
  password[i] = '\0';
  printf("\t\t\t\t\n");
}

struct User current_user; // global variable

int main() {
  char username[50], password[50];
  int attempts = 3;
  const char admin_username[] = "a";
  const char admin_password[] = "a";

  system("cls");
  printf("\t\t\t\t################################################################");
  printf("\n\t\t\t\t############                                        ############");
  printf("\n\t\t\t\t############ Library management System Project in C ############");
  printf("\n\t\t\t\t############                                        ############");
  printf("\n\t\t\t\t################################################################");
  printf("\n\t\t\t\t----------------------------------------------------------------\n");

  while (attempts-- > 0) {
    printf("\t\t\t\t\t\t\tAdmin Login");
    printf("\n\t\t\t\t----------------------------------------------------------------");

    printf("\n\t\t\t\tUsername: ");
    scanf("%49s", username);
    printf("\t\t\t\tPassword: ");
    getchar(); // clear newline
    get_password(password, sizeof(password));

    if (strcmp(username, admin_username) == 0 &&
        strcmp(password, admin_password) == 0) {
      printf("\t\t\t\tLogin successful!\n");
      strcpy(current_user.username, username);
      strcpy(current_user.role, "admin");
      admin_dashboard(); // You must define this
      return 0;
    }
    printf("\t\t\t\tInvalid credentials. You have %d attempts left.\n", attempts);
  }

  printf("Too many failed attempts. Exiting...\n");
  return 1;
}

void admin_dashboard() {
  int choice;

  while (1) {

             printf("\n\t\t\t\t----------------------------------------------------------------\n");
             printf("\t\t\t\t\t\t\tAdmin Dashboard");
             printf("\n\t\t\t\t----------------------------------------------------------------\n");



    printf("\t\t\t\t1.Add Book\n");
    printf("\t\t\t\t2.Add Student\n");
    printf("\t\t\t\t3.Add Staff\n");
    printf("\t\t\t\t4.Remove Record\n");
    printf("\t\t\t\t5.Update Record\n");
    printf("\t\t\t\t6.Search Record\n");
    printf("\t\t\t\t7.Show Records\n");
    printf("\t\t\t\t8.Issue Book\n");
    printf("\t\t\t\t9.Return Book\n");
    printf("\t\t\t\t10.Show Issued Records\n");
    printf("\t\t\t\t11.Logout\n");
    printf("\t\t\t\tEnter your choice: ");

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
      issue_book();
      break;
    case 9:
      return_book();
      break;
    case 10:
      show_issued_record();
      break;
    case 11:
      printf("Logging out...\n");
      return;
    default:
      printf("Invalid choice. Try again.\n");
    }
  }
}
/*=====================Adding part ======================================*/
void add_book() {
  int n;
  printf("\t\t\t\tNumber of books to add: ");
  scanf("%d", &n);
  getchar(); // clear newline

  FILE *f = fopen("books.txt", "a+");
  if (!f) {
    perror("Failed to open books file");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Book b;
    
    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t Enter Book Detail Of %d", i + 1);
    printf("\n\t\t\t\t----------------------------------------------------------------\n");

    printf("\t\t\t\tEnter Book Name: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // remove newline

    printf("\t\t\t\tEnter author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("\t\t\t\tEnter publisher: ");
    fgets(b.publisher, sizeof(b.publisher), stdin);
    b.publisher[strcspn(b.publisher, "\n")] = '\0';

    printf("\t\t\t\tEnter ISBN: ");
    fgets(b.isbn, sizeof(b.isbn), stdin);
    b.isbn[strcspn(b.isbn, "\n")] = '\0';

    printf("\t\t\t\tEnter year: ");
    scanf("%d", &b.year);
    getchar(); // clear newline

    printf("\t\t\t\tNumber of Books: ");
    scanf("%d", &b.copies);
    getchar(); // clear newline

    fprintf(f,
            "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Number of "
            "Books:-%d\n",
            b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
  }

  fclose(f);
  printf("\t\t\t\t\t\tBooks added successfully.\n");
}
void add_staff() {
  int n;
  printf("\n\t\t\t\tNumber of staff to add: ");
  scanf("%d", &n);
  getchar(); // clear newline

  FILE *f = fopen("staff.txt", "a+");
  if (!f) {
    perror("Failed to open staff file");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Staff s;

    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t     Enter Staff Detail Of %d:", i + 1);
    printf("\n\t\t\t\t----------------------------------------------------------------\n");



    printf("\t\t\t\tEnter Staff Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    sprintf(s.id, "STF%d", 1000 + rand() % 9000);

    printf("\t\t\t\tEnter email: ");
    fgets(s.email, sizeof(s.email), stdin);
    s.email[strcspn(s.email, "\n")] = '\0';

    printf("\t\t\t\tEnter password: ");
    get_password(s.password, sizeof(s.password));

    printf("\t\t\t\tEnter phone: ");
    fgets(s.phone, sizeof(s.phone), stdin);
    s.phone[strcspn(s.phone, "\n")] = '\0';

    printf("\t\t\t\tEnter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    printf("\t\t\t\tEnter age: ");
    scanf("%d", &s.age);
    getchar(); // clear newline

    fprintf(f,
            "Name:-%s|ID:-%s|Password:-%s|Email:-%s|Phone:-%s|Address:-%s|Age:-"
            "%d\n",
            s.name, s.id, s.password, s.email, s.phone, s.address, s.age);
    printf("\n\t\t\t\t\t------ Staff added successfully with ID: %s------\n", s.id);
  }

  fclose(f);
}
void add_student() {
  int n;
  printf("\t\t\t\tNumber of students to add: ");
  scanf("%d", &n);
  getchar(); // Clear newline left by scanf

  FILE *f = fopen("students.txt", "a+");
  FILE *u = fopen("users.txt", "a+");

  if (f == NULL || u == NULL) {
    printf("\t\t\t\tError opening file.\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    struct Student s;


    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t Enter Student Detail Of %d:", i + 1);
    printf("\n\t\t\t\t----------------------------------------------------------------\n");

    printf("\t\t\t\tEnter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    // Generate random ID
    sprintf(s.id, "STD%d", 1000 + rand() % 9000);

    printf("\t\t\t\tEnter email: ");
    scanf("%s", s.email);

    printf("\t\t\t\tEnter phone: ");
    scanf("%s", s.phone);
    getchar(); // Clear newline

    printf("\t\t\t\tEnter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    printf("\t\t\t\tEnter age: ");
    scanf("%d", &s.age);
    getchar(); // Clear newline

    // Write student record
    fprintf(f, "Name:-%s|ID:-%s|Email:-%s|Phone:-%s|Address:-%s|Age:-%d\n",
            s.name, s.id, s.email, s.phone, s.address, s.age);

    // Save to user credentials file (optional)
    fprintf(u, "%s|%s|student\n", s.name);

    printf("\n\t\t\t\t\t Student added successfully with ID: %s\n", s.id);
  }

  fclose(f);
  fclose(u);
}
/*===================== Remove part=========================================*/
void remove_record() {
  int choice;

  printf(
      "\n\t\t\t\t-------------------------------------------------------------");
  printf("\n\t\t\t\t\t\t Remove Record Menu \n");
  printf("\t\t\t\t-------------------------------------------------------------\n");
  printf("\t\t\t\t1. Remove Book\n");
  printf("\t\t\t\t2. Remove Student\n");
  printf("\t\t\t\t3. Remove Staff\n");
  printf("\t\t\t\t0. Cancel\n");
  printf("\t\t\t\tEnter your choice: ");
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
    printf("\t\t\t\t\tInvalid choice. Try again.\n");
  }
}
void remove_book() {
  char isbn[20];
  printf("\t\t\t\tEnter ISBN of the book to remove: ");
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
      printf("\t\t\t\t------Book with ISBN %s removed successfully.------\n", isbn);
    }
  } else {
    printf("\t\t\t\tNo book found with ISBN %s.\n", isbn);
    remove("temp.txt");
  }
}
//**********remove staff **********/
void remove_staff() {
  char id[10];
  printf("\t\t\t\tEnter ID of the staff to remove: ");
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
    printf("\t\t\t\tStaff with ID %s removed successfully.\n", id);
  } else {
    remove("temp.txt");
    printf("\t\t\t\tNo staff found with ID %s.\n", id);
  }
}
//**********remove student **********/
void remove_student() {
  char id[10];
  printf("\t\t\t\tEnter ID of the students to remove: ");
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
    printf("\t\t\t\t------ student with ID %s removed successfully.------\n", id);
  } else {
    remove("temp.txt");
    printf("\t\t\t\tNo students found with ID %s.\n", id);
  }
}
/*======================= Update part=========================================*/
void update_record() {
  int choice;
        printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t Update Record Menu");
    printf("\n\t\t\t\t----------------------------------------------------------------\n");
  printf("\t\t\t\t1. Update Book\n");
  printf("\t\t\t\t2. Update Student\n");
  printf("\t\t\t\t3. Update Staff\n");
  printf("\t\t\t\t0. Cancel\n");
  printf("\t\t\t\tEnter your choice: ");
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
    printf("\t\t\t\tInvalid choice. Try again.\n");
  }
}
//**********update book **********/
void update_book() {
  char isbn[20];
  printf("\t\t\t\tEnter ISBN of the book to update: ");
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
               "d|Number of Books:-%d",
               b.title, b.author, b.publisher, b.isbn, &b.year,
               &b.copies) == 6) {

      if (strcmp(b.isbn, isbn) == 0) {
        found = 1;
        printf("\t\t\t\tUpdating book with ISBN %s:\n", b.isbn);

        printf("\t\t\t\tEnter new title: ");
        fgets(b.title, sizeof(b.title), stdin);
        b.title[strcspn(b.title, "\n")] = '\0';

        printf("\t\t\t\tEnter new author: ");
        fgets(b.author, sizeof(b.author), stdin);
        b.author[strcspn(b.author, "\n")] = '\0';

        printf("\t\t\t\tEnter new publisher: ");
        fgets(b.publisher, sizeof(b.publisher), stdin);
        b.publisher[strcspn(b.publisher, "\n")] = '\0';

        printf("\t\t\t\tEnter new year: ");
        scanf("%d", &b.year);
        getchar(); // clear newline

        printf("\t\t\t\tEnter new Number of Books: ");
        scanf("%d", &b.copies);
        getchar(); // clear newline
      }

      // Write either updated or original book
      fprintf(temp,
              "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Number of "
              "Books:-%d\n",
              b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
    }
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("books.txt");
    rename("temp.txt", "books.txt");
    printf("\t\t\t\t\t\t---Book updated successfully.---\n");
  } else {
    printf("\t\t\t\tBook with ISBN %s not found.\n", isbn);
    remove("temp.txt");
  }
}
//**********update staff **********/
void update_staff() {
  char id[20];
  char age[10];

  printf("\t\t\t\tEnter ID of the staff to update: ");
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
      char current_id[20];
      sscanf(id_ptr, "ID:-%[^|]", current_id);

      if (strcmp(current_id, id) == 0) {
        found = 1;
        struct Staff s;
        strcpy(s.id, id); // retain ID

        printf("\t\t\t\t------ Updating staff with ID %s ------\n", s.id);

        printf("\t\t\t\tEnter new name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';

        printf("\t\t\t\tEnter new email: ");
        fgets(s.email, sizeof(s.email), stdin);
        s.email[strcspn(s.email, "\n")] = '\0';

        printf("\t\t\t\tEnter new password: ");
        get_password(s.password, sizeof(s.password));
        s.password[strcspn(s.password, "\n")] = '\0';

        printf("\t\t\t\tEnter new phone: ");
        fgets(s.phone, sizeof(s.phone), stdin);
        s.phone[strcspn(s.phone, "\n")] = '\0';

        printf("\t\t\t\tEnter new address: ");
        fgets(s.address, sizeof(s.address), stdin);
        s.address[strcspn(s.address, "\n")] = '\0';

        printf("\t\t\t\tEnter new age: ");
        fgets(age, sizeof(age), stdin);
        s.age = atoi(age);

        // ✅ Corrected format string with %d for age
        fprintf(temp,
                "Name:-%s|ID:-%s|Password:-%s|Email:-%s|Phone:-%s|Address:-%s|"
                "Age:-%d\n",
                s.name, s.id, s.password, s.email, s.phone, s.address, s.age);

        continue; // skip writing old line
      }
    }

    fputs(line, temp); // write unchanged line
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
    printf("\t\t\t\t--- Staff with ID %s updated successfully. ---\n", id);
  } else {
    remove("temp.txt");
    printf("\t\t\t\tStaff with ID %s not found.\n", id);
  }
}

//**********update student **********/
void update_student() {
  char id[10];
  printf("\t\t\t\tEnter ID of the student to update: ");
  fgets(id, sizeof(id), stdin);
  id[strcspn(id, "\n")] = '\0';

  FILE *f = fopen("students.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!f || !temp) {
    perror("\t\t\tFailed to open files");
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
               "\t\t\tName:-%[^|]|ID:-%[^|]|Email:-%[^|]|Phone:-%[^|]|Address:-"
               "%[^|]| Age:-%d",
               s.name, s.id, s.email, s.phone, s.address, &s.age);

        char input[100];

        printf("\t\t\t\tUpdating student with ID %s:\n", s.id);

        printf("\t\t\t\tEnter new name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';

        printf("\t\t\t\tEnter new email: ");
        fgets(s.email, sizeof(s.email), stdin);
        s.email[strcspn(s.email, "\n")] = '\0';

        printf("\t\t\t\tEnter new phone: ");
        fgets(s.phone, sizeof(s.phone), stdin);
        s.phone[strcspn(s.phone, "\n")] = '\0';

        printf("\t\t\t\tEnter new address: ");
        fgets(s.address, sizeof(s.address), stdin);
        s.address[strcspn(s.address, "\n")] = '\0';

        printf("\t\t\t\tEnter new age: ");
        fgets(input, sizeof(input), stdin);
        s.age = atoi(input);

        // Write updated record
        fprintf(temp,
                "Name:-%s|ID:-%s|Email:-%s|Phone:-%s|Address:-%s|Age:-%d\n",
                s.name, s.id, s.email, s.phone, s.address, s.age);
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
    printf("\t\t\t\t\t\t--- Student updated successfully.---\n");
  } else {
    remove("temp.txt");
    printf("\t\t\t\tStudent with ID %s not found.\n", id);
  }
}
/*=========================== Search Part=================================*/
void search_record() {
  int choice;
  char keyword[100];

  printf(
      "\n\t\t\t\t--------------------------------------------------------\n");
  printf("\t\t\t\t\t\tSearch Record Menu\n");
  printf("\t\t\t\t--------------------------------------------------------\n");
  printf("\t\t\t\t1. Search Book\n");
  printf("\t\t\t\t2. Search Student\n");
  printf("\t\t\t\t3. Search Staff\n");
  printf("\t\t\t\t0. Cancel\n");
  printf("\t\t\t\tEnter your choice: ");

  if (scanf("%d", &choice) != 1) {
    while (getchar() != '\n')
      ;
    printf("\t\t\t\tInvalid input.\n");
    return;
  }
  getchar(); // Clear newline

  if (choice == 0)
    return;

  printf("\t\t\t\tEnter keyword to search: ");
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
    printf("\t\t\t\tInvalid choice. Try again.\n");
  }
}

void search_books(const char *keyword) {
  FILE *f = fopen("books.txt", "r");
  if (!f) {
    printf("\t\t\t\tNo books available.\n");
    return;
  }

  struct Book b;
  char line[512];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    if (sscanf(line,
               "Title:-%99[^|]|Author:-%99[^|]|Publisher:-%99[^|]|ISBN:-%19[^|]"
               "|Year:-%d|Number of Books:-%d",
               b.title, b.author, b.publisher, b.isbn, &b.year,
               &b.copies) == 6) {

      char year_str[12], copies_str[12];
      snprintf(year_str, sizeof(year_str), "%d", b.year);
      snprintf(copies_str, sizeof(copies_str), "%d", b.copies);

      if (strstr(b.title, keyword) || strstr(b.author, keyword) ||
          strstr(b.publisher, keyword) || strstr(b.isbn, keyword) ||
          strstr(year_str, keyword) || strstr(copies_str, keyword)) {

        printf("\t\t\t\tTitle: %s | Author: %s | Publisher: %s | ISBN: %s | "
               "Year: %d | Copies: %d\n",
               b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("\t\t\t\tNo book found matching \"%s\".\n", keyword);
  }

  fclose(f);
}

void search_students(const char *keyword) {
  FILE *f = fopen("students.txt", "r");
  if (!f) {
    printf("\t\t\t\tError: Could not open student file.\n");
    return;
  }

  struct Student {
    char name[100];
    char id[20];
    char email[100];
    char phone[20];
    char address[200];
    int age;
  } s;

  char line[512], age_str[10];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    line[strcspn(line, "\n")] = '\0';

    // Debug: print line being parsed
    // printf("DEBUG LINE: %s\n", line);

    int matched = sscanf(line,
                         "Name:-%99[^|]|ID:-%19[^|]|Email:-%99[^|]|"
                         "Phone:-%19[^|]|Address:-%199[^|]|Age:-%d",
                         s.name, s.id, s.email, s.phone, s.address, &s.age);

    if (matched == 6) {
      snprintf(age_str, sizeof(age_str), "%d", s.age);

      if (strstr(s.name, keyword) || strstr(s.id, keyword) ||
          strstr(s.email, keyword) || strstr(s.phone, keyword) ||
          strstr(s.address, keyword) || strstr(age_str, keyword)) {

        printf("\t\t\t\tName: %s | ID: %s | Email: %s | Phone: %s | Address: "
               "%s | Age: %d\n",
               s.name, s.id, s.email, s.phone, s.address, s.age);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("\t\t\t\tNo student found matching \"%s\".\n", keyword);
  }

  fclose(f);
}

void search_staffs(const char *keyword) {
  FILE *f = fopen("staff.txt", "r");
  if (!f) {
    printf("\t\t\t\tError: Could not open staff file.\n");
    return;
  }

  struct Staff {
    char name[100];
    char id[20];
    char password[50];
    char email[100];
    char phone[20];
    char address[200];
    int age;
  } s;

  char line[512], age_str[10];
  int found = 0;

  while (fgets(line, sizeof(line), f)) {
    line[strcspn(line, "\n")] = '\0';

    if (sscanf(line,
               "Name:-%99[^|]|ID:-%19[^|]|Password:-%49[^|]|Email:-%99[^|]|"
               "Phone:-%19[^|]|Address:-%199[^|]|Age:-%d",
               s.name, s.id, s.password, s.email, s.phone, s.address,
               &s.age) == 7) {

      snprintf(age_str, sizeof(age_str), "%d", s.age);

      if (strstr(s.name, keyword) || strstr(s.id, keyword) ||
          strstr(s.password, keyword) || strstr(s.email, keyword) ||
          strstr(s.phone, keyword) || strstr(s.address, keyword) ||
          strstr(age_str, keyword)) {

        printf("\t\t\t\tName: %s | ID: %s | Email: %s | Phone: %s | Address: "
               "%s | Age: %d\n",
               s.name, s.id, s.email, s.phone, s.address, s.age);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("\t\t\t\tNo staff found matching \"%s\".\n", keyword);
  }

  fclose(f);
}


























    /*============================ Show part ================================*/
    void
    show_record() {
  int choice;


    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t Show Record Menu");
    printf("\n\t\t\t\t----------------------------------------------------------------\n");
  printf("\t\t\t\t1. Show Books\n");
  printf("\t\t\t\t2. Show Students\n");
  printf("\t\t\t\t3. Show Staff\n");
  printf("\t\t\t\t0. Cancel\n");
  printf("\t\t\t\tEnter your choice: ");
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
//**********show books **********/
void show_book() {
    FILE *f = fopen("books.txt", "r");
    if (!f) {
        printf("\t\t\t\tNo books available.\n");
        return;
    }

    struct Book b;
    char line[512];

    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t Show Book List");
    printf("\n\t\t\t\t----------------------------------------------------------------");

    // Print table header once
    printf("\n%-10s | %-10s | %-10s | %-10s | %-4s | %-15s\n",
           "\t\t\t\t   Title  ", "Author", "Publisher", "ISBN", "Year", "Number of Book");
    printf("\t\t\t\t----------------------------------------------------------------------\n");

    // Read and display each line
    while (fgets(line, sizeof(line), f)) {
        sscanf(line,
               "\t\t\t\tTitle:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-%d|Number of Books:-%d",
               b.title, b.author, b.publisher, b.isbn, &b.year, &b.copies);

        printf("\t\t\t\t%-10s | %-10s | %-10s | %-10s | %-4d | %-15d\n",
               b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
    }

    fclose(f);
}

/********show staff****** */
void show_staff() {
    FILE *f = fopen("staff.txt", "r");
    if (!f) {
        printf("\t\t\t\tNo staff available.\n");
        return;
    }

    struct Staff s;
    char line[512];

    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t Staff List");
    printf("\n\t\t\t\t----------------------------------------------------------------\n");

    // Print header
    printf("\n%-15s | %-10s | %-20s | %-12s | %-15s | %-3s\n",
           "\t\t\t\t  Name", "ID", "Email", "Phone", "Address", "Age");
    printf("\t\t\t\t----------------------------------------------------------------------------------------\n");

    // Read and display each staff entry
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line,
                   "\t\t\t\t\t Name:-%[^|] |ID:-%[^|]|Password:-%[^|]|Email:-%[^|]|Phone:-%[^|]|Address:-%[^|]|Age:-%d",
                   s.name, s.id, s.password, s.email, s.phone, s.address, &s.age) == 7) {

            printf("\t\t\t\t %-10s | %-10s | %-20s | %-12s | %-15s | %-3d\n",
                   s.name, s.id, s.email, s.phone, s.address, s.age);
        }
    }

    fclose(f);
}

/***************show student************ */
void show_student() {
    FILE *f = fopen("students.txt", "r");
    if (!f) {
        printf("\t\t\t\tNo students available.\n");
        return;
    }

    struct Student s;
    char line[512];

    printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t Student List\n");
    printf("\t\t\t\t----------------------------------------------------------------\n");

    // Print table header
    printf("\n%-15s | %-10s | %-20s | %-12s | %-20s | %-3s\n",
           "\t\t\t\t Name", "ID", "Email", "Phone", "Address", "Age");
    printf("\t\t\t\t------------------------------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), f)) {
        // Set default age
        s.age = 0;

        if (sscanf(line,
                   "Name:-%[^|]|ID:-%[^|]|Email:-%[^|]|Phone:-%[^|]|Address:-%[^|]|Age:-%d",
                   s.name, s.id, s.email, s.phone, s.address, &s.age) >= 5) {
            printf("\t\t\t\t %-10s | %-10s | %-20s | %-12s | %-20s | %-3d\n",
                   s.name, s.id, s.email, s.phone, s.address, s.age);
        }
    }

    fclose(f);
}

/*========================== issue book========================== */
// issue book by book name, author, isbn,student name, id,phone.
struct Issue {
  char student_id[20];
  char student_name[50];
  char student_phone[15];
  char book_title[100];
  char book_author[100];
  char book_isbn[20];
  char issue_date[30];
  char return_date[30];
  float fine;
};
void issue_book() {
  struct Issue issue;
  struct Book book;
  char book_title[100], book_author[100], book_isbn[20];

  printf("\t\t\t\tEnter student ID: ");
  scanf("%s", issue.student_id);
  getchar();

  printf("\t\t\t\tEnter student name: ");
  fgets(issue.student_name, sizeof(issue.student_name), stdin);
  issue.student_name[strcspn(issue.student_name, "\n")] = '\0';

  printf("\t\t\t\tEnter phone: ");
  scanf("%s", issue.student_phone);
  getchar();

  printf("\t\t\t\tEnter Book Title: ");
  fgets(book_title, sizeof(book_title), stdin);
  book_title[strcspn(book_title, "\n")] = '\0';

  printf("\t\t\t\tEnter Book Author: ");
  fgets(book_author, sizeof(book_author), stdin);
  book_author[strcspn(book_author, "\n")] = '\0';

  printf("\t\t\t\tEnter Book ISBN: ");
  scanf("%s", book_isbn);
  getchar();

  FILE *f_book = fopen("books.txt", "r");
  FILE *temp_book = fopen("temp_books.txt", "w");
  if (!f_book || !temp_book) {
    printf("\t\t\t\tError opening books file.\n");
    return;
  }

  int book_found = 0;
  while (fscanf(f_book,
                "Title:-%[^|]|Author:-%[^|]|Publisher:-%[^|]|ISBN:-%[^|]|Year:-"
                "%d|Number of Books:-%d\n",
                book.title, book.author, book.publisher, book.isbn, &book.year,
                &book.copies) == 6) {

    if (strcmp(book.title, book_title) == 0 &&
        strcmp(book.author, book_author) == 0 &&
        strcmp(book.isbn, book_isbn) == 0 && book.copies > 0) {
      book.copies--;
      book_found = 1;

      // Copy book details into issue struct
      strcpy(issue.book_title, book.title);
      strcpy(issue.book_author, book.author);
      strcpy(issue.book_isbn, book.isbn);

      // Generate issue date
      time_t now = time(NULL);
      struct tm *t = localtime(&now);
      strftime(issue.issue_date, sizeof(issue.issue_date), "%Y-%m-%d", t);

      strcpy(issue.return_date, "N/A"); // Not returned yet
      issue.fine = 0.00;
    }

    // Write updated or unchanged book back
    fprintf(temp_book,
            "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|Number of "
            "Books:-%d\n",
            book.title, book.author, book.publisher, book.isbn, book.year,
            book.copies);
  }

  fclose(f_book);
  fclose(temp_book);

  if (!book_found) {
    printf("\t\t\t\tBook not found or no Book is available.\n");
    remove("temp_books.txt");
    return;
  }

  // Replace old books file with updated one
  remove("books.txt");
  rename("temp_books.txt", "books.txt");

  // Save issued record
  FILE *f_issue = fopen("issued_books.txt", "a");
  if (f_issue) {
    fprintf(f_issue,
            "StudentID:-%s|Name:-%s|Phone:-%s|Book:-%s|Author:-%s|ISBN:-%s|"
            "Issued:-%s|Return:-%s|Fine:-%.2f\n",
            issue.student_id, issue.student_name, issue.student_phone,
            issue.book_title, issue.book_author, issue.book_isbn,
            issue.issue_date, issue.return_date, issue.fine);
    fclose(f_issue);
    printf("\t\t\t\t\t----Book issued successfully on %s!----\n", issue.issue_date);
  } else {
    printf("\t\t\t\tFailed to save issue record.\n");
  }
}
/***********return book******* */
void trim_newline(char *str) {
  size_t len = strlen(str);
  if (len > 0 && str[len - 1] == '\n')
    str[len - 1] = '\0';
}

void return_book() {
  char student_name[50], student_id[20], student_phone[20];
  char book_title[100], book_author[100], book_isbn[20];

  printf("\t\t\t\tEnter Student Name: ");
  fgets(student_name, sizeof(student_name), stdin);
  trim_newline(student_name);

  printf("\t\t\t\tEnter Student ID: ");
  fgets(student_id, sizeof(student_id), stdin);
  trim_newline(student_id);

  printf("\t\t\t\tEnter Student Phone: ");
  fgets(student_phone, sizeof(student_phone), stdin);
  trim_newline(student_phone);

  printf("\t\t\t\tEnter Book Title: ");
  fgets(book_title, sizeof(book_title), stdin);
  trim_newline(book_title);

  printf("\t\t\t\tEnter Book Author: ");
  fgets(book_author, sizeof(book_author), stdin);
  trim_newline(book_author);

  printf("\t\t\t\tEnter Book ISBN: ");
  fgets(book_isbn, sizeof(book_isbn), stdin);
  trim_newline(book_isbn);

  FILE *f = fopen("issued_books.txt", "r");
  FILE *temp = fopen("temp_issued_books.txt", "w");
  if (!f || !temp) {
    perror("Failed to open issued_books file");
    return;
  }

  struct Issue ir;
  int found = 0;
  char line[512];

  while (fgets(line, sizeof(line), f)) {
    // Try to parse all fields
    if (sscanf(line,
               "StudentID:-%19[^|]|Name:-%49[^|]|Phone:-%19[^|]|Book:-%99[^|]|"
               "Author:-%99[^|]|ISBN:-%19[^|]|Issued:-%19[^|]|Return:-%19[^|]|"
               "Fine:-%f",
               ir.student_id, ir.student_name, ir.student_phone, ir.book_title,
               ir.book_author, ir.book_isbn, ir.issue_date, ir.return_date,
               &ir.fine) == 9) {

      // Check if this is the matching unreturned book
      if (strcmp(ir.student_id, student_id) == 0 &&
          strcmp(ir.student_name, student_name) == 0 &&
          strcmp(ir.student_phone, student_phone) == 0 &&
          strcmp(ir.book_title, book_title) == 0 &&
          strcmp(ir.book_author, book_author) == 0 &&
          strcmp(ir.book_isbn, book_isbn) == 0 &&
          strcmp(ir.return_date, "N/A") == 0) {

        found = 1;

        // Set return date
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        strftime(ir.return_date, sizeof(ir.return_date), "%Y-%m-%d", t);

        // Calculate fine
        int y, m, d;
        if (sscanf(ir.issue_date, "%d-%d-%d", &y, &m, &d) == 3) {
          struct tm tm_issue = {0};
          tm_issue.tm_year = y - 1900;
          tm_issue.tm_mon = m - 1;
          tm_issue.tm_mday = d;
          time_t issue_time = mktime(&tm_issue);
          double days = difftime(now, issue_time) / (60 * 60 * 24);
          ir.fine = (days > 7) ? (days - 7) * 5.0 : 0.0;
        } else {
          ir.fine = 0.0;
        }

        // Update book inventory
        FILE *fb = fopen("books.txt", "r");
        FILE *ftb = fopen("temp_books.txt", "w");
        if (!fb || !ftb) {
          perror("Error opening book files");
          fclose(f);
          fclose(temp);
          return;
        }

        struct Book b;
        char book_line[512];
        while (fgets(book_line, sizeof(book_line), fb)) {
          if (sscanf(book_line,
                     "Title:-%99[^|]|Author:-%99[^|]|Publisher:-%99[^|]|ISBN:-%"
                     "19[^|]|Year:-%d|Number of Books:-%d",
                     b.title, b.author, b.publisher, b.isbn, &b.year,
                     &b.copies) == 6) {

            if (strcmp(b.title, book_title) == 0 &&
                strcmp(b.author, book_author) == 0 &&
                strcmp(b.isbn, book_isbn) == 0) {
              b.copies++; // Increase copy count
            }

            fprintf(ftb,
                    "Title:-%s|Author:-%s|Publisher:-%s|ISBN:-%s|Year:-%d|"
                    "Number of Books:-%d\n",
                    b.title, b.author, b.publisher, b.isbn, b.year, b.copies);
          }
        }
        fclose(fb);
        fclose(ftb);
        remove("books.txt");
        rename("temp_books.txt", "books.txt");

        // Write updated record
        fprintf(temp,
                "StudentID:-%s|Name:-%s|Phone:-%s|Book:-%s|Author:-%s|ISBN:-%s|"
                "Issued:-%s|Return:-%s|Fine:-%.2f\n",
                ir.student_id, ir.student_name, ir.student_phone, ir.book_title,
                ir.book_author, ir.book_isbn, ir.issue_date, ir.return_date,
                ir.fine);

        printf("\t\t\t\t\t---Book returned successfully on %s.---\n", ir.return_date);
        if (ir.fine > 0)
          printf("\t\t\t\tFine incurred: RS.%.2f\n", ir.fine);
        else
          printf("\t\t\t\tNo fine.\n");

        continue; // Don't write original line again
      }
    }

    // Copy line as-is if not matched
    fputs(line, temp);
  }

  fclose(f);
  fclose(temp);

  if (found) {
    remove("issued_books.txt");
    rename("temp_issued_books.txt", "issued_books.txt");
  } else {
    remove("temp_issued_books.txt");
    printf("\t\t\t\t\t\t\t\t--------Issue record not found or book already returned.\n");
  }
}

/*************view issue book */
void view_issued_books() {
  FILE *f = fopen("issued_books.txt", "r");
  if (!f) {
    printf("\t\t\t\tNo issued books available.\n");
    return;
  }

  struct IssueRecord b;
  printf("\t\t\t\t\nIssued Books:\n");
  while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%ld|%ld|%lf\n", b.student_id,
                b.student_name, b.student_phone, b.book_isbn, &b.issue_date,
                &b.return_date, &b.fine) == 7) {
    printf(
        "\t\t\tStudent ID: %s | Name: %s | Phone: %s | Book ISBN: %s | Issue "
        "Date: %ld | Return Date: %ld | Fine: %.2f\n",
        b.student_id, b.student_name, b.student_phone, b.book_isbn,
        b.issue_date, b.return_date, b.fine);
  }
  fclose(f);
}
/*************show issued record */
void show_issued_record() {
  FILE *f = fopen("issued_books.txt", "r");
  if (!f) {
    printf("\t\t\t\tNo issued records available.\n");
    return;
  }

  char line[512];
  struct Issue ir;

      printf("\n\t\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t Issued Book Records");
    printf("\n\t\t\t\t----------------------------------------------------------------\n");


  while (fgets(line, sizeof(line), f)) {
    sscanf(line,
           "StudentID:-%[^|]|Name:-%[^|]|Phone:-%[^|]|Book:-%[^|]|Author:-%[^|]"
           "|ISBN:-%[^|]|Issued:-%[^|]|Return:-%[^|]|Fine:-%f",
           ir.student_id, ir.student_name, ir.student_phone, ir.book_title,
           ir.book_author, ir.book_isbn, ir.issue_date, ir.return_date,
           &ir.fine);

    printf("\t\t\t\tStudent ID     : %s\n", ir.student_id);
    printf("\t\t\t\tStudent Name   : %s\n", ir.student_name);
    printf("\t\t\t\tPhone          : %s\n", ir.student_phone);
    printf("\t\t\t\tBook Title     : %s\n", ir.book_title);
    printf("\t\t\t\tBook Author    : %s\n", ir.book_author);
    printf("\t\t\t\tBook ISBN      : %s\n", ir.book_isbn);
    printf("\t\t\t\tIssue Date     : %s\n", ir.issue_date);
    printf("\t\t\t\tReturn Date    : %s\n",
           strlen(ir.return_date) > 0 ? ir.return_date : "Not Returned");
    printf("\t\t\t\tFine           : Rs.%.2f\n", ir.fine);
    printf("\t\t\t\t----------------------------------------\n");
  }

  fclose(f);
}
/*************save issue record */
void save_issue(const struct IssueRecord *b) {
  FILE *f = fopen("issued_books.txt", "a+");
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
