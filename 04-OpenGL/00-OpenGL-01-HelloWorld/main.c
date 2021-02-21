/*
 ============================================================================
 Name        : 00-Template.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <GL/glut.h>
#include <stdlib.h>

void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	{
		glVertex3f(0.5, 0.0, 0.5);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(0.0, 0.5, 0.0);
		glVertex3f(0.0, 0.0, 0.5);
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Hello World!");
	glutDisplayFunc(displayMe);
	glutMainLoop();

	return EXIT_SUCCESS;
}
