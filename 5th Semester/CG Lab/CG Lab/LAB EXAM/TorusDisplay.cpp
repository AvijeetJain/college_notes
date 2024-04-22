// #include <GLUT/glut.h>
#include <windows.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstring>
using namespace std;

void displayTorus()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLdouble iRadius = 0.5;
    GLdouble oRadius = 2;
    GLint sides = 15;
    GLint rings = 30;
    char view;
    glColor3f(1.0, 1.0, 1.0);
    cout << "Enter the torus view (wireframe(w) / solid(s)): " << endl;
    cin >> view;
    // glPushMatrix();
    // glTranslatef(2.0, 1, 0);
    glRotatef(45, 0, 1, 0);
    // if (view == 's')
    glutSolidTorus(iRadius, oRadius, sides, rings);
    // else
    // glutWireTorus(iRadius,oRadius,sides,rings);
    glPopMatrix();
    glBegin(GL_LINES);
    //X
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    //Y
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);
    //Z
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0 / 3.0, 1, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4, 5, 6, 0, 0, 0, 0, 0, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Normal Torus");
    glutDisplayFunc(displayTorus);
    init();
    glutMainLoop();
}