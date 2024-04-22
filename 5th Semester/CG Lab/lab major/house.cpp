#include <GL/glut.h> 
#include <math.h>

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //glTranslatef(0.6, 0.0, 0.0);
    glRotatef(30.0, 1.0f, 0.0f, 0.0f);
    glScaled(2.0, 2.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.15f);
    glVertex2f(-0.1f, 0.15f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(900, 900);
    glutCreateWindow("House with Door");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
