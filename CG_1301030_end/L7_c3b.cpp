#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float rad=3.142/180;
int h,k;
float a,b;

//displaying the final output
void display(void)
{
    float A;
    int i,j;
    float theta;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2s(h,k);
    for( theta=0 ; theta<=90 ; theta++)
    {
        A=theta*rad;
        j=floor(b*sin(A)+0.5);
        i=floor(a*cos(A)+0.5);

        glVertex2s(h+i,k+j);
        glVertex2s(h-i,k+j);
        glVertex2s(h-i,k-j);
        glVertex2s(h+i,k-j);
    }

//drawing  coordinate axes
    glColor3f (1.0, 1.0, 1.0);
    for(int i=-200 ; i<=200 ; i++)
    {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    for(int i=-2; i<=2 ; i++)
    {
        glVertex2s(195+i,4+i);
        glVertex2s(195-i,4+i);
    }
    for(int i=0; i<=2 ; i++)
    {
        glVertex2s(4+i,195+i);
        glVertex2s(4-i,195+i);
        glVertex2s(4,195-i);
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
int main(int argc, char** argv)
{
    printf("Enter the center of ellipse:\n");
    scanf("%d %d",&h,&k);
    printf("Enter the parameters a & b:\n");
    scanf("%f %f",&a,&b);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (700, 100);
    glutCreateWindow ("Ellipse : Trignometric Method ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
