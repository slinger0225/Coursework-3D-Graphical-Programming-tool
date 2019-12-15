//
//  dinoTiled.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/9.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

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

void drawPolyLineFile(char *filename) {
    FILE *ifp;
    int i, j;
    GLint numpolys, numLines, x, y;
    
    ifp = fopen (filename, "r");
    if(ifp==NULL) {
        printf("Error: can't open file for reading.\n");
        return;
    }
    
    //glClear(GL_COLOR_BUFFER_BIT);
    
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
    int k, l;
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (k=0; k < 10; k++) {
        for (l=0; l < 10; l++) {
            if(((k%2==0)&&(l%2==0))||((k%2==1)&&(l%2==1)))
            {
                setWindow (0, 640.0, 0, 440);
            }
            else
            {
                setWindow (0, 640.0, 440, 0);
            }
            
            glViewport (k*64, l*44, 64, 44);
            drawPolyLineFile ("dino1.dat");
        }
    }
    

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 440);
    glutCreateWindow("Dino");
    glutDisplayFunc(mydisplay);
    myInit();   
    glutMainLoop();
}


