#include<stdio.h>
int main(){
    int mark[2],i;
    float sum=0,per,avg;
    for(i=0;i<2;i++){
      printf("Enter marks of subjects %d:", i+1);               
      // printf("Enter marks of subjects %d:", i-1); printf("\nEnter marks of subjects %d:\n", i++);
        scanf("%d",&mark[i]);
        sum+=mark[i];
    }
    avg=sum/2;
    per=(sum/200)*100;
    for(i=0;i<2;i++){
        // printf("Subject %d: %d\n",i+1,mark[i]);
    }
    printf("The sum of total marks: %.2f\n",sum);
    printf("The average of total marks: %.2f\n",avg);
    printf("The percentage of total marks: %.2f%%\n",per);
    return 0;

}


