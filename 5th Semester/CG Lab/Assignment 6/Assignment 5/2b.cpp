#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/GLUT.h>
#include <math.h>

void myInit()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-50.0, 50.0, -50.0, 50.0,-1.0,1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    printf(", %d, %d, ", x, y);
    glEnd();
}
void drawLineLow(int x1, int y1, int x2, int y2)
{

    int dy = y2 - y1;
    int dx = x2 - x1;
    int yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    int D;
    D = (2 * dy) - dx;
    int y = y1;

    for (int x = x1; x <= x2; x++)
    {
        draw_pixel(x, y);
        if (D > 0)
        {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else
        {
            D = D + 2 * dy;
        }
    }
}
void drawLineHigh(int x1, int y1, int x2, int y2)
{

    int dy = y2 - y1;
    int dx = x2 - x1;
    int xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int D;
    D = (2 * dx) - dy;
    int x = x1;

    for (int y = y1; y <= y2; y++)
    {
        draw_pixel(x, y);
        if (D > 0)
        {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
        {
            D = D + 2 * dx;
        }
    }
}

void decideSlope(int x0, int y0, int x1, int y1)
{

    if (abs(y1 - y0) < abs(x1 - x0))
    {
        if (x0 > x1)
            drawLineLow(x1, y1, x0, y0);
        else
            drawLineLow(x0, y0, x1, y1);
    }
    else
    {
        if (y0 > y1)
            drawLineHigh(x1, y1, x0, y0);
        else
            drawLineHigh(x0, y0, x1, y1);
    }
}

void myDisplay()
{
    decideSlope(1, 1, 15, 15);
    decideSlope(15,15 , 29, 1);
    decideSlope(8,8, 22, 8);
    decideSlope(1,1,29,1);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Triangle using mid Point Algorithm");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}