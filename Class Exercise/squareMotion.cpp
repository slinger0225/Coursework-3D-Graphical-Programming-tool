//
//  squareMotion.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/9.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <GLUT/GLUT.h>

GLdouble W = 640.0;
GLdouble H = 480.0;
GLint xx = 0;
GLint yy = 0;

void myInit(void) {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (0, W, 0, H);
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void mymouse(int btn, int state, int x, int y)
{
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
        glColor3ub((char)(rand()*1000)%256, (char)(rand()*1000)%256, (char)(rand()*1000)%256); /* a random color */
        xx = x;
        yy = viewport[3] - y;
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        exit(0);
}

void drawSquare(int x, int y) {
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);
    y = viewport[3] - y; /* invert y position */
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2i(xx, yy);
    glVertex2i(x, yy);
    glVertex2i(x, y);
    glVertex2i(xx, y);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("simple");
    myInit();
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mymouse);
    glutMotionFunc(drawSquare);
    glutMainLoop();
}
