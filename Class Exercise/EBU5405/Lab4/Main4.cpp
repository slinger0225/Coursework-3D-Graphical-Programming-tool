//
//  Lab4.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 2019/6/9.
//  Copyright © 2019 沈凌儿. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <glut.h>

#define LEFT -10
#define RIGHT 10
#define BOTTOM -10
#define UP 10
#define NEAR -10
#define FAR 10
#define ZIGY 3

#define EYE_RADIUS 0.2
#define DISK_OUTER 0.7 //tail's length
#define PINCER_ANGLE 15.0
#define PINCER_HEIGHT 0.8
#define PINCER_RADIUS 0.3
#define UPPERHAND_RADIUS 0.1
#define UPPERHAND_LENGTH 1.5
#define UPPERHAND_ANGLE 40.0
#define UPPERLEG_RADIUS 0.10
#define UPPERLEG_LENGTH 1.0
#define LOWERLEG_RADIUS 0.06
#define LOWERLEG_LENGTH 0.8
#define LEG_ANGLE 20.0 //The leg will raise with a angle.
#define LOWER_ANGLE 60.0 //The angle between the upper leg and the lower leg.
#define HAND_ANGLE -60.0
#define HEAD_HEIGHT 1.6
#define BODY_UP_RADIUS 0.5
#define BODY_LOWER_RADIUS 0.7
#define BODY_HEIGHT 1.0


GLint i;




GLUquadricObj *p;   // pointer to quadric object

void eye_left() {
	glPushMatrix();
	glTranslatef(HEAD_HEIGHT / 2, 0.0, BODY_LOWER_RADIUS / 2);
	gluSphere(p, EYE_RADIUS, 50, 50);
	glPopMatrix();
}
void eye_right() {
	glPushMatrix();
	glTranslatef(HEAD_HEIGHT / 2, 0.0, -BODY_LOWER_RADIUS / 2);
	gluSphere(p, EYE_RADIUS, 50, 50);
	glPopMatrix();
}

void head()
{
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(p, 0, BODY_LOWER_RADIUS, HEAD_HEIGHT, 15, 15);
	glPopMatrix();
}

void body(GLfloat lower, GLfloat upper)
{
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(p, lower, upper, BODY_HEIGHT, 15, 15);
	glPopMatrix();
}
void last_body(GLfloat lower, GLfloat upper)
{
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);;
	gluCylinder(p, lower, 0, BODY_HEIGHT, 15, 15);
	glPopMatrix();
}

void tail1() {
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluPartialDisk(p, 0, DISK_OUTER, 30, 30, 35, 45);
	glPopMatrix();
}
void tail2() {
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluPartialDisk(p, 0, DISK_OUTER, 30, 30, 100, 45);
	glPopMatrix();
}

