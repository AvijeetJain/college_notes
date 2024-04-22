#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/GLUT.h>
#include <math.h>

void myInit()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-100.0, 100.0, -100.0, 100.0,-1.0,1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    printf(", %d, %d, ", x, y);
    glEnd();
}

void ellipseDraw(int rx, int ry, int xc, int yc)
{
    float dx, dy, d1, d2, x, y;
    x= 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2* rx * rx * y;

    while (dx < dy)
    {
        draw_pixel(x + xc, y + yc);
        draw_pixel(-x + xc, y + yc);
        draw_pixel(x + xc, -y + yc);
        draw_pixel(- x + xc, -y + yc);

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else{
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + 
         ((rx * rx) * ((y-1) * (y-1))) - 
         (rx * rx * ry * ry);
    
    while (y>=0)
    {
        draw_pixel(x + xc, y + yc);
        draw_pixel(-x + xc, y + yc);
        draw_pixel(x + xc, -y + yc);
        draw_pixel(-x + xc, -y + yc);

        if (d2 > 0)
        {
             y--;
             dy = dy - (2 * rx * rx);
             d2 = d2 + (rx * rx) - dy;
        }
        else{
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }

}

void myDisplay()
{
    ellipseDraw(10,15, 0,0);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse drawing Algorithm");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
