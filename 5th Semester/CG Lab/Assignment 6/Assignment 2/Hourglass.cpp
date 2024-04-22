#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    
    glLineWidth(3.0); // Set line width
    
    glBegin(GL_LINES);
    
    // Draw a triangle using lines
    glVertex2f(-0.5, -0.5); // Bottom left
    glVertex2f(0.5, -0.5);  // Bottom right
    
    glVertex2f(-0.5, -0.5); // Bottom left
    glVertex2f(0.0, 0.2);   // Top
    
    glVertex2f(0.5, -0.5);  // Bottom right
    glVertex2f(0.0, 0.2);   // Top


    glVertex2f(-0.5, 0.5); // Top left
    glVertex2f(0.5, 0.5);  // Top right
    
    glVertex2f(-0.5, 0.5); // Top left
    glVertex2f(0.0, -0.2);   // Bottom
    
    glVertex2f(0.5, 0.5);  // Top right
    glVertex2f(0.0, -0.2);   // Bottom

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
    glutCreateWindow("Triangle using GL_LINES");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
