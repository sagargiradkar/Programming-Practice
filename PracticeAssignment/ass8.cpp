/*
Implement animation principles for any object
*/
#include<iostream>
#include<GL/glut.h>
#include<math.h>

int sun = 300;

void myInit(void)
{
	glClearColor(0.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0,1920.0,0.0,1080.0);
}

void Sun(void)
{
	// Sun
	glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
	double theta;
	int radius = 100;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1600 + radius*sin(theta), 950 + radius*cos(theta));
    }
    glEnd();
}



void Scenery(void)
{
	// Sun
	glPushMatrix();
	glTranslatef(sun,0,0);
	glTranslatef(0,sun,0);
	glColor3f(1.0f,0.0f,1.0f);
	//background
	Sun();
	glPopMatrix();
}

void Timer1(int)
{
	glutPostRedisplay();
    glutTimerFunc(1000/60, Timer1, 0);
    sun -= 1;		//Increase it speed up
    if(sun == 500)
    {
    	sun = 500;		
    }
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	Scenery();
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(100,150);
	glutCreateWindow(" SCENERY ");
	glutTimerFunc(0, Timer1, 0);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	
	return 0;
}
