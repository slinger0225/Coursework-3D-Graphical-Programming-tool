//
//  squareKeyMoving.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/10.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>

GLint size = 30;
GLint H=640;
GLint W=480;
GLfloat moveX = 0.0;
GLfloat moveY = 0.0;
GLfloat xx = 0;
GLfloat yy = 0;


void myInit(void) {
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (0, 640, 0, 480);
}

void mydisplay(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawSquare(float x, float y)
{
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);
    y = viewport[3] - y; /* invert y position */
    xx = x;
    yy = y;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub((char)rand()%256, (char)rand()%256, (char)rand()%256);
    if ((xx+size)>viewport[2])
    {
        xx=viewport[2]-size;
    }
    if ((xx-size)<viewport[0])
    {
        xx=viewport[0]+size;
    }
    if ((yy+size)>viewport[3])
    {
        yy=viewport[3]-size;
    }
    if ((yy-size)<viewport[1])
    {
        yy=viewport[1]+size;
    }
    
    glBegin(GL_POLYGON);
    glVertex2f(xx+size, yy+size);
    glVertex2f(xx-size, yy+size);
    glVertex2f(xx-size, yy-size);
    glVertex2f(xx+size, yy-size);
    glEnd();
    glFlush();
}

void mymouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        drawSquare(x, y);
}

void myspecialkey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            moveX = -0.1;
            break;
        case GLUT_KEY_RIGHT:
            moveX = 0.1;
            break;
        case GLUT_KEY_DOWN:
            moveY = -0.1;
            break;
        case GLUT_KEY_UP:
            moveY = 0.1;
            break;
    }
}

void myspecialkeyup(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT)
        moveX = 0.0;
    if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
        moveY = 0.0;
}

void myidle() {
    if (moveX == 0 && moveY == 0) return;
    GLint viewport[4];
    glGetIntegerv (GL_VIEWPORT, viewport);
    xx = xx + moveX;
    yy = yy + moveY;
    if ((xx+size)>viewport[2])
    {
        xx=viewport[2]-size;
    }
    if ((xx-size)<viewport[0])
    {
        xx=viewport[0]+size;
    }
    if ((yy+size)>viewport[3])
    {
        yy=viewport[3]-size;
    }
    if ((yy-size)<viewport[1])
    {
        yy=viewport[1]+size;
    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(xx+size, yy+size);
    glVertex2f(xx-size, yy+size);
    glVertex2f(xx-size, yy-size);
    glVertex2f(xx+size, yy-size);
    glEnd();
    glFlush();

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(H, W);
    glutCreateWindow("squaresKeyMotionComplete");
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mymouse);
    glutSpecialFunc(myspecialkey);
    glutSpecialUpFunc(myspecialkeyup);
    glutIdleFunc(myidle);
    myInit();   
    glutMainLoop();
}
