#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#endif // SHAPES_H_INCLUDED
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14159265

void cord()//function for drawing coordinates
{
    int i,j;
    for(i=0,j=320; i<641;)
        putpixel(i++,j,15);
    for(i=0,j=320; i<641;)
        putpixel(j,i++,15);
}
/*	CS340 Computer Graphics Assignment
Md Syed Ahamad		1301030		B.tech		Computer Science and Engineering
IIIT Guwahati. 
*/
//I have used window tab of 640X640 size throught the whole function
/*All the following functions are written in this package:
1. Midpoint Algo for line
1a. Midpoint Algo for line with color option
2. Bresenhem's Line Algo
3. DDA Line Algo
4. Wu's Line Algo
5. Parametric  Circle Algo
6. Catesian Circle Algo
7. Bresenhem's Circle Algo
8. Midpoint Circle Algo
9. Cartesian Ellipse Algo
10. Parametric Ellipse Algo
11. Midpoint Ellipse Algo
12. DDALine Algo with color choice
13. Translation
14. Rotation
15. Scaling
16. Polygon translation
17. Polygon rotation
18. Polygon scaling
19. Polygon Reflection
20. Rgion codes function used for Cohen Sutherland Algo
21. Nicoll Lee Nicholl Line clipping Algo
22. Liang Barsky Line clipping Algo
23. Cohen Sutherland Line clipping Algo
24. Shearing
*/


//x1,y1 => initial coordinates, x2,y2 => final coordinates
//m=slope, x,y are involved in each pixel drawing
//xc,yc are coordinate of center of all conical drawings, r=radius rx=radius w.r.t x coord. ry=radius w.r.t y coord.

void midLine(int x1,int y1,int x2,int y2)
{
    //converting into catersian coordinate
    x1=320+x1;
    y1=320-y1;
    x2=320+x2;
    y2=320-y2;
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
            for(i=1; i<dx; i++)
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
            for(i=1; i<dy; i++)
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
            for(i=1; i<dx; i++)
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
            for(i=1; i<dy; i++)
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

void midLine(int x1,int y1,int x2,int y2,int c)
{
    //converting into catersian coordinate
    x1=320+x1;
    y1=320-y1;
    x2=320+x2;
    y2=320-y2;
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
            putpixel(x,y,c);
            p=(0.5)-m;
            for(i=1; i<=dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1-m;
                    putpixel(++x,++y,c);

                }
                else
                {
                    p=p-m;
                    putpixel(++x,y,c);
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
            putpixel(x,y,c);
            p=1-(m/2);
            for(i=1; i<=dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,c);

                }
                else
                {
                    p=p+1-m;
                    putpixel(++x,++y,c);
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
            putpixel(x,y,c);
            p=-0.5-m;
            for(i=1; i<=dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1+m;
                    putpixel(++x,--y,c);

                }
                else
                {
                    p=p+m;
                    putpixel(++x,y,c);
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
            putpixel(x,y,c);
            p=(m/2)+1;
            for(i=1; i<=dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,c);

                }
                else
                {
                    p=p+1+m;
                    putpixel(--x,++y,c);
                }
            }
        }
    }
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

    for(i=0; i<step; i++)
    {
        x=x+Dx;
        y=y+Dy;
        putpixel(x,y,3);
    }

}

