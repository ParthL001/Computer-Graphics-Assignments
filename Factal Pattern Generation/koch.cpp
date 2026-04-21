#include <GL/glut.h>
#include <cmath>

int n = 4; // recursion depth

// Function to draw Koch Curve
void koch(float x1, float y1, float x2, float y2, int depth) {
    float x3, y3, x4, y4, x5, y5;
    float angle = M_PI / 3; // 60 degrees

    if (depth == 0) {
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        return;
    }

    // Divide line into 3 parts
    x3 = (2 * x1 + x2) / 3;
    y3 = (2 * y1 + y2) / 3;

    x4 = (x1 + 2 * x2) / 3;
    y4 = (y1 + 2 * y2) / 3;

    // Calculate peak point
    x5 = x3 + (x4 - x3) * cos(angle) - (y4 - y3) * sin(angle);
    y5 = y3 + (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    // Recursive calls
    koch(x1, y1, x3, y3, depth - 1);
    koch(x3, y3, x5, y5, depth - 1);
    koch(x5, y5, x4, y4, depth - 1);
    koch(x4, y4, x2, y2, depth - 1);
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    // Triangle vertices
    float x1 = -0.5, y1 = -0.3;
    float x2 = 0.5, y2 = -0.3;
    float x3 = 0.0, y3 = 0.6;

    // Draw 3 sides of triangle using Koch
    koch(x1, y1, x2, y2, n);
    koch(x2, y2, x3, y3, n);
    koch(x3, y3, x1, y1, n);

    glEnd();
    glFlush();
}

// Initialization
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glColor3f(1.0, 1.0, 1.0);         // white snowflake
    glPointSize(2.0);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Koch Snowflake Fractal");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
