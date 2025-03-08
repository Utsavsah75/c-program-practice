#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[50], address[50];
  int  age,phone;
} std[100];

int main(){
    struct student  std[100], temp;
    int n, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter student %d details:\n", i+1);
        printf("Enter the name of student: ");
        scanf("%s",std[i].name);
        printf("Enter the Address of student: ");
        scanf("%s",std[i].address);
        printf("Enter the age of student: ");
        scanf("%d",&std[i].age);
        printf("Enter the phone of student: ");
        scanf("%u",&std[i].phone);
       
    }
      // Sorting students by age in ascending order
      for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (std[j].age < std[j + 1].age) {
                temp = std[j];
                std[j] = std[j + 1];
                std[j + 1] = temp;
            }
        }
    }
    printf("\nStudent details in ascending order of name:\n");
    for(i=0; i<n; i++){
        // for(int j=i+1; j<n; j++){
            if(std[i].age>25){
            printf("Student %d details:\n", i+1);
            printf("Name: %s\n",std[i].name);
            printf("Address: %s\n",std[i].address);
            printf("Age: %d\n",std[i].age);
            printf("Phone: %u\n",std[i].phone);
    }
}
return 0;
}