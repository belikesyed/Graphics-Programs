#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.142
//3D Polygon projection
/*
1.Orthogonal Projection
2.Obligue Projection
3.Perspective Projection
*/
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
    int i,l=4,k=0,tmp;
//cubic shape is taken for projection and its coordinate values areinitialized beforehand
    float x1[4]={60,180,180,60};
    float y1[4]={60,60,180,180};
    float z1[4]={10,10,10,10};
    float x2[4]={10,130,130,10};
    float y2[4]={10,10,130,130};
    float z2[4]={80,80,80,80};
    float dif=50;


    int option;
    while(option!=4)
    {
        printf("\nEnter your option\n1.Orthogonal Projection\n2.Obligue Projection\n3.Persoective Projection\n4.exit\n\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {

            k=0;
            while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],3);
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],3);
                midLine(x1[k],y1[k],x2[k],y2[k],3);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],3);
            midLine(x2[k],y2[k],x2[0],y2[0],3);
            midLine(x1[k],y1[k],x2[k],y2[k],3);

            break;
        }
        case 2:
        {
            cleardevice();
            int zvp;
            float phi,alfa;//rotation wrt phi & alfa
             printf("enter zvp:");
            scanf("%d",&zvp);
            printf("enter alfa:");
            scanf("%f",&alfa);
            printf("enter phi:");
            scanf("%f",&phi);
            printf("\n");

            alfa=(alfa/180)*PI;
            phi=(phi/180)*PI;
            k=0;
//color of the shape is changed so that projection is easily differentiated
            while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],2);
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],2);
                midLine(x1[k],y1[k],x2[k],y2[k],2);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],2);
            midLine(x2[k],y2[k],x2[0],y2[0],2);
            midLine(x1[k],y1[k],x2[k],y2[k],2);
            float xw1[4],yw1[4],xw2[4],yw2[4];
//all the logic for of the corresponding projection is written in the for loop
            for(i=0;i<4;i++)
            {
                xw1[i]=x1[i]+(zvp-z1[i])*cos(phi)*1/tan(alfa);
                yw1[i]=y1[i]+(zvp-z1[i])*sin(phi)*1/tan(alfa);
                xw2[i]=x2[i]+(zvp-z2[i])*cos(phi)*1/tan(alfa);
                yw2[i]=y2[i]+(zvp-z2[i])*sin(phi)*1/tan(alfa);
                printf("%f %f %f %f ",xw1[i],yw1[i],xw2[i],yw2[i]);
            }
            k=0;
//final projected view of the shape
            while(k!=3)
            {
                midLine(xw1[k],yw1[k],xw1[k+1],yw1[k+1],3);
                midLine(xw2[k],yw2[k],xw2[k+1],yw2[k+1],3);
                midLine(xw1[k],yw1[k],xw2[k],yw2[k],3);
                k++;
            }
            midLine(xw1[k],yw1[k],xw1[0],yw1[0],3);
            midLine(xw2[k],yw2[k],xw2[0],yw2[0],3);
            midLine(xw1[k],yw1[k],xw2[k],yw2[k],3);
            break;
        }
        case 3:
        {
            cleardevice();
            int zvp;
            float th;//rotation wrt fx & fy
            printf("enter zvp:");
            scanf("%d",&zvp);

            k=0;
             while(k!=3)
            {
                midLine(x1[k],y1[k],x1[k+1],y1[k+1],2);
                midLine(x2[k],y2[k],x2[k+1],y2[k+1],2);
                midLine(x1[k],y1[k],x2[k],y2[k],2);
                k++;
            }
            midLine(x1[k],y1[k],x1[0],y1[0],2);
            midLine(x2[k],y2[k],x2[0],y2[0],2);
            midLine(x1[k],y1[k],x2[k],y2[k],2);

           float xw1[4],yw1[4],xw2[4],yw2[4];

            for(i=0;i<4;i++)
            {
                xw1[i]=x1[i]*zvp/z1[i];
                yw1[i]=y1[i]*zvp/z1[i];
                xw2[i]=x2[i]*zvp/z2[i];
                yw2[i]=y2[i]*zvp/z2[i];
            }
            k=0;
            while(k!=3)
            {
                midLine(xw1[k],yw1[k],xw1[k+1],yw1[k+1],3);
                midLine(xw2[k],yw2[k],xw2[k+1],yw2[k+1],3);
                midLine(xw1[k],yw1[k],xw2[k],yw2[k],3);
                k++;
            }
            midLine(xw1[k],yw1[k],xw1[0],yw1[0],3);
            midLine(xw2[k],yw2[k],xw2[0],yw2[0],3);
            midLine(xw1[k],yw1[k],xw2[k],yw2[k],3);
            break;
        }
        }
    }
    delay(10000);
    closegraph();
}


//line drawing algo
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


