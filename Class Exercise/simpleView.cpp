//
//  simpleView.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-1, 1, -1, 1, -1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -1);
    glVertex2f(-1, 0);
    glVertex2f(0, 0);
    glVertex2f(0, -1);
    
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
}
