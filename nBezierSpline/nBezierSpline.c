#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468

void midLine(int,int,int,int,int);
float BezierSpline(int, float*,float*);

struct node
{
  float x;
  float y;
  struct node *next;
}*start;



struct node *getNode()
{
 struct node *newNode;
 newNode= (struct node *)(malloc(sizeof(struct node)));
 return newNode;
}
void cord()//function for drawing coordinates
{
    int i,j;
    for(i=0,j=320; i<641;)
        putpixel(i++,j,15);
    for(i=0,j=320; i<641;)
        putpixel(j,i++,15);
}

int max(int qx, int rx)
{
    if(qx>rx)
        return qx;
    else
        return rx;

  return 0;
}


int main()
{
    initwindow(640,640);
    cord();

    int i,n;
    printf("Enter degree of the Spline:");
    scanf("%d",&n);
    n=n+1;
    float x[n],y[n];

    for(i=0;i<n;i++)
    {
        printf("Enter Control point x[%d]:",i);
        scanf("%f",&(x[i]));
         printf("Enter Control point y[%d]:",i);
        scanf("%f",&(y[i]));
    }

    midLine(x[0],y[0],x[1],y[1],2);
    delay(20);
    midLine(x[1],y[1],x[2],y[2],2);
    delay(20);
    midLine(x[2],y[2],x[3],y[3],2);
    delay(20);

    BezierSpline(n,x,y);


    delay(10000);
    closegraph();
}

float BezierSpline(int n, float* x, float* y)
{
    float dx,dy,dmin;
    float qx,qy,rx,ry;
    //stopping condition
    qx=3*x[1]-2*x[0]-x[3];
    qy=3*y[1]-2*y[0]-y[3];
    rx=3*x[2]-2*x[3]-x[0];
    ry=3*y[2]-2*y[3]-y[0];

    qx=qx*qx;
    qy=qy*qy;
    rx=rx*rx;
    ry=ry*ry;

    dx=max(qx,rx);
    dy=max(qy,ry);
    dmin=16;

    if((dx+dy)<dmin)
    {
        midLine(x[0],y[0],x[1],y[1],4);
        delay(20);
        midLine(x[1],y[1],x[2],y[2],4);
        delay(20);
        midLine(x[2],y[2],x[3],y[3],4);
        delay(20);
        return 0;
    }
    else
    {
        //recursive division of spline into sub-splines through control points
        float x1[4],y1[4],x2[4],y2[4];
        float xx=0.5*(x[1]+x[2]);
        float yy=0.5*(y[1]+y[2]);

        x1[1]=0.5*(x[0]+x[1]);
        y1[1]=0.5*(y[0]+y[1]);
        x1[2]=0.5*(x1[1]+xx);
        y1[2]=0.5*(y1[1]+yy);
        x2[2]=0.5*(x[2]+x[3]);
        y2[2]=0.5*(y[2]+y[3]);
        x2[1]=0.5*(x2[2]+xx);
        y2[1]=0.5*(y2[2]+yy);
        x2[0]=0.5*(x1[2]+x2[1]);
        y2[0]=0.5*(y1[2]+y2[1]);
        x1[0]=x[0];y1[0]=y[0];
        x1[3]=x2[0];y1[3]=y2[0];
        x2[3]=x[3];y2[3]=y[3];

        BezierSpline(n,x1,y1);
        BezierSpline(n,x2,y2);

    }
    return 0;
}

//line drawing algorithm
void midLine(int x1,int y1,int x2,int y2, int color)
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
            putpixel(x,y,color);
            p=(0.5)-m;
            for(i=1; i<dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1-m;
                    putpixel(++x,++y,color);

                }
                else
                {
                    p=p-m;
                    putpixel(++x,y,color);
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
            putpixel(x,y,color);
            p=1-(m/2);
            for(i=1; i<dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,color);

                }
                else
                {
                    p=p+1-m;
                    putpixel(++x,++y,color);
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
            putpixel(x,y,color);
            p=-0.5-m;
            for(i=1; i<dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1+m;
                    putpixel(++x,--y,color);

                }
                else
                {
                    p=p+m;
                    putpixel(++x,y,color);
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
            putpixel(x,y,color);
            p=(m/2)+1;
            for(i=1; i<dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,color);

                }
                else
                {
                    p=p+1+m;
                    putpixel(--x,++y,color);
                }
            }
        }
    }
}
