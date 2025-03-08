#include<stdio.h>
#include<stdlib.h>
struct bookauthor {
    int title;
    char author[20];
    int price;
}book[100];

int main(){
    int n,i;
    FILE *ptr;
    ptr=fopen("book.txt","w+");
    if(ptr==NULL){
        printf("Error to found file");
        exit(1);
    }
    printf("Enter the number of books: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the book title:");
        scanf("%d",&book[i].title);
        printf("Enter the author name:");
        getchar();
        fgets(book[i].author,sizeof(book[i].author),stdin);
        printf("Enter the price of book:");
        scanf("%d",&book[i].price);
        printf("\n");
    }
    printf("Books details are:\n");
    for(i=0;i<n;i++){
        printf("Title=%d",book[i].title); 
        printf("\nAuthor=%s",book[i].author); 
        printf("\nPrice=%d",book[i].price);
    }
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
