//
//  Lab7.cpp
//  OpenGl Initialize
//
//  Created by 沈凌儿 on 2019/6/10.
//  Copyright © 2019 沈凌儿. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <glut.h>
#include <math.h>

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
#define CIRCLE_RADIUS 5.0       // The radius of circle trajectory.
#define JUMP 0.32                // The height of jump up and down


#define MOVE 0.02
#define CRAW 0.1
#define CRAW1 0.14
#define CRAW2 0.56

static GLfloat theta[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 };
static GLint axis = 5;
GLfloat Red = 1.0f;
GLfloat Zero = 0.0f;

// define material structure
typedef struct materialStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
} materialStruct;

// material templates
//Material Set 1: METAL WITH GOLDEN LUTSER

//1.156
materialStruct metalBody = {
	{Red, Zero, Zero, 1.0f},
	{Red*1.156f, Zero*1.156f, Zero*1.156f, 1.0f},
	{0.797357f, 0.723991f, 0.208006f, 1.0f},
	12.2f
};
//2.8125 transparent
materialStruct transTail = {
	{Red, Zero, Zero, 0.4f},
	{Red*2.8125f, Zero*2.8125f, Zero*2.8125f, 0.4f},
	{0.928281f, 0.855802f, 0.366065f, 0.4f},
	51.2f
};
//0.2941
materialStruct metalEye = {
	{0.05375f, 0.05f, 0.06625f, 0.82f},
	{0.18275f, 0.17f, 0.22525f, 0.82f},
	{0.332741f, 0.328634f, 0.346435f, 0.82f},
	38.4f
};
materialStruct metalHand = {
	{0.80f, 0.13f, 0.13f, 1.0f},
	{0.80f*0.5f, 0.13f*0.5f, 0.13f*0.5f, 1.0f},
	{0.6f, 0.6f, 0.208006f, 1.0f},
	12.2f
};
materialStruct metalLeg = {
	{0.3, 0.0, 0.0, 1.0},
	{0.6, 0.0, 0.0, 1.0},
	{0.8, 0.8, 0.4, 1.0},
	32.0
};

//Material Set 2: Plastic
materialStruct plasticBody = {
	{Red, Zero, Zero, 1.0f},
	{Red*2.368f, Zero*2.368f, Zero*2.368f, 1.0f},
	{0.992157f, 0.941176f, 0.807843f, 1.0f},
	27.8974f
};
materialStruct plasticEye = {
	{0.02f, 0.02f, 0.02f, 1.0f},
	{0.01f, 0.01f, 0.01f, 1.0f},
	{0.992157f, 0.941176f, 0.807843f, 1.0f},
	27.8974f
};
materialStruct plasticHand = {
	{0.7f, 0.13f, 0.13f, 1.0f},
	{0.7f*0.7f, 0.13f*0.7f, 0.13f*0.7f, 1.0f},
	{0.992157f, 0.941176f, 0.807843f, 1.0f},
	27.8974f
};
materialStruct plasticLeg = {
	{Red, Zero, Zero, 0.922f},
	{Red*0.25f, Zero*0.25f, Zero*0.25f, 0.922f},
	{0.992157f, 0.941176f, 0.807843f, 1.0f},
	27.8974f
};

//Materila Set 3: Transparent
//2.368

//1.156
materialStruct transBody = {
	{Red, Zero, Zero, 0.4f},
	{Red*1.156f, Zero*1.156f, Zero*1.156f, 0.4f},
	{0.797357f, 0.723991f, 0.208006f, 0.4f},
	51.2f
};

//0.2941
materialStruct transEye = {
	{0.05375f, 0.05f, 0.06625f, 0.4f},
	{0.18275f, 0.17f, 0.22525f, 0.4f},
	{0.332741f, 0.328634f, 0.346435f, 0.4f},
	38.4f
};
materialStruct transHand = {
	{0.80f, 0.13f, 0.13f, 0.4f},
	{0.80f*0.5f, 0.13f*0.5f, 0.13f*0.5f, 0.4f},
	{0.6f, 0.6f, 0.208006f, 0.4f},
	51.2f
};
materialStruct transLeg = {
	{0.3f, 0.0f, 0.0f, 0.4f},
	{0.6f, 0.0f, 0.0f, 0.4f},
	{0.8f, 0.8f, 0.4f, 0.4f},
	51.2f
};




