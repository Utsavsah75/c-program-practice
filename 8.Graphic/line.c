/* NOTE: -
Run this code into the turboc3 compiler

*/

#include <stdio.h>
#include <graphics.h>

int gd = DETECT, gm;
int gd=DETECT,gm;
int point[]={400,200,600,400,300,400,400,200};
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
setbkcolor(CYAN);
line(320,150,480,150);
setfillstyle(SOLID_FILL,RED);
rectangle(300,100,500,200);
circle(80,150,50);
circle(160,150,50);
line(30,200,220,200);
arc(220,175,0,90,50);
ellipse(400,150,360,0,100,40);
drawpoly(6,point);
//floodfill(252,158,15);
getch();
closegraph();
