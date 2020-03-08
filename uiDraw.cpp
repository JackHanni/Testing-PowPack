/***********************************************************************
 * Source File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Kevin Foniciello
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#include <string>     // need you ask?
#include <sstream>    // convert an integer into text
#include <cassert>    // I feel the need... the need for asserts


#ifdef __APPLE__
//#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif // __APPLE__

#ifdef __linux__
//#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#endif // _WIN32

#include "point.h"
#include "uiDraw.h"

using namespace std;

///
int generateGlList(int range) { return glGenLists(range); }

///
void drawSphere(const Point & centerPt, double radius)
{
  GLfloat MAGENTA[] = {1, 0, 1};
  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, MAGENTA);
  glTranslated(centerPt.getX(), centerPt.getY(), centerPt.getZ());
  glutSolidSphere(radius, 30, 30);
  glPopMatrix();
}

///
void createCheckerboard(const int width, const int depth, int displayListId)
{
  GLfloat WHITE[] = {1, 1, 1};
  GLfloat RED[] = {1, 0, 0};
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

///
void drawCheckerboard(int displayListId)
{
  glCallList(displayListId);
}

/******************************************************************
 * RANDOM
 * This function generates a random number.  
 *
 *    INPUT:   min, max : The number of values (min <= num < max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

/******************************************************************
 * RANDOM
 * This function generates a random number.  
 *
 *    INPUT:   min, max : The number of values (min <= num < max)
 *    OUTPUT   <return> : Return the double
 ****************************************************************/
double random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   
   assert(min <= num && num <= max);

   return num;
}

#pragma clang diagnostic pop