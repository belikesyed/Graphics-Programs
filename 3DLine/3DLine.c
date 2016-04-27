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
    int x1,x2,y1,y2,z1,z2;//starting coordinate and final coordinate
    printf("Enter x1:");
    scanf("%d",&x1);
    printf("Enter y1:");
    scanf("%d",&y1);
    printf("Enter z1:");
    scanf("%d",&z1);
    printf("Enter x2:");
    scanf("%d",&x2);
    printf("Enter y2:");
    scanf("%d",&y2);
    printf("Enter z2:");
    scanf("%d",&z2);

    midLine(x1,y1,x2,y2,3);
    int option;
    while(option!=6)
    {
        printf("\nEnter your option\n1.translate\n2.rotate wrt z-axis\n3.rotate wrt x-axis\n4.rotate wrt y-axis\n5.scale\n6.exit\n\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            int tx,ty,tz;//transaltion wrt tx & ty
            printf("enter tx\n");
            scanf("%d",&tx);
            printf("enter ty\n");
            scanf("%d",&ty);
            printf("enter tz\n");
            scanf("%d",&tz);
            printf("\n");
            midLine(x1,y1,x2,y2,2);
            x1=x1+tx;
            y1=y1+ty;
            z1=z1+tz;
            x2=x2+tx;
            y2=y2+ty;
            z2=z2+tz;
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
            int d=x1;
            x1=fx+(d-fx)*cos(th)-(y1-fy)*sin(th);
            y1=fy+(d-fx)*sin(th)+(y1-fy)*cos(th);
            d=x2;
            x2=fx+(d-fx)*cos(th)-(y2-fy)*sin(th);
            y2=fy+(d-fx)*sin(th)+(y2-fy)*cos(th);
            printf("\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n th %f",x1,y1,x2,y2,(th));
            midLine(x1,y1,x2,y2,3);
            break;
        }
        case 3:
        {
            int fz,fy;
            float th;//rotation wrt fx & fy
            printf("enter fy\n");
            scanf("%d",&fy);
            printf("enter fz\n");
            scanf("%d",&fz);
            printf("enter Rotation angle\n");
            scanf("%f",&th);
            printf("\n");
            midLine(x1,y1,x2,y2,2);
            th=(th/180)*PI;
            int d=y1;
            y1=fy+(d-fy)*cos(th)-(z1-fz)*sin(th);
            z1=fz+(d-fy)*sin(th)+(z1-fz)*cos(th);
            d=y2;
            y2=fy+(d-fy)*cos(th)-(z2-fz)*sin(th);
            z2=fz+(d-fy)*sin(th)+(z2-fz)*cos(th);
            printf("\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n th %f",x1,y1,x2,y2,(th));
            midLine(x1,y1,x2,y2,3);
            break;
        }

        case 4:
        {
            int fz,fx;
            float th;//rotation wrt fx & fy
            printf("enter fx\n");
            scanf("%d",&fx);
            printf("enter fz\n");
            scanf("%d",&fz);
            printf("enter Rotation angle\n");
            scanf("%f",&th);
            printf("\n");
            midLine(x1,y1,x2,y2,2);
            th=(th/180)*PI;
            int d=x1;
            x1=fx+(d-fx)*cos(th)-(z1-fz)*sin(th);
            z1=(d-fx)*sin(th)+(z1-fz)*cos(th);
            d=x2;
            x2=fx+(d-fx)*cos(th)-(z2-fz)*sin(th);
            z2=(d-fx)*sin(th)+(z2-fz)*cos(th);
            printf("\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n th %f",x1,y1,x2,y2,(th));
            midLine(x1,y1,x2,y2,3);
            break;
        }

        case 5:
        {
            int sx,sy,sz,fx,fy,fz;//scaling wrt sx & sy
            printf("enter fx\n");
            scanf("%d",&fx);
            printf("enter fy\n");
            scanf("%d",&fy);
            printf("enter fz\n");
            scanf("%d",&fz);
            printf("enter sx\n");
            scanf("%d",&sx);
            printf("enter sy\n");
            scanf("%d",&sy);
            printf("enter sz\n");
            scanf("%d",&sz);
            printf("\n");
            midLine(x1,y1,x2,y2,0);
            x1=x1*sx+(1-sx)*fx;
            y1=y1*sy+(1-sy)*fy;
            x2=x2*sx+(1-sx)*fx;
            z1=z1*sz+(1-sz)*fz;
            z2=z2*sz+(1-sz)*fz;
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


