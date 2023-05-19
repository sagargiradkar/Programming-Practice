#include<iostream>
#include<GL/glut.h>
#include<math.h>

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1920.0,0.0,1080.0);
}

void Scenery(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Background Sky
	glBegin(GL_POLYGON);
		glColor3f(0.529,0.808,0.922);
		glVertex2i(0,700);
		glVertex2i(0,1080);
		glVertex2i(1920,1080);
		glVertex2i(1920,700);
	glEnd();

	// Grass
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.7,0.0);
		glVertex2i(0,700);
		glVertex2i(1920,700);		
		glVertex2i(1920,0);
		glVertex2i(0,0);
	glEnd();
	
	// Mountain 1
	glBegin(GL_POLYGON);
		glColor3f(0.545f, 0.271f, 0.075f); 
		glVertex2i(2,700);
		glVertex2i(202,980);		
		glVertex2i(402,700);
	glEnd();
	glFlush();
	
	// Mountain 2
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
		//glColor3f(0.6,0.4,0.2);
		glVertex2i(252,700);
		glVertex2i(452,1000);		
		glVertex2i(652,700);
	glEnd();
	glFlush();
	
	// Mountain 3
	glBegin(GL_POLYGON);
		//glColor3f(0.6,0.4,0.2);
		glColor3f(0.196f, 0.804f, 0.196f); 
		glVertex2i(510,700);
		glVertex2i(710,960);		
		glVertex2i(910,700);
	glEnd();
	glFlush();
	
	// Mountain 4
	glBegin(GL_POLYGON);
	glColor3f(0.196f, 0.804f, 0.196f); 
		//glColor3f(0.6,0.4,0.2);
		glVertex2i(1010,700);
		glVertex2i(1210,950);		
		glVertex2i(1410,700);
	glEnd();
	glFlush();
	
	// Sun
	glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
	double theta;
	int radius=100;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1600 + radius*sin(theta), 950 + radius*cos(theta));
    }
    glEnd();
    
    // River
	glBegin(GL_POLYGON);
		glColor3f(0.678,0.847,0.902);
		glVertex2i(790,0);
		glVertex2i(900,700);		
		glVertex2i(1020,700);
		glVertex2i(1130,0);
	glEnd();
	
	
		// Tree 1
		int p = 0, q = 0;	
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,1.0,0.0);
			glVertex2i(400-p,500+q);
			glVertex2i(450,550+q);		
			glVertex2i(500+p,500+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(440,400);
			glVertex2i(460,400);		
			glVertex2i(460,350);
			glVertex2i(440,350);			
			glEnd();
			
		p = 0, q = 0;	
		// Tree 2	
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,1.0,0.0);
			glVertex2i(300-p,300+q);
			glVertex2i(350,350+q);		
			glVertex2i(400+p,300+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(340,200);
			glVertex2i(360,200);		
			glVertex2i(360,150);
			glVertex2i(340,150);			
			glEnd();
			
		p = 0, q = 0;	
		// Tree 3
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,1.0,0.0);
			glVertex2i(100-p,600+q);
			glVertex2i(150,650+q);		
			glVertex2i(200+p,600+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(140,500);
			glVertex2i(160,500);		
			glVertex2i(160,450);
			glVertex2i(140,450);			
			glEnd();
			
		p = 0, q = 0;	
		// Tree 4
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,1.0,0.0);
			glVertex2i(60-p,350+q);
			glVertex2i(110,400+q);		
			glVertex2i(160+p,350+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(100,250);
			glVertex2i(120,250);		
			glVertex2i(120,200);
			glVertex2i(100,200);			
			glEnd();			
		
	// Boat
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(910,500);
		glVertex2i(930,540);		
		glVertex2i(990,540);
		glVertex2i(1010,500);
	glEnd();
	
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(910,500);
		glVertex2i(930,540);		
		glVertex2i(990,540);
		glVertex2i(1010,500);
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(900,500);
		glVertex2i(960,525);		
		glVertex2i(1020,500);
		glVertex2i(1000,445);
		glVertex2i(960,450);	
		glVertex2i(920,445);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(900,500);
		glVertex2i(960,525);		
		glVertex2i(1020,500);
		glVertex2i(1000,445);
		glVertex2i(960,450);	
		glVertex2i(920,445);
	glEnd();
	
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(935,540);
		glVertex2i(945,575);		
		glVertex2i(975,575);
		glVertex2i(985,540);
	glEnd();
		
	// Boat window	
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(945,550);
		glVertex2i(950,565);		
		glVertex2i(955,565);
		glVertex2i(955,550);
	glEnd();
	
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(965,550);
		glVertex2i(965,565);		
		glVertex2i(970,565);
		glVertex2i(975,550);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(960,460);
		glVertex2i(960,515);	
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(955,575);
		glVertex2i(960,650);		
		glVertex2i(965,575);	
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(955,575);	
		glVertex2i(965,575);			
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(950,610);	
		glVertex2i(970,610);			
		glEnd();
		
	// House
		glBegin(GL_POLYGON);
	//	glColor3f(0.0,0.0,1.0);
		//glColor3f(0.529f, 0.808f, 0.922f);// Front Wall
		//glColor3f(1.0f, 1.0f, 0.5f); 
		glColor3f(1.0f, 0.71f, 0.76f); // Set the color to light pink
		glVertex2i(1300,250);
		glVertex2i(1300,450);		
		glVertex2i(1500,450);	
		glVertex2i(1500,250);	
		glEnd();
		
		glBegin(GL_POLYGON);
		//glColor3f(0.0,1.0,0.0);
		glColor3f(0.4f, 0.8f, 0.4f);
		//glColor3f(1.0f, 1.0f, 1.0f); 
		glVertex2i(1300,450);
		glVertex2i(1400,550);		
		glVertex2i(1500,450);		
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.71f, 0.4f, 0.11f); // Set the color to light brown
	//	glColor3f(0.4f, 0.2f, 0.0f);// roof color
	//	glColor3f(1.0,0.0,0.0);
		glVertex2i(1400,550);
		glVertex2i(1700,550);		
		glVertex2i(1800,450);
		glVertex2i(1500,450);		
		glEnd();
		
		glBegin(GL_POLYGON);
	//	glColor3f(1.0,0.0,1.0);
		//glColor3f(1.0f, 0.71f, 0.76f); // Set the color to light pink
	glColor3f(1.0f, 1.0f, 0.5f); // Set the color to light yellow
		glVertex2i(1500,250);
		glVertex2i(1500,450);		
		glVertex2i(1800,450);
		glVertex2i(1800,250);		
		glEnd();
		
		glBegin(GL_POLYGON);
		//glColor3f(0.3f, 0.21f, 0.23f); // Set the color to low-intensity dark
		glColor3f(0.0,1.0,1.0);//doar color
		glVertex2i(1360,250);
		glVertex2i(1360,400);		
		glVertex2i(1440,400);	
		glVertex2i(1440,250);	
		glEnd();
		
		glBegin(GL_POLYGON);
		//glColor3f(0.3f, 0.21f, 0.23f); // Set the color to low-intensity dark
		glColor3f(0.5f, 0.5f, 0.5f);
		//glColor3f(1.0,1.0,1.0);//window color
		glVertex2i(1580,300);
		glVertex2i(1580,400);		
		glVertex2i(1730,400);	
		glVertex2i(1730,300);	
		glEnd();
		
	// Cloud 1	
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(300 + radius*sin(theta), 1000 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(320 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(340 + radius*sin(theta), 1000 + radius*cos(theta));
    }
    glEnd();	
		
	glFlush();	
	
	// Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(360 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(380 + radius*sin(theta), 1000 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(60 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(80 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();	
		
	// Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(100 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(120 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(140 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(480 + radius*sin(theta), 920 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(500 + radius*sin(theta), 900 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(520 + radius*sin(theta), 920 + radius*cos(theta));
    }
    glEnd();
		
	// Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(540 + radius*sin(theta), 900 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(560 + radius*sin(theta), 920 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1250 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1270 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1290 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
		
	// Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1310 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1330 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Birds 
    
    // Bird-1 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1000,1000);
			glVertex2i(1020,980);		
			glVertex2i(1020,970);			
			glEnd();  	
			
		// Bird-1 Wing-Right
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1020,970);
			glVertex2i(1020,980);		
			glVertex2i(1040,1000);			
			glEnd(); 	
	
	 // Bird-2 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(900,950);
			glVertex2i(920,930);		
			glVertex2i(920,920);			
			glEnd();  	
			
		// Bird-2 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(920,920);
			glVertex2i(920,930);		
			glVertex2i(940,950);			
			glEnd(); 
			
	 // Bird-3 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(960,980);
			glVertex2i(980,960);		
			glVertex2i(980,950);			
			glEnd();  	
			
		// Bird-3 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(980,950);
			glVertex2i(980,960);		
			glVertex2i(1000,980);			
			glEnd(); 
			
	 // Bird-4 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1800,900);
			glVertex2i(1820,880);		
			glVertex2i(1820,870);			
			glEnd();  	
			
		// Bird-4 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1820,870);
			glVertex2i(1820,880);		
			glVertex2i(1840,900);			
			glEnd(); 					
		
	 // Bird-5 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1750,930);
			glVertex2i(1770,910);		
			glVertex2i(1770,900);			
			glEnd();  	
			
		// Bird-5 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1770,900);
			glVertex2i(1770,910);		
			glVertex2i(1790,930);			
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
	glutDisplayFunc(Scenery);
	myInit();
	glutMainLoop();
}
