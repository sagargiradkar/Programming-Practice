#include<iostream>
#include<math.h>
#include<GL/glut.h>
#define w 1080
#define h 720
using namespace std;
float oldx=-0.7,oldy=0.5;
float newx=0,newy=0;
float theta=0;
int n;
void myInit(void)
	{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0,w,0.0,h);
	}
void drawkoch(float theta,float len,int iter)
	{
	double radtheta=(3.142/180)*theta;
	newx=oldx+len*cos(radtheta);
	newy=oldy+len*sin(radtheta);
	glBegin(GL_LINE_LOOP);
	if(iter==0)
		{
		glVertex2f(newx,newy);
		glVertex2f(oldx,oldy);
		oldx=newx;
		oldy=newy;
		}
	else
		{
		iter--;
		drawkoch(theta,len,iter);
		theta+=60;
		drawkoch(theta,len,iter);
		theta-=120;
		drawkoch(theta,len,iter);
		theta+=60;
		drawkoch(theta,len,iter);
		}
	glEnd();
	}
void display(void)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	drawkoch(0.0,0.05,n);
	drawkoch(-120,0.05,n);
	drawkoch(120,0.05,n);
	glFlush();
	}

int main(int argc,char ** argv)
	{
	cout<<"Enter Number of Iteration :";
	cin>>n;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("KOCH CURVE");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	}
