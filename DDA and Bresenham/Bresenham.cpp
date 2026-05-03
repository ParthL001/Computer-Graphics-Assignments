#include <GL/glut.h>
#include <cmath>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    int x1 = 100 , y1 = 100 , x2 = 400 , y2 = 300;
    int dx = x2 - x1;
    int dy = y2 - y1;

    int Pk = (2*dy) - dx;

    int x = x1 , y = y1;

    while(x <= x2 ){
        glVertex2i(x , y);
        if(Pk < 0){

            Pk = Pk + (2*dy);
            x +=1;
        }else{
            
            Pk = Pk + (2*dy) - (2*dx);
            x += 1;
            y += 1;
        }
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
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}