void wuLine(int x1,int y1,int x2,int y2)
{
    int temp,xs;
    float dx,dy,m,ys,yinter,xsgap,xfgap,yf;

    if(x1>x2)
    {
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    dx = x2-x1;
    dy = y2-y1;
    m = dy/dx;

    if (m < 1)
    {
        xs = x1 + 0.5;
        ys = y1 + m * (xs - x1);
        yinter = ys + m;
        xsgap = xs + 0.5 - x1;

        int ysf = ys;
        float col = (ysf+1-ys)*xsgap;
        putpixel(xs,ysf,col);
        col = (ys - ysf) * xsgap;
        putpixel(xs,ysf+1,col);

        int xf = x2+0.5;
        yf = y2 + m * (xf - x2);
        int x2f = x2+0.5;
        xfgap = x2 + 0.5 - x2f;
        int yff = yf;
        col = (yff + 1 - yf)*xfgap;
        putpixel(xf,yff,col);
        col = (yf - yff)*xfgap;
        putpixel(xf,yff+1,col);

        int k;
        int yinterf;
        for(k=x1+1; k<=x2-1; k++)
        {
            yinterf = yinter;
            col = yinterf+1-yinter;
            putpixel(k,yinterf,col);
            col = yinter - yinterf;
            putpixel(k,yinterf+1,col);
            yinter = yinter + m;

        }


    }
}

void paraCircle(int xc,int yc,int r)//for parametric circle algo
{
    cord();
    float val = PI / 180;

    int x1,x2,y1,y2;
    float th,dlt,x,y;
    x1=320;
    y1=320;
    xc = 320 + xc;
    yc = 320 - yc;

    x1 = xc + 0.5;
    y1 = yc + r + 0.5;
    putpixel(x1,y1,3);

    y1 = yc - r + 0.5;
    putpixel(x1,y1,3);

    x2 = xc + r + 0.5;
    y2 = yc + 0.5;
    putpixel(x2,y2,3);

    x2 = xc - r + 0.5;
    putpixel(x2,y2,3);

    th=dlt = 1;
    while(th<=45)
    {
        x = r * cos(th*val);
        y = r * sin(th*val);
        th = th + dlt;

        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
        putpixel(xc+y+0.5,yc+x+0.5,3);
        putpixel(xc+y+0.5,yc-x+0.5,3);
        putpixel(xc-y+0.5,yc+x+0.5,3);
        putpixel(xc-y+0.5,yc-x+0.5,3);

    }
    if(th == 45)
    {
        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
    }

}
void carteCircle(int x1, int y1, int r)
{
    cord();

    x1=320+x1;
    y1=320-y1;
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

}

void bresenCircle(int xc, int yc,int r)
{
    cord();

    int x=0,y=r+0.5,p=3-2*r+0.5;
    xc = 320 + xc;
    yc = 320 - yc;

    while(x<=y)
    {
        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
        putpixel(xc+y+0.5,yc+x+0.5,3);
        putpixel(xc+y+0.5,yc-x+0.5,3);
        putpixel(xc-y+0.5,yc+x+0.5,3);
        putpixel(xc-y+0.5,yc-x+0.5,3);
        x++;
        if(p<0)
            p=p+4*x+6;
        else
        {
            y=y-1;
            p=p+4*(x-y)+10;
        }
    }
}

void midCircle(int xc,int yc,int r)
{
    cord();

    int x=0,y=r+0.5,p=1.25-2*r+0.5,X=x,Y=2*y;
    xc = 320 + xc;
    yc = 320 - yc;

    putpixel(xc+x+0.5,yc+y+0.5,3);
    putpixel(xc+x+0.5,yc-y+0.5,3);
    putpixel(xc-x+0.5,yc+y+0.5,3);
    putpixel(xc-x+0.5,yc-y+0.5,3);

    while(x<y)
    {
        x++;
        X+=2;
        if(p<0)
            p=p+X+1;
        else
        {
            Y=Y-2;
            p=p+X+1-Y;
            y--;
        }

        putpixel(xc+x+0.5,yc+y+0.5,3);
        putpixel(xc+x+0.5,yc-y+0.5,3);
        putpixel(xc-x+0.5,yc+y+0.5,3);
        putpixel(xc-x+0.5,yc-y+0.5,3);
        putpixel(xc+y+0.5,yc+x+0.5,3);
        putpixel(xc+y+0.5,yc-x+0.5,3);
        putpixel(xc-y+0.5,yc+x+0.5,3);
        putpixel(xc-y+0.5,yc-x+0.5,3);

    }
}

void carteEllipse(int xc,int yc, int rx,int ry)
{
    cord();
    int x0=320;
    int y0=320;
    int x1,y1,x2,x3,y2,y3,x,y,xc1,yc1;

    xc=x0+xc;
    yc=y0-yc;
    x1=xc+rx+0.5;
    y1=yc+0.5;
    x2=xc-rx+0.5;
    y2=yc+ry+0.5;
    x3=xc+0.5;
    y3=yc-ry+0.5;

    putpixel(x1,y1,3);
    putpixel(x2,y1,3);
    putpixel(x3,y2,3);
    putpixel(x3,y3,3);

    if(rx>ry)
    {
        x=rx-0.5;
    }
    else if(ry>rx)
    {
        y=ry-0.5;
    }
    xc1=xc+0.5;
    yc1=yc+0.5;
    if(rx>ry)
    {
        while(x>0)
        {
            y=sqrt((ry*ry)-(ry*ry*x*x)/(rx*rx))+0.5;
            putpixel(xc1+x,yc1+y,3);
            putpixel(xc1-x,yc1+y,3);
            putpixel(xc1+x,yc1-y,3);
            putpixel(xc1-x,yc1-y,3);
            x=x-1;
        }
    }
    else
    {
        while(y>0)
        {
            x=sqrt((rx*rx)-(rx*rx*y*y)/(ry*ry))+0.5;
            putpixel(xc1+x,yc1+y,3);
            putpixel(xc1+x,yc1-y,3);
            putpixel(xc1-x,yc1+y,3);
            putpixel(xc1-x,yc1-y,3);
            y=y-1;
        }
    }
}

void paraEllipse(int xc,int yc,int rx,int ry)
{
    cord();
    int x0=320;
    int y0=320;
    int x1,y1,x2,y2,y3,x3;
    float th,dlt,x,y;
    float val=PI/180;


    xc=x0+xc;
    yc=y0-yc;

    x1=xc+rx+0.5;
    y1=yc+0.5;
    y2=yc+ry+0.5;
    x2=xc-rx+0.5;
    y3=yc-ry+0.5;
    x3=xc+0.5;
    putpixel(x1,y1,3);
    putpixel(x2,y1,3);
    putpixel(x3,y2,3);
    putpixel(x3,y3,3);
    th = 1;
    dlt=1;
    while(th<=90)
    {
        x=rx*cos(th*val);
        y=ry*sin(th*val);
        x1=xc+x+0.5;
        y1=yc+y+0.5;
        x2=xc-x+0.5;
        y2=yc-y+0.5;

        putpixel(x1,y1,3);
        putpixel(x2,y1,3);
        putpixel(x1,y2,3);
        putpixel(x2,y2,3);

        th=th+dlt;
    }

}

void midEllipse(int xc,int yc,int rx,int ry)
{
    cord();
    int x,xcomp,y,rx2,ry2,_2rx2,_2ry2,X,Y,p1,p2,temp;


    xc=320+xc;
    yc=320-yc;

    x=0;
    xcomp=rx+0.5;
    y=ry+0.5;
    rx2=(rx*rx)+0.5;
    ry2=(ry*ry)+0.5;
    _2rx2=2*rx2;
    _2ry2=2*ry2;
    X=x;
    Y=_2rx2*y;
    temp=(1/4)*rx2;
    p1=ry2-rx2*y+temp;

    putpixel(floor(xc+0.5),(floor(yc+0.5))+y,3);
    putpixel(floor(xc+0.5),(floor(yc+0.5))-y,3);
    putpixel((floor(xc+0.5))+xcomp,floor(yc+0.5),3);
    putpixel((floor(xc+0.5))-xcomp,floor(yc+0.5),3);

    while((_2ry2*x) < (_2rx2*y))
    {
        x+=1;
        X=X+_2ry2;
        if(p1<0)
        {
            p1=p1+X+ry2;
        }
        else
        {
            Y=Y - _2rx2;
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
        Y=Y- _2rx2;
        if(p2>0)
        {
            p2=p2+rx2-Y;
        }
        else
        {
            X=X+ _2ry2;
            p2=p2+rx2-Y+X;
            x+=1;
        }
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,3);
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,3);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,3);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,3);
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

    for(i=0; i<step; i++)
    {
        x=x+Dx;
        y=y+Dy;
        putpixel(x,y,c);
    }

}

