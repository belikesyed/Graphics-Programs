#include<stdio.h>
#include<graphics.h>
#include<math.h>

void DDALine(int,int,int,int);//DDA line algo
void DDALineC(int,int,int,int,int);//DDA line algo with user color option

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
    int x1,x2,y1,y2;
    int i,c;
    printf("***Standard Rectangle Drawing***");
    printf("\nEnter x1: ");
    scanf("%d",&x1);
    printf("Enter y1: ");
    scanf("%d",&y1);
    printf("Enter opp. coordinate x2: ");
    scanf("%d",&x2);
    printf("Enter opp. coordinate y2: ");
    scanf("%d",&y2);
    printf("Enter color code of the rectangle: ");
    scanf("%d",&c);

    x1=320+x1;
    x2=320+x2;
    y1=320-y1;
    y2=320-y2;
//drawing rectangle
    DDALine(x1,y1,x1,y2);
    DDALine(x1,y1,x2,y1);
    DDALine(x2,y2,x1,y2);
    DDALine(x2,y2,x2,y1);


    //filling inside rectangle

    for(i=x1+1;i<x2;i++)
    {
        DDALineC(i,y1-1,i,y2,c);
    }

    delay(10000);
    closegraph();
}

void DDALine(int x1,int y1,int x2,int y2)//for DDA line algo
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

    for(i=1; i<step; i++)
    {
        x=x+Dx;
        y=y+Dy;
        putpixel(x,y,3);
    }

}

void DDALineC(int x1,int y1,int x2,int y2,int c)
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
    putpixel(x1,y1,c);
    x=x1,y=y1;

    for(i=1; i<step; i++)
    {
        x=x+Dx;
        y=y+Dy;
        putpixel(x,y,c);
    }

}

