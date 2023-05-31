//Digital Differential Algorithm
#include<GL/glut.h>
#include<iostream>
#define w 500
#define h 500
using namespace std;

float x1,y11,x2,y2,len,dx,dy,x,y;
int choice;

void myInit (void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(3.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
//Sign Function
int Sign(float x) {
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
}
//Plotting the pixel
void setpixel(float x,float y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
//Simple Line
void Simple_Line(float x1,float y11,float x2,float y2) {
	glBegin(GL_POINTS);
	if(abs(x2-x1)>=abs(y2-y11)) {
		len=abs(x2-x1);
	} else {
		len=abs(y2-y11);
	}
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	glVertex2i(x,y);
	int i=1;
	while(i<=len) {
		x=x+dx;
		y=y+dy;
		i++;
		glVertex2i(x,y);
	}
}
//Dotted Line
void Dotted_Line(float x1,float y11,float x2,float y2) { 
	glBegin(GL_POINTS);
	if(abs(x2-x1)>=abs(y2-y11)) {
		len=abs(x2-x1);
	} else {
		len=abs(y2-y11);
	}
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	glVertex2i(x,y);
	int i=1;
	while(i<=len) {
		x=x+dx;
		y=y+dy;
		i++;
		if(i%10==0){
			glVertex2i(x,y);
		}
	}
}
//Dashed Line
void Dashed_Line(float x1,float y11,float x2,float y2) {
	glBegin(GL_POINTS);
	if(abs(x2-x1)>=abs(y2-y11)) {
		len=abs(x2-x1);
	} else {
		len=abs(y2-y11);
	}
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	glVertex2i(x,y);
	int i=1,j=0;
	while(i<=len) {
		x=x+dx;
		y=y+dy;
		i++;
		if(i%10==0){
			j++;
		}
		if(j%2==0){
			glVertex2i(x,y);
		}
	}
}
//Center Dotted Line
void Center_Dotted_Line(float x1,float y11,float x2,float y2) {
	glBegin(GL_POINTS);
	if(abs(x2-x1)>=abs(y2-y11)) {
		len=abs(x2-x1);
	} else {
		len=abs(y2-y11);
	}
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	glVertex2i(x,y);
	int i=1,j=1;
	while(i<=len) {
		x=x+dx;
		y=y+dy;
		i++;
		if(i%5==0){
			j++;
		}
		if(j%7==0){
			j=1;
		}
		if(j%4==0 || j%6==0){
		}
		else{
			glVertex2i(x,y); 
		}
	}
}
//Boat
void Draw_Boat(){
	Simple_Line(50,100,200,100);
	Simple_Line(75,25,175,25);
	Simple_Line(50,100,75,25);
	Simple_Line(200,100,175,25);
	Simple_Line(150,100,150,225);
	Simple_Line(150,225,175,100);
}
//Display Function
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=-w; i<=w; i++) {
		setpixel(0,i);
		setpixel(i,0);
	}
	glEnd();
	glFlush();
}
//Menu
void Menu(int n) {
	if(n==1) {
		Simple_Line( x1, y11, x2 ,y2);
	} else if(n==2) {
		Dotted_Line(x1,y11,x2, y2);
	} else if(n==3) {
		Dashed_Line(x1, y11,x2,y2);
	} else if(n==4) {
		Center_Dotted_Line( x1, y11, x2, y2);
	} else if(n==5) {
		Draw_Boat();
	} else {
		exit(0);
	}
}
//Main Function
int main(int argc, char ** argv) {
	cout<<"Demonstration of DDA Algorithm"<<endl;
	cout<<"Give the coordinates of line\n";
	while(true){
		cout<<"Enter Point x1 : ";
		cin>>x1;
		cout<<"Enter Point y1 : ";
		cin>>y11;
		cout<<"Enter Point x2 : ";
		cin>>x2;
		cout<<"Enter Point y2 : ";
		cin>>y2;
		if(x1==x2 && y11==y2){
			cout<<"Please enter two different points"<<endl;
		}
		else{
			break;
		}
 	}
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow(" Quadarant");
	myInit();
	glutDisplayFunc(display);
	glutCreateMenu(Menu);
	glutAddMenuEntry("Simple line",1);
	glutAddMenuEntry("Dotted line",2);
	glutAddMenuEntry("Dashed line",3);
	glutAddMenuEntry("Center Dotted line",4);
	glutAddMenuEntry("Boat",5);
	glutAddMenuEntry("Exit",6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
