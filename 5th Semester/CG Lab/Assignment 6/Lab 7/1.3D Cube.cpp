// OpenGL Polyhedron Functions

#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
#include<GL/glu.h>

#include<iomanip>
#include<iostream>
#include<string>


GLsizei winWidth = 500, winHeight = 500;    // Initial display-window size.

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);       // Set display-window color to white.
}

void displayWirePolyhedra(void) {
    glClear(GL_COLOR_BUFFER_BIT);           // Clear display window.
    glColor3f(0.0, 0.0, 1.0);               // Set line color to blue.

    // set viewing transformation
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(1.5, 2.0, 1.0);

    glutWireCube(1.0);                      // Display wire cube.
    glScalef(0.8, 0.5, 0.8);
    glTranslatef(-6.0, 5.0, 0.0);
    glutWireDodecahedron();                 // Display wire dodecahedron.

    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Wire Polyhedra");
    init();
    glutDisplayFunc(displayWirePolyhedra);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}