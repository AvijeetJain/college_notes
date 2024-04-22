#include <GL/glut.h>
#include <math.h>

// Function to handle the display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to yellow
    glColor3f(1.0f, 1.0f, 0.0f);

    // Draw the star using lines
    glBegin(GL_LINES);

    // Outer pentagon
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.15f, 0.0f);

    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-0.5f, 0.0f);

    glVertex2f(-0.5f, 0.0f);
    glVertex2f(-0.2f, -0.15f);

    glVertex2f(-0.2f, -0.15f);
    glVertex2f(-0.3f, -0.5f);

    glVertex2f(-0.3f, -0.5f);
    glVertex2f(0.0f, -0.25f);

    glVertex2f(0.0f, -0.25f);
    glVertex2f(0.3f, -0.5f);

    glVertex2f(0.3f, -0.5f);
    glVertex2f(0.2f, -0.15f);

    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.5f, 0.0f);

    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.15f, 0.0f);

    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.0f, 0.5f);

    // Inner pentagon (to create the star shape)
    // glVertex2f(0.0f, 0.35f);
    // glVertex2f(-0.1f, 0.0f);

    // glVertex2f(-0.1f, 0.0f);
    // glVertex2f(-0.35f, 0.0f);

    // glVertex2f(-0.35f, 0.0f);
    // glVertex2f(-0.15f, -0.1f);

    // glVertex2f(-0.15f, -0.1f);
    // glVertex2f(0.0f, -0.35f);

    // glVertex2f(0.0f, -0.35f);
    // glVertex2f(0.15f, -0.1f);

    // glVertex2f(0.15f, -0.1f);
    // glVertex2f(0.35f, 0.0f);

    // glVertex2f(0.35f, 0.0f);
    // glVertex2f(0.1f, 0.0f);

    // glVertex2f(0.1f, 0.0f);
    // glVertex2f(0.0f, 0.35f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Star with Lines");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