void Translate(int x1,int y1,int x2,int y2, int tx, int ty)
{
    midLine(x1,y1,x2,y2,0);
    x1=x1+tx;
    y1=y1+ty;
    x2=x2+tx;
    y2=y2+ty;
    midLine(x1,y1,x2,y2,3);
}
void Rotate(int x1,int y1,int x2,int y2, int fx, int fy, float th)
{
    midLine(x1,y1,x2,y2,0);
    th=(th/180)*PI;
    int d=x1;
    x1=fx+(d-fx)*cos(th)-(y1-fy)*sin(th);
    y1=fy+(d-fx)*sin(th)+(y1-fy)*cos(th);
    d=x2;
    x2=fx+(d-fx)*cos(th)-(y2-fy)*sin(th);
    y2=fy+(d-fx)*sin(th)+(y2-fy)*cos(th);
    midLine(x1,y1,x2,y2,3);
}

void scale(int x1,int y1,int x2,int y2, int fx, int fy, int sx, int sy)
{
    midLine(x1,y1,x2,y2,0);
    x1=x1*sx+(1-sx)*fx;
    y1=y1*sy+(1-sy)*fy;
    x2=x2*sx+(1-sx)*fx;
    y2=y2*sy+(1-sy)*fy;
    midLine(x1,y1,x2,y2,3);
}
void polyTranslate(int l,int* x1,int* y1, int tx, int ty)
{

    int k=0,i;
    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],0);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],0);

    for(i=0; i<l; i++)
    {
        x1[i]=x1[i]+tx;
        y1[i]=y1[i]+ty;
    }
    k=0;
    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],3);
}

