#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
//3D Polygon Reflection
void midLine(int,int,int,int,int);


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
    int i,l=4,k=0;
//cubic coordinates are initialized
    int x1[4]={60,180,180,60};
    int y1[4]={60,60,180,180};
    int z1[4]={10,10,10,10};
    int x2[4]={10,120,120,10};
    int y2[4]={10,10,120,120};
    int z2[4]={120,120,120,120};


//drawing the projected Shape of cube in x-y plane
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


    int option;
    while(option!=6)
    {
        printf("\n***REFLECTION***\nEnter your option\n1.Reflection wrt xz-plane\n2.Reflection wrt yz-plane\n3.Reflection wrt xy-plane\n");
        printf("4.Reflection wrt cordinate axes.\n5.exit\n\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
//cubic color change so that we will know how it is moved from the original position
            k=0;
            while(k!=3)
            {
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],2);
                k++;
            }
            midLine(x2[k],y2[k],x2[0],y2[0],2);
//all the transformation logics are implemented into this for loop
            for(i=0;i<l;i++)
            {
               x1[i]=-1*x1[i];
               x2[i]=-1*x2[i];
            }
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
            break;
        }

         case 2:
        {
            k=0;
            while(k!=3)
            {
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],2);
                k++;
            }
            midLine(x2[k],y2[k],x2[0],y2[0],2);
//all the transformation logics are implemented into this for loop
            for(i=0;i<l;i++)
            {
               y1[i]=-1*y1[i];
               y2[i]=-1*y2[i];
            }
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
            break;
        }
        case 3:
        {
            k=0;
            while(k!=3)
            {
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],2);
                k++;
            }
            midLine(x2[k],y2[k],x2[0],y2[0],2);

            for(i=0;i<l;i++)
            {
               z1[i]=-1*z1[i];
               z2[i]=-1*z2[i];
            }
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
            break;
        }

        case 4:
        {
           k=0;
            while(k!=3)
            {
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],2);
                k++;
            }
            midLine(x2[k],y2[k],x2[0],y2[0],2);
//all the transformation logics are implemented into this for loop
            for(i=0;i<l;i++)
            {
               y1[i]=-1*y1[i];
               x1[i]=-1*x1[i];
               z1[i]=-1*z1[i];
               y2[i]=-1*y2[i];
               x2[i]=-1*x2[i];
               z2[i]=-1*z2[i];
            }
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
            break;
        }
        }
    }

    delay(10000);
    closegraph();
}

//line drawing algorithm
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


