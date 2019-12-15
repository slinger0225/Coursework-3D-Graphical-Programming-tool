//
//  tweening.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/22.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//


#include <GLUT/GLUT.h>

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 280.0);
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    int i;
    float j;
    int offset = 100;
    GLfloat A[9][2] = {{20.0, 20.0}, {20.0, 60.0}, {45.0, 80.0},
        {70.0, 60.0}, {70.0, 20.0}, {50.0, 20.0},
        {50.0, 35.0}, {40.0, 35.0}, {40.0, 20.0}};
    GLfloat B[9][2] = {{20.0, 60.0}, {20.0, 80.0}, {45.0, 80.0},
        {70.0, 80.0}, {70.0, 60.0}, {50.0, 60.0},
        {50.0, 20.0}, {40.0, 20.0}, {40.0, 60.0}};

    glBegin(GL_LINE_LOOP);
    glVertex2f(A[0][0], A[0][1]);
    glVertex2f(A[1][0], A[1][1]);
    glVertex2f(A[2][0], A[2][1]);
    glVertex2f(A[3][0], A[3][1]);
    glVertex2f(A[4][0], A[4][1]);
    glVertex2f(A[5][0], A[5][1]);
    glVertex2f(A[6][0], A[6][1]);
    glVertex2f(A[7][0], A[7][1]);
    glVertex2f(A[8][0], A[8][1]);
    glEnd();
    glFlush();


        for (i=0; i<5; i++) {
        j = i * 0.25;
        glBegin(GL_LINE_LOOP); // 9 lines to be completed
        glVertex2f(i*100+B[0][0], (1-j)*A[0][1]+j*B[0][1]);
        glVertex2f(i*100+B[1][0], (1-j)*A[1][1]+j*B[1][1]);
        glVertex2f(i*100+B[2][0], (1-j)*A[2][1]+j*B[2][1]);
        glVertex2f(i*100+B[3][0], (1-j)*A[3][1]+j*B[3][1]);
        glVertex2f(i*100+B[4][0], (1-j)*A[4][1]+j*B[4][1]);
        glVertex2f(i*100+B[5][0], (1-j)*A[5][1]+j*B[5][1]);
        glVertex2f(i*100+B[6][0], (1-j)*A[6][1]+j*B[6][1]);
        glVertex2f(i*100+B[7][0], (1-j)*A[7][1]+j*B[7][1]);
        glVertex2f(i*100+B[8][0], (1-j)*A[8][1]+j*B[8][1]);
        glEnd();
    }
    glFlush();
 
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 280);
    glutCreateWindow("Tween");
    glutDisplayFunc(mydisplay);
    myInit();   
    glutMainLoop();
}

