//
//  dinoSubMenu.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/9.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <GLUT/GLUT.h>

GLboolean animated = GL_FALSE;

GLdouble W = 640.0;
GLdouble H = 480.0;
GLdouble zoom = 1.0;
GLint menu_id = 0;
GLint submenu_id = 0;

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
}

void setWindow (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top) {
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (left, right, bottom, top);
}

void myidle() {
    //if (!animated) return;
    //if (zoom > 0.2) zoom -= 0.005;
    if (zoom > 0.2) zoom -= 0.01;
    glutPostRedisplay();
}

void drawPolyLineFile(char *filename) {
    FILE *ifp;
    int i, j;
    GLint numpolys, numLines, x, y;
    
    ifp = fopen (filename, "r");
    if(ifp==NULL) {
        printf("Error: can't open file for reading.\n");
        return;
    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    fscanf (ifp, "%d", &numpolys);
    
    for (j=0; j < numpolys; j++) {
        fscanf (ifp, "%d", &numLines);
        glBegin (GL_LINE_STRIP);
        for (i = 0; i < numLines; i++) {
            fscanf (ifp, "%d %d", &x, &y);
            glVertex2i (x, y);
        }
        glEnd();
    }
    glFlush();
    fclose (ifp);
    
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    setWindow (0, W*zoom, H*(1-zoom), H);
    drawPolyLineFile ("dino1.dat");
    glutSwapBuffers();
}

void mymenu(int id)
{
    if(id == 1) {
        glutIdleFunc(myidle); //just like once myidle have been called, it would always be called even id==2??
        //glutMouseFunc(mymouse);
        
    }

    
    if(id == 2) {
        glClear(GL_COLOR_BUFFER_BIT);//清理back buffer
        glutSwapBuffers();
        glFlush();
    }

}

void mysubmenu(int id)
{
    if(id == 1) exit(0);
    if(id == 2) return;
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("Dino");
    glutDisplayFunc(mydisplay);
    myInit();
    submenu_id = glutCreateMenu(mysubmenu);
    glutAddMenuEntry("yes", 1);
    glutAddMenuEntry("no", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    menu_id = glutCreateMenu(mymenu);
    glutAddMenuEntry("animation", 1);
    glutAddMenuEntry("clear screen", 2);
    glutAddSubMenu ("exit", submenu_id);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
