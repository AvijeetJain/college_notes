#include <windows.h> // for MS Windows
#include <GL/freeglut.h> // GLUT, include glut.h,and glu.h
#include <stdio.h>
#include <math.h>

void display() {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);


    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0); // red
    glVertex2f( 0.2, 0.2 );
    glColor3f( 0, 1, 0 ); // green
    glVertex2f( 0.8, 0.2 );
    glColor3f( 0, 0, 1 ); // blue
    glVertex2f(0.5, 0.9);
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
glutInitWindowSize(500,500); // Set the window&#39;s initial width &amp; height
glutInitWindowPosition(100,100); // Position the window&#39;s initial top-left corner
glutDisplayFunc(display); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}