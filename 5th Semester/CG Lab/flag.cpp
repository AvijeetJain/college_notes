#include <GL/glut.h>
#include <math.h>

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

// Function to draw a filled circle (Ashoka Chakra)
void drawFilledCircle(float x, float y, float radius, int segments, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * (float)i / (float)segments;
        float px = x + radius * cosf(angle);
        float py = y + radius * sinf(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

// Function to handle the display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the saffron stripe (top)
    drawFilledRectangle(-1.0, 0.33, 2.0, 0.33, 1.0, 0.5, 0.0); // Saffron

    // Draw the white stripe (middle)
    drawFilledRectangle(-1.0, 0.0, 2.0, 0.33, 1.0, 1.0, 1.0); // White

    // Draw the green stripe (bottom)
    drawFilledRectangle(-1.0, -0.33, 2.0, 0.33, 0.0, 0.56, 0.34); // Green

    // Draw the Ashoka Chakra (Blue Wheel)
    drawFilledCircle(0.011, 0.023, 0.1, 24, 0.0, 0.0, 1.0); // Blue

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 250);
    glutCreateWindow("Indian Flag");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set clear color to white

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
