#include<stdio.h>
#include<graphics.h>
#include<math.h>
//midpoint algo for ellipse
void cord()//coordinate axes
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

    float x,xcomp,y,rx2,ry2,XX,YY,X,Y,p1,p2,temp;
    int xc,yc,rx,ry;

    printf("Enter x: ");
    scanf("%d",&xc);
    printf("Enter y: ");
    scanf("%d",&yc);
    printf("Enter rx : ");
    scanf("%d",&rx);
    printf("Enter ry : ");
    scanf("%d",&ry);

    xc=320+xc;
    yc=320-yc;
    x=0;
    xcomp=rx+0.5;
    y=ry+0.5;
    rx2=(rx*rx)+0.5;
    ry2=(ry*ry)+0.5;
    XX=2*rx2;
    YY=2*ry2;
    X=x;
    Y=XX*y;
    temp=(1/4)*rx2;
    p1=ry2-rx2*y+temp;

    putpixel(xc+0.5,yc+0.5+y,3);
    putpixel(xc+0.5,yc+0.5-y,3);
    putpixel(xc+0.5+xcomp,yc+0.5,3);
    putpixel(xc+0.5-xcomp,yc+0.5,3);

    while((YY*x) < (XX*y))
    {
        x++;
        X=X+YY;
        if(p1<0)
        {
            p1=p1+X+ry2;
        }
        else
        {
            Y=Y - XX;
            p1=p1+X+ry2-Y;
            y--;
        }
        putpixel(xc+0.5+x,yc+0.5+y,3);
        putpixel(xc+0.5+x,yc+0.5-y,3);
        putpixel(xc+0.5-x,yc+0.5+y,3);
        putpixel(xc+0.5-x,yc+0.5-y,3);

    }

    p2=ry2*(x+0.5)*(x+0.5)+rx2*((y-1)*(y-1))-rx2*ry2;

    while(y>0)
    {
        y--;
        Y=Y- XX;
        if(p2>0)
        {
            p2=p2+rx2-Y;
        }
        else
        {
            X=X+ YY;
            p2=p2+rx2-Y+X;
            x++;
        }
        putpixel(xc+0.5+x,yc+0.5+y,3);
        putpixel(xc+0.5+x,yc+0.5-y,3);
        putpixel(xc+0.5-x,yc+0.5+y,3);
        putpixel(xc+0.5-x,yc+0.5-y,3);
    }

    delay(10000);
    closegraph();
    return 0;
}
