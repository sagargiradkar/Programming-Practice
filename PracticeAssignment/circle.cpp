#include<iostream>
#include<GL/glut.h>
using namespace std;
#define wi 1300
#define hi 1300

int h,k,r,d,x,y;
void myInit(void)
	{
		glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(0.0,0.0,0.0);
		glPointSize(3.0);
		glLineWidth(5.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-wi/2,wi/2,-h/2,h/2);
	}
void circle(int r)
	{
		glBegin(GL_POINTS);
		d=3-2*r;
		x=0;
		y=r;
		
		glVertex2i(x,y);
		while(x<=y)
			{
				if(d<=0)
					{
						d=d+4*x+6;
						x=x+1;
					}
				else
					{
						d=d+4*(x-y)+10;
						x=x+1;
						y=y-1;
					}
			
			glVertex2i(x+h,y+k);
			glVertex2i(-x+h,-y+k);
			glVertex2i(x+h,-y+k);
			glVertex2i(-x+h,y+k);
			glVertex2i(-y+h,x+k);
			glVertex2i(y+h,x+k);
			glVertex2i(-y+h,-x+k);
			glVertex2i(y+h,-x+k);
			
			}
			
			glEnd();
	}
void Simple_Circle(int h,int k,int r) {
	glBegin(GL_POINTS);
	d=3-2*r;
	x=0,y=r;
	glVertex2i(h,k); //Center
	while(x<=y) {
		if(d<=0) {
			d=d+4*x+6;
			x=x+1;
		} else {
			d=d+4*(x-y)+10;
			x=x+1;
			y=y-1;
		}
		glVertex2i(x+h,y+k);
		glVertex2i(-x+h,-y+k);
		glVertex2i(x+h,-y+k);
		glVertex2i(-x+h,y+k);
		glVertex2i(-y+h,x+k);
		glVertex2i(y+h,x+k);
		glVertex2i(-y+h,-x+k);
		glVertex2i(y+h,-x+k);
	}
}	
void display(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBegin(GL_LINES);
		glVertex2i(wi/2,0);
		glVertex2i(-wi/2,0);
		glEnd();
		glFlush();
		
		glBegin(GL_LINES);
		glVertex2i(0,hi/2);
		glVertex2i(0,-hi/2);
		glEnd();
		circle(r);
		glFlush();
	}
void Menu(int n)
	{
		switch(n){
			case 1: circle(r);
			Simple_Circle(h,k,r);
						break;
			default:exit(0);
			}
	}
			
									 	
int main(int argc , char ** argcv)
	{	
		cout<<"Demonstration of BCDA Algorithm"<<endl;
		cout<<"Give the coordinates of Simple Circle\n";
		cout<<"Demonstration of BCDA Algorithm"<<endl;
	cout<<"Give the coordinates of Simple Circle\n";
	cout<<"Enter Point h: ";
	cin>>h;
	cout<<"Enter Point k: ";
	cin>>k;
		cout<<"Enter radius r: ";
		cin>>r;
		glutInit(&argc,argcv);
		glutInitWindowSize(wi,hi);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Circle Drawing Algorithm");
		myInit();
		glutDisplayFunc(display);
		glutCreateMenu(Menu);
			glutAddMenuEntry("Circle",1);
			
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutMainLoop();
		
		return 0;
		
	}
		
		
		
