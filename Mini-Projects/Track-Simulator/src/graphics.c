#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdbool.h>
#include <context.h>

static Context *_context = NULL;

static void render(void);
static void update(void);
static void colision(void);
static void looping(int value);

bool is_inside(Track *track, Volume *volume);
bool is_inside_airspace(Track *track, Airspace *airspace);
void reset_track_position(Track *track);
void reset_track_position(Track *track);

static bool GL_Init(void)
{
    bool status = true;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800, 600, 0.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
        status = false;

    return status;

}

bool Graphics_Init(int argc, char *argv[])
{
    bool status = false;

    glutInit(&argc, argv);

    glutInitContextVersion(2, 1);

    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Airspace");

    do 
    {
        if(GL_Init() == false)
            break;

        glutDisplayFunc(render);

        glutTimerFunc(1000 / 60, looping, 0);

        status = true;
    } while (false);    

    return status;
}

bool Graphics_Run(void *context)
{
    _context = (Context *)context;
    glutMainLoop();
    return false;
}

static void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(800 / 2.f, 600 / 2.f, 0.f);
    Airspace *airspace = &_context->airspace;

    //draw airspace
    glBegin(GL_QUADS);
        glColor3f( 1.f, 1.f, 1.f );
        glVertex2f( airspace->points[0].x, airspace->points[0].y );
        glVertex2f( airspace->points[1].x, airspace->points[1].y );
        glVertex2f( airspace->points[2].x, airspace->points[2].y );
        glVertex2f( airspace->points[3].x, airspace->points[3].y );

    glEnd();


    Volume *volume = &_context->volume;
    //draw Volume
    glBegin(GL_QUADS);
        glColor3f( 1.f, 0.f, 0.f );
        glVertex2f(volume->points[0].x, volume->points[0].y);
        glVertex2f(volume->points[1].x, volume->points[1].y);
        glVertex2f(volume->points[2].x, volume->points[2].y);
        glVertex2f(volume->points[3].x, volume->points[3].y);

    glEnd();

    Track *track = &_context->track;
    // draw aircraft
    glBegin(GL_QUADS);
        if(_context->is_inside_airspace)
        {
            if(_context->is_a_colision)
                glColor3f( 1.f, 1.f, 0.f );
            else 
                glColor3f( 0.f, 1.f, 0.f );
        }
        else 
        {
            reset_track_position(&_context->track);
        }

        
        glVertex2f( track->position.x + (-2.f), track->position.y + (-2.f) );
        glVertex2f( track->position.x + 2.f   , track->position.y + (-2.f));
        glVertex2f( track->position.x + 2.f   , track->position.y + 2.f );
        glVertex2f( track->position.x + (-2.f), track->position.y + 2.f );
    glEnd();

    glutSwapBuffers();
}

static void update(void)
{
    _context->track.position.x += 0.1;    
}

static void colision(void)
{
    _context->is_a_colision = is_inside(&_context->track, &_context->volume);
    _context->is_inside_airspace = is_inside_airspace(&_context->track, &_context->airspace);  
}

static void looping(int value)
{
    update();
    colision();
    render();

    glutTimerFunc(1000 / 60, looping, value);
}


bool is_inside(Track *track, Volume *volume)
{
    bool ret = false;
    if( track->position.x >= volume->points[0].x &&
        track->position.x <= volume->points[2].x &&
        track->position.y >= volume->points[0].y &&
        track->position.y <= volume->points[2].y)
        ret = true;

    return ret;
}

bool is_inside_airspace(Track *track, Airspace *airspace)
{
    bool ret = false;
    if( track->position.x >= airspace->points[0].x &&
        track->position.x <= airspace->points[1].x &&
        track->position.y >= airspace->points[0].y &&
        track->position.y <= airspace->points[2].y)
        ret = true;

    return ret;
}

void reset_track_position(Track *track)
{
    track->position = track->initial_position;
}

