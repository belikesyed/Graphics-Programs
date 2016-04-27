#include <stdio.h>
#include <math.h>
#include <graphics.h>
#define PI 3.14159265

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
    int i;

    float val = PI / 180;

    int xc,yc,r,x1,x2,y1,y2;
    float th,delth,x,y;
    printf("Enter the x co-ordinate of circle : ");
    scanf("%d",&xc);
    printf("Enter the y co-ordinate of circle : ");
    scanf("%d",&yc);
    printf("Enter the radius of circle : ");
    scanf("%d",&r);
    x1=320;
    y1=320;
    xc = 320 + xc;
    yc = 320 - yc;
//value initlization of the initial point of four quadrant
    x1 = xc + 0.5;
    y1 = yc + r + 0.5;
    putpixel(x1,y1,3);

    y1 = yc - r + 0.5;
    putpixel(x1,y1,3);

    x2 = xc + r + 0.5;
    y2 = yc + 0.5;
    putpixel(x2,y2,3);

    x2 = xc - r + 0.5;
    putpixel(x2,y2,3);

    th = 1;
    delth = 1;
    while(th<=45)
    {
        x = r * cos(th*val);
        y = r * sin(th*val);
        th = th + delth;

        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
        putpixel(xc+y+0.5,yc+x+0.5,3);
        putpixel(xc+y+0.5,yc-x+0.5,3);
        putpixel(xc-y+0.5,yc+x+0.5,3);
        putpixel(xc-y+0.5,yc-x+0.5,3);

    }
    if(th == 45)
    {
        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
    }

    delay(10000);
    cleardevice();
    closegraph();
}
