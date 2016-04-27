#include<stdio.h>
#include<graphics.h>
#include<math.h>

void bresenLine(int,int,int,int);
void cord() //function for drawing coordinates
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
    int x1,x2,y1,y2,i;//starting coordinate and final coordinate
    printf("Enter x1:");
    scanf("%d",&x1);
     printf("Enter y1:");
    scanf("%d",&y1);
      printf("Enter x2:");
    scanf("%d",&x2);
     printf("Enter y2:");
    scanf("%d",&y2);

    //converting into catersian coordinate
    x1=320+x1;
    y1=320-y1;
    x2=320+x2;
    y2=320-y2;
        for(i=0;i<5;i++)
        {
            bresenLine(x1,y1,x2,y2);
        }


    delay(10000);
    closegraph();
}

void bresenLine(int x1,int y1,int x2,int y2)//for bresenhem line algo
{
    float dx,dy,i,x,y,m,p,yd;
    dx=(x2-x1);
    dy=(y2-y1);
    m=dy/dx;


    x=x1;
    y=y1;

    if(m>0)
    {
        if(m<1)
        {
            if(dx<0)//if x2>x1
            {
                dx=x1-x2;
                dy=y1-y2;
                x=x2;
                y=y2;
            }
            //putpixel(x,y,3);
            p=2*dy-dx;
            for(i=0; i<dx; i++)
            {
                if(p<0)
                {
                    x=x+1;
                    putpixel(x,y+1,3);
                    putpixel(x,y+2,3);
                    putpixel(x,y+3,3);
                    putpixel(x,y+4,3);
                    putpixel(x,y+5,3);
                    p=p+2*dy;
                }
                else
                {
                    x=x+1;
                    y=y+1;

                    putpixel(x,y+1,3);
                    putpixel(x,y+2,3);
                    putpixel(x,y+3,3);
                    putpixel(x,y+4,3);
                    putpixel(x,y+5,3);
                    p=p+2*(dy-dx);
                }
            }
        }
        else //if m>1
        {
            if(dy<0)
            {
                dx=x1-x2;
                dy=y1-y2;
                x=x2;
                y=y2;
            }
            putpixel(x,y,3);
            p=2*dx-dy;
            for(i=1; i<dy; i++)
            {
                if(p<0)
                {
                    y=y+1;
                    putpixel(x+1,y,3);
                    putpixel(x+2,y,3);
                    putpixel(x+3,y,3);
                    putpixel(x+4,y,3);
                    putpixel(x+5,y,3);
                    p=p+2*dx;
                }
                else
                {
                    x=x+1;
                    y=y+1;
                    putpixel(x+1,y,3);
                    putpixel(x+2,y,3);
                    putpixel(x+3,y,3);
                    putpixel(x+4,y,3);
                    putpixel(x+5,y,3);
                    p=p+2*(dx-dy);
                }
            }
        }

    }
    else
    {
        if(m>-1)
        {
            if(x1>x2)
            {
                dx=x1-x2;
                dy=y1-y2;
                x=x2;
                y=y2;
            }
            //putpixel(x,y,3);
            p=-2*dy-dx;
            for(i=0; i<dx; i++)
            {
                if(p<0)
                {
                    x=x+1;
                    putpixel(x,y+1,3);
                    putpixel(x,y+2,3);
                    putpixel(x,y+3,3);
                    putpixel(x,y+4,3);
                    putpixel(x,y+5,3);
                    p=p-2*dy;
                }
                else
                {
                    x=x+1;
                    y+y-1;
                    putpixel(x,y+1,3);
                    putpixel(x,y+2,3);
                    putpixel(x,y+3,3);
                    putpixel(x,y+4,3);
                    putpixel(x,y+5,3);
                    p=p-2*(dy+dx);
                }
            }
        }
        else
        {

            if(y2>y1)
            {
                x=x2;
                y=y2;
                dy=y1-y2;
                dx=x1-x2;
            }
            putpixel(x,y,3);
            yd=-1*dy;
            p=-2*dx-dy;
            for(i=0; i<yd; i++)
            {
                if(p<0)
                {
                    y=y-1;
                    putpixel(x+1,y,3);
                    putpixel(x+2,y,3);
                    putpixel(x+3,y,3);
                    putpixel(x+4,y,3);
                    putpixel(x+5,y,3);
                    p=p+2*dx;
                }
                else
                {
                    x=x+1;
                    y=y-1;
                    putpixel(x+1,y,3);
                    putpixel(x+2,y,3);
                    putpixel(x+3,y,3);
                    putpixel(x+4,y,3);
                    putpixel(x+5,y,3);
                    p=p+2*(dx+dy);
                }
            }
        }
    }
}

