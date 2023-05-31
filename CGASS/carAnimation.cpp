
#include <iostream>
#include <GL/glut.h>
#include <math.h>
int frameNumber = 0;
float car1=-350.0f;
int red,green,blue;
float Fanrotate=0.0f;
GLfloat angle = 0.0f;  //defines the angle the wheel bar should rotate to
GLfloat carAndWheelX = -350.0; //defines the x coordinates CAR BODY, CAR TOP, WHEEL 1, WHEEL 2, WHEEL 1 BAR and WHEEL 2 BAR should be translated to
void myInit(void){
	glClearColor(0.33, 0.58, 0.796, 0);
	glColor3f(1.0f,0.0f,0.0f);;
	glPointSize(10.0);
	glLineWidth(4.0);
 	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-600, 600, -400, 400);
}

// Cirlce function taking parameter coordinate of  circle
void myCircle(int xc, int yc, int r);
// grass function to provide texture to ground
void grass(int v, int w);
void grass1(int v, int w);
// flower function
void flower(int x, int y, int r, int color1, int color2);

void tyre()
{
glColor3f(0.0f,0.0f,0.0f);
glPointSize(10.0);
glLineWidth(4.0);

myCircle(-410,-150,34);//big wheel
glColor3f(0.5f,0.5f,0.5f);
myCircle(-410,-150,23);// mid 
glColor3f(0.0f,0.0f,0.0f);
myCircle(-410,-150,8);// circle




glColor3f(0.0f,0.0f,0.0f);
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-410,-126);
glEnd();
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-432.82,-142.58);
glEnd();
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-387.1746,-142.58);
glEnd();
glLineWidth(7.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-424.106,-169.416);
glEnd();
glLineWidth(7.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-395.893,-169.416);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
myCircle(-410,-150,4);


glColor3f(0.0f,0.0f,0.0f);//small wheel
myCircle(-285,-162,22.5);
glColor3f(0.5f,0.5f,0.5f);
myCircle(-285,-162,12);

glColor3f(0.0f,0.0f,0.0f);
myCircle(-285,-162,5);



glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-272.636,-157.982);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-285,-149);
glEnd();

glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-297.363,-157.982);
glEnd();

glLineWidth(4.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-292.641,-172.517);
glEnd();

glLineWidth(4.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-277.358,-172.517);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
myCircle(-285,-162,3);
}


