#include<stdio.h>
#include<math.h>
#include<graphics.h>

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
    float dx,dy,step,i,x,y,Dx,Dy,py,px;
    int x1,y1,x2,y2;
    printf("\nEnter x1: ");
    scanf("%d",&x1);
    printf("\nEnter y1: ");
    scanf("%d",&y1);
    printf("\nEnter x2: ");
    scanf("%d",&x2);
    printf("\nEnter y2: ");
    scanf("%d",&y2);
//for converting into cartesian coordinate
    x1=320+x1;
    y1=320-y1;
    x2=320+x2;
    y2=320-y2;
    dx=x2-x1;
    dy=y2-y1;
    if(x2>x1)
        px=x2-x1;
    else
        px=x1-x2;
    if(y2>y1)
        py=y2-y1;
    else
        py=y1-y2;

    if(px>py)
        step=px;
    else
        step=py;

    Dx=dx/step;
    Dy=dy/step;
    putpixel(x1,y1,3);
    x=x1,y=y1;

    for(i=0; i<step; i++)
    {
        x=x+Dx;
        y=y+Dy;
        putpixel(x,y,3);
    }

    delay(10000);
    closegraph();
}
