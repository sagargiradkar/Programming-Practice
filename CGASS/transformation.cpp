#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define w 500
#define h 500
using namespace std;
int x1,y11,k=0,flag=0;
float mati[50][50];
float mato[50][50];

void myInit (void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,1.0f);
	glPointSize(3.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
//Plotting the pixel
void setpixel(float x,float y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
//Multiply Matrices
void MultiplyMatrix(float arr[3][3]) {
	for(int i=0; i<k; i++) {
		mato[i][0]=(float)(arr[0][0]*mati[i][0]+arr[0][1]*mati[i][1]+arr[0][2]*mati[i][2]);
		mato[i][1]=(float)(arr[1][0]*mati[i][0]+arr[1][1]*mati[i][1]+arr[1][2]*mati[i][2]);
		mato[i][2]=(float)(arr[2][0]*mati[i][0]+arr[2][1]*mati[i][1]+arr[2][2]*mati[i][2]);
	}
}
//Mouse Function
void mouse_click(int button,int state,int x,int y) {
	if(state==GLUT_DOWN) {
		if(button==GLUT_LEFT_BUTTON) {
			if(flag==1) {
				k=0;
				flag=0;
			}
			mati[k][0]=(float)(x-250);
			mati[k][1]=(float)(250-y);
			mati[k][2]=(float)1;
			glBegin(GL_POINTS);
			glVertex2f(mati[k][0],mati[k][1]);
			glEnd();
			k++;
			glFlush();
		} else if(button==GLUT_RIGHT_BUTTON) {
			flag=1;
			glBegin(GL_LINE_LOOP);
			for(int i=0; i<k; i++) {
				glVertex2f(mati[i][0],mati[i][1]);
			}
			glEnd();
			glFlush();
		}
	}
}
//Drawing Output of Transformation
void drawOutput() {
	if(k==1) {
		glBegin(GL_POINTS);
		glVertex2f(mato[0][0],mato[0][1]);
	} else {
		glBegin(GL_LINE_LOOP);
		for(int i=0; i<k; i++) {
			glVertex2f(mato[i][0],mato[i][1]);
		}
	}
	glColor3f(1.0f,0.0f,1.0f);
	glEnd();
	glFlush();
}
//Translation
void Translation(float tx,float ty) {
	float arrT[3][3];
	arrT[0][0]=1;
	arrT[0][1]=0;
	arrT[0][2]=tx;
	arrT[1][0]=0;
	arrT[1][1]=1;
	arrT[1][2]=ty;
	arrT[2][0]=0;
	arrT[2][1]=0;
	arrT[2][2]=1;
	MultiplyMatrix(arrT);
	glColor3f(0.0f,0.0f,1.0f);
	drawOutput();
}
//Rotation
void Rotation(float theta) {
	theta = theta*((3.14)/180);
	float arrR[3][3];
	arrR[0][0]=cos(theta);
	arrR[0][1]=-sin(theta);
	arrR[0][2]=0;
	arrR[1][0]=sin(theta);
	arrR[1][1]=cos(theta);
	arrR[1][2]=0;
	arrR[2][0]=0;
	arrR[2][1]=0;
	arrR[2][2]=1;
	MultiplyMatrix(arrR);
	glColor3f(1.0f,0.0f,0.0f);
	drawOutput();
}
//Scaling
void Scaling(float Sx,float Sy) {
	float arrS[3][3];
	arrS[0][0]=Sx;
	arrS[0][1]=0;
	arrS[0][2]=0;
	arrS[1][0]=0;
	arrS[1][1]=Sy;
	arrS[1][2]=0;
	arrS[2][0]=0;
	arrS[2][1]=0;
	arrS[2][2]=1;
	MultiplyMatrix(arrS);
	glColor3f(0.0f,1.0f,0.0f);
	drawOutput();
}
//Shearing
void Shearing(float Shx,float Shy) {
	float arrSh[3][3];
	arrSh[0][0]=1;
	arrSh[0][1]=Shx;
	arrSh[0][2]=0;
	arrSh[1][0]=Shy;
	arrSh[1][1]=1;
	arrSh[1][2]=0;
	arrSh[2][0]=0;
	arrSh[2][1]=0;
	arrSh[2][2]=1;
	MultiplyMatrix(arrSh);
	glColor3f(1.0f,1.0f,0.0f);
	drawOutput();
}
//Reflection
void Reflection(float a,float b,float c,float d) {
	float arrRe[3][3];
	arrRe[0][0]=a;
	arrRe[0][1]=b;
	arrRe[0][2]=0;
	arrRe[1][0]=c;
	arrRe[1][1]=d;
	arrRe[1][2]=0;
	arrRe[2][0]=0;
	arrRe[2][1]=0;
	arrRe[2][2]=1;
	MultiplyMatrix(arrRe);
	glColor3f(0.0f,1.0f,1.0f);
	drawOutput();
}
//Arbitrary Point Reset
void ArbReset(){
	for(int i=0; i<k; i++) {
		mati[i][0]=mato[i][0];
		mati[i][1]=mato[i][1];
	}
}
//Rotation about Arbitrary Point
void ArbRotation(){
	float a,b,theta;
	cout<<"Enter Co-ordinates of Arbitrary Point\nx: ";
	cin>>a;
	cout<<"y: ";
	cin>>b;
	int i;
	while(true){
		cout<<"Select rotation type:\n(1) Clockwise\n(2) AntiClockwise ---> ";
		cin>>i;
		if(i==1 || i==2){
			break;
		} else{
			cout<<"Enter a valid choice"<<endl;
		}
	}
	cout<<"Give value of Theta (In Degree)"<<endl;
	cout<<"Enter Theta: ";
	cin>>theta;
	if(i==1){
		theta=-theta;
	}
	Translation(-a,-b);
	ArbReset();
	Rotation(theta);
	ArbReset();
	Translation(a,b);
}
//Scaling about Arbitrary Point
void ArbScaling(){
	float a,b,Sx,Sy;
	cout<<"Enter Co-ordinates of Arbitrary Point\nx: ";
	cin>>a;
	cout<<"y: ";
	cin>>b;
	int i;
	while(true){
		cout<<"Select scaling type:\n(1) Uniform\n(2) Differential ---> ";
		cin>>i;
		if(i==1 || i==2){
			break;
		} else{
			cout<<"Enter a valid choice"<<endl;
		}
	}
	if(i==1){
		cout<<"Give value for Scale Factor"<<endl;
		cout<<"Enter S: ";
		cin>>Sx;
		Sy=Sx;
	}
	else if(i==2){
		cout<<"Give values for Scale Factors"<<endl;
		cout<<"Enter Sx: ";
		cin>>Sx;
		cout<<"Enter Sy: ";
		cin>>Sy;
	}	
	Translation(-a,-b);
	ArbReset();
	Scaling(Sx,Sy);
	ArbReset();
	Translation(a,b);
}
//Menu
void Menu(int n) {
	if(n==1) {
		float tx,ty;
		cout<<"Give values for shift vector"<<endl;
		cout<<"Enter tx: ";
		cin>>tx;
		cout<<"Enter ty: ";
		cin>>ty;
		Translation(tx,ty);
	} 
	
	else if(n==2) {
		float theta;
		cout<<"Give value of Theta (In Degree)"<<endl;
		cout<<"Enter Theta: ";
		cin>>theta;
		Rotation(-theta);
	} else if(n==3) {
		float theta;
		cout<<"Give value of Theta (In Degree)"<<endl;
		cout<<"Enter Theta: ";
		cin>>theta;
		Rotation(theta);
	} 
	
	else if(n==4) {
		float S;
		cout<<"Give value for Scale Factor"<<endl;
		cout<<"Enter S: ";
		cin>>S;
		Scaling(S,S);
	} else if(n==5) {
		float Sx,Sy;
		cout<<"Give values for Scale Factors"<<endl;
		cout<<"Enter Sx: ";
		cin>>Sx;
		cout<<"Enter Sy: ";
		cin>>Sy;
		Scaling(Sx,Sy);
	} 
	
	else if(n==6) {
		float Shx;
		cout<<"Give value for X-Shear Factor"<<endl;
		cout<<"Enter Shx: ";
		cin>>Shx;
		Shearing(Shx,0);
	} else if(n==7) {
		float Shy;
		cout<<"Give value for Y-Shear Factor"<<endl;
		cout<<"Enter Shy: ";
		cin>>Shy;
		Shearing(0,Shy);
	} 
	
	else if(n==8) {
		Reflection(-1,0,0,1);
	} else if(n==9) {
		Reflection(1,0,0,-1);
	} else if(n==10) {
		Reflection(-1,0,0,-1);
	} else if(n==11) {
		Reflection(0,1,1,0);
	} else if(n==12) {
		Reflection(0,-1,-1,0);
	}    
	
	else if(n==13) {
		ArbRotation();
	} else if(n==14){
		ArbScaling();
	}
	
	else {
		exit(0);
	}
}
//Display Function
void display(void) {
	for(int i=-w; i<=w; i++) {
		setpixel(0,i);
		setpixel(i,0);
	}
	glEnd();
	glFlush();
}
//Main Function
int main(int argc, char ** argv) {
	
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Screen");
	myInit();
	glClear(GL_COLOR_BUFFER_BIT);
	glutMouseFunc(mouse_click);

	int menu1 = glutCreateMenu(Menu);
	glutAddMenuEntry("Clockwise Rotation",2);
	glutAddMenuEntry("Anti Clockwise Rotation",3);

	int menu2 = glutCreateMenu(Menu);
	glutAddMenuEntry("Uniform Scaling",4);
	glutAddMenuEntry("Differential Scaling",5);
	
	int menu3 = glutCreateMenu(Menu);
	glutAddMenuEntry("X - Shearing",6);
	glutAddMenuEntry("Y - Shearing",7);
	
	int menu4 = glutCreateMenu(Menu);
	glutAddMenuEntry("About Y axis",8);
	glutAddMenuEntry("About X axis",9);
	glutAddMenuEntry("About Origin",10);
	glutAddMenuEntry("About line y=x",11);
	glutAddMenuEntry("About line y=-x",12);
	
		
	glutCreateMenu(Menu);
	glutAddMenuEntry("Translation",1);
	glutAddSubMenu("Rotation",menu1);
	glutAddSubMenu("Scaling",menu2);
	glutAddSubMenu("Shearing",menu3);
	glutAddSubMenu("Reflection",menu4);
	glutAddMenuEntry("Rotation about Arbitrary Point",13);
	glutAddMenuEntry("Scaling about Arbitrary Point",14);
	glutAddMenuEntry("Exit",0);

	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
