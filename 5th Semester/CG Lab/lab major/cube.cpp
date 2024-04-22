#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
#include<GL/glu.h>

#include<iomanip>
#include<iostream>
#include<string>


GLsizei winWidth = 500, winHeight = 500;

void displayCube(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0, 1.0, 1.0);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // glScalef(-5.5, -5.5, -5.5);

    glutSolidCube(0.5);
    // glutWireCube(0.5);
    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(900, 900);
    glutCreateWindow("Wire Polyhedra");
    glutDisplayFunc(displayCube);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}