#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
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
void reshape(int width,int height){
    glViewport(0,0,(GLsizei) width,(GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity ();
/* Initialise it */
    glOrtho(-1.0,1.0, -1.0,1.0, -1.0,1.0); /* The unit cube */
    glMatrixMode (GL_MODELVIEW);
}
int main(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(500,500);
    glutCreateWindow("ex5");
    glutDisplayFunc(display);
    glutReshapeFunc (reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}