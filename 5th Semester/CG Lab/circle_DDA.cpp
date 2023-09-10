#include <GL/freeglut.h>
#include <cmath>

// Define the window size
const int windowWidth = 512;
const int windowHeight = 512;

// Circle properties
int centerX = windowWidth / 2;
int centerY = windowHeight / 2;
int radius = 100;

void drawCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    // Loop to draw points on the circle using DDA algorithm
    for (int angle = 0; angle <= 360; angle += 1) {
        // Convert the angle to radians
        float radians = angle * M_PI / 180.0;

        // Calculate the coordinates of the point on the circle
        int x = static_cast<int>(radius * cos(radians) + 0.5);
        int y = static_cast<int>(radius * sin(radians) + 0.5);

        // Plot the point
        glVertex2i(centerX + x, centerY + y);
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Circle Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}