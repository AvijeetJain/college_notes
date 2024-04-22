#include <GL/glut.h>

int windowWidth = 800;
int windowHeight = 600;

void plotPoint(int x, int y) {
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        plotPoint(x, y);

        if (x == x2 && y == y2) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }

        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Set color to white

    drawLineBresenham(250, 250, 450, 250); // Top line
    drawLineBresenham(250, 250, 350, 450); // Left slant line
    drawLineBresenham(350, 450, 450, 250); // Right slant line

    drawLineBresenham(250, 400, 450, 400);
    drawLineBresenham(250, 400, 350, 200);
    drawLineBresenham(350, 200, 450, 400);

    

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);

    windowWidth = width;
    windowHeight = height;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
