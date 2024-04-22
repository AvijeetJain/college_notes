#include <GL/freeglut.h>
#include <string.h>

void drawLine(double x1, double y1, double x2, double y2) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);
    glPointSize(2);

    double m = (y2 - y1) / (x2 - x1);

    double c = y1 - m * x1;  //Equation of line y = mx + c    

    for (int i = x1; i <= x2; i++) {
        double y = m * i + c;
        double y2 = m * (i + 1) + c;

        glVertex2i(i, y);
        glVertex2i(i + 1, y2);
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // glPointSize(50);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    // drawLine(0.1, 0.1, 0.3, 0.3);

    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.3f, 0.3f);

    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.7f, 0.5f);

    glVertex2f(0.7f, 0.5f);
    glVertex2f(0.9f, 0.3f);

    glVertex2f(0.9f, 0.3f);
    glVertex2f(0.7f, 0.1f);

    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.5f, 0.1f);

    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.3f, 0.3f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Setup Test");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
