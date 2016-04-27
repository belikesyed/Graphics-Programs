#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int x1,Y1,x2,y2;
void seedfill(int,int,int,int);
void square(void);
void Axes(void);
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    square();
    glEnd();
    glFlush();
}
void square(void)
{
    seedfill(x1 , Y1 , 0 , 0);
    Axes();
}
void seedfill(int x , int y , int flagx , int flagy)
{

    if(x<x2 && y<y2)
    {
        if(flagx==0 && flagy==0)
        {
            seedfill(x+1,y,1,0);
            seedfill(x,y+1,0,1);
        }
        if(flagx==1 && flagy ==0)
        {
            seedfill(x+1,y,1,0);
            seedfill(x,y+1,0,1);

        }
        if(flagx==0 && flagy ==1)
        {
            seedfill(x,y+1,0,1);
        }
        glVertex2s(x,y);
    }
}

void Axes()
{
    int i;
    glColor3f (1.0, 1.0, 1.0);
    for(i=-200 ; i<=200 ; i++)
    {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    for(i=-2; i<=2 ; i++)
    {
        glVertex2s(195+i,4+i);
        glVertex2s(195-i,4+i);
    }
    for(i=0; i<=2 ; i++)
    {
        glVertex2s(4+i,195+i);
        glVertex2s(4-i,195+i);
        glVertex2s(4,195-i);
    }
}
void init(void)
{
    glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-200.0, 200.0, -200.0, 200.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(700,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow("GLUT Shapes");
    init();

    printf("Enter x1 &y1 of rectangle:\n");
    scanf("%d %d",&x1,&Y1);
    printf("Enter x2 &y2 of rectangle:\n");
    scanf("%d %d",&x2,&y2);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
