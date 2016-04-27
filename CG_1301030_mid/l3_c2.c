#include <stdio.h>
#include <math.h>
#include <graphics.h>
#define PI 3.14159265
//midpoint algo for circle
void cord()//for coordinate axes
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
    int x=0,y=r+0.5,p=1.25-2*r+0.5,X=x,Y=2*y;
    xc = 320 + xc;
    yc = 320 - yc;

    putpixel(xc+x+0.5,yc+y+0.5,3);
    putpixel(xc+x+0.5,yc-y+0.5,3);
    putpixel(xc-x+0.5,yc+y+0.5,3);
    putpixel(xc-x+0.5,yc-y+0.5,3);

    while(x<y)
    {
        x++;
        X+=2;
        if(p<0)
            p=p+X+1;
        else
        {
            Y=Y-2;
            p=p+X+1-Y;
            y--;
        }

        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
        putpixel(xc+y+0.5,yc+x+0.5,3);
        putpixel(xc+y+0.5,yc-x+0.5,3);
        putpixel(xc-y+0.5,yc+x+0.5,3);
        putpixel(xc-y+0.5,yc-x+0.5,3);

    }
    delay(10000);
    cleardevice();
    closegraph();
}
