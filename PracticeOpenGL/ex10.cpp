#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex3f(0.0,6.0,4.0);
    glVertex3f (0.0, 8.0, 0.0);
    glVertex3f (8.0, 6.0, 0.0);
    glVertex3f (8.0, 3.0, 0.0);
    glVertex3f (6.0, 0.0, 5.0);
    glVertex3f (2.0, 0.0, 5.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0,6.0,4.0);
    glVertex3f(0.0,8.0,0.0);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f (8.0, 3.0, 0.0);
    glVertex3f (6.0, 0.0, 5.0);
    glVertex3f (2.0, 0.0, 5.0);
    glEnd ();

    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0,6.0,4.0);
    glVertex3f(0.0,8.0,0.0);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f (8.0, 3.0, 0.0);
    glVertex3f (6.0, 0.0, 5.0);
    glVertex3f (2.0, 0.0, 5.0);
    glEnd ();

    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0,6.0,4.0);
    glVertex3f(0.0,8.0,0.0);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f (8.0, 3.0, 0.0);
    glVertex3f (6.0, 0.0, 5.0);
    glVertex3f (2.0, 0.0, 5.0);
    glEnd ();

    glBegin (GL_TRIANGLES);
    glVertex3f (0.0, 6.0, 4.0);
    glVertex3f (0.0, 8.0, 0.0);
    glVertex3f (8.0, 6.0, 0.0);
    glVertex3f (8.0, 3.0, 0.0); 
    glVertex3f (6.0, 0.0, 5.0);
    glVertex3f (2.0, 0.0, 5.0);
    glEnd ();

    glBegin (GL_QUADS); /* or GL_QUAD_STRIP */
    glVertex3f (0.0, 6.0, 4.0);
    glVertex3f (0.0, 8.0, 0.0);
    glVertex3f (8.0, 6.0, 0.0);
    glVertex3f (8.0, 3.0, 0.0);
    glVertex3f (6.0, 0.0, 5.0);
    glVertex3f (2.0, 0.0, 5.0);
    glEnd ();

    glBegin (GL_POLYGON);
        glVertex3f (0.0, 6.0, 0.0);
        glVertex3f (0.0, 6.0, 6.0);
        glVertex3f (6.0, 6.0, 6.0);
        glVertex3f (9.0, 6.0, 2.0);
        glVertex3f (9.0, 6.0, 0.0);
    glEnd ();
    glFlush();
}

int main(int argc,char **argcv){
    glutInit(&argc,argcv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(250,250);
    glutCreateWindow("Drawing A Points");
    glutDisplayFunc(display);
    glutMainLoop();
}