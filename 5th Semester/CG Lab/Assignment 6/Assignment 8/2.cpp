#include <GL/glut.h>
#include <cmath>

bool wireframe = false;

void drawCylinder(float radius, float height, int numSegments) {
    if (wireframe) {
        glBegin(GL_LINES);
        for (int i = 0; i <= numSegments; i++) {
            float angle = i * 2.0f * M_PI / numSegments;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            glVertex3f(x, height / 2.0f, z);
            glVertex3f(x, -height / 2.0f, z);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= numSegments; i++) {
            float angle = i * 2.0f * M_PI / numSegments;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            glVertex3f(x, height / 2.0f, z);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= numSegments; i++) {
            float angle = i * 2.0f * M_PI / numSegments;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            glVertex3f(x, -height / 2.0f, z);
        }
        glEnd();
    } else {
        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i <= numSegments; i++) {
            float angle = i * 2.0f * M_PI / numSegments;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            glVertex3f(x, height / 2.0f, z);
            glVertex3f(x, -height / 2.0f, z);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, height / 2.0f, 0.0f);
        for (int i = 0; i <= numSegments; i++) {
            float angle = i * 2.0f * M_PI / numSegments;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            glVertex3f(x, height / 2.0f, z);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, -height / 2.0f, 0.0f);
        for (int i = 0; i <= numSegments; i++) {
            float angle = i * 2.0f * M_PI / numSegments;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            glVertex3f(x, -height / 2.0f, z);
        }
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCylinder(1.0f, 2.0f, 20);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w' || key == 'W') {
        wireframe = !wireframe;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Cylinder");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}