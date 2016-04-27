#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 22/7
//Line Clipping
void midLine(int,int,int,int);
int regionCodes(int, int );
int SuderlandAlgo(int,int,int,int,int,int,int,int);
int LiangBarskyAlgo(int,int,int,int,int,int,int,int);
int NichollLee(int,int,int,int,int,int,int,int);

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
    int xmin,ymin,xmax,ymax,x1,y1,x2,y2;
    printf("###Line Clipping Algorithm in Standard View Window###\nDraw the clipping window\n");
    printf("Enter xmin:");
    scanf("%d",&xmin);
    printf("Enter ymin:");
    scanf("%d",&ymin);
    printf("Enter xmax - diagonal to xmin:");
    scanf("%d",&xmax);
    printf("Enter ymax - diagonal to ymin:");
    scanf("%d",&ymax);
    //drwaing the view window

    midLine(xmin,ymin,xmin,ymax);
    midLine(xmin,ymin,xmax,ymin);
    midLine(xmin,ymax,xmax,ymax);
    midLine(xmax,ymin,xmax,ymax);

    int opt;
    do
    {
        printf("Enter the option:\n1.Cohen-Sutherland Algo\n2.Liang-Barsky Algo\n3.Nicholl-Lee-Nicholl\n0.Exit.\n");
        scanf("%d",&opt);
        printf("\nEnter the Line coordinates\n");
        printf("Enter x1:");
        scanf("%d",&x1);
        printf("Enter y1:");
        scanf("%d",&y1);
        printf("Enter x2:");
        scanf("%d",&x2);
        printf("Enter y2:");
        scanf("%d",&y2);

        switch(opt)
        {
        case 1:
        {

            SuderlandAlgo(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
            break;
        }
        case 2:
        {
            LiangBarskyAlgo(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
            break;
        }
        case 3:
        {
            NichollLee(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
        }
        }
    }
    while(opt!=0);

    delay(10000);
    closegraph();
}

int NichollLee(int xmin,int ymin,int xmax,int ymax,int x1,int y1, int x2, int y2)
{
    int p,q;
    float m1,m2,m3,m4,m;
    m1=(y1-ymin)/(1.00*(x1-xmin));
    m2=(y1-ymin)/(1.00*(x1-xmax));
    m3=(y1-ymax)/(1.00*(x1-xmin));
    m4=(y1-ymax)/(1.00*(x1-xmax));
    m=(y2-y1)/(1.00*(x2-x1));
    printf("%f %f %f %f %f \n",m1,m2,m3,m4,m);


    p=(regionCodes(ymax,y1)<<3)+(regionCodes(y1,ymin)<<2)+(regionCodes(xmax,x1)<<1)+regionCodes(x1,xmin);
    q=(regionCodes(ymax,y2)<<3)+(regionCodes(y2,ymin)<<2)+(regionCodes(xmax,x2)<<1)+regionCodes(x2,xmin);
    printf("p=%d q=%d \n",p,q);

    if(p==0)
    {
        if(q==0)
        {
            midLine(x1,y1,x2,y2);
            return 0;
        }
        else if((q&1)!=0 && m1>m && m3<m)//checking L region
        {
            midLine(x1,y1,xmin,y1+m*(xmin-x1)+0.5);
            return 0;
        }
        else if((q&2)!=0 && m>m2 && m<m4)//checking R region
        {
            midLine(x1,y1,xmax,y1+m*(xmax-x1)+0.5);
            return 0;
        }
        else if((q&4)!=0 && (abs(m)>abs(m1) && abs(m)>abs(m2)))//checking B region
        {
            midLine(x1,y1,x1+(1/m)*(ymin-y1)+0.5,ymin);
            return 0;
        }
        else if((q&8)!=0 && (abs(m)>abs(m4) && abs(m)>abs(m3)))//checking T region
        {
            midLine(x1,y1,x1+(1/m)*(ymax-y1)+0.5,ymax);
            return 0;
        }
    }

    else if(p==1)
    {
        if(q==0)
        {
            midLine(xmin,y1+m*(xmin-x1),x2,y2);
                return 0;
        }
        else if((q&4)!=0 && m>m1 && m<m2)
        {
                midLine(xmin,y1+m*(xmin-x1),x1+(ymin-y1)/m,ymin);
                return 0;
        }
        else if((q&2)!=0 && m>m2 && m<m3)
        {
                midLine(xmin,y1+m*(xmin-x1),xmax,y1+(xmax-x1)*m);
                return 0;
        }
        else if((q&8)!=0 && m<m3 && m>m4)
        {
            midLine(xmin,y1+m*(xmin-x1),x1+(ymax-y1)/m,ymax);
                return 0;
        }
    }

    return 0;

}

int LiangBarskyAlgo(int xmin,int ymin,int xmax,int ymax,int x1,int y1, int x2, int y2)
{
    int xs=x1,ys=y1,xe=x2,ye=y2,i;
    float u[4],u1=0.0,u2=1.0;
    int dx=x2-x1,dy=y2-y1;
    int p[4]= {-1*dx,dx,-1*dy,dy};
    int q[4]= {x1-xmin,xmax-x1,y1-ymin,ymax-y1};


    for(i=0; i<4; i++)
    {
        u[i]=q[i]/(p[i]*1.00);
        if(p[i]<0)
        {
            if(u[i]>u2)
                return 0;
            else if(u[i]>u1)
                u1=u[i];
        }
        else if(p[i]>0)
        {
            if(u[i]<u1)
                return 0;
            else if(u[i]<u2)
                u2=u[i];
        }
        else
        {
            if(q[i]<0)
                return 0;
        }
    }
    printf("u1=%f u2=%f\n",u1,u2);
    if(u1>0)
    {
        xs=x1+u1*dx+0.5;
        ys=y1+u1*dy+0.5;
    }
    if(u2<1)
    {
        xe=x1+u2*dx+0.5;
        ye=y1+u2*dy+0.5;
    }
    midLine(xs,ys,xe,ye);

    return 0;
}

int SuderlandAlgo(int xmin,int ymin,int xmax,int ymax,int x1,int y1, int x2, int y2)
{
    int p,q,s,e,xs,ys,xe,ye,temp1;
    float m;
    m=(y2-y1)/((x2-x1)*1.00);
    p=(regionCodes(ymax,y1)<<3)+(regionCodes(y1,ymin)<<2)+(regionCodes(xmax,x1)<<1)+regionCodes(x1,xmin);
    q=(regionCodes(ymax,y2)<<3)+(regionCodes(y2,ymin)<<2)+(regionCodes(xmax,x2)<<1)+regionCodes(x2,xmin);
    printf("P=%d Q=%d",p,q);

    if((p|q)==0)
    {
        midLine(x1,y1,x2,y2);
        return 0;
    }
    else if((p&q)!=0)
        return 0;
    s=p;
    e=q;
    xs=x1;
    ys=y1;
    xe=x2;
    ye=y2;
    int c;

    while((s|e)!=0 && (s&e)==0)
    {
        if(s!=0)
            c=s;
        else
        {
            c=e;
            e=s;
            //swap
            temp1=xs;
            xs=x2;
            xe=temp1;
            temp1=ys;
            ys=y2;
            ye=temp1;
        }
        if((c&1)!=0)
        {
            xs=xmin;
            ys=y1+m*(xmin-x1)+0.5;
            printf("(c&1)m=%f xs=%d ys=%d\n",m,xs,ys);
        }
        else
        {
            if((c&2)!=0)
            {
                xs=xmax;
                ys=y1+m*(xmax-x1)+0.5;
                printf("(c&2)m=%f xs=%d ys=%d\n",m,xs,ys);
            }
            else
            {
                if((c&4)!=0)
                {
                    ys=ymin;
                    xs=x1+(1/m)*(ymin-y1)+0.5;
                    printf("(c&4)m=%f xs=%d ys=%d\n",m,xs,ys);
                }
                else
                {
                    if((c&8)!=0)
                    {
                        ys=ymax;
                        xs=x1+(1/m)*(ymax-y1)+0.5;
                        printf("(c&8)m=%f xs=%d ys=%d\n",m,xs,ys);
                    }
                }
            }
        }
        s=(regionCodes(ymax,ys)<<3)+(regionCodes(ys,ymin)<<2)+(regionCodes(xmax,xs)<<1)+regionCodes(xs,xmin);
        printf("while loop s=%d e=%d\n",s,e);
    }

    if((s|e)==0)
    {
        midLine(xs,ys,xe,ye);
        return 0;
    }
    else if((s&e)!=0)
        return 0;

    return 0;
}

int regionCodes(int lx, int ex)
{
    int cmp=lx-ex;
    int rcodes;
    if(cmp<0)
        rcodes=1;
    else
        rcodes=0;
    return rcodes;
}


void midLine(int x1,int y1,int x2,int y2)
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
            putpixel(x,y,3);
            p=(0.5)-m;
            for(i=1; i<=dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1-m;
                    putpixel(++x,++y,3);

                }
                else
                {
                    p=p-m;
                    putpixel(++x,y,3);
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
            putpixel(x,y,3);
            p=1-(m/2);
            for(i=1; i<=dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,3);

                }
                else
                {
                    p=p+1-m;
                    putpixel(++x,++y,3);
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
            putpixel(x,y,3);
            p=-0.5-m;
            for(i=1; i<=dx; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1+m;
                    putpixel(++x,--y,3);

                }
                else
                {
                    p=p+m;
                    putpixel(++x,y,3);
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
            putpixel(x,y,3);
            p=(m/2)+1;
            for(i=1; i<=dy; i++)
            {
                //printf("x=%d y=%d p=%f\t",x,y,p);
                if(p<0)
                {
                    p=p+1;
                    putpixel(x,++y,3);

                }
                else
                {
                    p=p+1+m;
                    putpixel(--x,++y,3);
                }
            }
        }
    }
}

