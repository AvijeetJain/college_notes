/*write a glut program to create a display window of resolution of 512x512 on your
computer screen. On that display window, draw the circle using line loop*/

#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.14159265

GLint xc, yc, sizes = 100;

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-sizes, sizes, -sizes, sizes);
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
	int lineAmount = 100; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(0, 0, 60);
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