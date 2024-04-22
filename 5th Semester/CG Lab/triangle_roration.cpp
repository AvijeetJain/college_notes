#include <stdio.h>
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glScaled(0.5, 0.5, 0.5);
    glRotatef(180.0, 1.0f, 0.0f, 0.0f);
    // glRotatef(180.0, 0.0f, 1.0f, 0.0f);


    glBegin(GL_POLYGON);
    glVertex2f(0.0, 1.0);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glEnd();
    glPopMatrix();
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}