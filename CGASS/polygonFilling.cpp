#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
int x1,y11,x2,y2,dx,dy,x,y,s1,s2,temp,interchange,e;
int pixel1,pixel2;
float Fcolor[3],Icolor[3]={1,1,1},pixel[3],Bcolor[3]={1,0,0};

void myInit (void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}

int Sign(int x) {
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
}

void Simple_Line(int x1,int y11,int x2,int y2) {
	glBegin(GL_POINTS);
	x=x1,y=y11;
	dx=abs(x2-x1);
	dy=abs(y2-y11);
	s1=Sign(x2-x1);
	s2=Sign(y2-y11);
	if(dy>dx) {
		temp=dx;
		dx=dy;
		dy=temp;
		interchange=1;
	} else {
		interchange=0;
	}
	e=2*dy-dx;
	for(int i=0; i<=dx; i++) {
		glVertex2i(x,y);
		while(e>=0) {
			if(interchange==1) {
				x=x+s1;
			} else {
				y=y+s2;
			}
			e=e-2*dx;
		}
		if(interchange==1) {
			y=y+s2;
		} else {
			x=x+s1;
		}
		e=e+2*dy;
	}
	glEnd();
	glFlush();
}

void setPixel(int x,int y){
	glColor3fv(Fcolor);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void getPixel(int x,int y,float* color){
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

void FloodFill(int x, int y){
	getPixel(x,y,pixel);
	cout<<x<<endl<<y<<endl;
	if(Icolor[0]==pixel[0] && Icolor[1]==pixel[1] && Icolor[2]==pixel[2]){
		setPixel(x,y);
		FloodFill(x+1,y);
		FloodFill(x-1,y);
		FloodFill(x,y+1);
		FloodFill(x,y-1);
		glFlush();
	}
}

void BoundaryFill(int x,int y){
	getPixel(x,y,pixel);
	if(!(Bcolor[0]==pixel[0] && Bcolor[1]==pixel[1] && Bcolor[2]==pixel[2]) && !(Fcolor[0]==pixel[0] && Fcolor[1]==pixel[1] && Fcolor[2]==pixel[2])){
		setPixel(x,y);
		BoundaryFill(x+1,y);
		BoundaryFill(x-1,y);	
		BoundaryFill(x,y+1);	
		BoundaryFill(x,y-1);
		glFlush();		
	}
}

void mouse_click(int button,int state,int x,int y) {
	if(state==GLUT_DOWN) {
		if(button==GLUT_LEFT_BUTTON) {
//			Fcolor[0]=0.6471;
//			Fcolor[1]=0.1647;
//			Fcolor[2]=0.1647;
			Fcolor[0]=1;
			Fcolor[1]=1;
			Fcolor[2]=0;
			pixel1=x;
			pixel2=500-y;
//			FloodFill(x,500-y);
		}
//		else if(button==GLUT_RIGHT_BUTTON) {
//			Fcolor[0]=1;
//			Fcolor[1]=1;
//			Fcolor[2]=0;
//			BoundaryFill(x,500-y);
//		}
	}
}

void display(void) {
	glColor3f(1,0,0);
	Simple_Line(200,300,300,300);
	Simple_Line(300,300,300,400);
	Simple_Line(300,400,200,400);
	Simple_Line(200,400,200,300);
	
	glColor3f(1,0,0);
	Simple_Line(200,50,300,50);
	Simple_Line(300,150,200,150);
	glColor3f(0,1,0);
	Simple_Line(300,50,300,150);
	Simple_Line(200,150,200,50);
	
//	//Chess
//	glColor3f(0,0,0);
//	Simple_Line(130,130,370,130);
//	Simple_Line(130,160,370,160);
//	Simple_Line(130,190,370,190);
//	Simple_Line(130,220,370,220);
//	Simple_Line(130,250,370,250);
//	Simple_Line(130,280,370,280);
//	Simple_Line(130,310,370,310);
//	Simple_Line(130,340,370,340);
//	Simple_Line(130,370,370,370);
//	
//	Simple_Line(130,130,130,370);
//	Simple_Line(160,130,160,370);
//	Simple_Line(190,130,190,370);
//	Simple_Line(220,130,220,370);
//	Simple_Line(250,130,250,370);
//	Simple_Line(280,130,280,370);
//	Simple_Line(310,130,310,370);
//	Simple_Line(340,130,340,370);
//	Simple_Line(370,130,370,370);
}
void Menu (int n){
	if(n==1){
		BoundaryFill(pixel1,pixel2);
	}
	else if(n==2){
		FloodFill(pixel1,pixel2);
	}
	else{
		exit(0);
	}
}
int main(int argc, char ** argv) {
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(700, 150);
	glutCreateWindow("Screen");
	myInit();
	glutDisplayFunc(display);
	glClear(GL_COLOR_BUFFER_BIT);
	glutMouseFunc(mouse_click);
	glutCreateMenu(Menu);
	glutAddMenuEntry("Boundary Fill Algorithm",1);
	glutAddMenuEntry("Flood Fill Algorithm",2);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
