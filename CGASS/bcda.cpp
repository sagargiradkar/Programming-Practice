//Bresenham's Circle Drawing Algorithm
#include<GL/glut.h>
#include<iostream>
#define width 500
#define height 500

using namespace std;
int r,h,k,x,y,d,choice,arr[50],n,turns;

void myInit (void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(3.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width/2,width/2,-height/2,height/2);
}
//Sign Function
int Sign(int x) {
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
}
//Plotting the pixel
void setpixel(int x,int y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
//Simple Circle
void Simple_Circle(int h,int k,int r) {
	glBegin(GL_POINTS);
	d=3-2*r;
	x=0,y=r;
//	glVertex2i(h,k); //Center
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
//Concentric Circles
void Concentric_Circles() {
	for(int i=0; i<n; i++) {
		glBegin(GL_POINTS);
		glVertex2i(h,k);
		Simple_Circle(h,k,arr[i]);
	}
}
//Olympic Ring
void Olympic_Ring() {
	glColor3f(0.0f, 0.5f, 1.0f);
	Simple_Circle(50,150,35);
	glColor3f(0.0f, 0.0f, 0.0f);
	Simple_Circle(125,150,35);
	glColor3f(1.0f, 0.0f, 0.0f);
	Simple_Circle(200,150,35);
	glColor3f(1.0f, 1.0f, 0.0f);
	Simple_Circle(87,115,35);
	glColor3f(0.0f, 1.0f, 0.0f);
	Simple_Circle(162,115,35);
	glColor3f(1.0f, 0.0f, 0.0f);
}
//Spiral
void Spiral() {
	glBegin(GL_POINTS);
	int radius=10;
	glVertex2i(x+h,y+h);
	for(int i=0; i<turns; i++) {
		h=h+10;
		d=3-2*radius;
		x=0,y=radius;
		while(x<=y) {
			if(d<=0) {
				d=d+4*x+6;
				x=x+1;
			} else {
				d=d+4*(x-y)+10;
				x=x+1;
				y=y-1;
			}
			glVertex2i(y+h,x+k);
			glVertex2i(x+h,y+k);
			glVertex2i(-x+h,y+k);
			glVertex2i(-y+h,x+k);
		}
		radius=radius+10;
		h=h-10;
		d=3-2*radius;
		x=0,y=radius;
		while(x<=y) {
			if(d<=0) {
				d=d+4*x+6;
				x=x+1;
			} else {
				d=d+4*(x-y)+10;
				x=x+1;
				y=y-1;
			}
			glVertex2i(x+h,-y+k);
			glVertex2i(-y+h,-x+k);
			glVertex2i(y+h,-x+k);
			glVertex2i(-x+h,-y+k);
		}
		radius=radius+10;
	}
}
//Display Function
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=-width; i<=width; i++) {
		setpixel(0,i);
		setpixel(i,0);
	}
	glEnd();
	glFlush();
}
//Menu
void Menu(int n) {
	if(n==1) {
		Simple_Circle(h,k,r);
	} else if(n==2) {
		Concentric_Circles();
	} else if(n==3) {
		Olympic_Ring();
	} else if(n==4) {
		Spiral();
	} else {
		exit(0);
	}
}
//Main Function
int main(int argc, char ** argv) {
	cout<<"Demonstration of BCDA Algorithm"<<endl;
	cout<<"Give the coordinates of Simple Circle\n";
	cout<<"Enter Point h: ";
	cin>>h;
	cout<<"Enter Point k: ";
	cin>>k;
	while(true){
		cout<<"Enter radius r: ";
		cin>>r;
		if(r>0){
			break;
		}
		else{
			cout<<"Enter a valid positive radius"<<endl;
		}
	}
	cout<<"Enter number of concentric circles: ";
	cin>>n;
	for(int i=0; i<n; i++) {
		cout<<"Radius of circle "<<i+1<<" :";
		cin>>arr[i];
	}
	cout<<"Enter turns of spiral: ";
	cin>>turns;
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow(" Quadarant");
	myInit();
	glutDisplayFunc(display);
	glutCreateMenu(Menu);
	glutAddMenuEntry("Simple Circle",1);
	glutAddMenuEntry("Concentric Circles",2);
	glutAddMenuEntry("Olympic Ring",3);
	glutAddMenuEntry("Spiral",4);
	glutAddMenuEntry("Exit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
