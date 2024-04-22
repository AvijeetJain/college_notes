#include <GL/glut.h>
#include <cmath>

void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawIndianFlag() {
    // Saffron Rectangle (top)
    glColor3f(1.0, 0.5, 0.0); // Saffron color
    drawRectangle(-1.0, 0.333, 1.0, 1.0);

    // White Rectangle (middle)
    glColor3f(1.0, 1.0, 1.0); // White color
    drawRectangle(-1.0, -0.333, 1.0, 0.333);

    // Green Rectangle (bottom)
    glColor3f(0.0, 0.5, 0.0); // Green color
    drawRectangle(-1.0, -1.0, 1.0, -0.333);

    // Blue Circle (Ashoka Chakra)
    glColor3f(0.0, 0.0, 0.545); // Navy Blue color
    drawCircle(0.0, 0.0, 0.24, 24);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawIndianFlag();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Indian Tricolor Flag");
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
