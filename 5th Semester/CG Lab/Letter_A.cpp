#include <GL/freeglut.h> // Include the GLUT header

// Function to handle the display
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Draw the points for the letter "A"
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.5f); // Top point

    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.25f, 0.0f);
    glVertex2f(0.25f, 0.0f);

    glVertex2f(-0.12f, 0.26f);
    glVertex2f(0.12f, 0.26f);

    glVertex2f(-0.35f, -0.25f);
    glVertex2f(0.35f, -0.25f);

    glVertex2f(-0.5f, -0.5f); // Bottom-left point
    glVertex2f(0.5f, -0.5f); // Bottom-right point
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode

    glutInitWindowSize(500, 500); // Set window size
    glutCreateWindow("OpenGL Letter A"); // Create the window

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black

    glutDisplayFunc(display); // Set the display callback

    glutMainLoop(); // Enter the GLUT main loop

    return 0;
}
