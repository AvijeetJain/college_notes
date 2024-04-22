#include <GL/glut.h>

void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawHouse() {
    // Base
    glColor3f(0.8, 0.5, 0.2); // Brown color
    drawRectangle(-0.5, -0.5, 0.5, 0.0);

    // Chimney
    glColor3f(0.2, 0.2, 0.2); // Gray color
    drawRectangle(-0.35, 0.0, -0.15, 0.4);

    // Roof
    glColor3f(0.8, 0.5, 0.2); // Same as base
    drawTriangle(-0.5, 0.0, 0.5, 0.0, 0.0, 0.4);

    // Door
    glColor3f(0.3, 0.2, 0.0); // Dark Brown color
    drawRectangle(-0.3, -0.5, -0.1, -0.2);

    // Window
    glColor3f(0.2, 0.6, 0.8); // Light Blue color
    // drawRectangle(-0.35, -0.1, -0.15, 0.1);
    drawRectangle(0.15, -0.28, 0.35, -0.1);
    // drawRectangle(-0.25, 0.2, -0.05, 0.4);
    // drawRectangle(0.05, 0.2, 0.25, 0.4);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouse();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("House with Chimney, Door, and Window");
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