void drawCar(){
//	glColor3f(1.0f,0.0f,1.0f);
//	//background
//	glBegin(GL_POLYGON);
//	glVertex2f(-500,-200);
//	glVertex2f(-250,-200);
//	glVertex2f(-250,-50);
//	glVertex2f(-500,-50);
//	glEnd();

	//Helicopter
	glColor3f((float)46/255, (float)43/255, (float)42/255);
	glBegin(GL_POLYGON);
    glVertex2f(-135, 170);
    glVertex2f(-70, 190);
    glVertex2f(-10,190);
    glVertex2f(20, 170);
    glVertex2f(20,160);
    glVertex2f(-10, 140);    
    glVertex2f(-70, 140);
    glVertex2f(-135, 160);
    glVertex2f(-145, 150);
    glVertex2f(-140, 165);
    glVertex2f(-145, 190);
    glVertex2f(-135, 170);
    glEnd();
    glBegin(GL_POLYGON);
    	glVertex2f(-40, 190);
	    glVertex2f(-40, 200);
	    glVertex2f(-35, 200);
	    glVertex2f(-35, 190);
	glEnd();
	//Heli Window
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-70, 180);
    glVertex2f(-70, 165);
    glVertex2f(-50, 165);
    glVertex2f(-50, 180);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-40, 180);
    glVertex2f(-13, 180);
    glVertex2f(10, 165);
    glVertex2f(-40,165);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-20,140);
    glVertex2f(-20,120);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(-60,140);
    glVertex2f(-60,120);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(-10,120);
    glVertex2f(-70,120);
	glEnd();
	//heli fan
	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
    	glVertex2f(-40, 200);
	    glVertex2f(-35, 200);
	    glVertex2f(-55, 100);
	    glVertex2f(-55, 115);
	glEnd();
	glBegin(GL_POLYGON);
    	glVertex2f(-40, 200);
	    glVertex2f(-35, 200);
	    glVertex2f(-100, 270);
	    glVertex2f(-100, 260);
	glEnd();
	glBegin(GL_POLYGON);
    	glVertex2f(-40, 200);
	    glVertex2f(-35, 200);
	    glVertex2f(30, 240);
	    glVertex2f(30, 250);
	glEnd();
    //heli end
	glLineWidth(2.0);
	
	//seat 
	glColor3f(0.0f,0.0f,0.0f);
	myCircle(-395,-93,17);
	
	//below rod
	glColor3f(0.5f,0.5f,0.5f);
	glBegin(GL_POLYGON); //grey
	glVertex2f(-450,-160);
	glVertex2f(-470,-100);
	glVertex2f(-465,-100);
	glVertex2f(-450,-135);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);//black
	glBegin(GL_LINE_LOOP);
	glVertex2f(-450,-160);
	glVertex2f(-470,-100);
	glVertex2f(-465,-100);
	glVertex2f(-450,-135);
	glEnd();
	
	//upper rod of blade
	glColor3f(0.5f,0.5f,0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(-450,-100);
	glVertex2f(-465,-95);
	glVertex2f(-465,-90);
	glVertex2f(-442,-95);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-450,-100);
	glVertex2f(-465,-95);
	glVertex2f(-465,-90);
	glVertex2f(-442,-95);
	glEnd();
	
	//blade
	glColor3f(1.9f,0.0f,0.3f);
	glBegin(GL_POLYGON);
	glVertex2f(-465,-100);
	glVertex2f(-465,-60);
	glVertex2f(-500,-50);
	glVertex2f(-500,-70);
	glVertex2f(-470,-100);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-465,-100);
	glVertex2f(-465,-60);
	glVertex2f(-500,-50);
	glVertex2f(-500,-70);
	glVertex2f(-470,-100);
	glEnd();
	
	//bladeUp
	glColor3f(0.5f,0.5f,0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(-465,-70);
	glVertex2f(-465,-60);
	glVertex2f(-500,-50);
	glVertex2f(-500,-60);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-465,-70);
	glVertex2f(-465,-60);
	glVertex2f(-500,-50);
	glVertex2f(-500,-60);
	glEnd();
	
	//upper body
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-450,-135);
	glVertex2f(-450,-100);
	glVertex2f(-415,-70);
	glVertex2f(-390,-70);
	glVertex2f(-390,-95);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-450,-135);
	glVertex2f(-450,-100);
	glVertex2f(-415,-70);
	glVertex2f(-390,-70);
	glVertex2f(-390,-95);
	glEnd();
	
	//below body
	glColor3f(1.9f,0.0f,0.3f);
	glBegin(GL_POLYGON);
	glVertex2f(-450,-135);
	glVertex2f(-415,-95);
	glVertex2f(-390,-95);
	glVertex2f(-375,-100);
	glVertex2f(-350,-100);
	glVertex2f(-345,-95);
	glVertex2f(-250,-145);
	glVertex2f(-250,-150);
	glVertex2f(-253,-150);
	glVertex2f(-253,-160);
	glVertex2f(-450,-160);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-450,-135);
	glVertex2f(-415,-95);
	glVertex2f(-390,-95);
	glVertex2f(-375,-100);
	glVertex2f(-350,-100);
	glVertex2f(-345,-95);
	glVertex2f(-250,-145);
	glVertex2f(-250,-150);
	glVertex2f(-253,-150);
	glVertex2f(-253,-160);
	glVertex2f(-450,-160);
	glEnd();
	
	//door
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-410,-160);
	glVertex2f(-410,-130);
	glVertex2f(-340,-120);
	glVertex2f(-340,-160);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-410,-160);
	glVertex2f(-410,-130);
	glVertex2f(-340,-120);
	glVertex2f(-340,-160);
	glEnd();
	
	//mirror
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-340,-95);
	glVertex2f(-325,-95);
	glVertex2f(-325,-105);
	glVertex2f(-340,-105);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-340,-95);
	glVertex2f(-325,-95);
	glVertex2f(-325,-105);
	glVertex2f(-340,-105);
	glEnd();
	
	//mud guard
	glColor3f(0.5f,0.5f,0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(-450,-160);
	glVertex2f(-253,-160);
	glVertex2f(-253,-165);
	glVertex2f(-450,-165);
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-450,-160);
	glVertex2f(-253,-160);
	glVertex2f(-253,-165);
	glVertex2f(-450,-165);
	glEnd();
	
	//manshirt
	glColor3f(1.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-375,-100);
	glVertex2f(-350,-100);
	glVertex2f(-355,-88);
    glVertex2f(-370,-88);
    glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-375,-100);
	glVertex2f(-350,-100);
	glVertex2f(-355,-88);
    glVertex2f(-370,-88);
    glEnd();
	
	//man sleev
	glColor3f(1.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-375,-100);
	glVertex2f(-350,-100);
	glVertex2f(-355,-93);
    glVertex2f(-370,-93);
    glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-375,-100);
	glVertex2f(-350,-100);
	glVertex2f(-355,-93);
    glVertex2f(-370,-93);
    glEnd();
    
    //man cap
    glColor3f(0.0f,0.0f,0.0f);
    myCircle(-365,-65,16);
    glColor3f(1.0f,1.0f,0.0f);
    myCircle(-365,-65,15);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
	glVertex2f(-350,-55);
	glVertex2f(-380,-77);
	glVertex2f(-381,-74);
    glVertex2f(-351,-52);
    glEnd();
    
    //man hair
    glColor3f(0.36f, 0.25f, 0.20f);
    glBegin(GL_POLYGON);
	glVertex2f(-379,-76);
	glVertex2f(-376,-85);
	glVertex2f(-368,-85);
    glVertex2f(-351,-56);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
	glVertex2f(-379,-76);
	glVertex2f(-376,-85);
	glVertex2f(-368,-85);
    glVertex2f(-351,-56);
    glEnd();
    
    //face
    glColor3f(0.96f, 0.80f, 0.69f);
    glBegin(GL_POLYGON);
    glVertex2f(-351,-56);
	glVertex2f(-346,-70);
	glVertex2f(-344,-73);
	glVertex2f(-350,-75);
	glVertex2f(-351,-85);
	glVertex2f(-358,-80);
	glVertex2f(-358,-88);
	glVertex2f(-375,-88);	
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
	glVertex2f(-351,-56);
	glVertex2f(-346,-70);
	glVertex2f(-344,-73);
	glVertex2f(-350,-75);
	glVertex2f(-351,-85);
	glVertex2f(-358,-80);
	glVertex2f(-358,-88);
	glVertex2f(-375,-88);	
    glEnd();
    
	//Details
	glColor3f(1.0f,1.0f,1.0f);
	myCircle(-405,-110,8);
	glColor3f(0.0f,0.0f,0.0f);
	myCircle(-405,-110,5);
	
	glColor3f(1.0f,1.0f,1.0f);
	myCircle(-473,-85,6);
	glColor3f(0.0f,0.0f,0.0f);
	myCircle(-473,-85,5);
	
	glColor3f(0.0f,0.0f,0.0f);
	myCircle(-351,-67,2);
	
	glBegin(GL_LINES);
	glVertex2f(-253,-150);
	glVertex2f(-340,-150);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(-340,-140);
	glVertex2f(-320,-140);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(-340,-130);
	glVertex2f(-317,-130);
	glEnd();	
	//cloud 0
	glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
	double theta;
	int radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-480 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-480 - 10 + radius * cos(theta), (360) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-480 + 10 + radius * cos(theta), (330) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-480+ 40 + radius * cos(theta), (340) + radius * sin(theta));
    }

    glEnd();
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-480+ 50 + radius * cos(theta), (330) + radius * sin(theta));
    }

    glEnd();
    //cloud 0 end
	//cloud 1
	glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80 + 10 + radius * cos(theta), (360) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80 + 10 + radius * cos(theta), (330) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80+ 20 + radius * cos(theta), (340) + radius * sin(theta));
    }

    glEnd();
    //cloud 1 end
    //cloud 2 started
    glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-320 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-320 - 10 + radius * cos(theta), (360) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-330 + 20 + radius * cos(theta), (330+30) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-300-50 + radius * cos(theta), (300+40) + radius * sin(theta));
    }

    glEnd();
	//cloud 2 end	
		 //cloud 3 started
    glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(320 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(320 + 10 + radius * cos(theta), (360) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(330 + 10 + radius * cos(theta), (330+30) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(300+ 10 + radius * cos(theta), (300+40) + radius * sin(theta));
    }
    glEnd();
	//cloud 3 end
	 //cloud 4 started
    glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(200 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(200 + 10 + radius * cos(theta), (360) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(200 + 10 + radius * cos(theta), (330+30) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(200+ 10 + radius * cos(theta), (300+40) + radius * sin(theta));
    }

    glEnd();
	//cloud 4 end
	 //cloud 5 started
    glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-200 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-200 + 10 + radius * cos(theta), (360) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-200 + 10 + radius * cos(theta), (330+30) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-200+ 10 + radius * cos(theta), (300+40) + radius * sin(theta));
    }

    glEnd();
	//cloud 5 end	
	//cloud 6 started
    glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450 + radius * sin(theta), 350 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450 -20 + radius * cos(theta), (360) + radius * sin(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450 + 20 + radius * cos(theta), (330+30) + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450+ 50 + radius * cos(theta), (300+40) + radius * sin(theta));
    }
    glEnd();
    //cloud ends
}


