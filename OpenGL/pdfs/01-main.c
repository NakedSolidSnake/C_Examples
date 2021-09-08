#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLfloat v[4] = {1.0, 5.0, 9.0, 1.0};
GLint dt = 0, t = 0; 
GLboolean rotate = GL_FALSE;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_STRIP);

    glVertex3fv(&v[0]);
    glVertex3fv(&v[1]);
    glVertex3fv(&v[2]);
    glVertex3fv(&v[3]);

    glEnd();
    glutSwapBuffers();
}

void idle(void)
{
    t += dt;
    glutPostRedisplay();
}

void keyboard(char key, int x, int y)
{
    switch (key)
    {
    case 'q': case 'Q':
        exit(EXIT_SUCCESS);        
        break;

    case 'r': case 'R':
        rotate = GL_TRUE;
        break;
    
    default:
        break;
    }
}

int main(char *argc, char *argv[])
{
    int mode = GLUT_RGB | GLUT_DOUBLE;
    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}