//2
materialStruct materialBlackRubber = {
	{Red, Zero, Zero, 1.0f},
	{Red*2.0f, Zero*2.0f, Zero*2.0f, 1.0f},
	{0.4f, 0.4f, 0.4f, 1.0f},
	10.0f
};
//0.25
materialStruct materialPearl = {
	{Red, Zero, Zero, 0.922f},
	{Red*0.25f, Zero*0.25f, Zero*0.25f, 0.922f},
	{0.296648f, 0.296648f, 0.296648f, 0.922f},
	11.264f
};

// material of each part
materialStruct *mat_body;
materialStruct *mat_eye;
materialStruct *mat_tail;
materialStruct *mat_hand;
materialStruct *mat_leg;

//set lighting structure.
typedef struct lightingStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
} lightingStruct;

lightingStruct whiteLighting = {
	{0.0, 0.0, 0.0, 1.0},
	{1.0, 1.0, 1.0, 1.0},
	{1.0, 1.0, 1.0, 1.0}
};

// the position of the light
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

// to get material from the materials template
void getMaterial(materialStruct *material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material->ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material->diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material->specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &material->shininess);
}

//GLfloat theta[4] = {0.0, 0.0, 0.0,0.0};
GLfloat zigx = 0.0;
GLfloat zigy = 0.0;
GLboolean zig = GL_FALSE;
GLboolean crawl = GL_FALSE;
GLboolean  ro = GL_FALSE;
GLboolean  xisback = GL_FALSE;
GLboolean  yisback = GL_FALSE;
GLint menu_id = 0;
GLint zig_direction = 1;
GLint leg_direction = 1;
GLint subleg_direction = 1;
GLint hand_direction = 1;
GLint graphand_direction = 1;
GLint tail_direction = 1;
GLint i;



GLUquadricObj *p;   // pointer to quadric object

void eye_left() {
	getMaterial(mat_eye);
	glPushMatrix();
	glTranslatef(HEAD_HEIGHT / 2, 0.0, BODY_LOWER_RADIUS / 2);
	gluSphere(p, EYE_RADIUS, 50, 50);
	glPopMatrix();
}
void eye_right() {
	getMaterial(mat_eye);
	glPushMatrix();
	glTranslatef(HEAD_HEIGHT / 2, 0.0, -BODY_LOWER_RADIUS / 2);
	gluSphere(p, EYE_RADIUS, 50, 50);
	glPopMatrix();
}

void head()
{
	getMaterial(mat_body);
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(p, 0, BODY_LOWER_RADIUS, HEAD_HEIGHT, 15, 15);
	glPopMatrix();
}

void body(GLfloat lower, GLfloat upper)
{
	getMaterial(mat_body);
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(p, lower, upper, BODY_HEIGHT, 15, 15);
	glPopMatrix();
}
void last_body(GLfloat lower, GLfloat upper)
{
	getMaterial(mat_body);
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);;
	gluCylinder(p, lower, 0, BODY_HEIGHT, 15, 15);
	glPopMatrix();
}

void tail1() {
	getMaterial(mat_tail);
	glPushMatrix();
	glRotatef(theta[0], 0.0, 1.0, 0.0);//tail rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluPartialDisk(p, 0, DISK_OUTER, 30, 30, 35, 45);
	glPopMatrix();
}
void tail2() {
	getMaterial(mat_tail);
	glPushMatrix();
	glRotatef(-theta[0], 0.0, 1.0, 0.0);//tail rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluPartialDisk(p, 0, DISK_OUTER, 30, 30, 100, 45);
	glPopMatrix();
}

