#include <GL/freeglut.h>
#include <cmath>

// Define the window size
const int windowWidth = 512;
const int windowHeight = 512;

void drawTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    // Define the triangle's vertices
    int vertex1X = 100, vertex1Y = 100;
    int vertex2X = 300, vertex2Y = 100;
    int vertex3X = 200, vertex3Y = 300;

    // Loop through each side of the triangle
    for (int t = 0; t <= 100; ++t) {
        // Calculate intermediate points on each side
        int x1 = vertex1X + (t * (vertex2X - vertex1X)) / 100;
        int y1 = vertex1Y + (t * (vertex2Y - vertex1Y)) / 100;

        int x2 = vertex2X + (t * (vertex3X - vertex2X)) / 100;
        int y2 = vertex2Y + (t * (vertex3Y - vertex2Y)) / 100;

        int x3 = vertex3X + (t * (vertex1X - vertex3X)) / 100;
        int y3 = vertex3Y + (t * (vertex1Y - vertex3Y)) / 100;

        // Draw the points on each side
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawTriangle();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Triangle Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
