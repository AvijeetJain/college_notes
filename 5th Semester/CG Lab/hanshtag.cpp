#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); // Define an orthographic projection

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2d(0.2, 0.2);
    glColor3f(0, 1, 0);
    glVertex2d(0.8, 0.2);
    glColor3f(0, 0, 1);
    glVertex2d(0.5, 0.9);
    glEnd();
    glFlush();
}

void lineStrip()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(20, 10);
    glVertex2i(50, 10);
    glVertex2i(20, 80);
    glVertex2i(50, 80);
    glEnd();
    glFlush();
}

void tictactoe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100, 200);
    glVertex2i(400, 200);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(200, 100);
    glVertex2i(200, 400);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(100, 300);
    glVertex2i(400, 300);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(300, 100);
    glVertex2i(300, 400);
    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Program");
    init();
    glutDisplayFunc(tictactoe);
    glutMainLoop();
    return 0;
}