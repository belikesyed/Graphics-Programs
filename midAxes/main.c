#include<stdio.h>
#include<graphics.h>
#include<math.h>

void cord()
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

        int x,xcomp,y,rx2,ry2,XX,YY,X,Y,p1,p2,temp;
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

        putpixel(floor(xc+0.5),(floor(yc+0.5))+y,3);
        putpixel(floor(xc+0.5),(floor(yc+0.5))-y,3);
        putpixel((floor(xc+0.5))+xcomp,floor(yc+0.5),3);
        putpixel((floor(xc+0.5))-xcomp,floor(yc+0.5),3);

        while((YY*x) < (XX*y))
        {
            x+=1;
            X=X+YY;
            if(p1<0)
            {
                p1=p1+X+ry2;
            }
            else
            {
                Y=Y - XX;
                p1=p1+X+ry2-Y;
                y-=1;
            }
            putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,3);
            putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,3);
            putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,3);
            putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,3);

        }

        p2=ry2*floor((x+0.5)*(x+0.5))+rx2*((y-1)*(y-1))-rx2*ry2;

        while(y>0)
        {
            y-=1;
            Y=Y- XX;
            if(p2>0)
            {
                p2=p2+rx2-Y;
            }
            else
            {
                X=X+ YY;
                p2=p2+rx2-Y+X;
                x+=1;
            }
            putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,3);
            putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,3);
            putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,3);
            putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,3);
        }

    delay(10000);
    closegraph();
    return 0;
}
