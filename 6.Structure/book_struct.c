#include <stdio.h>
#include <stdlib.h>
struct bookauthor {
    int title;
    char author[20];
    int price;
} book[100];
int main() {
    int n, i, high_price = 0;
    FILE *ptr;
    ptr = fopen("book.txt", "w+");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Enter the number of books: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the book title (ID): ");
        scanf("%d", &book[i].title);

        printf("Enter the author name: ");
        scanf("%s", book[i].author);  //   fgets(book[i].author, sizeof(book[i].author), stdin); // Use fgets to read strings with spaces
 
        printf("Enter the price of the book: ");
        scanf("%d", &book[i].price);
        printf("\n");
    }

    // Find the book with the highest price
    for (i = 1; i < n; i++) {
        if (book[i].price > book[high_price].price) {
            high_price = i;
        }
    }

    // Print highest priced book details
    printf("\nBook with the highest price:\n");
    printf("Title = %d\n", book[high_price].title);
    printf("Author = %s\n", book[high_price].author);
    printf("Price = %d\n", book[high_price].price);

    // Optional: write to file
    fprintf(ptr, "Book with the highest price:\n");
    fprintf(ptr, "Title = %d\n", book[high_price].title);
    fprintf(ptr, "Author = %s\n", book[high_price].author);
    fprintf(ptr, "Price = %d\n", book[high_price].price);

    fclose(ptr);
    return 0;
}


// #include<stdio.h>
// #include<stdlib.h>
// struct bookauthor {
//     char title[20];
//     char author[20];
//     int price;
// };
// int main(){
//     int n,i;
//     struct bookauthor *books;
//     FILE *ptr;
//     ptr=fopen("book.txt","w+");
//     if(ptr==NULL){
//         printf("Error to found file");
//         exit(1);
//     }
//     printf("Enter the number of books: ");
//     scanf("%d",&n);
//     books = (struct bookauthor*)malloc(n * sizeof(struct bookauthor));
//     for(i=0;i<n;i++){
//         printf("Enter the book title:");
//         scanf("%s",books[i].title);
//         printf("Enter the author name:");
//         scanf("%s",books[i].author);
//         printf("Enter the price of book:");
//         scanf("%d",&books[i].price);
//     }
//     free(books);
//     fclose(ptr);
// }
