#include <GL/freeglut.h>
#include <cmath>

const int windowWidth = 512;
const int windowHeight = 512;

void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_POINTS);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = std::max(dx, dy);

    float xIncrement = static_cast<float>(x2 - x1) / steps;
    float yIncrement = static_cast<float>(y2 - y1) / steps;

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    for (int i = 0; i <= steps; ++i) {
        glVertex2i(static_cast<int>(x + 0.5), static_cast<int>(y + 0.5));
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
}

void drawTrapezium() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    int leftX = 100, rightX = 300;
    int topY = 400, bottomY = 100;

    drawLine(leftX, bottomY, rightX, bottomY); // Bottom side
    drawLine(leftX, bottomY, leftX + (topY - bottomY) / 2, topY); // Left slant side
    drawLine(rightX, bottomY, rightX - (topY - bottomY) / 2, topY); // Right slant side
    drawLine(leftX + (topY - bottomY) / 2, topY, rightX - (topY - bottomY) / 2, topY); // Top side

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawTrapezium();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Trapezium Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
