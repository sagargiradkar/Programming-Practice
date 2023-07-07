//Cube 
#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glutWireCube(2.0);
    glFlush();
}
void keyboard(unsigned key ,int x,int y){
    if(key==27){
        exit(0);
    }
    else{
        cout<<"You entered is "<<key;
    }
}
void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(500,500);
    glutCreateWindow("ex6");
    glutDisplayFunc(display);
   // gutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;

}