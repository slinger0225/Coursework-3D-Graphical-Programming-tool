//
//  dino.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/8.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
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
    printf("%d ",numpolys);
    
    for (j=0; j < numpolys; j++) {
        fscanf (ifp, "%d", &numLines);
        printf("%d ",numLines);
        glBegin (GL_LINE_STRIP);
        for (i = 0; i < numLines; i++) {
            if (i%2==0)
            {
                fscanf (ifp, "%d %d", &x, &y);
                printf("%d %d ",x,y);
                glVertex2i (x, y);
            }
            else
            {
                fscanf (ifp, "%d %d", &x, &y);
            }

        }
        glEnd();
    }
    glFlush();
    fclose (ifp);
}

void mydisplay(){
    drawPolyLineFile ("dino.dat");
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Dino");     
    glutDisplayFunc(mydisplay); 
    myInit();   
    glutMainLoop();
}


