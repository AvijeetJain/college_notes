/* Write a glut program to Create a display window of resolution of 512x512 on your
computer screen. On that display window, draw the following circle:

using points    (a) r=1, center=(0,0)
                (b) r=50, center=(20,20)
*/

#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

GLint xc, yc, sizes = 200;

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-sizes, sizes, -sizes, sizes);
}

void drawCircle(GLint xc, GLint yc, GLint r) {
    glBegin(GL_POINTS);
    for (int i = 0; i < 360; i++) {
        glVertex2i(xc + r * cos(i), yc + r * sin(i));
    }
    glEnd();
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    // drawCircle(0, 0, 1);
    drawCircle(20, 20, 50);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // single buffer and RGB
    glutInitWindowSize(512, 512); // 512 by 512 window
    glutInitWindowPosition(250, 250); // where do you want to place the window
    glutCreateWindow("Circle"); // name of the window
    glutDisplayFunc(myDisplay); // tell graphics to run myDisplay
    myInit();
    glutMainLoop(); // run the program
    return 0;
}