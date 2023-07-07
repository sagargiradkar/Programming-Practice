/* ex1.c */
#include <GL/glut.h>
void display (void) {
    /* Called when OpenGL needs to update the display */
    glClear (GL_COLOR_BUFFER_BIT); /* Clear the window */
    glFlush();
    /* Force update of screen */
    }
int main (int argc, char **argv) {
    glutInit (&argc, argv);
    /* Initialise OpenGL */
    glutCreateWindow ("ex1"); /* Create the window */
    glutDisplayFunc (display); /* Register the "display" function */
    glutMainLoop ();
    /* Enter the OpenGL main loop */
    return 0;
}
/* end of ex1.c */