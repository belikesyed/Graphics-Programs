#include <GL/glut.h>
#include <stdlib.h>

void GLshapes();
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-600.0, 600.0, -600.0, 600.0);
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

void GLshapes()
{
    cords(600,600);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    //glLineWidth(2.5);
    glVertex2f(10.0, 10.0);
    glVertex2f(100.0, 10.0);
    glVertex2f(50.0, 50.0);
    glEnd();

    glFlush();
}
