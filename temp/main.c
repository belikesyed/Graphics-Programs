#include<stdio.h>
#include<graphics.h>
#include<math.h>



void scanFill(int,int,int,int);
void midLine(int,int,int,int);
int bFill4(int,int,int,int);
int oldx;

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
    int x,y,i,l,k=0;
    int fc;

    printf("Enter no. edge:");
    scanf("%d",&l);

    int x1[l],y1[l];

    for(i=0;i<l;i++)
    {
        printf("Enter x[%d]:",i);
        scanf("%d",&x1[i]);
        printf("Enter y[%d]:",i);
        scanf("%d",&y1[i]);

        x1[i]=320+x1[i];
        y1[i]=320-y1[i];

    }


    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1]);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0]);

  int bc=3;
    printf("Enter any enterior x:");
    scanf("%d",&x);
     printf("Enter any enterior y:");
    scanf("%d",&y);
    printf("Enter enterior color code:");
    scanf("%d",&fc);
    scanFill(320+x,320-y,fc,bc);


    delay(10000);
    closegraph();
}

void scanFill(int x, int y,int fc, int bc)
{
    int ny=0,dc=getpixel(x,y),ox;
    while(dc!=bc && dc!=fc)
    {
        x--;
        dc=getpixel(x,y);
    }
    x++;
    ox=x;
    ny=bFill4(x,y,fc,bc);
    if(ny!=0)
    {
        while(getpixel(x,y)!=fc && getpixel(x,y)!=bc)
        {
            putpixel(x++,y,fc);
        }
        scanFill(oldx,ny,fc,bc);
    }
}

int bFill4(int x,int y,int fc,int bc)
{
    int dc=getpixel(x,y-1),k;
    int uc=getpixel(x,y+1);
    if(dc!=fc && dc!=bc)
    {
        oldx=x;
        return y-1;
    }
    /*else if(uc!=fc && uc!=bc)
    {
        oldx=x;
        return y-1;
    }*/
    else if(getpixel(x+1,y)!=bc && getpixel(x+1,y)!=fc)
    {
        k=bFill4(x+1,y,fc,bc);
        return k;
    }
    return 0;
}

void midLine(int x1,int y1,int x2,int y2)
{
    float dx,dy,m,p;
    int i,x,y;
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
            for(i=1; i<=dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
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
        else
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
            for(i=1; i<=dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
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
            putpixel(x,y,3);
            p=-0.5-m;
            for(i=1; i<=dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
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
        else
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
            for(i=1; i<=dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
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
}


