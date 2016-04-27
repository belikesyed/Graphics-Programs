#include<stdio.h>
#include<graphics.h>
#include<math.h>

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
    int x1,y1,yc,xc,r;
    printf("\nEnter centre of x-axis: ");
    scanf("%d",&xc);
    printf("\nEnter centre of y-axis: ");
    scanf("%d",&yc);
    printf("\nEnter radius: ");
    scanf("%d",&r);
    x1=320+xc;
    y1=320-yc;

    int i=(x1-r+0.5),j=(y1+0.5);
    putpixel(i,j,3);
    putpixel(i+r+r,j,3);
    int x,y,z;


    for(x=(x1-r+0.5)+1; x<(x1+r+0.5)-1; x++)
    {
        y=y1+sqrt(r*r-(x1-x)*(x1-x));
        z=y+0.5;
        putpixel(x,z,3);
        y=y1-sqrt(r*r-(x1-x)*(x1-x));
        z=y+0.5;
        putpixel(x,z,3);
    }


    delay(10000);
    closegraph();
}


