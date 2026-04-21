#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}

    Point operator+(Point offset) {
        return Point(x + offset.x, y + offset.y);
    }

    Point operator*(float factor) {
        return Point(x * factor, y * factor);
    }

    Point operator^(float degree) {
        float rad = degree * 3.14159 / 180.0;
        return Point(x * cos(rad) - y * sin(rad),
                     x * sin(rad) + y * cos(rad));
    }
};

const int MAX_SIDES = 4;
Point original[MAX_SIDES];
Point transformed[MAX_SIDES];

// Display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 🔴 Original (Shift LEFT)
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < MAX_SIDES; i++)
        glVertex2f(original[i].x - 0.5, original[i].y);
    glEnd();

    // 🟢 Transformed (Shift RIGHT)
    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < MAX_SIDES; i++)
        glVertex2f(transformed[i].x + 0.5, transformed[i].y);
    glEnd();

    glFlush();
}

// Init
void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    // Original square
    original[0] = Point(-0.3, -0.3);
    original[1] = Point(0.3, -0.3);
    original[2] = Point(0.3, 0.3);
    original[3] = Point(-0.3, 0.3);

    int choice;
    cout << "1. Translate\n2. Scale\n3. Rotate\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            float tx, ty;
            cout << "Enter tx ty (e.g. 0.2 0.2): ";
            cin >> tx >> ty;
            for (int i = 0; i < MAX_SIDES; i++)
                transformed[i] = original[i] + Point(tx, ty);
            break;
        }
        case 2: {
            float s;
            cout << "Enter scale (e.g. 1.2): ";
            cin >> s;
            for (int i = 0; i < MAX_SIDES; i++)
                transformed[i] = original[i] * s;
            break;
        }
        case 3: {
            float deg;
            cout << "Enter angle (e.g. 45): ";
            cin >> deg;
            for (int i = 0; i < MAX_SIDES; i++)
                transformed[i] = original[i] ^ deg;
            break;
        }
        default:
            for (int i = 0; i < MAX_SIDES; i++)
                transformed[i] = original[i];
    }

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D Transformation - Both Shapes Visible");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}