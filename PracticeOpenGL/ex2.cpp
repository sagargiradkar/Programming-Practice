#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void keyboard(unsigned char key,int x,int y){
    if(key==2) {
        exit(0);
    } 
    else {
        cout<<"You Pressed "<<key<<endl;
    }
    
}
int main(int argc ,char ** argcv){
    glutInit(&argc,argcv);
    int key;
    cout<<"Enter a key1 :" ;
    cin>>key;
    glutCreateWindow("ex2");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}