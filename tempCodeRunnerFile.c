#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Book {
    char title[100];
    char author[50];
    char publisher[50];
    char isbn[20];
    int year;
    int copies;
};

struct Student {
    char name[50];
    char id[10];
    char username[50];
    char email[50];
    char phone[20];
    char address[100];
    int age;
};

void issue_book() {
    char book_title[100], book_author[50], book_isbn[20];
    char student_name[50], student_id[10], student_phone[20];

    // --- Input Book Details ---
    printf("Enter Book Title: ");
    fgets(book_title, sizeof(book_title), stdin);
    book_title[strcspn(book_title, "\n")] = '\0';

    printf("Enter Book Author: ");
    fgets(book_author, sizeof(book_author), stdin);
    book_author[strcspn(book_author, "\n")] = '\0';

    printf("Enter Book ISBN: ");
    fgets(book_isbn, sizeof(book_isbn), stdin);
    book_isbn[strcspn(book_isbn, "\n")] = '\0';

    // --- Input Student Details ---
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
        if (f_book) fclose(f_book);
        if (temp_book) fclose(temp_book);
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
            b.copies--;  // Issue one copy
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
    fprintf(f_issue, "Name:-%s|ID:-%s|Phone:-%s|Title:-%s|Author:-%s|ISBN:-%s|IssuedOn:-%ld\n",
            student_name, student_id, student_phone,
            book_title, book_author, book_isbn, now);

    fclose(f_issue);
    printf("Book issued successfully and recorded in issue.txt!\n");
}