void polyRotate(int l,int* x1,int* y1, int fx, int fy,float th)
{
    th=(th/180)*PI;
    int  k=0,i,d;
    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],0);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],0);

    for(i=0; i<l; i++)
    {
        d=x1[i];
        x1[i]=fx+(d-fx)*cos(th)-(y1[i]-fy)*sin(th);
        y1[i]=fy+(d-fx)*sin(th)+(y1[i]-fy)*cos(th);
    }
    k=0;
    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],3);
}

void polyScale(int l,int* x1,int* y1, int fx, int fy,int sx, int sy)
{
    int i,k=0;
    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],0);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],0);

    for(i=0; i<l; i++)
    {
        x1[i]=x1[i]*sx+(1-sx)*fx;
        y1[i]=y1[i]*sy+(1-sy)*fy;
    }
    k=0;
    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],3);
}

void polyReflection(int l, int* x1,int* y1,float m,int c)
{
        int  i,k=0;
         while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],0);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],0);

            if(m==0)
            {
                for(i=0;i<l;i++)
                {
               y1[i]=-1*y1[i]+c;
                }
            }
            else if(m==INFINITY)
            {
                for(i=0;i<l;i++)
                {
                    x1[i]=-1*x1[i]+c;
                }
            }
            else
            {
                int d;
                for(i=0;i<l;i++)
                {
                    d=x1[i];
                    x1[i]=(y1[i]-c)/m+0.5;
                    y1[i]=m*d+c+0.5;
                }

            }

            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
}

int regionCodes(int lx, int ex)
{
    int cmp=lx-ex;
    int rcodes;
    if(cmp<0)
        rcodes=1;
    else
        rcodes=0;
    return rcodes;
}
int NichollLee(int xmin,int ymin,int xmax,int ymax,int x1,int y1, int x2, int y2)
{
    int p,q;
    float m1,m2,m3,m4,m;
    m1=(y1-ymin)/(1.00*(x1-xmin));
    m2=(y1-ymin)/(1.00*(x1-xmax));
    m3=(y1-ymax)/(1.00*(x1-xmin));
    m4=(y1-ymax)/(1.00*(x1-xmax));
    m=(y2-y1)/(1.00*(x2-x1));
    printf("%f %f %f %f %f \n",m1,m2,m3,m4,m);


    p=(regionCodes(ymax,y1)<<3)+(regionCodes(y1,ymin)<<2)+(regionCodes(xmax,x1)<<1)+regionCodes(x1,xmin);
    q=(regionCodes(ymax,y2)<<3)+(regionCodes(y2,ymin)<<2)+(regionCodes(xmax,x2)<<1)+regionCodes(x2,xmin);
    printf("p=%d q=%d \n",p,q);

    if(p==0)
    {
        if(q==0)
        {
            midLine(x1,y1,x2,y2);
            return 0;
        }
        else if((q&1)!=0 && m1>m && m3<m)//checking L region
        {
            midLine(x1,y1,xmin,y1+m*(xmin-x1)+0.5);
            return 0;
        }
        else if((q&2)!=0 && m>m2 && m<m4)//checking R region
        {
            midLine(x1,y1,xmax,y1+m*(xmax-x1)+0.5);
            return 0;
        }
        else if((q&4)!=0 && (m>m1 || m<m2))//checking B region
        {
            midLine(x1,y1,x1+(1/m)*(ymin-y1)+0.5,ymin);
            return 0;
        }
        else if((q&8)!=0 && (m>m4 || m<m3))//checking T region
        {
            midLine(x1,y1,x1+(1/m)*(ymax-y1)+0.5,ymax);
            return 0;
        }
    }
        return 0;
}

