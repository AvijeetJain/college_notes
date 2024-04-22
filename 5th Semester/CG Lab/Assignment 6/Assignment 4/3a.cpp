#include <GL/glut.h>
#include <cmath>

const int width = 800;
const int height = 600;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Bresenham's circle drawing algorithm
void drawCircle(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX + y, centerY + x);
        drawPixel(centerX - y, centerY + x);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX - x, centerY - y);
        drawPixel(centerX - y, centerY - x);
        drawPixel(centerX + y, centerY - x);
        drawPixel(centerX + x, centerY - y);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Draw the Star of David
    drawCircle(400, 300, 200);

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Star of David Circle using Bresenham's Algorithm");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black

    glutMainLoop();

    return 0;
}
