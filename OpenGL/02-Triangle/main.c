/*
 ============================================================================
 Name        : 00-Template.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define RED   0.5
#define GREEN 0.5
#define BLUE  0.5

void display(void)
{
	/* Clear window */
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	/* draw red triangle */
	glColor3d(RED, GREEN, BLUE);
	glBegin(GL_TRIANGLES);
	{
		glVertex2d(-1, -1);
		glVertex2d(1, -1);
		glVertex2d(0, 1);
	}
	glEnd();

	/* update screen */
	glFlush();
}

int main(int argc, char **argv) {

	/* GLut Init */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250,250);

	/* Create Window */
	glutCreateWindow("Simple");
	glutDisplayFunc(display);

	/* interact */
	glutMainLoop();

	return EXIT_SUCCESS;
}
