#include<stdio.h>
#include<graphics.h>
#include<math.h>
//midpoint line algo
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

    int x1,y1,x2,y2,x,y,i;
    float m,p,dx,dy;
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

    dx=(x2-x1);
    dy=(y2-y1);
    m=dy/dx;


    x=x1;
    y=y1;

    if(m>=0)
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
            putpixel(x,y,3);
            p=(0.5)-m;
            for(i=1;i<dx;i++)
            {
                printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1-m;
                    putpixel(++x,++y,3);

                }
                else
                {
                    p=p-m;
                    putpixel(++x,y,3);
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
            p=1-(m/2);
            for(i=1;i<dy;i++)
            {
                printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,3);

                }
                else
                {
                    p=p+1-m;
                    putpixel(++x,++y,3);
                }
            }
        }
    }
    else //if m<0
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
            p=-0.5-m;
            for(i=1;i<dx;i++)
            {
                printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1+m;
                    putpixel(++x,--y,3);

                }
                else
                {
                    p=p+m;
                    putpixel(++x,y,3);
                }
            }
        }
        else //if m<-1
        {
            if(y2<y1)
            {
                x=x2;
                y=y2;
                dy=y1-y2;
                dx=x1-x2;
            }
            putpixel(x,y,3);
            p=(m/2)+1;
            for(i=1;i<dy;i++)
            {
                printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,3);

                }
                else
                {
                    p=p+1+m;
                    putpixel(--x,++y,3);
                }
            }
        }
    }


    delay(10000);
    closegraph();
}

