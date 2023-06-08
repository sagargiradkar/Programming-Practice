
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define w 500
#define h 500
using namespace std;

int algo = 0;
float interiorColor[3]={1,1,1}, fillColor[3]={0,0,1}, readpixel[3];

void myInit (void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,1.0f);
	glPointSize(1.0);
    glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

void SetPixel(int p, int q)
{
  	glColor3fv(fillColor);
	glBegin(GL_POINTS);
	glVertex2f(p,q);
	glEnd();
	glFlush();
}

void GetPixel(int p, int q, float *color)
{
	glReadPixels(p, q, 1, 1, GL_RGB, GL_FLOAT, color);
}

// Flood Fill Algorithm
void FloodFill4(int x, int y)
{
	GetPixel(x, y, readpixel);

	if( readpixel[0] == interiorColor[0] && readpixel[1] == interiorColor[1] && readpixel[2] == interiorColor[2])
	{
		SetPixel(x, y);
		
		FloodFill4(x+1,y);
		FloodFill4(x-1,y);
		FloodFill4(x,y+1);
		FloodFill4(x,y-1);
	}
}

void Menu(int n)
{
	switch(n)
	{
	
		case 1:
			// FloodFill4
			algo = 1;
			break;	
			
		case 2:
			exit(0);
	}	
	
}	

// Mouse Interfacing Method
void Mouse(int btn, int state, int x, int y)
{
	if((btn == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (algo == 1))
	{
		FloodFill4(x,480-y);
	}	 
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(200,200);
	glVertex2i(200,400);
	glVertex2i(400,400);
	glVertex2i(400,200);	
	glEnd();
	glFlush();
}
		
int main(int argc, char **argv)
{
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(640, 480);
			glutInitWindowPosition(0, 0);
			glutCreateWindow(" Polygon Fill Algorithm ");
			myInit();
			glutDisplayFunc(myDisplay);
			glutMouseFunc(Mouse);
			glutCreateMenu(Menu); //Menu Creation
				glutAddMenuEntry(" 1. Flood Fill Algorithm ", 1);
				glutAddMenuEntry(" 2. Exit ", 2);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	
	return 0;	
}
