#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
double theta;
int radius;
float angle=0;
void myInit(void)
	{
	glClearColor(0.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1920,0,1080);
	}
	
void Sun(void)
	{
	glTranslated(1600,900,0);
	glRotated(4*angle,0,0,1.0);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	radius=70;
	for(int i=0;i<360;i++)
		{
		theta=i*(3.142/180);
		glVertex2f(radius*sin(theta),radius*cos(theta));
		}
	glEnd();
	
	for(int i=0; i<10;i++)
	{
	glRotated(360/10,0,0,1.0);
	glBegin(GL_LINES);
	glVertex2f(80,0);
	glVertex2f(140,00);
	glEnd();
	}
	}
void scenary(void)
	{
	
	glPushMatrix();
	Sun();
	glPopMatrix();
	
	}
void display(void)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	scenary();
	glEnd();
	glFlush();
	}
void Timer1(int)
	{
	glutPostRedisplay();
	glutTimerFunc(1000/60,Timer1,0);
	angle-=0.2;
	if(angle>20)
		{
		angle=-30;
		}
	}
int main(int argc,char **argv)
	{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Animation");
	glutTimerFunc(0,Timer1,0);
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	}
	
