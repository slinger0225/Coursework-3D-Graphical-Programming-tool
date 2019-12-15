//
//  barnWithWindows.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/22.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

/* A rotating barn with 2 doors and a window */

#include <stdlib.h>
#include <GLUT/GLUT.h>

GLfloat X = 0.5;		/* A scaling factor */
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;


GLfloat GlobalVertices[][3] = {{-1.0,-1.0,-1.5}, {1.0,-1.0,-1.5},
    {1.0,1.0,-1.5}, {0.0,2.0,-1.5},
    {-1.0,1.0,-1.5}, {-1.0,-1.0, 1.5},
				{1.0,-1.0,1.5}, {1.0,1.0,1.5},
    {0.0,2.0,1.5}, {-1.0,1.0,1.5},
    {-0.5, 1.0, 1.5}, {0.5, 1.0, 1.5},
    {0.5, 0.2, 1.5}, {-0.5, 0.2, 1.5},
    {-1.0, 0.2, 1.5}, {1.0, 0.2, 1.5},
    {1.0, 0.2, 1.2}, {1.0, 0.2, 0.3},
    {1.0, -1.0, 0.3}, {1.0, -1.0, 1.2},
    {1.0, 0.2, -0.3}, {1.0, 0.2, -1.2},
    {1.0, -1.0, -1.2}, {1.0, -1.0, -0.3},
    {1.0, 0.2, -1.5}};

GLfloat BarnVertices[][3] = {{-1.0,-1.0,-1.5}, {1.0,-1.0,-1.5},
    {1.0,1.0,-1.5}, {0.0,2.0,-1.5},
    {-1.0,1.0,-1.5}, {-1.0,-1.0, 1.5},
				{1.0,-1.0,1.5}, {1.0,1.0,1.5},
    {0.0,2.0,1.5}, {-1.0,1.0,1.5},
    {-0.5, 1.0, 1.5}, {0.5, 1.0, 1.5},
    {0.5, 0.2, 1.5},{-0.5, 0.2, 1.5},
    {-1.0, 0.2, 1.5}, {1.0, 0.2, 1.5},
    {1.0, 0.2, 1.2}, {1.0, 0.2, 0.3},
    {1.0, -1.0, 0.3}, {1.0, -1.0, 1.2},
    {1.0, 0.2, -0.3}, {1.0, 0.2, -1.2},
    {1.0, -1.0, -1.2}, {1.0, -1.0, -0.3},
    {1.0, 0.2, -1.5}};


GLint BarnFaces[][6] = {{0,5,9,4,-1},{3,4,9,8,-1},{8,7,2,3,-1},{0,4,3,2,1,-1},{0,1,6,5,-1},{9,7,8,-1},{9,14,13,10,-1},{11,12,15,7,-1},{14,5,6,15,-1},{7,15,24,2,-1},{15,6,19,16,-1},{17,18,23,20,-1},{21,22,1,24,-1},{13,12,11,10,-1},{19,18,17,16,-1},{23,22,21,20,-1}
    
    
    
    
    
};

GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},
    {0.0,1.0,0.0}, {0.0,0.0,1.0},{1.0,0.0,1.0},
    {0.5,0.5,0.5}, {0.0,1.0,1.0}, {1.0, 1.0, 1.0}};


void a3dpolygon(GLfloat vertices[][3], GLint face[]) {
    /* draw a polygon via list of vertices */
    int i = 0;
    int id;
    glShadeModel(GL_FLAT);
    glBegin(GL_POLYGON);
    while (face[i] > -1) {
        id = face[i];
        glVertex3fv(vertices[id]);
        i++;
    }
    glEnd();
}

void barn()
{
    /* map vertices to facets */
    glColor3fv(colors[0]);
    a3dpolygon(BarnVertices, BarnFaces[0]);
    glColor3fv(colors[1]);
    a3dpolygon(BarnVertices, BarnFaces[1]);
    glColor3fv(colors[2]);
    a3dpolygon(BarnVertices, BarnFaces[2]);
    glColor3fv(colors[4]);
    a3dpolygon(BarnVertices, BarnFaces[3]);
    glColor3fv(colors[6]);
    a3dpolygon(BarnVertices, BarnFaces[4]);
    glColor3fv(colors[3]);
    a3dpolygon(BarnVertices, BarnFaces[5]);
    a3dpolygon(BarnVertices, BarnFaces[6]);
    a3dpolygon(BarnVertices, BarnFaces[7]);
    a3dpolygon(BarnVertices, BarnFaces[8]);
    glColor3fv(colors[5]);
    a3dpolygon(BarnVertices, BarnFaces[9]);
    a3dpolygon(BarnVertices, BarnFaces[10]);
    a3dpolygon(BarnVertices, BarnFaces[11]);
    a3dpolygon(BarnVertices, BarnFaces[12]);
    glColor3fv(colors[8]);
    a3dpolygon(BarnVertices, BarnFaces[13]);
    a3dpolygon(BarnVertices, BarnFaces[14]);
    a3dpolygon(BarnVertices, BarnFaces[15]);
}







void display()
{
    /* display callback, clear frame buffer and z buffer */
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    barn();
    glutSwapBuffers();
}

void spinBarn()
{
    theta[axis] += 1;
    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    glutPostRedisplay();
}

void specialkey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            axis = 0;
            break;
        case GLUT_KEY_UP:
            axis = 1;
            break;
        case GLUT_KEY_RIGHT:
            axis = 2;
            break;
    }
}

void init()
{
    int i, j;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    for (i = 0; i < 25; i++) {
        for (j = 0; j < 3; j++) {
            BarnVertices[i][j] = GlobalVertices[i][j] * X;  // scaling
        }
    }
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat) h / (GLfloat) w,
                1.5 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat) w / (GLfloat) h,
                1.5 * (GLfloat) w / (GLfloat) h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    /* need both double buffering and z buffer */
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("A Barn");
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutIdleFunc(spinBarn);
    glutSpecialFunc(specialkey);
    glEnable(GL_DEPTH_TEST); /* Enable hidden-surface removal */
    init();
    glutMainLoop();
}



