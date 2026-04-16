#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
using namespace std;

float x_start, y_start, x_end, y_end;

// DDA Algorithm
void drawLineDDA() {
    float dx = x_end - x_start;
    float dy = y_end - y_start;

    float steps = max(abs(dx), abs(dy));

    float xInc = dx / steps;
    float yInc = dy / steps;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(x_start, y_start);
        x_start += xInc;
        y_start += yInc;
    }
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1); // White line
    drawLineDDA();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1: ";
    cin >> x_start >> y_start;

    cout << "Enter x2 y2: ";
    cin >> x_end >> y_end;

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("DDA Line Drawing");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
//-Iinclude -Llib -lfreeglut -lopengl32 -lglu32 -o