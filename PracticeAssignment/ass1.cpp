#include<GL/glut.h>
#include<iostream>
using namespace std;
#define h 500
#define w 500 

int choice ;
float x1,x2,y11,y2;
float dx,dy,length,x,y;

void myInit(void)
	{	
		glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(0.0,0.0,0.0);
		glPointSize(5.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-w/2,w/2,-h/2,h/2);
		
	}
int sign(int x)
	{
		if(x>0) 
			{
				return +1;
			}
		else if(x<0) 
			{
			return -1;
			}
		else
			{
			 return 0;
			}
	}
void SetPixel(int x,int y)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
	}

void plot(float x, float y)
	{
		glVertex2i(x,y);
	}
void DDA_Line(float x1,float y11,float x2,float y2)
	{
		int i=1;
		if(abs(x2-x1)>=abs(y2-y11))
			{
				length=abs(x2-x1);
			}
		else
			{ 
			length=abs(y2-y11);
			}
		dx=(x2-x1)/length;
		dy=(y2-y11)/length;
		
		x=x1+0.5* sign(dx);
		y=y11+0.5* sign(dy);
		
		glBegin(GL_POINTS);
			plot(x,y);
			while(i<=length)
				{
					x=x+dx;
					y=y+dy;
					plot(x,y);
					
					i++;
				}
		}
			
void myDisplay(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINT);
		
		for(int i=-w;i<=w;i++)
			{
				SetPixel(i,0);
				SetPixel(0,i);
			}
		glEnd();
		//DDA_Line(x1,y11,x2,y2);
		glFlush();	
	}
void Menu(int n){
	if(n==1)
		{
			DDA_Line(x1,y11,x2,y2);
		}
	else 
		{
		exit(0);
		}
	}
int main(int argc ,char ** argv)
	{	
			cout<<"\n Enter The Start Point :: \n\n >> x = ";
			cin>>x1;
			cout<<" >> y = ";
			cin>>y11;
			
			cout<<"\n Enter The End Point :: \n\n >> x = ";
			cin>>x2;
			cout<<" >> y = ";
			cin>>y2;
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE  | GLUT_RGB);
		glutInitWindowSize(500,500);
		glutInitWindowPosition(100,100);
		glutCreateWindow("DDA LINE DRAWING ALGORITHM");
		
		myInit();
		glutDisplayFunc(myDisplay);
		
		glutCreateMenu(Menu);
			glutAddMenuEntry("Simple Line",1);
			
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		
		glutMainLoop();
		return 0;
		
	}
