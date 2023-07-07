#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.4,-0.4,0.0);
    glVertex3f(0.0,0.4,0.0);
    glVertex3f(0.4,-0.4,0.0);
    glEnd();
    glFlush();
}
void keyboard(unsigned char key ,int x,int y){
    if(key==27){
        exit(0);
    }
    else{
        cout<<"Entered key is "<<key;
    }
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("ex4");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}