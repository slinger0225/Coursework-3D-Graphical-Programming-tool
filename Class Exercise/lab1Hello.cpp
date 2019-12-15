//
//  lab1Hello.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <GLUT/GLUT.h>

void display_func()
{
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Hello GLUT!");
    glutDisplayFunc(display_func);
    glutMainLoop();
}
