#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

void display(){

glClearColor(0, 0, 0, 0);

glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);

glBegin(GL_POINTS);

    for(int i=0; i<1000; ++i){

    glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);

    }

glEnd();

glFlush();
}
int main(int argc, char** argv) {

glutInit(&argc, argv),
glutCreateWindow("OpenGL Setup Test");
glutInitWindowSize(600,600);
glutInitWindowPosition(50, 50);
glutDisplayFunc(display);
glutMainLoop();

}
