//
//  squaredMouse.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/9.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>

GLdouble W = 640.0;
GLdouble H = 480.0;
GLint size = 30;

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

void drawSquare(int x, int y)
{
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);
    //y = viewport[3] - y; /* invert y position */
    glColor3ub((char)rand()%256, (char)rand()%256, (char)rand()%256);
    glBegin(GL_POLYGON);
    glVertex2i(x+size, y+size);
    glVertex2i(x-size, y+size);
    glVertex2i(x-size, y-size);
    glVertex2i(x+size, y-size);
    glEnd();
    glFlush();
}

void mymouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        drawSquare(x, y);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("simple");
    myInit();
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mymouse);
    glutMainLoop();
}

