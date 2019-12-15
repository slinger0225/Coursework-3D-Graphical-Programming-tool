//
//  dinoReshape.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/10.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); //default white, backgroud color
    glColor3f(0.0, 0.0, 0.0);//default black
    glPointSize(3.0);
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
    drawPolyLineFile ("dino1.dat");
}
//A reshape is posted automatically at the end of the execution of the callback
void myreshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0.0, 640, 0.0, 480.0);
    if (w <= h) //When the window is streched in length, it eqauls to the viewing volume is streched in width
        gluOrtho2D(0.0, 640.0, 0.0, 480 * (GLfloat) h / (GLfloat) w);//So we must strech the viewing volume in length to make it back to the original ratio of viewing volume(640*480). Now we should persist the smaller side (width), so that it would not exceeds the window, and strech the larger size according to the ratio.
    else  gluOrtho2D(0.0, 640 *
                     (GLfloat) w / (GLfloat) h, 0.0, 480.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("dinoReshape");
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(myreshape);
    myInit();
    glutMainLoop();
}

