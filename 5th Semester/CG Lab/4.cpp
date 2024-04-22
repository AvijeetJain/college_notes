#include <GL/glut.h>
#include <cmath>

// Define the initial position of the sphere
float sphereX = 0.0f;
float sphereY = 0.0f;
float sphereZ = -5.0f;

// Define the radius of the sphere
float sphereRadius = 2.2f;

// Define the number of slices and stacks for the sphere
int sphereSlices = 7;
int sphereStacks = 5;

// Define the rotation angles for the sphere
float sphereRotationX = 0.0f;
float sphereRotationY = 0.0f;

// Define the mouse position variables
int mouseX = 0;
int mouseY = 0;

// Define the mouse button state variables
bool leftMouseButton = false;
bool rightMouseButton = false;

// Function to draw the sphere
void drawSphere() {
    glPushMatrix();
    glTranslatef(sphereX, sphereY, sphereZ);
    glRotatef(sphereRotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(sphereRotationY, 0.0f, 1.0f, 0.0f);
    glutWireSphere(sphereRadius, sphereSlices, sphereStacks);
    glPopMatrix();
}

// Function to handle mouse events
void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            leftMouseButton = true;
            mouseX = x;
            mouseY = y;
        }
        else if (state == GLUT_UP) {
            leftMouseButton = false;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            rightMouseButton = true;
            mouseX = x;
            mouseY = y;
        }
        else if (state == GLUT_UP) {
            rightMouseButton = false;
        }
    }
}

// Function to handle mouse motion events
void handleMouseMove(int x, int y) {
    if (leftMouseButton) {
        sphereRotationY += (x - mouseX) * 0.5f;
        sphereRotationX += (y - mouseY) * 0.5f;
        mouseX = x;
        mouseY = y;
    }
    else if (rightMouseButton) {
        sphereZ += (y - mouseY) * 0.1f;
        mouseY = y;
    }
}



// Function to handle window resize events
void handleResize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    drawSphere();
    glutSwapBuffers();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Interactive Sphere");
    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);
    glutMouseFunc(handleMouse);
    glutMotionFunc(handleMouseMove);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
