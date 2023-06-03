#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
float oldx=-0.7,oldy=0.5;
int n;
void myInit(void)
	{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	}
void drawkoch(float dir,float len,int iter)
	{
		double dirRad=0.0174533*dir;
		float newx=oldx + len * cos(dirRad);
		float newy=oldy + len * sin(dirRad);
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
				drawkoch(dir,len,iter);
				dir+=60;
				drawkoch(dir,len,iter);
				dir-=120;
				drawkoch(dir,len,iter);
				dir+=60;
				drawkoch(dir,len,iter);
			}
		glEnd();
	}
void display(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		drawkoch(0.0,0.05,n);
		drawkoch(-120.0,0.05,n);
		drawkoch(120.0,0.05,n);
		glFlush();
		
	}
	
int main(int argc,char **argcv)
	{
		cout<<"\nEnter the number of interation :";
		cin>>n;
		glutInit(&argc,argcv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(1080,720);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Koach Curve");
		myInit();
		glutDisplayFunc(display);
		glutMainLoop();
		return 0;
	}
