#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
int sun=0;
void myInit(void)
	{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1080.0,0.0,720.0);
	}
	
void Sun(void)
{
	// Sun
	glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
	double theta;
	int radius = 100;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1600 + radius*sin(theta), 950 + radius*cos(theta));
    }
    glEnd();
}
void Scenery()
	{
		glPushMatrix();
		glTranslatef(0,sun,0);
		glColor3f(1.0f,0.0f,1.0f);
		//background
		Sun();
		glPopMatrix();
		//	glutSwapBuffers();		
	
		// sun cover background
		glBegin(GL_POLYGON);
		glColor3f(0.6,0.7,0.0);
		glVertex2i(1300,580);
		glVertex2i(1300,700);		
		glVertex2i(1700,700);	
		glVertex2i(1700,580);	
		glEnd();
	
	}
void display(void)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	Scenery();
	glEnd();
	glFlush();
	}
void Timer1(int)
{
	glutPostRedisplay();
    glutTimerFunc(1000/60, Timer1, 0);
    sun -= 1;		//Increase it speed up
    if(sun == -270)
    {
        // Background Sky
    	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);		//black
		glVertex2i(0,700);
		glVertex2i(0,1080);
		glVertex2i(1920,1080);
		glVertex2i(1920,700);
		glEnd();
    	sun = 300;		
    }
}

int main(int argc,char **argv)
	{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(0.0,0.0);
	glutCreateWindow("Animation");
	glutTimerFunc(0, Timer1, 0);
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	}
