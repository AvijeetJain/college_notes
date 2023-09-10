#include <GL/freeglut.h>
#include <cmath>

void drawNetflixLogo() {
    // Draw the background rectangle
    glColor3f(0.827f, 0.125f, 0.176f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(100, 100);
    glVertex2f(700, 100);
    glVertex2f(700, 500);
    glVertex2f(100, 500);
    glEnd();

    // Draw the white "N"
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glBegin(GL_POLYGON);
    glVertex2f(200, 300);
    glVertex2f(350, 300);
    glVertex2f(350, 400);
    glVertex2f(250, 400);
    glVertex2f(250, 500);
    glVertex2f(200, 500);
    glEnd();

    // Draw the red "N" part
    glColor3f(0.827f, 0.125f, 0.176f); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(250, 300);
    glVertex2f(300, 300);
    glVertex2f(350, 350);
    glVertex2f(350, 400);
    glVertex2f(250, 400);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawNetflixLogo();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simplified Netflix Logo Drawing");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
