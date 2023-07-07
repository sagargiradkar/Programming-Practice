#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void keyboard(unsigned char key ,int x,int y){
    if(key==5){
        exit(0);
    }
    else{
        cout<<"Entered you "<<key;
    }
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("ex3");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;

}