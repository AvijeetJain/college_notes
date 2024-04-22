#include <GL/glut.h>
#include <math.h>

// Function to draw a filled circle
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

    // Draw the head (a filled circle)
    drawFilledCircle(0.0, 0.0, 0.5, 100, 1.0, 1.0, 0.0); // Yellow

    // Draw the left eye (a filled circle)
    drawFilledCircle(-0.2, 0.2, 0.1, 100, 1.0, 1.0, 1.0); // White

    // Draw the right eye (a filled circle)
    drawFilledCircle(0.2, 0.2, 0.1, 100, 1.0, 1.0, 1.0); // White

    // Draw the smile (a curved line)
    glColor3f(0.0, 0.0, 0.0); // Set color to black
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 180; i++) {
        float angle = M_PI * (float)i / 180.0;
        float x = 0.2 * cosf(angle);
        float y = -0.2 * sinf(angle) - 0.1;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Smiley Face with Curves");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set clear color to white

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
