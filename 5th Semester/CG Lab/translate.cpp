#include<windows.h>
#include<math.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include<cstdio>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glTranslated(-0.3, 0.2, 0.0);
    //for polygon
    glBegin(GL_LINELOOP);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Filled rectangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}