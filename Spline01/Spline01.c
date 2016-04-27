#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
//program written paramatric spline
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

    int n,i;
    float du,pw,u=0.01;
    printf("Enter the degree of polynimial:");
    scanf("%d",&n);
    n=n+1;
    float ax[n],ay[n],az[n];
    float x,y,z;
    for(i=0;i<n;i++)
    {
        printf("Enter ax[%d]:",i);
        scanf("%f",&(ax[i]));
        printf("Enter ay[%d]:",i);
        scanf("%f",&(ay[i]));
        //printf("Enter az[%d]:",i);//here z component is not required.
        //scanf("%f",&(az[i]));
    }
    du=0.02;

    while(u<=1)
    {
        x=320;
        y=320;
        for(i=0;i<n;i++)
        {
            pw=pow(u,i);
            x=x+ax[i]*pw;
            y=y-ay[i]*pw;
            //z=z+az[i]*pw;
        }
        putpixel(floor(x+0.5),floor(y+0.5),3);
        delay(20);
        u=u+du;
    }

    delay(10000);
    closegraph();
}
