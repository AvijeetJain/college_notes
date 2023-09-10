#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments) {

    float theta = 3.1415926 * 2 / float(num_segments);

    float tangential_factor = tanf(theta);//calculate the tangential facto

    float radial_factor = cosf(theta);//calculate the radial factor

    float x = r; //we start at angle = 0

    float y = 0;

    glLineWidth(2);

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < num_segments; i++) {
        glVertex2f(x + cx, y + cy);

        float tx = -y;
        float ty = x;

        x += tx * tangential_factor;
        y += ty * tangential_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

void Init() {
    /* Set clear color to white */
    glClearColor(1.0, 1.0, 1.0, 0); /* Set fill color to black / */

    glColor3f(0.0, 0.0, 0.0);
    // glViewport(0, 0, 640, 480); 
    // glMatrixMode(GL_PROJECTION); 

    /* glLoadIdentity(); */
    glOrtho(0, 640, 0, 480, -1, 1);

}

void display() {

    glClearColor(0, 0, 0, 0);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    drawCircle(250, 250, 100, 360);

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    Init();
    glutDisplayFunc(display);
    glutMainLoop();

}
