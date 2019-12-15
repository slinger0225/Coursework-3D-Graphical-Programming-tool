//
//  colourCube.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 19/3/22.
//  Copyright © 2019年 沈凌儿. All rights reserved.
//

/* demonstration of use of homogeneous-coordinate transformations
 and simple data structure for representing cube */

/*cube is centered at origin */

#include <stdlib.h>
#include <GLUT/GLUT.h>

GLfloat X = 0.5;		/* A scaling factor */

static GLfloat theta[] = {45.0,45.0,45.0};
static GLint axis = 2;

GLfloat GlobalVertices[][3] = {{-1.0,-1.0,1.0},
    {-1.0,1.0,1.0}, {1.0,1.0,1.0}, {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0}, {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0}};

// These will be the coordinates of the vertices of the cube
GLfloat CubeVertices[][3] = {{-1.0,-1.0,1.0},
    {-1.0,1.0,1.0}, {1.0,1.0,1.0}, {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0}, {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0}};

GLfloat colors[][4] = {{0.0,0.0,0.0,0.5},{0.0,1.0,0.0,0.5},
    {1.0,0.0,1.0,0.5}, {1.0,0.0,0.0,0.5}, {0.0,0.0,1.0,0.5},
    {1.0,1.0,0.0,0.5}};

void a3dpolygon(int color, GLfloat vertices[][3], int a, int b, int c, int d) {
    /* draw a polygon via list of vertices */
    
    //glShadeModel(GL_FLAT);
    //glShadeModel(GL_SMOOTH);
    glColor4fv(colors[color]);
    glBegin(GL_POLYGON);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void colorcube()
{
    /* map vertices to facets */
    //glColor3fv(colors[0]);
    a3dpolygon(0,CubeVertices, 0,3,2,1);
    //glColor3fv(colors[1]);
    a3dpolygon(1,CubeVertices, 2,3,7,6);
    //glColor3fv(colors[2]);
    a3dpolygon(2,CubeVertices, 3,0,4,7);
    //glColor3fv(colors[3]);
    a3dpolygon(3,CubeVertices, 1,2,6,5);
    //glColor3fv(colors[4]);
    a3dpolygon(4,CubeVertices, 4,5,6,7);
    //glColor3fv(colors[5]);
    a3dpolygon(5,CubeVertices, 5,4,0,1);
}

void display()
{
    /* display callback, clear frame buffer and z buffer,
     rotate cube and draw, swap buffers */
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/* Enable hidden-surface removal */
    //glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    colorcube();
    
    glutSwapBuffers();
}

void spinCube()
{
    /* idle callback, spin cube about selected axis */
    
    theta[axis] += 1;
    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    glutPostRedisplay();/*Enable smooth animation*/
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
    glShadeModel(GL_SMOOTH);
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 8; i++) {
            CubeVertices[i][j] = GlobalVertices[i][j]*X; //Scale each vertex by X
        }
    }
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    /* need both double buffering and z buffer */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);/* Enable hidden-surface removal and smooth animation*/
    //glutInitDisplayMode(GLUT_SINGLE|  GLUT_RGB  | GLUT_DEPTH);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize(500, 500);
    glutCreateWindow("Colourcube");
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glutSpecialFunc(specialkey);
    glEnable(GL_DEPTH_TEST); /* Enable hidden-surface removal */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);
    init();
    glutMainLoop();
}

