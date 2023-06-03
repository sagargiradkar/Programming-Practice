#include<iostream>
#include<GL/glut.h>
using namespace std;

#define h 1000
#define w 1000
int x,y,x1,y11,x2,y2,dx,dy;
void myInit(void)
	{
		glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(0,0,0);
		glPointSize(3.0);
		glLineWidth(3.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-w/2,w/2,-h/2,h/2);
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
int sign(int x)
	{
		if(x>0)
		return +1;
		else if(x<0)
		return -1;
		else 
		return 0;
	}
void BSLD(int x1,int y11,int x2,int y2)
	{	
		int interchange,e,s1,s2;
		x=x1,y=y11;
		dx=(x2-x1);
		dy=(y2-y11);
		s1=sign(dx);
		s2=sign(dy);
		
		if(dy>dx)
			{
				swap(dx,dy);
				interchange=1;
			}
		else
			{
				interchange=0;
			}
		e=2*dy-dx;
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		for(int i=1;i<=dx;i++)
			{
				glBegin(GL_POINTS);
				glVertex2i(x,y);
				glEnd();
				while(e>=0)
					{
						if(interchange==1)
							{
								x=x+s1;
							}
						else 
							{
							y=y+s2;
							}
						e=e-2*dx;
						}
				if(interchange==1)
					{
						y=y+s2;
					}
				else
					{
						x=x+s1;
					}
				e=e+2*dy;
			}
	}		
void BSLD1(int x1,int y11,int x2,int y2)
	{	
		int interchange,e,s1,s2;
		x=x1,y=y11;
		dx=(x2-x1);
		dy=(y2-y11);
		s1=sign(dx);
		s2=sign(dy);
		
		if(dy>dx)
			{
				swap(dx,dy);
				interchange=1;
			}
		else
			{
				interchange=0;
			}
		e=2*dy-dx;
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		for(int i=1;i<=dx;i++)
			{
				glBegin(GL_POINTS);
				if(i%20==0)
				glVertex2i(x,y);
				glEnd();
				while(e>=0)
					{
						if(interchange==1)
							{
								x=x+s1;
							}
						else 
							{
							y=y+s2;
							}
						e=e-2*dx;
						}
				if(interchange==1)
					{
						y=y+s2;
					}
				else
					{
						x=x+s1;
					}
				e=e+2*dy;
			}
	}		
	void BSLD2(int x1,int y11,int x2,int y2)
	{	
		int interchange,e,s1,s2;
		x=x1,y=y11;
		dx=(x2-x1);
		dy=(y2-y11);
		s1=sign(dx);
		s2=sign(dy);
		
		if(dy>dx)
			{
				swap(dx,dy);
				interchange=1;
			}
		else
			{
				interchange=0;
			}
		e=2*dy-dx;
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		for(int i=1;i<=dx;i++)
			{
				glBegin(GL_POINTS);
				if(i%2==0 && i%15!=0)
				glVertex2i(x,y);
				glEnd();
				while(e>=0)
					{
						if(interchange==1)
							{
								x=x+s1;
							}
						else 
							{
							y=y+s2;
							}
						e=e-2*dx;
						}
				if(interchange==1)
					{
						y=y+s2;
					}
				else
					{
						x=x+s1;
					}
				e=e+2*dy;
			}
	}		
	void BSLD3(int x1,int y11,int x2,int y2)
	{	
		int interchange,e,s1,s2;
		x=x1,y=y11;
		dx=(x2-x1);
		dy=(y2-y11);
		s1=sign(dx);
		s2=sign(dy);
		
		if(dy>dx)
			{
				swap(dx,dy);
				interchange=1;
			}
		else
			{
				interchange=0;
			}
		e=2*dy-dx;
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		for(int i=1;i<=dx;i++)
			{
				glBegin(GL_POINTS);
				if(i%20<=10 || i%20==15)
				glVertex2i(x,y);
				glEnd();
				while(e>=0)
					{
						if(interchange==1)
							{
								x=x+s1;
							}
						else 
							{
							y=y+s2;
							}
						e=e-2*dx;
						}
				if(interchange==1)
					{
						y=y+s2;
					}
				else
					{
						x=x+s1;
					}
				e=e+2*dy;
			}
	}		
void Menu(int n)
	{
		switch(n)
			{
				case 1:BSLD(x1,y11,x2,y2);
				 break;
				case 2:BSLD1(x1,y11,x2,y2);
				break;
				case 3:BSLD2(x1,y11,x2,y2);
				break;
				case 4:BSLD3(x1,y11,x2,y2);
				break;
				default :exit(0);
			}
		}		
int main(int argc,char ** argcv)
	{
		cout<<"Enter x1,y1,x2,y2 :";
		cin>>x1>>y11>>x2>>y2;
		glutInit(&argc,argcv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(w,h);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Bresnham Line Drawing Algorithm");
		myInit();
		glutDisplayFunc(display);
		glutCreateMenu(Menu);
			glutAddMenuEntry("1] Simple Line ",1);
			glutAddMenuEntry("2] Dotted Line ",2);
			glutAddMenuEntry("3] Dash  Line ",3);
			glutAddMenuEntry("4] Center Dotted Line ",4);
			glutAddMenuEntry("5] Exit From Program ",5);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		
		glutMainLoop();
		
		return 0;
		
		}
		
