#include <GL/glut.h>
#include <vector>

struct Point {
    float x, y;
};

std::vector<Point> controlPoints = {
    {-0.8, -0.3},
    {-0.5, 0.3},
    {0.5, 0.3},
    {0.8, -0.3}
};

Point computeBezierPoint(float t, const Point& p0, const Point& p1, const Point& p2) {
    float u = 1.0 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    Point p;
    p.x = uuu * p0.x + 3 * uu * t * p1.x + 3 * u * tt * p2.x + ttt * controlPoints[3].x;
    p.y = uuu * p0.y + 3 * uu * t * p1.y + 3 * u * tt * p2.y + ttt * controlPoints[3].y;

    return p;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Draw the first spline
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1; t += 0.01) {
        Point point = computeBezierPoint(t, controlPoints[0], controlPoints[1], controlPoints[2]);
        glVertex2f(point.x, point.y);
    }
    glEnd();

    // Draw the second spline below the first one
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1; t += 0.01) {
        Point point = computeBezierPoint(t, controlPoints[0], controlPoints[1], controlPoints[2]);

        point.y -= 0.5;
        glVertex2f(point.x, point.y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Racetrack Spline");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
