//
//  squareMotionExercise.cpp
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
GLboolean started = GL_FALSE;

void myInit(void) {
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (0, W, 0, H);
    glLineWidth (3.0);
}

void mydisplay(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void mymouse(int btn, int state, int x, int y)
{
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
        glColor3ub((char)rand()%256, (char)rand()%256, (char)rand()%256);
        xx = x;
        yy = viewport[3] - y; /* invert y position */
        started = GL_TRUE;
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        exit(0);
}
void drawPath(int x, int y) {
    if (!started)
        return;
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);  // 8 lines to be completed
    y = viewport[3] - y; /* invert y position */
    glBegin(GL_LINES);
    glVertex2i(xx, yy);
    glVertex2i(x, y);
    glEnd();
    glFlush();
    xx=x;
    yy=y;

    }

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mymouse);
    glutPassiveMotionFunc(drawPath);
    myInit();   
    glutMainLoop();
}

