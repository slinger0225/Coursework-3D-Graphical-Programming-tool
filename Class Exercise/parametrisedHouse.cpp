//
//  parametrisedHouse.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <GLUT/GLUT.h>
GLint peak[2], width, height;

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 440.0);
}
void drawhouse() {  // same as in the mydisplay function of the parameterisedHouse.c program
    glBegin(GL_LINE_LOOP);
  		glVertex2i(peak[0], peak[1]); // house
    glVertex2i(peak[0]+width/2, peak[1]-(3*height/8));
  		glVertex2i(peak[0]+width/2, peak[1]-height);
  		glVertex2i(peak[0]-width/2, peak[1]-height);
  		glVertex2i(peak[0]-width/2, peak[1]-(3*height/8));
    glEnd();
    glBegin (GL_LINE_STRIP); 	// chimney
    glVertex2i(peak[0]-(2*width/6), peak[1]-(2*height/8));
    glVertex2i(peak[0]-(2*width/6), peak[1]);
  		glVertex2i(peak[0]-(width/6), peak[1]);
  		glVertex2i(peak[0]-(width/6), peak[1]-(height/8));
    glEnd();
    glBegin (GL_LINE_STRIP);	// door
    glVertex2i(peak[0]-(2*width/6), peak[1]-(height));
    glVertex2i(peak[0]-(2*width/6), peak[1]-(5*height/8));
  		glVertex2i(peak[0]-(5*width/60), peak[1]-(5*height/8));
  		glVertex2i(peak[0]-(5*width/60), peak[1]-(height));
    glEnd();
    glBegin(GL_LINE_LOOP);        	// window
    glVertex2i(peak[0]+(5*width/60), peak[1]-(55*height/80));
    glVertex2i(peak[0]+(5*width/60), peak[1]-(4*height/8));
  		glVertex2i(peak[0]+(2*width/6), peak[1]-(4*height/8));
  		glVertex2i(peak[0]+(2*width/6), peak[1]-(55*height/80));
    glEnd();
    glFlush();
}

void drawhouse1() {  // flipped house (the door and the chimney on the right side of the house)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
  		glVertex2i(peak[0], peak[1]);
    glVertex2i(peak[0]+width/2, peak[1]-(3*height/8));
  		glVertex2i(peak[0]+width/2, peak[1]-height);
  		glVertex2i(peak[0]-width/2, peak[1]-height);
  		glVertex2i(peak[0]-width/2, peak[1]-(3*height/8));
    glEnd();
    glBegin (GL_LINE_STRIP); 	// chimney (4 lines to be completed)
     glVertex2i(peak[0]+(2*width/6), peak[1]-(2*height/8));
        		glVertex2i(peak[0]+(2*width/6), peak[1]);
      		glVertex2i(peak[0]+(width/6), peak[1]);
      		glVertex2i(peak[0]+(width/6), peak[1]-(height/8));
    glEnd();
    glBegin (GL_LINE_STRIP);	// door (4 lines to be completed)
    glVertex2i(peak[0]+(2*width/6), peak[1]-(height));
        glVertex2i(peak[0]+(2*width/6), peak[1]-(5*height/8));
      		glVertex2i(peak[0]+(5*width/60), peak[1]-(5*height/8));
      		glVertex2i(peak[0]+(5*width/60), peak[1]-(height));
    glEnd();
    glBegin(GL_LINE_LOOP);        // window (4 lines to be completed)
    glVertex2i(peak[0]-(5*width/60), peak[1]-(55*height/80));
        glVertex2i(peak[0]-(5*width/60), peak[1]-(4*height/8));
      		glVertex2i(peak[0]-(2*width/6), peak[1]-(4*height/8));
      		glVertex2i(peak[0]-(2*width/6), peak[1]-(55*height/80));
    glEnd();
    glFlush();
}

void drawhouse2() { // upside down house
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);  // house (5 lines to be completed)
  		glVertex2i(peak[0], peak[1]);
        glVertex2i(peak[0]+width/2, peak[1]+(3*height/8));
      		glVertex2i(peak[0]+width/2, peak[1]+height);
      		glVertex2i(peak[0]-width/2, peak[1]+height);
      		glVertex2i(peak[0]-width/2, peak[1]+(3*height/8));
    glEnd();
    glBegin (GL_LINE_STRIP); 	// chimney (4 lines to be completed)
      glVertex2i(peak[0]-(2*width/6), peak[1]+(2*height/8));
        glVertex2i(peak[0]-(2*width/6), peak[1]);
      		glVertex2i(peak[0]-(width/6), peak[1]);
      		glVertex2i(peak[0]-(width/6), peak[1]+(height/8));
    glEnd();
    glBegin (GL_LINE_STRIP);	// door (4 lines to be completed)
    glVertex2i(peak[0]-(2*width/6), peak[1]+(height));
        glVertex2i(peak[0]-(2*width/6), peak[1]+(5*height/8));
      		glVertex2i(peak[0]-(5*width/60), peak[1]+(5*height/8));
      		glVertex2i(peak[0]-(5*width/60), peak[1]+(height));
    glEnd();
    glBegin(GL_LINE_LOOP);      // window (4 lines to be completed)
    glVertex2i(peak[0]+(5*width/60), peak[1]+(55*height/80));
        glVertex2i(peak[0]+(5*width/60), peak[1]+(4*height/8));
      		glVertex2i(peak[0]+(2*width/6), peak[1]+(4*height/8));
      		glVertex2i(peak[0]+(2*width/6), peak[1]+(55*height/80));
    glEnd();
    glFlush();
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    peak[0] = 70; //top of the roof
    peak[1] = 200;
    width = 60;
    height = 80;
    drawhouse ();
    
    peak[0] = 100;
    peak[1] = 300;
    width = 40;
    height = 60;
    drawhouse ();
    
    peak[0] = 200;
    peak[1] = 280;
    width = 90;
    height = 80;
    drawhouse ();
    
    peak[0] = 160;
    peak[1] = 180;
    width = 40;
    height = 120;
    drawhouse ();
    
    peak[0] = 350;
    peak[1] = 350;
    width = 80;
    height = 120;
    drawhouse ();
    
    peak[0] = 400;
    peak[1] = 150;
    width = 60;
    height = 50;
    drawhouse ();
    
    peak[0] = 500;
    peak[1] = 250;
    width = 50;
    height = 80;
    drawhouse ();
    
    peak[0] = 250;
    peak[1] = 100;
    width = 70;
    height = 70;
    drawhouse1 ();
    
    peak[0] = 520;
    peak[1] = 50;
    width = 60;
    height = 80;
    drawhouse2 ();
    
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 440);
    glutCreateWindow("House");     
    glutDisplayFunc(mydisplay); 
    myInit();   
    glutMainLoop();
}

