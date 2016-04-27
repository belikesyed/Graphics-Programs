#include <stdio.h>
#include <math.h>
#include <graphics.h>
#define PI 3.14159265

void cord()//coordinate axes
{

    int i,j;
    for(i=0,j=320; i<641;)
        putpixel(i++,j,3);
    for(i=0,j=320; i<641;)
        putpixel(j,i++,3);

}

int main()
{
    initwindow(640,640);
    cord();

    int xc,yc,r;

    printf("Enter the x co-ordinate of circle : ");
    scanf("%d",&xc);
    printf("Enter the y co-ordinate of circle : ");
    scanf("%d",&yc);
    printf("Enter the radius of circle : ");
    scanf("%d",&r);
    int x=0,y=r+0.5,p=3-2*r+0.5;
    xc = 320 + xc;
    yc = 320 - yc;

    while(x<=y)
    {
        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
        putpixel(xc+y+0.5,yc+x+0.5,3);
        putpixel(xc+y+0.5,yc-x+0.5,3);
        putpixel(xc-y+0.5,yc+x+0.5,3);
        putpixel(xc-y+0.5,yc-x+0.5,3);
        x++;
        if(p<0)
            p=p+4*x+6;
        else
        {
            y=y-1;
            p=p+4*(x-y)+10;
        }
    }
    delay(10000);
    cleardevice();
    closegraph();
}
