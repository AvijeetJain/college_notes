#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    glPointSize(5);
    glBegin(GL_POINT);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    
    glFlush();


    glLineWidth(3.0); // Set line width
    
    glBegin(GL_LINES);
    
    // Draw a parallelogram using lines
    glVertex2f(-0.5, -0.25); // Bottom left
    glVertex2f(0.5, -0.25);  // Bottom right
    
    glVertex2f(0.5, -0.25);  // Midpoint bottom
    glVertex2f(0.75, 0.25);   // Top right
    
    glVertex2f(-0.5, -0.25); // Bottom left
    glVertex2f(-0.25, 0.25);   // Midpoint top
    
    glVertex2f(-0.25, 0.25);   // Midpoint top
    glVertex2f(0.75, 0.25);   // Top right
    
    glEnd();
    
    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Parallelogram using GL_LINES");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
