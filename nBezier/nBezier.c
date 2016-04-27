
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int fact(int,int);
int fa(int);

void cord()//function for drawing coordinates
{
    int i,j;
    for(i=0,j=320; i<641;)
        putpixel(i++,j,15);
    for(i=0,j=320; i<641;)
        putpixel(j,i++,15);
}

int fact(int n, int i)
{
        int k=fa(n)/(fa(i)*fa(n-i));
        return k;
}

int fa(int i)
{
    if(i==0)
    {
        return 1;
    }
    else
    {
        return(i*fa(i-1));
    }
}

int main()
{
    initwindow(600,600);
    cord();
    int n,i;
    printf("Enter degree of spline:");
    scanf("%d",&n);

    float x[n],y[n];

    for(i=0; i<n; i++)
    {
        printf("Enter x[%d]:",i);
        scanf("%f",&x[i]);
        printf("Enter y[%d]:",i);
        scanf("%f",&y[i]);
    }

        float x1,y1,u=0.005;
        while(u<1){
            x1=0.0;
        y1=0.0;
        for(i=0; i<n; i++)
        {
            x1=x[i]*fact(n-1,i)*pow(u,i)*pow(1-u,n-1-i)+x1;
            y1=y[i]*fact(n-1,i)*pow(u,i)*pow(1-u,n-1-i)+x1;

        }
        putpixel(500+x1,500-y1,5);
        u=u+0.005;
        }
        delay(30000);
        closegraph();
}

