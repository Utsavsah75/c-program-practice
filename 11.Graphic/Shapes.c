/*All the grogram run in a TURBO c++ Application*/

#include <graphics.h>
#include <stdio.h>


void main() {
  int gd = DETECT, gm;
  int point[] = {50, 300, 50, 400, 150, 400, 50, 300};

  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  // Set Background Color
  setbkcolor(CYAN);
  cleardevice();

  // Text Display
  setcolor(BLACK);
  outtextxy(30, 250, "All of the common shapes of geomatics");

  // Rectangle with Color
  // setcolor(WHITE);
  // rectangle(300, 100, 500, 200);
  //  setfillstyle(SOLID_FILL, RED);
  //  floodfill(310, 110, WHITE);  // Fill inside rectangle

  // Circles with Colors
  setcolor(YELLOW);
  circle(80, 150, 50);
  setfillstyle(SOLID_FILL, GREEN);
  floodfill(80, 150, YELLOW); // Fill first circle

  setcolor(WHITE);
  circle(160, 150, 50);
  setfillstyle(SOLID_FILL, BLUE);
  floodfill(160, 150, WHITE); // Fill second circle

  // Line
  setcolor(YELLOW);
  line(10, 200, 250, 200);

  // Arc
  setcolor(RED);
  arc(220, 175, 0, 90, 50);

  // Ellipse
  // setcolor(MAGENTA);
  ellipse(400, 150, 0, 360, 100, 40);
  // setfillstyle(HATCH_FILL, MAGENTA);
  //  floodfill(400, 150, MAGENTA);

  //   setcolor(5);
  ellipse(570, 150, 360, 0, 40, 100);

  // Polygon (Triangle-like)
  setcolor(WHITE);
  drawpoly(4, point);
  setfillstyle(SOLID_FILL, LIGHTBLUE);
  floodfill(51, 301, WHITE);

  // concentric circle
  outtextxy(200, 420, "Concentric circle");
  setcolor(12);
  circle(250, 350, 50);
  circle(250, 350, 30);

  // concentric rectangle
  outtextxy(420, 350, "Concentric rectangle");
  setcolor(5);
  rectangle(400, 300, 600, 400);
  setcolor(GREEN);
  rectangle(420, 320, 580, 380);

  getch();
  closegraph();
}