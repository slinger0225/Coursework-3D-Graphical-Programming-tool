//
//  rotatingSquares.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/9.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <Glut/glut.h>
#include <math.h>

#define DEGREES_TO_RADIANS 3.14159/180.0

static GLfloat spin = 0.0;
GLfloat a, b;

void square()
{
    glBegin(GL_QUADS);
	   glVertex2f(a , b);
	   glVertex2f(-b , a);
    glVertex2f(-a , -b);
	   glVertex2f(b , -a);
    glEnd();
}

void displayd()
{
    glClear (GL_COLOR_BUFFER_BIT);
    square();
    glutSwapBuffers ();
    /*back buffer and front buffer is swapped, so that the content in the back buffer would be displayed.*/
}

void spinDisplay (void)
{
    spin = spin + 5.0;
    if (spin > 360.0) spin = spin - 360.0;
    a = 0.5 * cos(DEGREES_TO_RADIANS * spin);
    b = 0.5 * sin(DEGREES_TO_RADIANS * spin);
    glutPostRedisplay();
    //To avoid to many times that the display callback function being executed. Only the flag would be executed.
}

void myinit ()
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f (1.0, 1.0, 1.0);
    glShadeModel (GL_FLAT);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    /*double buffer:Front Buffer is used to display but not write to ;Back Buffer is used to write but not display. In order to avoid flikering brought by single buffer.
     */
    glutInitWindowPosition(500,0);
    glutCreateWindow("double buffered");
    myinit ();
    glutDisplayFunc(displayd);
    glutIdleFunc (spinDisplay);
    /*The idle callback is executed whenever there are no events in the event queue. More exactly, it is determined by whether the CPU is busy or not at the moment.*/
    glutMainLoop();
}


