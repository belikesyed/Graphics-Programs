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
    float du,u=0,d1x,d1y,d1z,d2x,d2y,d2z,d3x,d3y,d3z,d4x,d4y,d4z;
    printf("Enter coeficient for dgree 4 polynimial:\n");
    n=5;
    float ax[n],ay[n],az[n];
    float x=0,y=0,z=0;
  for(i=0;i<n;i++)
    {
        printf("Enter ax[%d]:",i);
        scanf("%f",&(ax[i]));
        printf("Enter ay[%d]:",i);
        scanf("%f",&(ay[i]));
        printf("Enter az[%d]:",i);
        scanf("%f",&(az[i]));
    }
    //initialization
    du=0.05;
    x=ax[0];
    y=ay[0];
    //du power calculation
    float pw4x=ax[4]*pow(du,4),pw4y=ay[4]*pow(du,4),pw4z=az[4]*pow(du,4);
    float pw3x=ax[3]*pow(du,3),pw3y=ay[3]*pow(du,3),pw3z=az[3]*pow(du,3);
    float pw2x=ax[2]*du*du,pw2y=ay[2]*du*du,pw2z=az[2]*du*du;
    float pw1x=ax[1]*du,pw1y=ay[1]*du,pw1z=az[1]*du;

    d1x=pw4x+pw3x+pw2x+pw1x;
    d1y=pw4y+pw3y+pw2y+pw1y;
    d1z=pw4z+pw3z+pw2z+pw1z;
    d2x=14*pw4x+6*pw3x+2*pw2x;
    d2y=14*pw4y+6*pw3y+2*pw2y;
    d2z=14*pw4z+6*pw3z+2*pw2z;
    d3x=36*pw4x+6*pw3x;
    d3y=36*pw4y+6*pw3y;
    d3z=36*pw4z+6*pw3z;
    d4x=24*pw4x;
    d4y=24*pw4y;
    d4z=24*pw4z;

//putpixel at inital point
    putpixel(floor(320+x+0.5),floor(320-y+0.5),2);
    delay(20);
//implementation of the 4th degree spline
    while(u<=1)
    {
        x=x+d1x;y=y+d1y;z=z+d1z;
        d1x=d1x+d2x;d1y=d1y+d2y;d1z=d1z+d2z;
        d2x=d2x+d3x;d2y=d2y+d3y;d2z=d2z+d3z;
        d3x=d3x+d4x;d3y=d3y+d4y;d3z=d3z+d4z;
        putpixel(floor(320+x+0.5),floor(320-y+0.5),2);
        delay(20);
        u=u+du;
    }


 delay(10000);
 closegraph();
}
