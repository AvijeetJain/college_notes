#include <GL/freeglut.h>
#include <cmath>

const int windowWidth = 512;
const int windowHeight = 512;

void drawPentagon() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;
    int radius = 150;

    for (int angle = 0; angle < 360; angle += 72) {
        float radians = angle * M_PI / 180.0;
        int x = static_cast<int>(radius * cos(radians) + 0.5);
        int y = static_cast<int>(radius * sin(radians) + 0.5);
        glVertex2i(centerX + x, centerY + y);
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawPentagon();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Pentagon Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
