#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    
    glLineWidth(3.0); // Set line width
    
    glBegin(GL_LINES);
    
    // Draw a pentagon using lines
    const int sides = 5;
    const float radius = 0.4;
    const float centerX = 0.0;
    const float centerY = 0.0;
    
    for (int i = 0; i < sides; ++i) {
        float angle1 = 2 * M_PI * i / sides;
        float angle2 = 2 * M_PI * (i + 1) / sides;
        
        float x1 = centerX + radius * cos(angle1);
        float y1 = centerY + radius * sin(angle1);
        
        float x2 = centerX + radius * cos(angle2);
        float y2 = centerY + radius * sin(angle2);
        
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    
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
    glutCreateWindow("Pentagon using GL_LINES");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}
