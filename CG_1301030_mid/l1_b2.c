#include<stdio.h>
#include<graphics.h>
#include<math.h>


//bresenhem line algo
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
    int x1,x2,y1,y2;//starting coordinate and final coordinate
    float dx,dy,i,x,y,m,p,yd,xd;
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

    dx=(x2-x1);
    dy=(y2-y1);
    m=dy/dx;
    x=x1;
    y=y1;

    if(m>0)
    {
        if(m<1)
        {
            if(dx<0)//if final coordinate is smaller than that of initial
                {
                    dx=x1-x2;
                    dy=y1-y2;
                    x=x2;
                    y=y2;
                }
            putpixel(x,y,3);
            p=2*dy-dx;
            for(i=0; i<dx; i++)
            {
                if(p<0)
                {
                    putpixel(++x,y,3);
                    p=p+2*dy;
                }
                else
                {
                    putpixel(++x,++y,3);
                    p=p+2*(dy-dx);
                }
            }
        }
        else//if m>1
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
                    putpixel(x,++y,3);
                    p=p+2*dx;
                }
                else
                {
                    putpixel(++x,++y,3);
                    p=p+2*(dx-dy);
                }
            }
        }

    }
    else//if m<0
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
            putpixel(x,y,3);
            p=-2*dy-dx;
            for(i=0; i<dx; i++)
            {
                if(p<0)
                {
                    putpixel(++x,y,3);
                    p=p-2*dy;
                }
                else
                {
                    putpixel(++x,--y,3);
                    p=p-2*(dy+dx);
                }
            }
        }
        else //if m<-1
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
                    putpixel(x,--y,3);
                    p=p+2*dx;
                }
                else
                {
                    putpixel(++x,--y,3);
                    p=p+2*(dx+dy);
                }
            }
        }
    }


    delay(10000);
    closegraph();
}

