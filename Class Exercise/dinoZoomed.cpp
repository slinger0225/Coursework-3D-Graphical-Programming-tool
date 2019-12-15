//
//  dinoZoomed.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/9.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

GLdouble W = 640.0;
GLdouble H = 480.0;
GLdouble scale=0.0;

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
void myidle(){
    while(scale<1.0){
        scale=scale+0.001;
        printf("%f\n",scale);
    }
    glutPostRedisplay();
    
}
void mydisplay(){
    setWindow (0,(1-scale)*W, scale*H, H);
    //setWindow (-0.5*W, 1.5*W, -0.5*H, 1.5*H);
    drawPolyLineFile ("dino1.dat");
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("Dino");
    glutDisplayFunc(mydisplay);
    glutIdleFunc(myidle);
    myInit();
    glutMainLoop();
}

