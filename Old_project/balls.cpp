// This application shows balls bouncing on a checkerboard, with no respect
// for the laws of Newtonian Mechanics.  There's a little spotlight to make
// the animation interesting, and arrow keys move the camera for even more
// fun.

#define GRAVITY 9.807

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include <cmath>
#include <cstdlib> // for RNG lib
//#include <vector>
// using std::vector;
// using std::iterator;

#include "Camera.cpp"
#include "Point.cpp"
#include "Ball.cpp"

// Colors
GLfloat WHITE[] = {1, 1, 1};
GLfloat RED[] = {1, 0, 0};
GLfloat GREEN[] = {0, 1, 0};
GLfloat MAGENTA[] = {1, 0, 1};

// A checkerboard class.  A checkerboard has alternating red and white
// squares.  The number of squares is set in the constructor.  Each square
// is 1 x 1.  One corner of the board is (0, 0) and the board stretches out
// along positive x and positive z.  It rests on the xz plane.  I put a
// spotlight at (4, 3, 7).
class Checkerboard
{
  int displayListId;
  int width;
  int depth;

public:
  Checkerboard(int width, int depth) : width(width), depth(depth) {}
  double centerx() { return width / 2; }
  double centerz() { return depth / 2; }
  void create()
  {
    displayListId = glGenLists(1);
    glNewList(displayListId, GL_COMPILE);
    GLfloat lightPosition[] = {4, 3, 7, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    for (int x = 0; x < width - 1; x++)
    {
      for (int z = 0; z < depth - 1; z++)
      {
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (x + z) % 2 == 0 ? RED : WHITE);
        glVertex3d(x, 0, z);
        glVertex3d(x + 1, 0, z);
        glVertex3d(x + 1, 0, z + 1);
        glVertex3d(x, 0, z + 1);
      }
    }
    glEnd();
    glEndList();
  }
  void draw() { glCallList(displayListId); }
};

// Global variables: a camera, a checkerboard and some balls.
Checkerboard checkerboard(8, 8);
Camera camera;
Ball redBall = Ball(1,
                    RED,
                    /*height: */ 0,
                    /*lateral1: */ checkerboard.centerx(),
                    /*lateral2: */ checkerboard.centerz());
Ball greenBall = Ball(1,
                      GREEN,
                      /*height: */ 5,
                      /*lateral1: */ checkerboard.centerx(),
                      /*lateral2: */ checkerboard.centerz());
// std::vector<Ball> balls(1, Ball(1, GREEN, 6, 3, 8));
// balls.push_back(Ball(1, GREEN, 6, 3, 8));
// balls.push_back(Ball(1.5, MAGENTA, 6, 3, 2));
// balls.push_back(Ball(0.4, WHITE, 5, 1, 7));

// Application-specific initialization: Set up global lighting parameters
// and create display lists.
void
init()
{
  glEnable(GL_DEPTH_TEST);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
  glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  checkerboard.create();
}

// Draws one frame, the checkerboard then the balls, from the current camera
// position.
void
display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(camera.getX(),
            camera.getY(),
            camera.getZ(),
            checkerboard.centerx(),
            0.0,
            checkerboard.centerz(),
            0.0,
            1.0,
            0.0);
  checkerboard.draw();
  redBall.update(greenBall);
  greenBall.update(redBall);
  //  for(std::vector<Ball> :: iterator ballsIterator = balls.begin(); ballsIterator != balls.end();
  //  ++ballsIterator) {
  //    *ballsIterator.update();
  //  }
  glFlush();
  glutSwapBuffers();
}

// On reshape, constructs a camera that perfectly fits the window.
void
reshape(GLint w, GLint h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
  glMatrixMode(GL_MODELVIEW);
}

// Requests to draw the next frame.
void
timer(int v)
{
  glutPostRedisplay();
  glutTimerFunc(1000 / 60, timer, v);
}

// Moves the camera according to the key pressed, then ask to refresh the
// display.
void
special(int key, int, int)
{
  switch (key)
  {
    case GLUT_KEY_LEFT:
      camera.moveLeft();
      break;
    case GLUT_KEY_RIGHT:
      camera.moveRight();
      break;
    case GLUT_KEY_UP:
      camera.moveUp();
      break;
    case GLUT_KEY_DOWN:
      camera.moveDown();
      break;
  }
  glutPostRedisplay();
}

// Initializes GLUT and enters the main loop.
int
main(int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Bouncing Balls");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutTimerFunc(100, timer, 0);
  init();
  glutMainLoop();
}
