#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct student {
    char name[50];
    char id[10];
    char username[20];
    char password[20];
    char email[50];
    char phone[15];
    char address[100];
    int age;
} stdudent;

struct admin {
    char name[50];
    char id[10];
    char username[20];
    char password[20];
    char email[50];
    char phone[15];
    char address[100];
} admin;

struct book {
    char title[100];
    char author[50];
    char publisher[50];
    char isbn[20];
    int year;
    int copies;
} book;

struct borrow {
    char student_id[10];
    char student_name[50];
    char student_phone[20];
    char book_isbn[20];
    time_t borrow_date;
    time_t return_date;
} borrow;

void save_all_data_to_file(){
    FILE *file;
    file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Save student data
    fprintf(file, "Student Name: %s\n", stdudent.name);
    fprintf(file, "Student ID: %s\n", stdudent.id);
    fprintf(file, "Username: %s\n", stdudent.username);
    fprintf(file, "Password: %s\n", stdudent.password);
    fprintf(file, "Email: %s\n", stdudent.email);
    fprintf(file, "Phone: %s\n", stdudent.phone);
    fprintf(file, "Address: %s\n", stdudent.address);
    fprintf(file, "Age: %d\n", stdudent.age);

    // Save admin data
    fprintf(file, "\nAdmin Name: %s\n", admin.name);
    fprintf(file, "Admin ID: %s\n", admin.id);
    fprintf(file, "Username: %s\n", admin.username);
    fprintf(file, "Password: %s\n", admin.password);
    fprintf(file, "Email: %s\n", admin.email);
    fprintf(file, "Phone: %s\n", admin.phone);
    fprintf(file, "Address: %s\n", admin.address);

    // Save book data
    fprintf(file, "\nBook Title: %s\n", book.title);
    fprintf(file, "Author: %s\n", book.author);
    fprintf(file, "Publisher: %s\n", book.publisher);
    fprintf(file, "ISBN: %s\n", book.isbn);
    fprintf(file, "Year: %d\n", book.year);
    fprintf(file, "Copies: %d\n", book.copies);

    // Save borrow data
    fprintf(file, "\nBorrow Student ID: %s\n", borrow.student_id);
    fprintf(file, "Student Name: %s\n", borrow.student_name);
    fprintf(file, "Student Phone: %s\n", borrow.student_phone);
    fprintf(file, "Book ISBN: %s\n", borrow.book_isbn);
    
    fclose(file);
}
void load_all_data_from_file(){
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
  }
    // user resisteration
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



    // Load student data
    fscanf(file, "Student Name: %[^\n]\n", stdudent.name);
    fscanf(file, "Student ID: %[^\n]\n", stdudent.id);
    fscanf(file, "Username: %[^\n]\n", stdudent.username);
    fscanf(file, "Password: %[^\n]\n", stdudent.password);
    fscanf(file, "Email: %[^\n]\n", stdudent.email);
    fscanf(file, "Phone: %[^\n]\n", stdudent.phone);
    fscanf(file, "Address: %[^\n]\n", stdudent.address);
    fscanf(file, "Age: %d\n", &stdudent.age);

    // Load admin data
    fscanf(file, "\nAdmin Name: %[^\n]\n", admin.name);
    fscanf(file, "Admin ID: %[^\n]\n", admin.id);
    fscanf(file, "Username: %[^\n]\n", admin.username);
    fscanf(file, "Password: %[^\n]\n", admin.password);
    fscanf(file, "Email: %[^\n]\n", admin.email);
    fscanf(file, "Phone: %[^\n]\n", admin.phone);
    fscanf(file, "Address: %[^\n]\n", admin.address);

    // Load book data
    fscanf(file, "\nBook Title: %[^\n]\n", book.title);
    fscanf(file, "Author: %[^\n]\n", book.author);
    fscanf(file, "Publisher: %[^\n]\n", book.publisher);
    fscanf(file, "ISBN: %[^\n]\n", book.isbn);
    fscanf(file, "Year: %d\n", &book.year);
    fscanf(file, "Copies: %d\n", &book.copies);

    // Load borrow data
    fscanf(file, "\nBorrow Student ID: %[^\n]\n", borrow.student_id);
    fscanf(file, "Student Name: %[^\n]\n", borrow.student_name);
    fscanf(file, "Student Phone: %[^\n]\n", borrow.student_phone);
    fscanf(file, "Book ISBN: %[^\n]\n", borrow.book_isbn);

    fclose(file);
}

