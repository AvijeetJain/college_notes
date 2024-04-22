#include <GL/glut.h>

// Function to draw a filled rectangle
void drawFilledRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to handle the display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the first rectangle from top
    drawFilledRectangle(-0.5, 0.5, 1.0, 0.2, 1.0, 0.5, 0.0); // Red

    // Draw the second rectangle below the first
    drawFilledRectangle(-0.5, 0.3, 1.0, 0.2, 1.0, 1.0, 1.0); // Green

    // Draw the third rectangle below the second
    drawFilledRectangle(-0.5, 0.1, 1.0, 0.2, 0.0, 1.0, 0.0); // Blue



    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Three Rectangles");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set clear color to white

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
