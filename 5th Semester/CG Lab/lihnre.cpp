#include <GL/freeglut.h>
unsigned char image[512][512][3];

void setPixel(int x, int y) {
    image[y][x][0] = 0;
    image[y][x][1] = 0;
    image[y][x][2] = 255;
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (1) {
        setPixel(x1, y1);

        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void display() {
    for (int y = 0; y < 512; ++y) {
        for (int x = 0; x < 512; ++x) {
            glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, image[y][x]);
        }
    }
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Pixel Drawing");
    drawLine(86, 79, 26, 39);
    drawLine(102, 153, 410, 461);
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
