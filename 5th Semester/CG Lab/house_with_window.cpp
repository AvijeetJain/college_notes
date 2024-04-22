#include <GL/glut.h> // Include the GLUT header

// Function to handle the display
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Draw the house using lines
    glBegin(GL_LINES);

    // House base
    glVertex2f(-0.5f, -0.4f); // Bottom-left corner
    glVertex2f(0.5f, -0.4f);  // Bottom-right corner

    glVertex2f(0.5f, -0.4f);  // Bottom-right corner
    glVertex2f(0.5f, 0.4f);   // Top-right corner

    glVertex2f(0.5f, 0.4f);   // Top-right corner
    glVertex2f(-0.5f, 0.4f);  // Top-left corner

    glVertex2f(-0.5f, 0.4f);  // Top-left corner
    glVertex2f(-0.5f, -0.4f); // Bottom-left corner

    // Roof
    glVertex2f(-0.5f, 0.4f);  // Top-left corner
    glVertex2f(0.0f, 0.7f);   // Apex

    glVertex2f(0.5f, 0.4f);   // Top-right corner
    glVertex2f(0.0f, 0.7f);   // Apex

    // Shifted Door
    glVertex2f(-0.35f, -0.4f); // Left side
    glVertex2f(-0.35f, 0.0f);  // Top

    glVertex2f(-0.15f, -0.4f); // Right side
    glVertex2f(-0.15f, 0.0f);  // Top

    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.15f, 0.0f);

    // Window
    glVertex2f(0.2f, 0.15f);  // Top-left corner
    glVertex2f(0.4f, 0.15f);  // Top-right corner

    glVertex2f(0.2f, -0.05f); // Bottom-left corner
    glVertex2f(0.4f, -0.05f); // Bottom-right corner

    glVertex2f(0.2f, 0.15f);  // Left side
    glVertex2f(0.2f, -0.05f); // Right side

    glVertex2f(0.4f, 0.15f);  // Top side
    glVertex2f(0.4f, -0.05f); // Bottom side

    // Chimney
    glVertex2f(-0.3f, 0.53f);  // Top-left corner
    glVertex2f(-0.3f, 0.7f);  // Top-right corner

    glVertex2f(-0.3f, 0.7f);  // Left side
    glVertex2f(-0.2f, 0.7f);  // Right side

    glVertex2f(-0.2f, 0.59f);  // Top side
    glVertex2f(-0.2f, 0.7f);  // Bottom side

    glEnd();

    glFlush(); // Flush the OpenGL pipeline
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode

    glutInitWindowSize(500, 500); // Set window size
    glutCreateWindow("OpenGL House with Door and Window"); // Create the window

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black

    glutDisplayFunc(display); // Set the display callback

    glutMainLoop(); // Enter the GLUT main loop

    return 0;
}
