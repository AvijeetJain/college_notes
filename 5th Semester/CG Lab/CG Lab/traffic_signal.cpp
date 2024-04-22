#include <GL/freeglut.h>
#include <cmath>

// int drawCircle(int radius, double centerX, double centerY, float r, float g, float b) {
//     // glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(r, g, b);
//     glBegin(GL_POINTS);

//     glVertex2f(centerX, centerY);

//     for (int angle = 0; angle <= 360; angle += 1) {
//         float radians = angle * M_PI / 180.0;

//         int x = static_cast<int>(radius * cos(radians) + 0.5);
//         int y = static_cast<int>(radius * sin(radians) + 0.5);

//         glVertex2f(centerX + x, centerY + y);
//     }
//     glEnd();
//     // glFlush();
//     return 0;
// };

void drawFilledCircle(float x, float y, float radius, int segments, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * (float)i / (float)segments;
        float px = x + radius * cosf(angle);
        float py = y + radius * sinf(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

// int drawLine(double a, double b, double c, double d) {
//     glColor3f(1.0, 1.0, 1.0);
//     glBegin(GL_LINES);

//     glVertex2i(a, b);
//     glVertex2i(c, d);
//     glEnd();

//     return 0;
// };


void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);


    drawFilledCircle(0.0, 0.3, 0.14, 100, 1.0, 0.0, 0.0);  // red
    drawFilledCircle(0.0, 0.0, 0.14, 100, 1.0, 1.0, 0.0);  // yellow
    drawFilledCircle(0.0, -0.3, 0.14, 100, 0.0, 1.0, 0.0); // Green

    drawFilledCircle(0.7, 0.6, 0.12, 100, 0.0, 0.0, 1.0); // Baloon

    drawFilledCircle(-0.5, 0.7, 0.1, 100, 1.0, 1.0, 1.0); // Moon


    // drawCircle(20, 100, 500, 1.0, 1.0, 1.0);

    // drawCircle(50, 300, 410, 1.0, 0.0, 0.0);
    // drawCircle(50, 300, 300, 1.0, 1.0, 0.0);
    // drawCircle(50, 300, 190, 0.0, 1.0, 0.0);

    glBegin(GL_LINES);

    // drawLine(0.5, 0.5, 0.1, 0.1);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.2f, 0.5f);

    glVertex2f(0.2f, 0.5f);
    glVertex2f(-0.2f, 0.5f);

    glVertex2f(0.2f, -0.5f);
    glVertex2f(-0.2f, -0.5f);

    glVertex2f(-0.2f, 0.5f);
    glVertex2f(-0.2f, -0.5f);

    glVertex2f(-0.05f, -0.5f);
    glVertex2f(-0.05f, -0.9f);

    glVertex2f(0.05f, -0.5f);
    glVertex2f(0.05f, -0.9f);

    glVertex2f(0.7f, 0.47f);
    glVertex2f(0.7f, 0.1f);

    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Traffic Signal");

    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // gluOrtho2D(0, 600, 0, 600);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}