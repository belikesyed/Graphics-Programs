#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 22/7
//Line Clipping in the non standard view
void midLine(int,int,int,int);
int regionCodes(int, int );
int SuderlandAlgo(int*,int,int,int,int);
int LiangBarskyAlgo(int*,int,int,int,int);
int NichollLee(int*,int,int,int,int);

int ln[4]={0,0,0,0};
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
    int xw[4],x1,y1,x2,y2,xs,ys,ye,xe,i,d;
    float th,m,ith;
    printf("###Line Clipping Algorithm in Non-Standard View Window###\nDraw the clipping window =>Enetr Sequencially!!!\n");
    int x[4],y[4];
    for(i=0; i<4; i++)
    {
        printf("Enter x[%d]:",i);
        scanf("%d",&x[i]);
        printf("Enter y[%d]:",i);
        scanf("%d",&y[i]);
    }
    //drwaing the view window

    midLine(x[0],y[0],x[1],y[1]);
    midLine(x[1],y[1],x[2],y[2]);
    midLine(x[2],y[2],x[3],y[3]);
    midLine(x[3],y[3],x[0],y[0]);

    m=(y[1]-y[0])/(1.00*(x[1]-x[0]));
    th=atan(m);
    printf("%f %f %f",th,m,atan(m));
    ith=th;
    th=-1*th;
    xw[0]=x[0];
    xw[1]=y[0];
    xw[2]=x[0]+(x[2]-x[0])*cos(th)-(y[2]-y[0])*sin(th)+0.5;
    xw[3]=y[0]+(x[2]-x[0])*sin(th)+(y[2]-y[0])*cos(th)+0.5;
    printf("%d %d %d %d %f\n",xw[0],xw[1],xw[2],xw[3],th);

    int opt;
    do
    {
        printf("Enter the option:\n1.Cohen-Sutherland Algo\n2.Liang-Barsky Algo\n3.Nicholl-Lee-Nicholl\n0.Exit.\n");
        scanf("%d",&opt);
        printf("\nEnter the Line coordinates\n");
        printf("Enter xs:");
        scanf("%d",&xs);
        printf("Enter ys:");
        scanf("%d",&ys);
        printf("Enter xe:");
        scanf("%d",&xe);
        printf("Enter ye:");
        scanf("%d",&ye);
        x1=x[0]+(xs-x[0])*cos(th)-(ys-y[0])*sin(th)+0.5;
        y1=x[0]+(xs-x[0])*sin(th)+(ys-y[0])*cos(th)+0.5;
        x2=x[0]+(xe-x[0])*cos(th)-(ye-y[0])*sin(th)+0.5;
        y2=x[0]+(xe-x[0])*sin(th)+(ye-y[0])*cos(th)+0.5;
        printf("%d %d %d %d\n",x1,y1,x2,y2);
        switch(opt)
        {
        case 1:
        {

            SuderlandAlgo(xw,x1,y1,x2,y2);
            d=ln[0];
            ln[0]=x[0]+(d-x[0])*cos(ith)-(ln[1]-y[0])*sin(ith)+0.5;
            ln[1]=y[0]+(d-x[0])*sin(ith)+(ln[1]-y[0])*cos(ith)+0.5;
            d=ln[2];
            ln[2]=x[0]+(d-x[0])*cos(ith)-(ln[3]-y[0])*sin(ith)+0.5;
            ln[3]=y[0]+(d-x[0])*sin(ith)+(ln[3]-y[0])*cos(ith)+0.5;
            midLine(ln[0],ln[1],ln[2],ln[3]);
        }
        case 2:
        {
            LiangBarskyAlgo(xw,x1,y1,x2,y2);
             d=ln[0];
            ln[0]=x[0]+(d-x[0])*cos(ith)-(ln[1]-y[0])*sin(ith)+0.5;
            ln[1]=y[0]+(d-x[0])*sin(ith)+(ln[1]-y[0])*cos(ith)+0.5;
            d=ln[2];
            ln[2]=x[0]+(d-x[0])*cos(ith)-(ln[3]-y[0])*sin(ith)+0.5;
            ln[3]=y[0]+(d-x[0])*sin(ith)+(ln[3]-y[0])*cos(ith)+0.5;
            printf("%d %d %d %d",ln[0],ln[1],ln[2],ln[3]);
            midLine(ln[0],ln[1],ln[2],ln[3]);
            break;
        }
        case 3:
        {
            NichollLee(xw,x1,y1,x2,y2);
            d=ln[0];
            ln[0]=x[0]+(d-x[0])*cos(ith)-(ln[1]-y[0])*sin(ith)+0.5;
            ln[1]=y[0]+(d-x[0])*sin(ith)+(ln[1]-y[0])*cos(ith)+0.5;
            d=ln[2];
            ln[2]=x[0]+(d-x[0])*cos(ith)-(ln[3]-y[0])*sin(ith)+0.5;
            ln[3]=y[0]+(d-x[0])*sin(ith)+(ln[3]-y[0])*cos(ith)+0.5;
            midLine(ln[0],ln[1],ln[2],ln[3]);
            break;
        }
        }
    }
    while(opt!=0);

    delay(10000);
    closegraph();
}

