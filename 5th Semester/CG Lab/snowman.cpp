#include <GL/freeglut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawCat() {
    // Draw cat's body
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color
    drawCircle(400, 300, 100, 100);

    // Draw cat's head
    drawCircle(400, 400, 50, 100);

    // Draw cat's eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    drawCircle(385, 415, 10, 50);
    drawCircle(415, 415, 10, 50);

    // Draw cat's nose
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    drawCircle(400, 395, 5, 50);

    // Draw cat's ears
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color
    drawCircle(370, 420, 15, 50);
    drawCircle(430, 420, 15, 50);

    // Draw cat's tail
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(300, 250);
    glVertex2f(200, 200);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCat();

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
    glutCreateWindow("Simple Cat Drawing");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
