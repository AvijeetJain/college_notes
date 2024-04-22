#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(5);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (float i = 0; i < 400; i++) {
        glVertex2f(cos(2 * 3.14159 * i / 400.0), sin(2 * 3.14159 * i / 400.0));
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}