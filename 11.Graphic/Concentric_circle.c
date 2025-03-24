/*All the grogram run in a TURBO c++ Application*/

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main(){
   int gd = DETECT, gm;
   int x, y, n, i, x1, y1;

   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;

   x1 = getmaxx()/3;
   y1 = getmaxy()/4;
   outtextxy(x1,y1, "Concentric Circles");
   /* Draw circles on screen */
   printf("Enter the number of circles: ");
   scanf("%d", &n);
   for(i=1; i<=n; i++){
      setcolor(i % 15 + 1); // Change color for each circle
      circle(x, y, i * 10);
   }
   getch();

   closegraph();
   return 0;
}