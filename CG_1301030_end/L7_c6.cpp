#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.142

void GLshapes();
void GLshapes1();
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-200.0, 200.0, -200.0, 200.0);
}

void cords(int height, int width)
{
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-1*height, 0.0);
    glVertex2f(height, 0.0);
    glVertex2f(0.0, -1*width);
    glVertex2f(0.0, width);
    glEnd();
    glFlush();
}

float x1[3],y[3];
int l=3;
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(700,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow("GLUT Shapes");
    init();

    int i;
    for(i=0;i<3;i++)
    {
        printf("Enter x[%d] for triangle:",i);
        scanf("%f",&x1[i]);
        printf("Enter y[%d] for triangle:",i);
        scanf("%f",&y[i]);
    }
    glutDisplayFunc( GLshapes );

int option;
    while(option!=4)
    {
        printf("\nEnter your option\n1.translate\n2.rotate\n3.scale\n4.exit\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            int tx,ty;//transaltion wrt tx & ty
            printf("enter tx\n");
            scanf("%d",&tx);
            printf("enter ty\n");
            scanf("%d",&ty);
            printf("\n");

            glutDisplayFunc( GLshapes );
            for(i=0;i<l;i++)
            {
                x1[i]=x1[i]+tx;
                y[i]=y[i]+ty;
            }
           glutDisplayFunc( GLshapes1 );
           glutMainLoop();
            break;
        }
        case 2:
        {
            int fx,fy;
            float th;//rotation wrt fx & fy
            printf("enter fx:");
            scanf("%d",&fx);
            printf("enter fy:");
            scanf("%d",&fy);
            printf("enter Rotation angle:");
            scanf("%f",&th);
            printf("\n");

            glutDisplayFunc( GLshapes );
            int tmp;
            th=(th/180)*PI;
            for(i=0;i<l;i++)
            {
                tmp=x1[i];
                x1[i]=fx+(tmp-fx)*cos(th)-(y[i]-fy)*sin(th)+0.5;
                y[i]=fy+(tmp-fx)*sin(th)+(y[i]-fy)*cos(th)+0.5;
            }
            glutDisplayFunc( GLshapes1 );
            glutMainLoop();
            break;
        }
        case 3:
        {
            float sx,sy;
            int fx,fy;//scaling wrt sx & sy
            printf("enter fx\n");
            scanf("%d",&fx);
            printf("enter fy\n");
            scanf("%d",&fy);
            printf("enter sx\n");
            scanf("%f",&sx);
            printf("enter sy\n");
            scanf("%f",&sy);
            printf("\n");
            glutDisplayFunc( GLshapes );

            for(i=0;i<l;i++)
            {
               x1[i]=x1[i]*sx+(1-sx)*fx;
               y[i]=y[i]*sy+(1-sy)*fy;
            }
            glutDisplayFunc( GLshapes1 );
            glutMainLoop();
            break;
        }
        }
    }
    return EXIT_SUCCESS;
}

void GLshapes()
{
    cords(600,600);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    //glLineWidth(2.5);
    glVertex2f(x1[0],y[0]);
    glVertex2f(x1[1],y[1]);
    glVertex2f(x1[2],y[2]);
    glEnd();
    glFlush();
}

void GLshapes1()
{
    cords(600,600);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,1.0,0.0);
    //glLineWidth(2.5);
    glVertex2f(x1[0],y[0]);
    glVertex2f(x1[1],y[1]);
    glVertex2f(x1[2],y[2]);
    glEnd();
    glFlush();
}
