#include<iostream>
#include<GL/glut.h>
using namespace std;

void myInit(void)
	{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(1.0);
	glLineWidth(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
	}
	
	
void display(void)
	{
	glClear(GL_COLOR_BUFFER_BIT);
		
	glEnd();
	glFlush();
	}

int main(int argc,char ** argv)
	{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Boundary Fill Algorithm ");
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
	}		
