// #include <iostream>
// #include <GL/freeglut.h>
// #include <stdlib.h>
// #include<math.h>

// GLsizei winWidth = 600, winHeight = 600;
// GLfloat xwcMin = -200.0, xwcMax = 200.0;
// GLfloat ywcMin = -200.0, ywcMax = 200.0;

// class wcPt3D
// {
// public:
//     GLfloat x, y, z;
// };

// void plotPoint(wcPt3D bezCurvePt)
// {
//     glBegin(GL_POINTS);
//     glVertex2f(bezCurvePt.x, bezCurvePt.y);
//     glEnd();
// }

// void binomialCoeffs(GLint n, GLint* C)
// {
//     GLint k, j;
//     for (k = 0; k <= n; k++)
//     {
//         C[k] = 1;
//         for (j = n; j >= k + 1; j--)
//             C[k] *= j;
//         for (j = n - k; j >= 2; j--)
//             C[k] /= j;
//     }
// }

// void computeBezPt(GLfloat u, wcPt3D* bezPt, GLint nCtrlPts, wcPt3D* ctrlPts, GLint* C)
// {
//     GLint k, n = nCtrlPts - 1;
//     GLfloat bezBlendFcn;
//     bezPt->x = bezPt->y = bezPt->z = 0.0;
//     for (k = 0; k < nCtrlPts; k++)
//     {
//         bezBlendFcn = C[k] * pow(u, k) * pow(1 - u, n - k);
//         bezPt->x += ctrlPts[k].x * bezBlendFcn;
//         bezPt->y += ctrlPts[k].y * bezBlendFcn;
//         bezPt->z += ctrlPts[k].z * bezBlendFcn;
//     }
// }

// void bezier(wcPt3D* ctrlPts, GLint nCtrlPts, GLint nBezCurvePts)
// {
//     wcPt3D bezCurvePt;
//     GLfloat u;
//     GLint* C, k;
//     C = new GLint[nCtrlPts];
//     binomialCoeffs(nCtrlPts - 1, C);
//     for (k = 0; k <= nBezCurvePts; k++)
//     {
//         u = GLfloat(k) / GLfloat(nBezCurvePts);
//         computeBezPt(u, &bezCurvePt, nCtrlPts, ctrlPts, C);
//         plotPoint(bezCurvePt);
//     }
//     delete[] C;
// }

// void displayFcn(void)
// {
//     GLint nCtrlPts = 4, nBezCurvePts = 1000;
//     wcPt3D ctrlPts[4] = {
//     {-160.0, 40.0, 0.0},
//     {-30.0, 300.0, 0.0},
//     {80.0, -300.0, 0.0} };
//     glClear(GL_COLOR_BUFFER_BIT);
//     glPointSize(4);
//     glColor3f(1.0, 0.0, 0.0);
//     bezier(ctrlPts, nCtrlPts, nBezCurvePts);
//     glFlush();
// }

// void WinReshapeFcn(GLint newWidth, GLint newHeight)
// {
//     glViewport(0, 0, newHeight, newHeight);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
//     glClear(GL_COLOR_BUFFER_BIT);
// }

// int main(int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowPosition(50, 50);
//     glutCreateWindow("Bezier curve");

//     glutDisplayFunc(displayFcn);
//     glutReshapeFunc(WinReshapeFcn);
//     glutMainLoop();
// }

#include <GL/glut.h>
#include <vector>

// Define control points for the spline
struct Point {
    float x, y;
};

std::vector<Point> controlPoints = {
    {-0.8, -0.5},
    {-0.5, 0.5},
    {0.5, 0.5},
    {0.8, -0.5}
};

// Function to compute the point on a quadratic Bezier curve
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

// Function to draw the racetrack using spline curves
void drawRacetrack() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);

    for (float t = 0; t <= 1; t += 0.01) {
        Point point = computeBezierPoint(t, controlPoints[0], controlPoints[1], controlPoints[2]);
        glVertex2f(point.x, point.y);
    }

    glEnd();
}

// Function to initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawRacetrack();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Racetrack Spline");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
