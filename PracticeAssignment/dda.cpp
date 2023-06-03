#include<iostream>
#include<GL/glut.h>
using namespace std;

#define w 1000
#define h 1000

float x1,x2,y11,y2,dx,dy;
int x,y;
float length;
void myInit(void)
	{
		glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(0.0,0.0,0.0);
		glPointSize(3.0);
		glLineWidth(5.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-w/2,w/2,-h/2,h/2);
	}
int sig(int x)
	{
		if(x>0)
		return +1;
		else if (x<0)
		return -1;
		else
		return 0;
	}	
void dda(float x1,float y11,float x2,float y2)
	{
		if(abs(x2-x1)>=abs(y2-y11))
			length=(x2-x1);
		else
			length=(y2-y11);
		
		dx=(x2-x1)/length;
		dy=(y2-y11)/length;
		
		x=x1+0.5*sig(dx);
		y=y11+0.5*sig(dy);
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		
		int i=1;
		while(i<=length)
			{	
				x=x+dx;
				y=y+dy;
				glVertex2i(x,y);
				i++;
			}
		glEnd();
	}
void dda1(float x1,float y11,float x2,float y2)
	{
		if(abs(x2-x1)>=abs(y2-y11))
			length=(x2-x1);
		else
			length=(y2-y11);
		
		dx=(x2-x1)/length;
		dy=(y2-y11)/length;
		
		x=x1+0.5*sig(dx);
		y=y11+0.5*sig(dy);
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		
		int i=1;
		while(i<=length)
			{	
				x=x+dx;
				y=y+dy;
				if(i%2==0 ){
				glVertex2i(x,y);
				}
				i++;
			}
		glEnd();
	}
void dda2(float x1,float y11,float x2,float y2)
	{
		if(abs(x2-x1)>=abs(y2-y11))
			length=(x2-x1);
		else
			length=(y2-y11);
		
		dx=(x2-x1)/length;
		dy=(y2-y11)/length;
		
		x=x1+0.5*sig(dx);
		y=y11+0.5*sig(dy);
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		
		int i=1;
		while(i<=length)
			{
				x=x+dx;
				y=y+dy;
				if( i%15!=0)
				glVertex2i(x,y);
				i++;
			}
		glEnd();
	}
	
void dda3(float x1,float y11,float x2,float y2)
	{
		if(abs(x2-x1)>=abs(y2-y11))
			length=(x2-x1);
		else
			length=(y2-y11);
		
		dx=(x2-x1)/length;
		dy=(y2-y11)/length;
		
		x=x1+0.5*sig(dx);
		y=y11+0.5*sig(dy);
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		
		int i=1;
		while(i<=length)
			{
				x=x+dx;
				y=y+dy;
				if( i%20<=10 || i%20==15)
				glVertex2i(x,y);
				i++;
			}
		glEnd();
	}
void display(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINES);
		
		glVertex2i(w/2,0);
		glVertex2i(-w/2,0);
		
		glEnd();
		glBegin(GL_LINES);
		
		glVertex2i(0,h/2);
		glVertex2i(0,-h/2);
		
		glEnd();
		glFlush();
	}
void Menu(int n)
	{
	switch(n){
		case 1:dda(x1,y11,x2,y2);
				break;
		case 2:dda1(x1,y11,x2,y2);
				break;
		case 3:dda2(x1,y11,x2,y2);
				break;
		case 4:dda3(x1,y11,x2,y2);
				break;
		default: exit(0);
		}
	}
int main(int argc,char ** argcv)
	{
		cout<<"Enter x1,y1,x2,y2 :";
		cin>>x1>>y11>>x2>>y2;
		glutInit(&argc,argcv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(w,h);
		glutInitWindowPosition(100,100);
		glutCreateWindow("AXIS");
		myInit();
		glutDisplayFunc(display);
		glutCreateMenu(Menu);
			glutAddMenuEntry("SIMPLE LINE",1);
			glutAddMenuEntry("DOTTED LINE",2);
			glutAddMenuEntry("DASHED LINE",3);
			glutAddMenuEntry("CENTER DOTTED LINE",4);	
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutMainLoop();
		
		return 0;
		
	}
