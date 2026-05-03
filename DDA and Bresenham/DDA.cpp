#include <GL/glut.h>
#include <cmath>
using namespace std;



void display(){
    float x1 = 100 , y1 = 100 , x2 = 400 , y2 = 300;
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;
    
    float x = x1 , y = y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for(int i = 0 ; i <= steps ; i++){
        glVertex2i(round(x) , round(y));
        x += xInc;
        y += yInc;
    }

    glEnd();
    glFlush();
}

void init(){
    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}