#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
void midLine(int,int,int,int,int);
void rotateCube(float);

void cord()//function for drawing coordinates
{
    int i,j;
    for(i=0,j=320; i<641;)
        putpixel(i++,j,15);
    for(i=0,j=320; i<641;)
        putpixel(j,i++,15);
}

float mx1,my1,mx2,my2;
    int x1[4]={60,180,180,60};
    int y1[4]={60,60,180,180};
    int z1[4]={10,10,10,10};
    int x2[4]={10,130,130,10};
    int y2[4]={10,10,130,130};
    int z2[4]={120,120,120,120};

int main()
{
    initwindow(640,640);
    cord();
    int k=0;
     mx1=(x1[0]+x1[1])*0.5;
     mx2=(x2[0]+x2[1])*0.5;
     my1=(y1[1]+y1[2])*0.5;
     my2=(y2[1]+y2[2])*0.5;

    k=0;
    while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],4);
                midLine(x1[k],y1[k],x2[k],y2[k],5);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            midLine(x2[k],y2[k],x2[0],y2[0],4);
            midLine(x1[k],y1[k],x2[k],y2[k],5);
            float th;
            printf("Enter angle of rotation:");
            scanf("%f",&th);
            th=(th/180)*PI;
//untill any key is hit it will rotate
            while(!kbhit())
            {
                rotateCube(th);
            }

        //delay(10000);
        closegraph();
}

void rotateCube(float th)
{
    int i,k,tmp;
//cubic rotation with the given angle
    for(i=0;i<4;i++)
            {
                tmp=x1[i];
                x1[i]=mx1+(tmp-mx1)*cos(th)-(y1[i]-my1)*sin(th)+0.5;
                y1[i]=my1+(tmp-mx1)*sin(th)+(y1[i]-my1)*cos(th)+0.5;
                tmp=x2[i];
                x2[i]=mx2+(tmp-mx2)*cos(th)-(y2[i]-my2)*sin(th)+0.5;
                y2[i]=my2+(tmp-mx2)*sin(th)+(y2[i]-my2)*cos(th)+0.5;
            }
    cleardevice();
//cubic drawing at each instances
     k=0;
    while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],4);
                midLine(x1[k],y1[k],x2[k],y2[k],5);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            midLine(x2[k],y2[k],x2[0],y2[0],4);
            midLine(x1[k],y1[k],x2[k],y2[k],5);
            delay(150);
}

//line drawing algo
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

