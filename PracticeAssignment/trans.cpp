#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

#define w 700
#define h 700

int mati[100][100],mato[100][100],k=0;
void myInit(void)
	{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
	}
void multMatrix(float arrT[3][3])
	{
		for(int i=0;i<k;i++)
			{
			mato[i][0]=(float)(arrT[0][0]*mati[i][0]+arrT[0][1]*mati[i][1]+arrT[0][2]*mati[i][2]);
			mato[i][1]=(float)(arrT[1][0]*mati[i][0]+arrT[1][1]*mati[i][1]+arrT[1][2]*mati[i][2]);
			mato[i][2]=(float)(arrT[2][0]*mati[i][0]+arrT[2][1]*mati[i][1]+arrT[2][2]*mati[i][2]);
			}
	}
void Translate()
	{
	float tx,ty;
	cout<<"ENTER TX TY ";
	cin>>tx>>ty;
	float arrT[3][3]={1,0,tx,0,1,ty,0,0,1};
	multMatrix(arrT);	
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<k;i++)
		{
		glVertex2f(mato[i][0],mato[i][1]);
		}
	glEnd();
	glFlush();
	}
			
	
	
void MouseClick(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			mati[k][0] = (float)(x-350);
			mati[k][1] = (float)(350-y);
			mati[k][2] = (float)(1);
			glBegin(GL_POINTS);
			glVertex2f(mati[k][0], mati[k][1]);
			glEnd();
			k++;
			glFlush();
		}
		
		if(button == GLUT_RIGHT_BUTTON)
		{
			glBegin(GL_LINE_LOOP);
			for(int i = 0; i<k; i++)
			{
				glVertex2f(mati[i][0], mati[i][1]);
			}
			glEnd();
			glFlush();
		}
	}		
}
void display(void)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINES);
	glVertex2f(w/2,0);
	glVertex2f(-w/2,0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(0,h/2);
	glVertex2f(0,-h/2);
	glEnd();
	glFlush();
	
	}
void Menu(int n)
	{
	switch(n)
		{
			case 1:Translate();
					break;
			default:exit(0);
		}
	}
int   main(int argc,char ** argv)
	{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("2D Transformation");
	myInit();
	glutDisplayFunc(display);
	glutMouseFunc(MouseClick);
	glutCreateMenu(Menu);
		glutAddMenuEntry("1] Translation",1);
		glutAddMenuEntry("2] Exit ",2);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
	}	
	
	
