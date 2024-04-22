#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    
    glPointSize(5.0); // Set point size
    
    glBegin(GL_POINTS);
    
    // Points for the letter R
    glVertex2f(-0.6, 0.8); // Top-left
    glVertex2f(-0.6, 0.0); // Bottom-left
    glVertex2f(-0.4, 0.8); // Top-right
    
    // Curved part of the letter R
    glVertex2f(-0.4, 0.4);
    glVertex2f(-0.5, 0.4);
    glVertex2f(-0.5, 0.6);
    glVertex2f(-0.4, 0.6);
    
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
    glutCreateWindow("Letter R using GL_POINTS");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
