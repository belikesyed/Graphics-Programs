#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
void GLshapes();
float degToRad=3.142/180;
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-600.0, 600.0, -600.0, 600.0);
}

//drawing coordinate axes
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

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(700,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow("GLUT Shapes");
    init();
    glutDisplayFunc( GLshapes );
    glutMainLoop();
    return EXIT_SUCCESS;
}
//this function works as display function
void GLshapes()
{
    cords(600,600);
    int i,radius=100;
    int centre[2]={200,200};
    glBegin(GL_LINE_LOOP);
    for(i=0;i<360; i++)
    {
        float degInRad = i*degToRad;
        glVertex2f(centre[0]+cos(degInRad)*radius,centre[1]+sin(degInRad)*radius);
    }
    glEnd();
    glFlush();
}
