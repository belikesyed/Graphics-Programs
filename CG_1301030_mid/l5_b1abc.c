#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
//translation, rotation, and scaling
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
    int x1,x2,y1,y2;//starting coordinate and final coordinate
    printf("Enter x1:");
    scanf("%d",&x1);
    printf("Enter y1:");
    scanf("%d",&y1);
    printf("Enter x2:");
    scanf("%d",&x2);
    printf("Enter y2:");
    scanf("%d",&y2);

    midLine(x1,y1,x2,y2,3);
    int option;
    while(option!=4)
    {
        printf("\nEnter your option\n1.translate\n2.rotate\n3.scale\n4.exit\n\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            int tx,ty;//transaltion wrt tx & ty
            printf("enter tx\n");
            scanf("%d",&tx);
            printf("enter ty\n");
            scanf("%d",&ty);
            printf("\n");
            midLine(x1,y1,x2,y2,0);
            x1=x1+tx;
            y1=y1+ty;
            x2=x2+tx;
            y2=y2+ty;
            midLine(x1,y1,x2,y2,3);
            break;
        }
        case 2:
        {
            int fx,fy;
            float th;//rotation wrt fx & fy
            printf("enter fx\n");
            scanf("%d",&fx);
            printf("enter fy\n");
            scanf("%d",&fy);
            printf("enter Rotation angle\n");
            scanf("%f",&th);
            printf("\n");
            midLine(x1,y1,x2,y2,0);
            th=(th/180)*PI;
            x1=(x1-fx)*cos(th)-(y1-fy)*sin(th);
            y1=(x1-fx)*sin(th)+(y1-fy)*cos(th);
            x2=(x2-fx)*cos(th)-(y2-fy)*sin(th);
            y2=(x2-fx)*sin(th)+(y2-fy)*cos(th);
            printf("\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n th %f",x1,y1,x2,y2,(th));
            midLine(x1,y1,x2,y2,3);
            break;
        }
        case 3:
        {
            int sx,sy,fx,fy;//scaling wrt sx & sy
            printf("enter fx\n");
            scanf("%d",&fx);
            printf("enter fy\n");
            scanf("%d",&fy);
            printf("enter sx\n");
            scanf("%d",&sx);
            printf("enter sy\n");
            scanf("%d",&sy);
            printf("\n");
            midLine(x1,y1,x2,y2,0);
            x1=x1*sx+(1-sx)*fx;
            y1=y1*sy+(1-sy)*fy;
            x2=x2*sx+(1-sx)*fx;
            y2=y2*sy+(1-sy)*fy;
            midLine(x1,y1,x2,y2,3);
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


