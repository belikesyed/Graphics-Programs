#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
//2D Polygon reflection
void midLine(int,int,int,int,int);
//int matrixx(int**, int**);


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
    int i,l,k=0;
    //int translate[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    //int rotate[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    //int scale[3][3]={{0,0,0},{0,0,0},{0,0,0}};

    printf("Enter no. edge:");
    scanf("%d",&l);

    int x1[l],y1[l];

    for(i=0;i<l;i++)
    {
        printf("Enter x[%d]:",i);
        scanf("%d",&x1[i]);
        printf("Enter y[%d]:",i);
        scanf("%d",&y1[i]);
    }


    while(k!=l-1)
    {
        midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
        k++;
    }
    midLine(x1[k],y1[k],x1[0],y1[0],3);

    int option;
    while(option!=6)
    {
        printf("\n***REFLECTION***\nEnter your option\n1.Reflection wrt y-axis\n2.Reflection wrt x-axis\n");
        printf("3.Reflection wrt cordinate axes.\n4.Reflection wrt y=-x,y=x\n5.Reflection wrt any line y=mx+c.\n6.exit\n\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],2);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],2);

            for(i=0;i<l;i++)
            {
               x1[i]=-1*x1[i];
            }
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            break;
        }

         case 2:
        {
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],2);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],2);

            for(i=0;i<l;i++)
            {
               y1[i]=-1*y1[i];
            }
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            break;
        }

        case 3:
        {
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],2);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],2);

            for(i=0;i<l;i++)
            {
               y1[i]=-1*y1[i];
               x1[i]=-1*x1[i];
            }
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            break;
        }

        case 4:
        {
            int x,temp;
            printf("\n1.for y=x\n2.fory=-x");
            scanf("%d",&x);
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],2);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],2);

            for(i=0;i<l;i++)
            {
               if(x==1)
               {
                   temp=x1[i];
                   x1[i]=y1[i];
                   y1[i]=temp;
               }
               else
               {
                   temp=y1[i];
                   y1[i]=-1*x1[i];
                    x1[i]=-1*temp;
               }
            }
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            break;
        }

         case 5:
        {
            float m,c;
            printf("\nEnter m c");
            scanf("%f",&m);
            scanf("%f",&c);
            k=0;
            int tx1,ty1,tx2,ty2;
            if(m<1)
            {
                tx1=-320;
                tx2=320;
                ty1=m*tx1+c;
                ty2=m*tx2+c;
            }
            else
            {
                ty1=-320;
                ty2=320;
                tx1=(1/m)*(ty1-c);
                tx2=(1/m)*(ty2-c);
            }
            midLine(tx1,ty1,tx2,ty2,5);

            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],4);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],4);

            int d;
            for(i=0;i<l;i++)
            {
                d=2*(x1[i]+m*(y1[i]-c))/(1+m*m);
                x1[i]=floor(d-x1[i]+0.5);
                y1[i]=floor(d*m-y1[i]+2*c+0.5);

            }
            k=0;
            while(k!=l-1)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            break;
        }
        }
    }

    delay(10000);
    closegraph();
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


