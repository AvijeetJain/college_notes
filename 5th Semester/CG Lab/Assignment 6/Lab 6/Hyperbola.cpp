#include <GL/glut.h>
#include <math.h>

int x=0, y=0, a1=4, b1=5;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 480, 0, 640);
}

void display() {
    glColor3f (1, 1, 0);

    glBegin (GL_POINTS);
       for (x = -10; x < 10; x += 0.01)  {     // Horizontal axis hyperbola
	    y = a1 * sqrt (1 + (x*x)/(b1*b1));
          glVertex2f (x,  y);
          glVertex2f (x, -y);
       }
    glEnd ();

    glColor3f (1, 0.4, 0.4);                    // Vertical axis hyperbola

    glBegin (GL_POINTS);
       for (y = -10; y < 10; y += 0.01)  {     
          x = a1 * sqrt (1 + (y*y)/(b1*b1));
          glVertex2f ( x, y);
          glVertex2f (-x, y);
       }
    glEnd();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(200, 400);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Quadratic Formula");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}