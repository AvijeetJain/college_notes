#include <GL/glut.h>

// Define the octahedron vertices
GLfloat vertices[][3] = {
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0},
    {-1.0, 0.0, 0.0},
    {0.0, 0.0, -1.0},
    {0.0, -1.0, 0.0}
};

// Define the octahedron faces
GLint faces[][3] = {
    {0, 1, 2},
    {0, 2, 3},
    {0, 3, 4},
    {0, 4, 1},
    {5, 2, 1},
    {5, 3, 2},
    {5, 4, 3},
    {5, 1, 4}
};

// Define the rotation angles
GLfloat angles[] = {0.0, 0.0, 0.0};

// Define the mouse position
int mouse_x = 0;
int mouse_y = 0;

// Define the mouse button state
int mouse_button = -1;

// Define the octahedron drawing function
void draw_octahedron() {
    int i, j;
    glBegin(GL_LINES);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            glVertex3fv(vertices[faces[i][j]]);
            glVertex3fv(vertices[faces[i][(j+1)%3]]);
        }
    }
    glEnd();
}

// Define the display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(angles[0], 1.0, 0.0, 0.0);
    glRotatef(angles[1], 0.0, 1.0, 0.0);
    glRotatef(angles[2], 0.0, 0.0, 1.0);
    draw_octahedron();
    glutSwapBuffers();
}

// Define the mouse function
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        mouse_x = x;
        mouse_y = y;
        mouse_button = button;
    } else if (state == GLUT_UP) {
        mouse_button = -1;
    }
}

// Define the motion function
void motion(int x, int y) {
    if (mouse_button == GLUT_LEFT_BUTTON) {
        angles[1] += (x - mouse_x) / 2.0;
        angles[0] += (y - mouse_y) / 2.0;
    } else if (mouse_button == GLUT_RIGHT_BUTTON) {
        angles[2] += (x - mouse_x) / 2.0;
    }
    mouse_x = x;
    mouse_y = y;
    glutPostRedisplay();
}

// Define the reshape function
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

// Define the main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Interactive Octahedron");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