void leg_right(GLfloat lower, GLfloat upper)
{
	glPushMatrix();
	glRotatef(-LEG_ANGLE, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, upper);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERLEG_RADIUS, LOWERLEG_RADIUS, UPPERLEG_LENGTH, 15, 15);  // the upper leg
	glTranslatef(0.0, 0.0, UPPERLEG_LENGTH - 0.05);
	glRotatef(LOWER_ANGLE, 1.0, 0.0, 0.0);
	gluCylinder(p, LOWERLEG_RADIUS, 0, LOWERLEG_LENGTH, 15, 15);//the lower leg.
	glPopMatrix();

}
void leg_left(GLfloat lower, GLfloat upper)
{
	glPushMatrix();
	glRotatef(180 + LEG_ANGLE, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, upper);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERLEG_RADIUS, LOWERLEG_RADIUS, UPPERLEG_LENGTH, 15, 15);  // the upper leg
	glTranslatef(0.0, 0.0, UPPERLEG_LENGTH - 0.05);
	glRotatef(-LOWER_ANGLE, 1.0, 0.0, 0.0);
	gluCylinder(p, LOWERLEG_RADIUS, 0, LOWERLEG_LENGTH, 15, 15);//the lower leg
	glPopMatrix();
}
void pincer1() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, UPPERHAND_LENGTH);
	glRotatef(PINCER_ANGLE, 0.0, 1.0, 0.0);
	gluCylinder(p, 0, PINCER_RADIUS, PINCER_HEIGHT, 15, 15);
	glTranslatef(0.0, 0.0, PINCER_HEIGHT);
	gluCylinder(p, PINCER_RADIUS, 0, PINCER_HEIGHT, 15, 15);
	glPopMatrix();
}
void pincer2() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, UPPERHAND_LENGTH);
	glRotatef(-PINCER_ANGLE, 0.0, 1.0, 0.0);
	gluCylinder(p, 0, PINCER_RADIUS, PINCER_HEIGHT, 15, 15);
	glTranslatef(0.0, 0.0, PINCER_HEIGHT);
	gluCylinder(p, PINCER_RADIUS, 0, PINCER_HEIGHT, 15, 15);
	glPopMatrix();
}
void hand_right()
{
	glPushMatrix();
	glTranslatef(0.0, 0.0, BODY_LOWER_RADIUS);
	glRotatef(-UPPERHAND_ANGLE, 0.0, 1.0, 0.0);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);  // the upper hand
	glTranslatef(0.0, 0.0, UPPERHAND_LENGTH);
	glRotatef(HAND_ANGLE, 0.0, 1.0, 0.0);
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);//the lower hand
	pincer1();
	pincer2();
	glPopMatrix();
}
void hand_left()
{
	glPushMatrix();
	glRotatef(180, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, BODY_LOWER_RADIUS);
	glRotatef(-UPPERHAND_ANGLE, 0.0, 1.0, 0.0);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);  // the upper leg
	glTranslatef(0.0, 0.0, UPPERHAND_LENGTH);
	glRotatef(HAND_ANGLE, 0.0, 1.0, 0.0);
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);
	pincer1();
	pincer2();
	glPopMatrix();
}
void animal() {
	glTranslatef(-HEAD_HEIGHT - BODY_HEIGHT, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	head();
	glColor3f(0.0, 0.0, 0.0);
	eye_left();
	eye_right();

	glTranslatef(HEAD_HEIGHT, 0.0, 0.0);
	glColor3f(1.0, 0.3, 0.3); //un-saturated red
	body(BODY_LOWER_RADIUS, BODY_UP_RADIUS);
	hand_right();
	hand_left();

	for (i = 1; i < 4; i++) {
		glTranslatef(BODY_HEIGHT - 0.2, 0.0, 0.0);
		glColor3f(1.0, 0.3, 0.3);
		glRotatef(15, 0.0, 0.0, 1.0);
		body(BODY_LOWER_RADIUS - 0.1*i, BODY_UP_RADIUS - 0.1*i);
		leg_right(BODY_LOWER_RADIUS - 0.1*(i - 1), BODY_UP_RADIUS - 0.1*(i - 1));
		leg_left(BODY_LOWER_RADIUS - 0.1*(i - 1), BODY_UP_RADIUS - 0.1*(i - 1));
	}

	glTranslatef(BODY_HEIGHT - 0.2, 0.0, 0.0);
	glRotatef(15, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.3, 0.3);
	last_body(BODY_LOWER_RADIUS - 0.1*i, 0);
	leg_right(BODY_LOWER_RADIUS - 0.1*(i - 1), 0);
	leg_left(BODY_LOWER_RADIUS - 0.1*(i - 1), 0);

	glTranslatef(BODY_HEIGHT - 0.2, 0.0, 0.0);
	glRotatef(10, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.5, 0.3);
	tail1();
	tail2();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-1.0, 1.5, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//isometric look
	//gluLookAt(-1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	animal();


	glutSwapBuffers();
	glFlush();
}


void init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	p = gluNewQuadric();
}

void myreshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0, 640, 0.0, 480.0);
	if (w <= h) //When the window is streched in length, it eqauls to the viewing volume is streched in width
		glOrtho(LEFT, RIGHT, BOTTOM, UP* (GLfloat)h / (GLfloat)w, NEAR, FAR);//So we must strech the viewing volume in length to make it back to the original ratio of viewing volume(640*480). Now we should persist the smaller side (width), so that it would not exceeds the window, and strech the larger size according to the ratio.
	else  glOrtho(LEFT, RIGHT *
		(GLfloat)w / (GLfloat)h, BOTTOM, UP, NEAR, FAR);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lobster animated");
	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	glEnable(GL_DEPTH_TEST); /* Enable hidden-surface removal */
	init();
	glutMainLoop();
}

