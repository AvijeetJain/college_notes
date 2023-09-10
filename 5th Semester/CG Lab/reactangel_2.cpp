#include <GL/freeglut.h>
#include <cmath>

// Define the window size
const int windowWidth = 512;
const int windowHeight = 512;

void drawRectangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    // Define the rectangle's coordinates
    int left = 100, right = 300;
    int bottom = 100, top = 300;

    // Loop through each side of the rectangle
    for (int i = left; i <= right; ++i) {
        // Draw top side
        glVertex2i(i, top);
        // Draw bottom side
        glVertex2i(i, bottom);
    }

    for (int j = bottom; j <= top; ++j) {
        // Draw left side
        glVertex2i(left, j);
        // Draw right side
        glVertex2i(right, j);
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawRectangle();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Rectangle Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