int NichollLee(int* xw,int x1,int y1, int x2, int y2)
{
    int p,q;
    float m1,m2,m3,m4,m;
    m1=(y1-xw[1])/(1.00*(x1-xw[0]));
    m2=(y1-xw[1])/(1.00*(x1-xw[2]));
    m3=(y1-xw[3])/(1.00*(x1-xw[0]));
    m4=(y1-xw[3])/(1.00*(x1-xw[2]));
    m=(y2-y1)/(1.00*(x2-x1));
    printf("%f %f %f %f %f \n",m1,m2,m3,m4,m);


    p=(regionCodes(xw[3],y1)<<3)+(regionCodes(y1,xw[1])<<2)+(regionCodes(xw[2],x1)<<1)+regionCodes(x1,xw[0]);
    q=(regionCodes(xw[3],y2)<<3)+(regionCodes(y2,xw[1])<<2)+(regionCodes(xw[2],x2)<<1)+regionCodes(x2,xw[0]);
    printf("p=%d q=%d \n",p,q);

    if(p==0)
    {
        if(q==0)
        {
            ln={x1,y1,x2,y2};
            return 0;
        }
        else if((q&1)!=0 && m1>m && m3<m)//checking L region
        {
            ln={x1,y1,xw[0],y1+m*(xw[0]-x1)+0.5};
            return 0;
        }
        else if((q&2)!=0 && m>m2 && m<m4)//checking R region
        {
            ln={x1,y1,xw[2],y1+m*(xw[2]-x1)+0.5};
            return 0;
        }
        else if((q&4)!=0 && (m>m1 || m<m2))//checking B region
        {
            ln={x1,y1,x1+(1/m)*(xw[1]-y1)+0.5,xw[1]};
            return 0;
        }
        else if((q&8)!=0 && (m>m4 || m<m3))//checking T region
        {
            ln={x1,y1,x1+(1/m)*(xw[3]-y1)+0.5,xw[3]};
            return 0;
        }
    }

    return 0;

}

int LiangBarskyAlgo(int* xw,int x1,int y1, int x2, int y2)
{
    int xs=x1,ys=y1,xe=x2,ye=y2,i;
    float u[4],u1=0.0,u2=1.0;
    int dx=x2-x1,dy=y2-y1;
    int p[4]= {-1*dx,dx,-1*dy,dy};
    int q[4]= {x1-xw[0],xw[2]-x1,y1-xw[1],xw[3]-y1};


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
    printf("%d %d %d %d\n",xs,ys,xe,ye);
    ln= {xs,ys,xe,ye};

    return 0;
}

int SuderlandAlgo(int* xw,int x1,int y1, int x2, int y2)
{
    int p,q,s,e,xs,ys,xe,ye,temp1;
    float m;
    m=(y2-y1)/((x2-x1)*1.00);
    p=(regionCodes(xw[3],y1)<<3)+(regionCodes(y1,xw[1])<<2)+(regionCodes(xw[2],x1)<<1)+regionCodes(x1,xw[0]);
    q=(regionCodes(xw[3],y2)<<3)+(regionCodes(y2,xw[1])<<2)+(regionCodes(xw[2],x2)<<1)+regionCodes(x2,xw[0]);
    printf("P=%d Q=%d",p,q);

    if((p|q)==0)
    {
        ln={x1,y1,x2,y2};
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
            xs=xw[0];
            ys=y1+m*(xw[0]-x1)+0.5;
            printf("(c&1)m=%f xs=%d ys=%d\n",m,xs,ys);
        }
        else
        {
            if((c&2)!=0)
            {
                xs=xw[2];
                ys=y1+m*(xw[2]-x1)+0.5;
                printf("(c&2)m=%f xs=%d ys=%d\n",m,xs,ys);
            }
            else
            {
                if((c&4)!=0)
                {
                    ys=xw[1];
                    xs=x1+(1/m)*(xw[1]-y1)+0.5;
                    printf("(c&4)m=%f xs=%d ys=%d\n",m,xs,ys);
                }
                else
                {
                    if((c&8)!=0)
                    {
                        ys=xw[3];
                        xs=x1+(1/m)*(xw[3]-y1)+0.5;
                        printf("(c&8)m=%f xs=%d ys=%d\n",m,xs,ys);
                    }
                }
            }
        }
        s=(regionCodes(xw[3],ys)<<3)+(regionCodes(ys,xw[1])<<2)+(regionCodes(xw[2],xs)<<1)+regionCodes(xs,xw[0]);
        printf("while loop s=%d e=%d\n",s,e);
    }

    if((s|e)==0)
    {
        ln={xs,ys,xe,ye};
        return 0;
    }
    else if((s&e)!=0)
        return NULL;

    return NULL;
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

