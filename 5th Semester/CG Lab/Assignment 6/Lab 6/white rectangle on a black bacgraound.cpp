#include <windows.h> // for MS Windows
#include <GL/freeglut.h> // GLUT, include glut.h,and glu.h
#include <stdio.h>
#include <math.h>

void display() {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.25, 0.25, 0.0);
    glVertex3f (0.75, 0.25, 0.0);
    glVertex3f (0.75, 0.75, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glFlush();
// Render now
}
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(500,500); // Set the window&#39;s initial width height
    glutInitWindowPosition(50,50); // Position the window&#39;s initial    top-left corner
    glutDisplayFunc(display); // Register display callback handler for    window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}