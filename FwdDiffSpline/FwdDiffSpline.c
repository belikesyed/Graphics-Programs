#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468
//program for drawing spline using forward different approach
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
    float du,u=0,d1x,d1y,d2x,d2y,d3x,d3y;
    printf("Enter coeficient for dgree 3 polynimial:\n");
    n=4;
    float ax[n],ay[n],az[n];
    float x=0,y=0,z=0;
    for(i=0;i<n;i++)
    {
        printf("Enter ax[%d]:",i);
        scanf("%f",&(ax[i]));
        printf("Enter ay[%d]:",i);
        scanf("%f",&(ay[i]));
    }
    //initialization
    du=0.02;
    x=ax[0];
    y=ay[0];
    float pw3x=ax[3]*pow(du,3),pw3y=ay[3]*pow(du,3);
    float pw2x=ax[2]*du*du,pw2y=ay[2]*du*du;
    float pw1x=ax[1]*du,pw1y=ay[1]*du;

    d1x=pw3x+pw2x+pw1x;
    d1y=pw3y+pw2y+pw1y;
    d2x=6*pw3x+2*pw2x;
    d2y=6*pw3y+2*pw2y;
    d3x=6*pw3x;
    d3y=6*pw3y;

    putpixel(floor(320+x+0.5),floor(320-y+0.5),2);
    delay(20);
//implementation
    while(u<=1)
    {
        x=x+d1x;y=y+d1y;
        d1x=d1x+d2x;d1y=d1y+d2y;
        d2x=d2x+d3x;d2y=d2y+d3y;
        putpixel(floor(320+x+0.5),floor(320-y+0.5),2);
        delay(20);
        u=u+du;
    }


 delay(10000);
 closegraph();
}