int LiangBarskyAlgo(int xmin,int ymin,int xmax,int ymax,int x1,int y1, int x2, int y2)
{
    int xs=x1,ys=y1,xe=x2,ye=y2,i;
    float u[4],u1=0.0,u2=1.0;
    int dx=x2-x1,dy=y2-y1;
    int p[4]= {-1*dx,dx,-1*dy,dy};
    int q[4]= {x1-xmin,xmax-x1,y1-ymin,ymax-y1};


    for(i=0; i<4; i++)
    {
        u[i]=q[i]/(p[i]*1.00);
        if(p[i]<0)
        {
            if(u[i]>u2)
                return 0;
            else if(u[i]>u1)
                u1=u[i];
        }
        else if(p[i]>0)
        {
            if(u[i]<u1)
                return 0;
            else if(u[i]<u2)
                u2=u[i];
        }
        else
        {
            if(q[i]<0)
                return 0;
        }
    }
    printf("u1=%f u2=%f\n",u1,u2);
    if(u1>0)
    {
        xs=x1+u1*dx+0.5;
        ys=y1+u1*dy+0.5;
    }
    if(u2<1)
    {
        xe=x1+u2*dx+0.5;
        ye=y1+u2*dy+0.5;
    }
    midLine(xs,ys,xe,ye);

    return 0;
}

int SuderlandAlgo(int xmin,int ymin,int xmax,int ymax,int x1,int y1, int x2, int y2)
{
    int p,q,s,e,xs,ys,xe,ye,temp1;
    float m;
    m=(y2-y1)/((x2-x1)*1.00);
    p=(regionCodes(ymax,y1)<<3)+(regionCodes(y1,ymin)<<2)+(regionCodes(xmax,x1)<<1)+regionCodes(x1,xmin);
    q=(regionCodes(ymax,y2)<<3)+(regionCodes(y2,ymin)<<2)+(regionCodes(xmax,x2)<<1)+regionCodes(x2,xmin);
    printf("P=%d Q=%d",p,q);

    if((p|q)==0)
    {
        midLine(x1,y1,x2,y2);
        return 0;
    }
    else if((p&q)!=0)
        return 0;
    s=p;
    e=q;
    xs=x1;
    ys=y1;
    xe=x2;
    ye=y2;
    int c;

    while((s|e)!=0 && (s&e)==0)
    {
        if(s!=0)
            c=s;
        else
        {
            c=e;
            e=s;
            //swap
            temp1=xs;
            xs=x2;
            xe=temp1;
            temp1=ys;
            ys=y2;
            ye=temp1;
        }
        if((c&1)!=0)
        {
            xs=xmin;
            ys=y1+m*(xmin-x1)+0.5;
            printf("(c&1)m=%f xs=%d ys=%d\n",m,xs,ys);
        }
        else
        {
            if((c&2)!=0)
            {
                xs=xmax;
                ys=y1+m*(xmax-x1)+0.5;
                printf("(c&2)m=%f xs=%d ys=%d\n",m,xs,ys);
            }
            else
            {
                if((c&4)!=0)
                {
                    ys=ymin;
                    xs=x1+(1/m)*(ymin-y1)+0.5;
                    printf("(c&4)m=%f xs=%d ys=%d\n",m,xs,ys);
                }
                else
                {
                    if((c&8)!=0)
                    {
                        ys=ymax;
                        xs=x1+(1/m)*(ymax-y1)+0.5;
                        printf("(c&8)m=%f xs=%d ys=%d\n",m,xs,ys);
                    }
                }
            }
        }
        s=(regionCodes(ymax,ys)<<3)+(regionCodes(ys,ymin)<<2)+(regionCodes(xmax,xs)<<1)+regionCodes(xs,xmin);
        printf("while loop s=%d e=%d\n",s,e);
    }

    if((s|e)==0)
    {
        midLine(xs,ys,xe,ye);
        return 0;
    }
    else if((s&e)!=0)
        return 0;

    return 0;
}

void Shearing(int* x1,int*y1,int xref,int yref,float shx, float shy)
{
            int k=0,i;
            while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],0);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],0);

            for(i=0;i<4;i++)
            {
               x1[i]=x1[i]+shx*y1[i]-shx*yref;
               y1[i]=y1[i]+shy*x1[i]-shy*xref;
            }
            k=0;
            while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
}