void myDisplay(void){
glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3f,1.0f,0.4f);
	glColor3f(0.62f, 0.49f, 0.23f);
	glBegin(GL_POLYGON);
		glVertex2f(-600, -130);
		glVertex2f(-600, 230);
		glVertex2f(600, 230);
		glVertex2f(600,-130);
	glEnd();
	
	
	glColor3f(0.3,0.50,0.2);
	//Hills behind city
		glBegin(GL_POLYGON);
	glVertex2f(-660,190);
	glVertex2f(-475,350);
	glVertex2f(-360,190);
	glEnd();	
	
	glBegin(GL_POLYGON);
	glVertex2f(-390,190);
	glVertex2f(-290,350);
	glVertex2f(-190,190);
	glEnd();	
	glBegin(GL_POLYGON);
	glVertex2f(-250,200);
	glVertex2f(-80,380);
	glVertex2f(0,200);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-10,210);
	glVertex2f(70,390);
	glVertex2f(150,210);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(140,210);
	glVertex2f(230,380);
	glVertex2f(380,210);
	glEnd();	
	glBegin(GL_POLYGON);
	glVertex2f(350,210);
	glVertex2f(650,210);
	glVertex2f(450,380);
	glEnd();	
	//Hills completed
    //Building No1
    	glColor3f((float)46/255, (float)43/255, (float)42/255);
	glBegin(GL_POLYGON);
    glVertex2f(-10, 60);
    glVertex2f(-10, 0);
    glVertex2f(25, 0);
    glVertex2f(25, 60);
    glEnd();
    //First Building Window
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-55, 55);
    glVertex2f(-35, 55);
    glVertex2f(-35, 45);
    glVertex2f(-55, 45);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-55, 40);
    glVertex2f(-35, 40);
    glVertex2f(-35, 30);
    glVertex2f(-55, 30);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-55, 25);
    glVertex2f(-35, 25);
    glVertex2f(-35, 15);
    glVertex2f(-55, 15);
    glEnd();
    //first building completed
     //Building no-2
    glColor3f((float)47/255, (float)41/255, (float)44/255);
    glBegin(GL_POLYGON);
    glVertex2f(-60, 60);
    glVertex2f(-30, 60);
    glVertex2f(-30, 10);
    glVertex2f(-60, 10);
    glEnd();
    //Second building window
    //Row1
	glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-5, 30);
    glVertex2f(-5, 25);
    glVertex2f(0, 25);
    glVertex2f(0, 30);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5, 30);
    glVertex2f(5, 25);
    glVertex2f(10, 25);
    glVertex2f(10, 30);
    glEnd();
    
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15, 30);
    glVertex2f(15, 25);
    glVertex2f(20, 25);
    glVertex2f(20, 30);
    glEnd();
    //Row2
    //----------BULDING WINDOWS ROW2----------
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-5, 15);
    glVertex2f(-5, 10);
    glVertex2f(0, 10);
    glVertex2f(0, 15);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5, 15);
    glVertex2f(5, 10);
    glVertex2f(10, 10);
    glVertex2f(10, 15);
    glEnd();
    
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15, 15);
    glVertex2f(15, 10);
    glVertex2f(20, 10);
    glVertex2f(20, 15);
    glEnd();
    //----------END OF BULDING WINDOWS ROW2----------
    //third Building
     glColor3f(0.0f, 1.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2f(50, 0);
    glVertex2f(50, 200);
    glVertex2f(120, 200);
    glVertex2f(120, 0);
    glEnd();
    //third building window
    //Row1
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(60, 190);
    glVertex2f(60, 150);
    glVertex2f(70, 150);
    glVertex2f(70, 190);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(80, 190);
    glVertex2f(80, 150);
    glVertex2f(90, 150);
    glVertex2f(90, 190);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(100, 190);
    glVertex2f(100, 150);
    glVertex2f(110, 150);
    glVertex2f(110, 190);
    glEnd();
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(60, 140);
    glVertex2f(60, 100);
    glVertex2f(70, 100);
    glVertex2f(70, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(80, 140);
    glVertex2f(80, 100);
    glVertex2f(90, 100);
    glVertex2f(90, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(100, 140);
    glVertex2f(100, 100);
    glVertex2f(110, 100);
    glVertex2f(110, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(60, 90);
    glVertex2f(60, 50);
    glVertex2f(70, 50);
    glVertex2f(70, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(80, 90);
    glVertex2f(80, 50);
    glVertex2f(90, 50);
    glVertex2f(90, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(100, 90);
    glVertex2f(100, 50);
    glVertex2f(110, 50);
    glVertex2f(110, 90);
    glEnd();
    //third building completed
     //fourth Building
     glColor3f(0.0f, 1.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2f(-100, 0);
    glVertex2f(-100, 189);
    glVertex2f(-170, 289);
    glVertex2f(-170, 0);
    glEnd();
    //fourth building window
    //Row1
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-110, 190);
    glVertex2f(-110, 150);
    glVertex2f(-120, 150);
    glVertex2f(-120, 190);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-130, 190);
    glVertex2f(-130, 150);
    glVertex2f(-140, 150);
    glVertex2f(-140, 190);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-150, 190);
    glVertex2f(-150, 150);
    glVertex2f(-160, 150);
    glVertex2f(-160, 190);
    glEnd();
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(-110, 140);
    glVertex2f(-110, 100);
    glVertex2f(-120, 100);
    glVertex2f(-120, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-130, 140);
    glVertex2f(-130, 100);
    glVertex2f(-140, 100);
    glVertex2f(-140, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-150, 140);
    glVertex2f(-150, 100);
    glVertex2f(-160, 100);
    glVertex2f(-160, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(-110, 90);
    glVertex2f(-110, 50);
    glVertex2f(-120, 50);
    glVertex2f(-120, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-130, 90);
    glVertex2f(-130, 50);
    glVertex2f(-140, 50);
    glVertex2f(-140, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-150, 90);
    glVertex2f(-150, 50);
    glVertex2f(-160, 50);
    glVertex2f(-160, 90);
    glEnd();
    //fourth building completed
    //fifth Building
     glColor3f(0.2f, 1.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2f(250, 0);
    glVertex2f(250, 200);
    glVertex2f(285, 250);
    glVertex2f(320, 200);
    glVertex2f(320, 0);
    glEnd();
    //fifth building window
    //Row1
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(260, 190);
    glVertex2f(260, 150);
    glVertex2f(270, 150);
    glVertex2f(270, 190);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(280, 190);
    glVertex2f(280, 150);
    glVertex2f(290, 150);
    glVertex2f(290, 190);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(300, 190);
    glVertex2f(300, 150);
    glVertex2f(310, 150);
    glVertex2f(310, 190);
    glEnd();
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(260, 140);
    glVertex2f(260, 100);
    glVertex2f(270, 100);
    glVertex2f(270, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(280, 140);
    glVertex2f(280, 100);
    glVertex2f(290, 100);
    glVertex2f(290, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(300, 140);
    glVertex2f(300, 100);
    glVertex2f(310, 100);
    glVertex2f(310, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(260, 90);
    glVertex2f(260, 50);
    glVertex2f(270, 50);
    glVertex2f(270, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(280, 90);
    glVertex2f(280, 50);
    glVertex2f(290, 50);
    glVertex2f(290, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(300, 90);
    glVertex2f(300, 50);
    glVertex2f(310, 50);
    glVertex2f(310, 90);
    glEnd();
    //fifth building completed
     //Sixth Building
     glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-200, 0);
    glVertex2f(-200, 195);
    glVertex2f(-270, 195);
    glVertex2f(-270, 0);
    glEnd();
    //Sixth building window
    //Row1
    glColor3f(1.9f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-210, 190);
    glVertex2f(-210, 150);
    glVertex2f(-220, 150);
    glVertex2f(-220, 190);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-230, 190);
    glVertex2f(-230, 150);
    glVertex2f(-240, 150);
    glVertex2f(-240, 190);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-250, 190);
    glVertex2f(-250, 150);
    glVertex2f(-260, 150);
    glVertex2f(-260, 190);
    glEnd();
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(-210, 140);
    glVertex2f(-210, 100);
    glVertex2f(-220, 100);
    glVertex2f(-220, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-230, 140);
    glVertex2f(-230, 100);
    glVertex2f(-240, 100);
    glVertex2f(-240, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-250, 140);
    glVertex2f(-250, 100);
    glVertex2f(-260, 100);
    glVertex2f(-260, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(-210, 90);
    glVertex2f(-210, 50);
    glVertex2f(-220, 50);
    glVertex2f(-220, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-230, 90);
    glVertex2f(-230, 50);
    glVertex2f(-240, 50);
    glVertex2f(-240, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-250, 90);
    glVertex2f(-250, 50);
    glVertex2f(-260, 50);
    glVertex2f(-260, 90);
    glEnd();
    //sixth building completed
      //seventh Building
     glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-300, 0);
    glVertex2f(-300, 150);
    glVertex2f(-370, 150);
    glVertex2f(-370, 0);
    glEnd();
    //seventh building window
     glColor3f(1.0f, 1.0f,0.0f);
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(-310, 140);
    glVertex2f(-310, 100);
    glVertex2f(-320, 100);
    glVertex2f(-320, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-330, 140);
    glVertex2f(-330, 100);
    glVertex2f(-340, 100);
    glVertex2f(-340, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-350, 140);
    glVertex2f(-350, 100);
    glVertex2f(-360, 100);
    glVertex2f(-360, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(-310, 90);
    glVertex2f(-310, 50);
    glVertex2f(-320, 50);
    glVertex2f(-320, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-330, 90);
    glVertex2f(-330, 50);
    glVertex2f(-340, 50);
    glVertex2f(-340, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-350, 90);
    glVertex2f(-350, 50);
    glVertex2f(-360, 50);
    glVertex2f(-360, 90);
    glEnd();
    //seventh building completed
     //8th Building
     glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-400, 0);
    glVertex2f(-400, 150);
     glVertex2f(-495, 180);
    glVertex2f(-590, 150);
    glVertex2f(-590, 0);
    glEnd();
    //8th building window
     glColor3f(0.0f, 0.0f,0.0f);
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(-410, 140);
    glVertex2f(-410, 100);
    glVertex2f(-420, 100);
    glVertex2f(-420, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-430, 140);
    glVertex2f(-430, 100);
    glVertex2f(-440, 100);
    glVertex2f(-440, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-450, 140);
    glVertex2f(-450, 100);
    glVertex2f(-460, 100);
    glVertex2f(-460, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(-410, 90);
    glVertex2f(-410, 50);
    glVertex2f(-420, 50);
    glVertex2f(-420, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-430, 90);
    glVertex2f(-430, 50);
    glVertex2f(-440, 50);
    glVertex2f(-440, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-450, 90);
    glVertex2f(-450, 50);
    glVertex2f(-460, 50);
    glVertex2f(-460, 90);
    glEnd();
    //ROw4
    glBegin(GL_POLYGON);
    glVertex2f(-470, 140);
    glVertex2f(-470, 100);
    glVertex2f(-480, 100);
    glVertex2f(-480, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-490, 140);
    glVertex2f(-490, 100);
    glVertex2f(-500, 100);
    glVertex2f(-500, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-510, 140);
    glVertex2f(-510, 100);
    glVertex2f(-520, 100);
    glVertex2f(-520, 140);
    glEnd();
    //Row5
    glBegin(GL_POLYGON);
    glVertex2f(-470, 90);
    glVertex2f(-470, 50);
    glVertex2f(-480, 50);
    glVertex2f(-480, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-490, 90);
    glVertex2f(-490, 50);
    glVertex2f(-500, 50);
    glVertex2f(-500, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-510, 90);
    glVertex2f(-510, 50);
    glVertex2f(-520, 50);
    glVertex2f(-520, 90);
    glEnd();
    //ROw6
    glBegin(GL_POLYGON);
    glVertex2f(-530, 140);
    glVertex2f(-530, 100);
    glVertex2f(-540, 100);
    glVertex2f(-540, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-550, 140);
    glVertex2f(-550, 100);
    glVertex2f(-560, 100);
    glVertex2f(-560, 140);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-570, 140);
    glVertex2f(-570, 100);
    glVertex2f(-580, 100);
    glVertex2f(-580, 140);
    glEnd();
    //Row7
    glBegin(GL_POLYGON);
    glVertex2f(-530, 90);
    glVertex2f(-530, 50);
    glVertex2f(-540, 50);
    glVertex2f(-540, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-550, 90);
    glVertex2f(-550, 50);
    glVertex2f(-560, 50);
    glVertex2f(-560, 90);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(-570, 90);
    glVertex2f(-570, 50);
    glVertex2f(-580, 50);
    glVertex2f(-580, 90);
    glEnd();
    //8th building completed
    //9th Building
     glColor3f(0.2f, 1.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2f(400, 0);
    glVertex2f(400, 200);
    glVertex2f(580, 200);
    glVertex2f(580, 0);
    glEnd();
    //9th building window
    //Row1
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(410, 190);
    glVertex2f(410, 150);
    glVertex2f(570, 150);
    glVertex2f(570, 190);
    glEnd();
    //ROw2
    glBegin(GL_POLYGON);
    glVertex2f(410, 140);
    glVertex2f(410, 100);
    glVertex2f(570, 100);
    glVertex2f(570, 140);
    glEnd();
    //Row3
    glBegin(GL_POLYGON);
    glVertex2f(410, 90);
    glVertex2f(410, 50);
    glVertex2f(570, 50);
    glVertex2f(570, 90);
    glEnd();
    //row4
     glBegin(GL_POLYGON);
    glVertex2f(410, 40);
    glVertex2f(410, 5);
    glVertex2f(570, 5);
    glVertex2f(570, 40);
    glEnd();
    //tree
    // started
    //tree1
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    	double theta;
	int radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-450 + radius * sin(theta), -10 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-450 -20 + radius * cos(theta), (-15) + radius * sin(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-450 + 20 + radius * cos(theta), -20 + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-450+ 50 + radius * cos(theta), (-17) + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-450 + radius * sin(theta), -10 + radius * cos(theta));
    }
    glEnd();
    //tree2
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450 -20 + radius * cos(theta), (-15) + radius * sin(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450 + 20 + radius * cos(theta), -20 + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(450+ 50 + radius * cos(theta), (-17) + radius * sin(theta));
    }
    glEnd();
    //tree3
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-150-20 + radius * cos(theta), (-15) + radius * sin(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-150+ 20 + radius * cos(theta), -20 + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-150+ 50 + radius * cos(theta), (-9) + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-150+ 60 + radius * cos(theta), (-10) + radius * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-450, -100);
    glVertex2f(-450, -10);
    glVertex2f(-440, -10);
    glVertex2f(-440, -100);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(450, -100);
    glVertex2f(450, -10);
    glVertex2f(440, -10);
    glVertex2f(440, -100);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(-150, -120);
    glVertex2f(-150, -5);
    glVertex2f(-140, -5);
    glVertex2f(-140, -120);
    glEnd();
    for (int i=-600; i <=600; i=i+100)
   	grass1(i,-100);
   	//tree4
   	glBegin(GL_POLYGON);
    glVertex2f(140, 130);
    glVertex2f(180, 180);
    glVertex2f(220, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(130, 100);
    glVertex2f(180, 160);
    glVertex2f(230, 100);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(120, 70);
    glVertex2f(180, 140);
    glVertex2f(240, 70);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(110, 40);
    glVertex2f(180, 120);
    glVertex2f(250, 40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(100, 10);
    glVertex2f(180, 100);
    glVertex2f(260, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(90, -30);
    glVertex2f(180, 80);
    glVertex2f(270, -30);
    glEnd();
     glBegin(GL_POLYGON);
     glVertex2f(175, -100);
    glVertex2f(175, 140);
    glVertex2f(185, 140);
    glVertex2f(185, -100);
    glEnd();
	//tree ended
    
    
    //9th building completed
    
    
    //------ Start of ground-----//
    // first soil 
    	glColor3f(0.62f, 0.49f, 0.23f);
	glBegin(GL_POLYGON);
		glVertex2f(-600, -600);
		glVertex2f(-600, -230);
		glVertex2f(600, -230);
		glVertex2f(600, -600);
	glEnd();
   
   	
   //road 
   glColor3f(0.1f, 0.1f, 0.1f);
   glBegin(GL_POLYGON);
   	glVertex2f(-600, -225);
   	glVertex2f(-600, -135);
   	glVertex2f(600, -135);
   	glVertex2f(600, -225);
   glEnd();
   
   glColor3f(1.0f, 1.0f, 1.0f);
   glLineWidth(20.0);
   glBegin(GL_LINES);
   	for (int i=-600; i<=600; i=i+50)
   		glVertex2f(i, -180);
   glEnd();
   
   // upper green color ground
   glColor3f(0.3f,1.0f,0.4f);
   glBegin(GL_POLYGON);
   	glVertex2f(-600, -135);
   	glVertex2f(-600, -130);
   	glVertex2f(600, -130);
   	glVertex2f(600, -135);
   glEnd();
   // grass texture we will use same color of ground
   for (int i=-600; i <=600; i=i+20)
   	grass(i,-130);
   	
   // lower green color ground
   glColor3f(0.3f,1.0f,0.4f);
   glBegin(GL_POLYGON);
   	glVertex2f(-600, -230);
   	glVertex2f(-600, -225);
   	glVertex2f(600, -225);
   	glVertex2f(600, -230);
   glEnd();
   // grass texture we will use same color of ground
   for (int i=-600; i <=600; i=i+20)
   	grass(i, -225);
   
   //flowers
   flower(-500, -280, 26, 1, 2);
   flower(-350, -320, 26, 2, 1);
   flower(-200, -280, 26, 3, 2);
   flower(-50, -320, 26, 1, 3);
   flower(100, -280, 26, 2, 4);
   flower(250, -320, 26, 3, 1);
   flower(400, -280, 26, 1, 2);
   flower(550, -320, 26, 2, 3);
   
	

	  
	glPushMatrix();
	glTranslatef(car1,0,0);
	glColor3f(1.0f,0.0f,1.0f);
	//background
	drawCar();
	//tyre(); 
	glTranslatef(carAndWheelX, 0.0f, 0.0f);
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(carAndWheelX + -400.0f, -150.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1*carAndWheelX + 400.0f, 150.0f, 0.0f);
    glTranslatef(carAndWheelX, 0.0, 0.0);
    glColor3f((float)46/255, (float)43/255, (float)42/255);
    glColor3f(0.0f,0.0f,0.0f);
glPointSize(10.0);
glLineWidth(4.0);

myCircle(-410,-150,34);//big wheel
glColor3f(0.5f,0.5f,0.5f);
myCircle(-410,-150,23);// mid 
glColor3f(0.0f,0.0f,0.0f);
myCircle(-410,-150,8);// circle


    glColor3f(0.0f,0.0f,0.0f);
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-410,-140);
glEnd();
glColor3f(0.0f,0.0f,0.0f);
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-410,-126);
glEnd();
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-432.82,-142.58);
glEnd();
glLineWidth(6.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-387.1746,-142.58);
glEnd();
glLineWidth(7.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-424.106,-169.416);
glEnd();
glLineWidth(7.0);
glBegin(GL_LINES);
	glVertex2f(-410,-150);
	glVertex2f(-395.893,-169.416);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
myCircle(-410,-150,4);
    glPopMatrix();
	
	
	glPushMatrix();
    glTranslatef(carAndWheelX + -300.0f, -150.0f, -100.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1*carAndWheelX + 300.0f, 150.0f, 100.0f);
    glTranslatef(carAndWheelX, 1.0, 0.0);
    glColor3f((float)46/255, (float)43/255, (float)42/255);
glPointSize(10.0);
glLineWidth(4.0);



glColor3f(0.0f,0.0f,0.0f);//small wheel
myCircle(-285,-162,22.5);
glColor3f(0.5f,0.5f,0.5f);
myCircle(-285,-162,12);

glColor3f(0.0f,0.0f,0.0f);
myCircle(-285,-162,5);



glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-272.636,-157.982);
glEnd();

glColor3f(0.0f,0.0f,0.0f);
glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-285,-149);
glEnd();

glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-297.363,-157.982);
glEnd();

glLineWidth(4.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-292.641,-172.517);
glEnd();

glLineWidth(4.0);
glBegin(GL_LINES);
	glVertex2f(-285,-162);
	glVertex2f(-277.358,-172.517);
glEnd();

glColor3f(1.0f,0.0f,0.0f);
myCircle(-285,-162,3);
 glPopMatrix();
	
	glutSwapBuffers();
	glFlush();
}


void timer (int){
	glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    car1+=5.0;//Increase it speed up
    if(car1>1200){
    	car1=-340;
	}
	angle -= 10;
    carAndWheelX +=5;
    //if car is outside the viewport
    //change the color to any color from 0 to 254 + 20(to avoid darker colors)
    if (carAndWheelX > 1200) {

        carAndWheelX = -340;
    }
//	1)declare one variable for your object in toppmost section with value -350 like car1
//	2)write here logic for it in timer function by referencing github code
//	3)in display func, start with glPushMatrix(); and end with glPopMatrix(); 
//	4) In between use any predefined functions with reference to github
//	5) and copy paste above respective code in between them as per required object to move
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  	glutInitWindowSize(1200, 800);
  	glutInitWindowPosition(200, 0);
	glutCreateWindow("Animation Assignment");
	myInit();
	glutDisplayFunc(myDisplay);
	glutTimerFunc(100, timer, 0);
	//glutSwapBuffers();
	glutMainLoop();
	return 0;
}

//circle function defination
void myCircle(int xc, int yc, int r)
{
   const int num_segments = 360;
   float angle, x, y;
   
   glBegin(GL_POLYGON);
   for(int i = 0; i < num_segments; ++i) {
      angle = 3.142/180*i;
      x = xc + r * cos(angle);
      y = yc + r * sin(angle);
      glVertex2f(x, y);
   }
   glEnd(); // End drawing the circle
}
//small grass to provide texture 
void grass(int v, int w)
{
	glBegin(GL_POLYGON);
		glVertex2f(v, w+0);
		glVertex2f(v+2, w+0);
		glVertex2f(v+5, w+7);
		glVertex2f(v, w+3);
		glVertex2f(v-5, w+10);
		glVertex2f(v-2, w+0);
	glEnd();
}
void grass1(int v, int w)
{
	glBegin(GL_POLYGON);
		glVertex2f(v, w+0);
		glVertex2f(v+10, w+0);
		glVertex2f(v+15, w+17);
		glVertex2f(v, w+3);
		glVertex2f(v-15, w+20);
		glVertex2f(v-10, w+0);
	glEnd();
}

// flower function
void flower(int x, int y, int r, int color1, int color2)
{
	// steam
	glColor3f(0.0f, 0.39f, 0.0);
	glLineWidth(7.0);
    	glBegin(GL_LINES);
    	glVertex2i(x, y);
    	glVertex2i(x, -400);
    	glEnd();
    	glLineWidth(4.0);
    	
    	//grass below steam
    	glColor3f(0.0, 1.0, 0.0);
    	grass1(x, -400);
    	
	switch (color1)
	{
		case 1: glColor3f(1.0, 1.0, 1.0);  // white
		break;
		case 2: glColor3f(1.0,1.0, 0.0); // yellow
		break;
		case 3: glColor3f(1.0f, 0.75f, 0.8f); // pink
		break;
		case 4: glColor3f(1.0f, 0.0f, 0.0f); // red
		break;
	}
    
	int xa, xb, xc, xd, xe,ya, yb, yc, yd, ye;
    	//vertex A at x, y-r
    
    	xa = x;
    	ya = y-r;

    	// Calculate the angle between consecutive vertices at centre
    		double angle = 72.0* (M_PI / 180.0);  // Convert to radians

    
    	// vertex B 
    	xb = (x + r * cos(angle));
    	
    	yb = (y + r * sin(angle));
    
    	xc = (x + r * cos(2*angle));
    	yc = (y + r * sin(2*angle));
    
    	xd = (x + r * cos(3*angle));
    	yd = (y + r * sin(3*angle));
    
    	xe = (x + r * cos(4*angle));
    	ye = (y + r * sin(4*angle));
    
    	// length of side i.e finding length of small circles
    	double dx = xa - xb;
    	double dy = ya - yb;
    	int radius = (int)(sqrt(dx * dx + dy * dy)*0.3);
    
    	//drawing cicles
    	
    	myCircle((int)(xb), (int)(yb), radius);
    	
    	myCircle((int)(xc), (int)(yc), radius);
    	
    	myCircle((int)(xd), (int)(yd), radius);
    
    	myCircle((int)(xe), (int)(ye), radius);
    
    	myCircle((int)(x + r * cos(5*angle)), (int)(y + r * sin(5*angle)), radius);
    	
    	
    	// middle small circle 
    	switch (color2)
	{
		case 1: glColor3f(0.53f, 0.81f, 0.92f);  // blue
		break;
		case 2: glColor3f(1.0,1.0, 0.0); // yellow
		break;
		case 3: glColor3f(1.0f, 0.75f, 0.8f); // pink
		break;
		case 4: glColor3f(1.0f, 0.0f, 0.0f); // red
		break;
	}
    	myCircle(x, y, (int)(r*0.7));
}
