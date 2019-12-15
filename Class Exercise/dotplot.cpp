//
//  dotplot.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>

const int screenWidth = 1000040;	   // width of the screen window in pixels
const int screenHeight = 480;	   // height of the screen window in pixels
GLdouble A, B, C, D;  // values used for scaling and shifting


void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);       // the background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // the drawing color is black
    glPointSize(2.0);		           // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
    A = screenWidth / 4.0; // sets the values used for scaling and shifting
    B = D= 0.0;
    C = screenHeight / 2.0;
}


void myDisplay(void)
{
    GLdouble x;
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    glBegin(GL_POINTS);
    for(x = 0; x < 4.0 ; x += 0.01)
    {
        GLdouble func = exp(-x) * cos(2 * 3.14159265 * x);
        glVertex2d(A * x + B, C * func + D);
    }
    glEnd();
    glFlush();		   // send all output to display
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
    glutInitWindowSize(screenWidth, screenHeight); // set the window size
    glutInitWindowPosition(100, 150); // set the window position
    glutCreateWindow("Dot Plot of a Function"); // open the screen window
    glutDisplayFunc(myDisplay);     // register the redraw function
    myInit();
    glutMainLoop(); 		     // go into a perpetual loop
}

