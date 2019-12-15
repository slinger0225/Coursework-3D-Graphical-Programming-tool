//
//  simple.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <GLUT/GLUT.h>
//only called once

#include <GLUT/GLUT.h>

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -1);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -1);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
}
