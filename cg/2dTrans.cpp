//Mouse Interfacing

#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
#define h 700
#define w 700
 
int mati[100][100], k = 0, c;
int mato[100][100]; 
int x, y, x1, y11, x2, y2;
// hello
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void Plot(float x, float y)
{
	glVertex2i(x, y);
}

void multMatrix(float  arrT[3][3])
	{
		for(int i=0;i<k;i++)
			{
				mato[i][0]=(float)(arrT[0][0]*mati[i][0]+arrT[0][1]*mati[i][1]+arrT[0][2]*mati[i][2]);
				mato[i][1]=(float)(arrT[1][0]*mati[i][0]+arrT[1][1]*mati[i][1]+arrT[1][2]*mati[i][2]);
				mato[i][2]=(float)(arrT[2][0]*mati[i][0]+arrT[2][1]*mati[i][1]+arrT[2][2]*mati[i][2]);
			}
	}

void Translation()
	{
		float tx,ty;
		float arrT[3][3];
		cout<<"Enter the value of tx :";
		cin>>tx;
		cout<<"Enter the value of ty :";
		cin>>ty;
		arrT[0][0]=1;
		arrT[0][1]=0;
		arrT[0][2]=tx;
		arrT[1][0]=0;
		arrT[1][1]=1;
		arrT[1][2]=ty;
		arrT[2][0]=0;
		arrT[2][1]=0;
		arrT[2][2]=1;
		
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Scaling()
	{
		float sx,sy;
		float arrT[3][3];
		cout<<"Enter the value of sx :";
		cin>>sx;
		cout<<"Enter the value of sy :";
		cin>>sy;
		arrT[0][0]=sx;
		arrT[0][1]=0;
		arrT[0][2]=0;
		arrT[1][0]=0;
		arrT[1][1]=sy;
		arrT[1][2]=0;
		arrT[2][0]=0;
		arrT[2][1]=0;
		arrT[2][2]=1;
		
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}

void Rotation()
	{
		float angle=0;
		float arrT[3][3];
		cout<<"Enter the value angle :";
		cin>>angle;
		angle=(angle*(3.142/180));
		arrT[0][0]=cos(angle);
		arrT[0][1]=-(sin(angle));
		arrT[0][2]=0;
		arrT[1][0]=sin(angle);
		arrT[1][1]=cos(angle);
		arrT[1][2]=0;
		arrT[2][0]=0;
		arrT[2][1]=0;
		arrT[2][2]=1;
		
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Reflection()
	{
	float arrT[3][3];
		arrT[0][0]=1;
		arrT[0][1]=0;
		arrT[0][2]=0;
		arrT[1][0]=0;
		arrT[1][1]=-1;
		arrT[1][2]=0;
		arrT[2][0]=0;
		arrT[2][1]=0;
		arrT[2][2]=1;
		
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void MouseClick(int button, int state, int x, int y)
{
	int p, q;
	
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			mati[k][0] = (float)(x-350);
			mati[k][1] = (float)(350-y);
			mati[k][2] = (float)(1);
			glColor3f(1.0, 0.0, 0.0);
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
void keyboardClick(unsigned char key,int x,int y)
	{
		if(key=='t')
			{
			Translation();
			}
		else if(key=='s')
			{
			Scaling();
			}
		else if(key=='r')
			{
			Rotation();
			}
		else if(key=='e')
			{
			 Reflection();
			}
	}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	
	for(int i=-w; i<=w; i++)
	{
		Plot(i, 0);
		Plot(0, i);
	}	
		
	glEnd();
	glFlush();
}
		
int main(int argc, char **argv)
{			
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(700,700);
			glutCreateWindow("Translation");
			myInit();
			glutDisplayFunc(myDisplay);
			glutMouseFunc(MouseClick);
			glutKeyboardFunc(keyboardClick);
			glutMainLoop();
	return 0;	
}


	
