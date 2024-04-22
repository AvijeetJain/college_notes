#include <GL/glut.h> 
#include <stdio.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments){
    float theta = 2 * 3.1415926 / (float)(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor
    float radial_factor = cosf(theta);//calculate the radial factor
    float x = r;//we start at angle = 0
    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex

        float tx = -y;
        float ty = x;
        //add the tangential vector
        x += tx * tangetial_factor;
        y += ty * tangetial_factor;
        //correct using the radial factor
        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
void Init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0); // black
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    glOrtho(0, 640, 0, 480, -1.0, 1.0);
}
void display(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.5, 0.5); // green
    drawCircle(250, 250, 100, 360);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(640,640);
    glutInitWindowPosition(50, 50);
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}