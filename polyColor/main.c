#include<stdio.h>
#include<graphics.h>
#include<math.h>


void DDALine(int,int,int,int);
void scanFill(int,int,int,int);


void cord()
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
        DDALine(x1[k],y1[k],x1[k+1],y1[k+1]);
        k++;
    }
    DDALine(x1[k],y1[k],x1[0],y1[0]);

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

void scanFill(int x, int y,int fc, int bc)//scanline color filling algo
{                                          //fc->fill color, bc-> boundary color
    int ox=x;
    int dc=getpixel(x,y);
    if(dc!=bc && dc!=fc)
    {
        while(getpixel(--x,y)!=bc)
            {
                putpixel(x,y,fc);
            }
        while(getpixel(++x,y)!=bc)
            putpixel(x,y,fc);

        x=ox;
        scanFill(x,y+1,fc,bc);
        scanFill(x,y-1,fc,bc);
    }

}

void DDALine(int x1,int y1,int x2,int y2)//DDA line Algo
{

    float dx,dy,step,i,x,y,Dx,Dy,py,px;
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

    for(i=0;i<step;i++)
    {
        x=x+Dx;
        y=y+Dy;
        putpixel(x,y,3);
    }

}
