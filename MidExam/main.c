#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468



float degtoRad(float rad)
{
    return ((rad/180)*PI);
}

void cord() //function for drawing coordinates
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

    float a,p,m,alfa,beta,lmt,k;

    alfa=2*sin(degtoRad(0.5))*sin(degtoRad(0.5));
    beta=sin(degtoRad(1));
    int x=320,y=320,i=0;
    printf("%f %f\n",alfa, beta);

    printf("Drawing y=asinx curve\n");
    printf("Enter a:");
    scanf("%f",&a);
    m=a;//cos(0)=1
    p=1-a*sin(degtoRad(0.5));


        lmt=sqrt(a*a-1);
        printf("m=%f lmt=%f\n",m,lmt);
        for(i=0;i<45;i++)
        {
            if(p<0)
            {
                p=p+1;
                y--;
                putpixel(x,y,3);
            }
            else
            {

                p=p-a*cos(degtoRad(i+1))*sin(degtoRad(0.5));
                x++;
                y--;
                putpixel(x,y,3);

            }
            printf("p=%f,x=%d,y=%d ",p,x,y);
        }
    p=-0.2;

    for(i=45;i<90;i++)
        {
            if(p<0)
            {
                p=p+1-a*cos(degtoRad(i+1.5))*sin(degtoRad(0.5));
                y--;
                x++;
                putpixel(x,y,3);
            }
            else
            {
                p=p-a*cos(degtoRad(i+1.5))*sin(degtoRad(0.5));
                x++;
                putpixel(x,y,3);

            }
            printf("\n\np=%f,x=%d,y=%d ",p,k,x,y);
        }
    delay(10000);
    closegraph();
    return 0;
}
