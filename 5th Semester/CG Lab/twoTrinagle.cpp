#include <GL/freeglut.h>
#include <string.h>


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(12);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.5f, 0.3f);

    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.2f, 0.1f);

    glVertex2f(0.5f, 0.3f);
    glVertex2f(0.2f, 0.1f);


    glEnd();
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
