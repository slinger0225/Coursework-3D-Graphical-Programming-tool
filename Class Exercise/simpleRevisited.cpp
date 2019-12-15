//
//  simpleRevisited.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

void myinit()
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
    glOrtho(-0.7, 0.7, -0.7, 0.7, -1.0, 1.0);
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    myinit(); 
    glutMainLoop();
}
