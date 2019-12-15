//
//  twist.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 2019/4/12.
//  Copyright © 2019 沈凌儿. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>

/* initial triangle */
GLfloat v[3][2]={{-1.0, -0.58}, {1.0, -0.58}, {0.0, 1.15}};

int n = 4; /* number of recursive steps */

GLfloat twist = 1.5;

void triangle (GLfloat *a, GLfloat *b, GLfloat *c)
{
    /* display one triangle  */
    
    GLfloat v[2];
    double d;
    
    glBegin(GL_POLYGON);
    d = sqrt(a[0]*a[0] + a[1]*a[1]);
    printf("d1=%f\n",d);
    v[0] = cos(twist * d) * a[0] - sin(twist *d) * a[1];
    v[1] = sin(twist * d) * a[0] + cos (twist * d) * a[1];
    glVertex2fv(v);
    d = sqrt(b[0]*b[0] + b[1]*b[1]);
    printf("d2=%f\n",d);
    v[0] = cos(twist * d) * b[0] - sin(twist *d) * b[1];
    v[1] = sin(twist * d) * b[0] + cos (twist * d) * b[1];
    glVertex2fv(v);
    d = sqrt(c[0]*c[0] + c[1]*c[1]);
    printf("d3=%f\n",d);
    v[0] = cos(twist * d) * c[0] - sin(twist *d) * c[1];
    v[1] = sin(twist * d) * c[0] + cos (twist * d) * c[1];
    glVertex2fv(v);
    glEnd();
}





void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
    /* triangle subdivision using vertex numbers */
    GLfloat v[3][2];
    int j;
    
    if(m>0)
    {
        for(j=0; j<2; j++)
        {
            v[0][j]=(a[j]+b[j])/2;
            printf("v1=%f\n",v[0][j]);
        }
        for(j=0; j<2; j++)
        {
            v[1][j]=(a[j]+c[j])/2;
            printf("v2=%f\n",v[1][j]);
        }
        for(j=0; j<2; j++)
        {
            v[2][j]=(b[j]+c[j])/2;
            printf("v3=%f\n",v[2][j]);
        }
        divide_triangle(a, v[0], v[1], m-1);
        divide_triangle(v[0], b, v[2], m-1);
        divide_triangle(v[1], v[2], c, m-1);
        divide_triangle(v[0], v[1], v[2], m-1);
    }
    else(triangle(a,b,c));
    /* draw triangle at end of recursion */
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    divide_triangle(v[0], v[1], v[2], n);
    glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0,0.0,0.0);
    glPolygonMode(GL_FRONT, GL_LINE);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("tessalation");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}



