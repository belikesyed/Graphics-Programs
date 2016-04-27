#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
// program for spline drawing using Horner's Rule
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
    float du,pw,u=0;
    printf("Enter the dgree of polynimial:");
    scanf("%d",&n);
    n=n+1;
    float ax[n],ay[n],az[n];
    float x=0,y=0,z=0;
    for(i=0;i<n;i++)
    {
        printf("Enter ax[%d]:",i);
        scanf("%f",&(ax[i]));
        printf("Enter ay[%d]:",i);
        scanf("%f",&(ay[i]));
    }
    du=0.02;

   while(u<=1)
    {
        x=0;y=0;
        i=n;
        while(i>=0)
        {
            x=ax[i]+x*u;
            y=ay[i]+y*u;
            i--;
        }
        x=320+x;
        y=320-y;
        putpixel(floor(x+0.5),floor(y+0.5),3);
        delay(20);
        u=u+du;
    }

    delay(10000);
    closegraph();
}