void leg_right(GLfloat lower, GLfloat upper)
{
	getMaterial(mat_leg);
	glPushMatrix();
	glRotatef(theta[0], 1.0, 0.0, 0.0);//leg rotation
	glRotatef(-LEG_ANGLE, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, upper);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERLEG_RADIUS, LOWERLEG_RADIUS, UPPERLEG_LENGTH, 15, 15);  // the upper leg
	glTranslatef(0.0, 0.0, UPPERLEG_LENGTH - 0.05);
	glRotatef(theta[1], 1.0, 0.0, 0.0);//sub-leg rotation
	glRotatef(LOWER_ANGLE, 1.0, 0.0, 0.0);
	gluCylinder(p, LOWERLEG_RADIUS, 0, LOWERLEG_LENGTH, 15, 15);//the lower leg.
	glPopMatrix();

}
void leg_left(GLfloat lower, GLfloat upper)
{
	getMaterial(mat_leg);
	glPushMatrix();
	glRotatef(-theta[0], 1.0, 0.0, 0.0);
	glRotatef(180 + LEG_ANGLE, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, upper);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERLEG_RADIUS, LOWERLEG_RADIUS, UPPERLEG_LENGTH, 15, 15);  // the upper leg
	glTranslatef(0.0, 0.0, UPPERLEG_LENGTH - 0.05);
	glRotatef(-theta[1], 1.0, 0.0, 0.0);
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
	getMaterial(mat_hand);
	glPushMatrix();
	glTranslatef(0.0, 0.0, BODY_LOWER_RADIUS);
	glRotatef(theta[2], 0.0, 1.0, 0.0);//hand rotation
	glRotatef(-UPPERHAND_ANGLE, 0.0, 1.0, 0.0);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);  // the upper hand
	glTranslatef(0.0, 0.0, UPPERHAND_LENGTH);
	glRotatef(HAND_ANGLE, 0.0, 1.0, 0.0);
	glRotatef(theta[4], 0.0, 1.0, 0.0);//sub-hand rotation
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);//the lower hand
	pincer1();
	pincer2();
	glPopMatrix();
}
void hand_left()
{
	getMaterial(mat_hand);
	glPushMatrix();
	glRotatef(180, 1.0, 0.0, 0.0);
	glRotatef(theta[2], 0.0, 1.0, 0.0);//hand rotation
	glTranslatef(0.0, 0.0, BODY_LOWER_RADIUS);
	glRotatef(-UPPERHAND_ANGLE, 0.0, 1.0, 0.0);
	glColor3f(0.8, 0.15, 0.15);//dark red
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);  // the upper leg
	glTranslatef(0.0, 0.0, UPPERHAND_LENGTH);
	glRotatef(HAND_ANGLE, 0.0, 1.0, 0.0);
	glRotatef(theta[4], 0.0, 1.0, 0.0);//sub-hand rotation
	gluCylinder(p, UPPERHAND_RADIUS, UPPERHAND_RADIUS, UPPERHAND_LENGTH, 15, 15);
	pincer1();
	pincer2();
	glPopMatrix();
}
void animal() {
	glTranslatef(-HEAD_HEIGHT - BODY_HEIGHT, 0.0, 0.0);
	//glRotatef(theta[0], 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	head();
	glColor3f(0.0, 0.0, 0.0);
	eye_left();
	eye_right();

	glTranslatef(HEAD_HEIGHT, 0.0, 0.0);
	//glRotatef(theta[1], 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.3, 0.3); //un-saturated red
	body(BODY_LOWER_RADIUS, BODY_UP_RADIUS);
	hand_right();
	hand_left();

	for (i = 1; i < 4; i++) {
		glTranslatef(BODY_HEIGHT - 0.2, 0.0, 0.0);
		//glRotatef(theta[1], 0.0, 0.0, 1.0);
		glColor3f(1.0, 0.3, 0.3);
		glRotatef(theta[3], 0.0, 0.0, 1.0);//body rotation.
		glRotatef(15, 0.0, 0.0, 1.0);
		body(BODY_LOWER_RADIUS - 0.1*i, BODY_UP_RADIUS - 0.1*i);
		leg_right(BODY_LOWER_RADIUS - 0.1*(i - 1), BODY_UP_RADIUS - 0.1*(i - 1));
		leg_left(BODY_LOWER_RADIUS - 0.1*(i - 1), BODY_UP_RADIUS - 0.1*(i - 1));
	}

	glTranslatef(BODY_HEIGHT - 0.2, 0.0, 0.0);
	glRotatef(15, 0.0, 0.0, 1.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	//glRotatef(theta[1], 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.3, 0.3);
	last_body(BODY_LOWER_RADIUS - 0.1*i, 0);
	leg_right(BODY_LOWER_RADIUS - 0.1*(i - 1), 0);
	leg_left(BODY_LOWER_RADIUS - 0.1*(i - 1), 0);

	glTranslatef(BODY_HEIGHT - 0.2, 0.0, 0.0);
	glRotatef(10, 0.0, 0.0, 1.0);
	//glRotatef(theta[1], 0.0, 0.0, 1.0);
	glColor4f(1.0, 0.3, 0.3, 0.5);
	tail1();
	tail2();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-1.0, 1.5, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//isometric look
	glRotatef(theta[5], 0.0, 1.0, 0.0);
	glTranslatef(-CIRCLE_RADIUS, JUMP*sin(0.25*theta[5]), 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	animal();

	glutSwapBuffers();
	glFlush();
}


void init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	p = gluNewQuadric();
	/* lighting settings */

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glLightfv(GL_LIGHT0, GL_AMBIENT, whiteLighting.ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLighting.diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteLighting.specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	//The default setting is metal material.
	mat_body = &metalBody;
	mat_tail = &transTail;
	mat_hand = &metalHand;
	mat_leg = &metalLeg;
	mat_eye = &metalEye;

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


void mymouse(GLint button, GLint state, GLint x, GLint y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (crawl == GL_FALSE && ro == GL_FALSE) {
			crawl = GL_TRUE;
			ro = GL_TRUE;
		}
		else {
			crawl = GL_FALSE;
			ro = GL_FALSE;
		}
	}
}

void idle()
{
	if (crawl) {
		if (leg_direction > 0) {
			theta[0] += CRAW1;
			if (theta[0] > 15) {
				leg_direction = -1;
				theta[0] -= CRAW1;
			}
		}
		else {
			theta[0] -= CRAW1;
			if (theta[0] < -15) {
				leg_direction = 1;
				theta[0] += CRAW1;
			}
		}

		if (subleg_direction > 0) {
			theta[1] += CRAW2;
			if (theta[1] > 30) {
				subleg_direction = -1;
				theta[1] -= CRAW2;
			}
		}
		else {
			theta[1] -= CRAW2;
			if (theta[1] < -30) {
				subleg_direction = 1;
				theta[1] += CRAW2;
			}
		}

		if (hand_direction > 0) {
			theta[2] += CRAW1;
			if (theta[2] > 10) {
				hand_direction = -1;
				theta[2] -= CRAW1;
			}
		}
		else {
			theta[2] -= CRAW1;
			if (theta[2] < -10) {
				hand_direction = 1;
				theta[2] += CRAW1;
			}
		}

		if (tail_direction > 0) {
			theta[3] += CRAW;
			if (theta[3] > 8) {
				tail_direction = -1;
				theta[3] -= CRAW;
			}
		}
		else {
			theta[3] -= CRAW;
			if (theta[3] < -8) {
				tail_direction = 1;
				theta[3] += CRAW;
			}
		}
		//the sub-hand should compensate the hand-angle to let the whole hand be straight, in order to grap something.
		if (graphand_direction > 0) {
			theta[4] += CRAW2;
			if (theta[4] > -HAND_ANGLE) {
				graphand_direction = -1;
				theta[4] -= CRAW2;
			}
		}
		else {
			theta[4] -= CRAW2;
			if (theta[4] < -20) {
				graphand_direction = 1;
				theta[4] += CRAW2;
			}
		}
	}
	//rotate around y-axis.
	if (ro) {
		theta[5] += 0.1;
		if (theta[5] > 360.0) theta[5] -= 360.0;

	}

	glutPostRedisplay();
}

void mymenu(int id)
{
	if (id == 1)
	{
		mat_body = &metalBody;
		mat_tail = &transTail;
		mat_hand = &metalHand;
		mat_leg = &metalLeg;
		mat_eye = &metalEye;
	}
	if (id == 2)
	{
		mat_body = &plasticBody;
		mat_tail = &transTail;
		mat_hand = &plasticHand;
		mat_leg = &plasticLeg;
		mat_eye = &plasticEye;

	}
	if (id == 3)
	{
		mat_body = &transBody;
		mat_tail = &transTail;
		mat_hand = &transHand;
		mat_leg = &transLeg;
		mat_eye = &transEye;

	}

}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lobster animated");
	glutMouseFunc(mymouse);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	glEnable(GL_DEPTH_TEST); /* Enable hidden-surface removal */
	init();
	menu_id = glutCreateMenu(mymenu);
	glutAddMenuEntry("Hard Shell With Golden Luster", 1);
	glutAddMenuEntry("Plastic", 2);
	glutAddMenuEntry("Transparent", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}