void add_student() {
    printf("Enter student name: ");
    scanf("%s", stdudent.name);
    printf("Enter student ID: ");
    scanf("%s", stdudent.id);
    printf("Enter username: ");
    scanf("%s", stdudent.username);
    printf("Enter password: ");
    scanf("%s", stdudent.password);
    printf("Enter email: ");
    scanf("%s", stdudent.email);
    printf("Enter phone: ");
    scanf("%s", stdudent.phone);
    printf("Enter address: ");
    scanf("%s", stdudent.address);
    printf("Enter age: ");
    scanf("%d", &stdudent.age);
}

void add_admin() {
    printf("Enter admin name: ");
    scanf("%s", admin.name);
    printf("Enter admin ID: ");
    scanf("%s", admin.id);
    printf("Enter username: ");
    scanf("%s", admin.username);
    printf("Enter password: ");
    scanf("%s", admin.password);
    printf("Enter email: ");
    scanf("%s", admin.email);
    printf("Enter phone: ");
    scanf("%s", admin.phone);
    printf("Enter address: ");
    scanf("%s", admin.address);
}

void add_book() {
    printf("Enter book title: ");
    scanf("%s", book.title);
    printf("Enter author: ");
    scanf("%s", book.author);
    printf("Enter publisher: ");
    scanf("%s", book.publisher);
    printf("Enter ISBN: ");
    scanf("%s", book.isbn);
    printf("Enter year: ");
    scanf("%d", &book.year);
    printf("Enter number of copies: ");
    scanf("%d", &book.copies);
}

void borrow_book() {
    printf("Enter student ID: ");
    scanf("%s", borrow.student_id);
    printf("Enter student name: ");
    scanf("%s", borrow.student_name);
    printf("Enter student phone: ");
    scanf("%s", borrow.student_phone);
    printf("Enter book ISBN: ");
    scanf("%s", borrow.book_isbn);
    
    time(&borrow.borrow_date);
    borrow.return_date = 0; // Not returned yet
}
void return_book() {
    printf("Enter student ID: ");
    scanf("%s", borrow.student_id);
    printf("Enter book ISBN: ");
    scanf("%s", borrow.book_isbn);
    
    time(&borrow.return_date);
}

void view_borrowed_books() {
    printf("Borrowed Book Details:\n");
    printf("Student ID: %s\n", borrow.student_id);
    printf("Student Name: %s\n", borrow.student_name);
    printf("Student Phone: %s\n", borrow.student_phone);
    printf("Book ISBN: %s\n", borrow.book_isbn);
    printf("Borrow Date: %s", ctime(&borrow.borrow_date));
    if (borrow.return_date != 0) {
        printf("Return Date: %s", ctime(&borrow.return_date));
    } else {
        printf("Book not returned yet.\n");
    }
}

void view_student_details() {
    printf("Student Details:\n");
    printf("Name: %s\n", stdudent.name);
    printf("ID: %s\n", stdudent.id);
    printf("Username: %s\n", stdudent.username);
    printf("Email: %s\n", stdudent.email);
    printf("Phone: %s\n", stdudent.phone);
    printf("Address: %s\n", stdudent.address);
    printf("Age: %d\n", stdudent.age);
}
void view_admin_details() {
    printf("Admin Details:\n");
    printf("Name: %s\n", admin.name);
    printf("ID: %s\n", admin.id);
    printf("Username: %s\n", admin.username);
    printf("Email: %s\n", admin.email);
    printf("Phone: %s\n", admin.phone);
    printf("Address: %s\n", admin.address);
}

void view_book_details() {
    printf("Book Details:\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("ISBN: %s\n", book.isbn);
    printf("Year: %d\n", book.year);
    printf("Copies: %d\n", book.copies);
}

void view_all_data() {
    view_student_details();
    view_admin_details();
    view_book_details();
    view_borrowed_books();
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Student\n");
        printf("2. Add Admin\n");
        printf("3. Add Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. View Borrowed Books\n");
        printf("7. View Student Details\n");
        printf("8. View Admin Details\n");
        printf("9. View Book Details\n");
        printf("10. Save All Data to File\n");
        printf("11. Load All Data from File\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                add_admin();
                break;
            case 3:
                add_book();
                break;
            case 4:
                borrow_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                view_borrowed_books();
                break;
            case 7:
                view_student_details();
                break;
            case 8:
                view_admin_details();
                break;
            case 9:
                view_book_details();
                break;
            case 10:
                save_all_data_to_file();
                break;
            case 11:
                load_all_data_from_file();
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}




