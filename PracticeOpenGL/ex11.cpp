#include<GL/glut.h>
#include<iostream>
using namespace std;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void keyboard(unsigned char key,int x,int y){
    if(key==27){
        exit(0);
    }
    else{
        cout<<"You Enterd :"<<key;
    }
}
void toys_bistro(int item){
    cout<<"Toby's bistro: you click item "<<item;
}
void steves_chippy(int item){
    cout<<"Steves chippy :you clicked item "<<item;
}
int main(int argc ,char **argv){
    glutInit(&argc,argv);
    glutCreateWindow("Menus");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutCreateMenu (toys_bistro); /* Create the first menu & add items */
    glutAddMenuEntry ("Petto di Tacchino alla Napoletana", 1);
    glutAddMenuEntry ("Bruschetta al Pomodoro e Olive", 2);
    glutAddMenuEntry ("Chianti Classico", 3);
    glutAttachMenu (GLUT_RIGHT_BUTTON); /* Attach it to the right button */

    glutCreateMenu (steves_chippy); /* Create the second menu & add items */
    glutAddMenuEntry ("Rissoles", 1);
    glutAddMenuEntry ("Curry sauce", 2);
    glutAddMenuEntry ("Vimto", 3);
    glutAttachMenu (GLUT_MIDDLE_BUTTON);


    glutMainLoop();
    return 0;

}