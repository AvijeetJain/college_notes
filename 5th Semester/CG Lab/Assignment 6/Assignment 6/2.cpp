#include <GL/glut.h>
#include <cmath>

void drawCircle(float x, float y, float radius) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float dx = radius * cos(theta);
        float dy = radius * sin(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawCrescentMoon() {
    // Outer Circle (full moon)
    glColor3f(1.0, 1.0, 1.0); // White color
    drawCircle(0.5, 0.5, 0.4);

    // Inner Circle (moon surface)
    glColor3f(0.0, 0.0, 0.0); // Black color
    drawCircle(0.7, 0.5, 0.4);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCrescentMoon();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Crescent Moon");
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
