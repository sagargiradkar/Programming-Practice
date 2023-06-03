/*
Generate fractal patterns using KOCH curve...
*/
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
float oldx=-0.5,oldy=0.5;
void drawkoch(GLfloat dir,GLfloat len,GLint iter)
{
	double dirRad=0.0174533*dir;
	float newx=oldx+ len*cos(dirRad);
	float newy=oldy+ len*sin(dirRad);
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
void mydisplay(void)
{
	int n;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	cout<<"\nEnter the number of iteration\n";
	cin>>n;
	drawkoch(0.0,0.05,n);
	drawkoch(-120.0,0.05,n);
	drawkoch(120.0,0.05,n);
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("koch");
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;

}

