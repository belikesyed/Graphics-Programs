#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 22/7
//Line Clipping
void midLine(int,int,int,int,int);

void cord()//function for drawing coordinates
{
    int i,j;
    for(i=0,j=320; i<641;)
        putpixel(i++,j,15);
    for(i=0,j=320; i<641;)
        putpixel(j,i++,15);
}

int main()
{
    initwindow(640,640);
    cord();
    float i,x,y,th=60;
    th=(th/180)*PI;
        printf("10>>01=%d 10<<01=%d\n",(01>>10),(10<<2));

    delay(10000);
    closegraph();
}
