// DDA Line Drawing Algorithm
#include<iostream>
#include<GL/glut.h>

using namespace std;
#define h 500
#define w 500

int choice;
float x1, x2, y11, y2;
float dx, dy, length, x, y;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void SetPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}	

void Plot(float x, float y)
{
	glVertex2i(x, y);
}

int Sign(int x)
{
 	if(x>0)
 	{
 		return 1;
 	}
 	else if(x==0)
 	{
 		return 0;
 	}
 	else
 	{
 		return -1;
 	}

}	

void DDA_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5*Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		Plot(x,y);
		
		i++;
	}
}

void DDA_Dotted_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5 *Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		if(i%20 == 0)
		{	
			Plot(x,y);
		}
		
		i++;
	}
}

void DDA_Dashed_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5 *Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
		
		if(i%2==0 && i%15!=0)
		{
			Plot(x,y);
		}
		
		i++;
	}
}

void DDA_Center_Dot_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5*Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		
		if(i%20<=10 || i%20==15)
		{
			Plot(x,y);
		}	
		
		i++;
	}
}

void DDABoat(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5*Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		Plot(x,y);
		
		i++;
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
	for(int i=-w; i<=w; i++)
	{
		SetPixel(i, 0);
		SetPixel(0, i);
	}		
	glEnd();
	glFlush();
}

void Menu(int n){
	if(n==1)
		{
			DDA_Line(x1,y11,x2,y2);
		}
	else if(n==2)
		{
			DDA_Dotted_Line(x1,y11,x2,y2);			
		}
	else if(n==3)
		{
			DDA_Dashed_Line(x1,y11,x2,y2);	
		}
	else if(n==4)
		{
			DDA_Center_Dot_Line(x1,y11,x2,y2);
		}
	else if(n==5)
		{
			DDABoat(25.0f,100.0f,75.0f,50.0f);
			glColor3f(1.0,0.0,1.0);
			DDABoat(75.0f,50.0f,125.0f,50.0f);
			glColor3f(1.0,0.0,1.0);
			DDABoat(125.0f,50.0f,150.0f,100.0f);
			glColor3f(1.0,0.0,1.0);
			DDABoat(150.0f,100.0f,25.0f,100.0f);
			glColor3f(1.0,0.0,1.0);
			DDABoat(125.0f,100.0f,125.0f,150.0f);
			glColor3f(1.0,0.0,1.0);
			DDABoat(125.0f,150.0f,100.0f,100.0f);
			glColor3f(1.0,0.0,1.0);
			DDABoat(100.0f,100.0f,25.0f,100.0f);

		}
	else 
		{
			exit(0);
		}
	}
	
int main(int argc, char **argv)
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
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(1080,720);
			glutInitWindowPosition(50,100);
			glutCreateWindow("DDA Line With Axis");
			
			myInit();
			glutDisplayFunc(myDisplay);
			
			glutCreateMenu(Menu);
				glutAddMenuEntry("Simple Line",1);
				glutAddMenuEntry("Dotted line",2);
				glutAddMenuEntry("Dash Line",3);
				glutAddMenuEntry("Center Dotted Line",4);
				glutAddMenuEntry("Draw Boat",5);
				glutAddMenuEntry("EXIT From Program",6);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	
	
	return 0;	
}


