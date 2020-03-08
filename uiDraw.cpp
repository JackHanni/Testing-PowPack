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
//#include <time.h>     // for clock


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

/*********************************************
 * NUMBER OUTLINES
 * We are drawing the text for score and things
 * like that by hand to make it look "old school."
 * These are how we render each individual character.
 * Note how -1 indicates "done".  These are paired
 * coordinates where the even are the x and the odd
 * are the y and every 2 pairs represents a point
 ********************************************/
const char NUMBER_OUTLINES[10][20] =
{
  {0, 0,  7, 0,   7, 0,  7,10,   7,10,  0,10,   0,10,  0, 0,  -1,-1, -1,-1},//0
  {7, 0,  7,10,  -1,-1, -1,-1,  -1,-1, -1,-1,  -1,-1, -1,-1,  -1,-1, -1,-1},//1
  {0, 0,  7, 0,   7, 0,  7, 5,   7, 5,  0, 5,   0, 5,  0,10,   0,10,  7,10},//2
  {0, 0,  7, 0,   7, 0,  7,10,   7,10,  0,10,   4, 5,  7, 5,  -1,-1, -1,-1},//3
  {0, 0,  0, 5,   0, 5,  7, 5,   7, 0,  7,10,  -1,-1, -1,-1,  -1,-1, -1,-1},//4
  {7, 0,  0, 0,   0, 0,  0, 5,   0, 5,  7, 5,   7, 5,  7,10,   7,10,  0,10},//5
  {7, 0,  0, 0,   0, 0,  0,10,   0,10,  7,10,   7,10,  7, 5,   7, 5,  0, 5},//6
  {0, 0,  7, 0,   7, 0,  7,10,  -1,-1, -1,-1,  -1,-1, -1,-1,  -1,-1, -1,-1},//7
  {0, 0,  7, 0,   0, 5,  7, 5,   0,10,  7,10,   0, 0,  0,10,   7, 0,  7,10},//8
  {0, 0,  7, 0,   7, 0,  7,10,   0, 0,  0, 5,   0, 5,  7, 5,  -1,-1, -1,-1} //9
};

int generateGlList(int range) { return glGenLists(range); }

void positionCamera(double x, double y, double z, double centerX, float centerY, double centerZ, float upX, float upY, float upZ) {
  gluLookAt(x, y, z, centerX, centerY, centerZ, upX, upY, upZ);
}

void drawSphere(const Point & centerPt, double radius)
{
  GLfloat MAGENTA[] = {1, 0, 1};
  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, MAGENTA);
  glTranslated(centerPt.getX(), centerPt.getY(), centerPt.getZ());
  glutSolidSphere(radius, 30, 30);
  glPopMatrix();
}

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

void drawCheckerboard(int displayListId)
{
  glCallList(displayListId);
}


/************************************************************************
 * DRAW DIGIT
 * Draw a single digit in the old school line drawing style.  The
 * size of the glyph is 8x11 or x+(0..7), y+(0..10)
 *   INPUT  topLeft   The top left corner of the character
 *          digit     The digit we are rendering: '0' .. '9'
 *************************************************************************/
void drawDigit(const Point & topLeft, char digit)
{
   // we better be only drawing digits
   assert(isdigit(digit));
   if (!isdigit(digit))
      return;

   // compute the row as specified by the digit
   int r = digit - '0';
   assert(r >= 0 && r <= 9);

   // go through each segment.
   for (int c = 0; c < 20 && NUMBER_OUTLINES[r][c] != -1; c += 4)
   {
      assert(NUMBER_OUTLINES[r][c    ] != -1 &&
             NUMBER_OUTLINES[r][c + 1] != -1 &&
             NUMBER_OUTLINES[r][c + 2] != -1 &&
             NUMBER_OUTLINES[r][c + 3] != -1);

      //Draw a line based off of the num structure for each number
      Point start;
      start.setX(topLeft.getX() + NUMBER_OUTLINES[r][c]);
      start.setY(topLeft.getY() - NUMBER_OUTLINES[r][c + 1]);
      Point end;
      end.setX(topLeft.getX() + NUMBER_OUTLINES[r][c + 2]);
      end.setY(topLeft.getY() - NUMBER_OUTLINES[r][c + 3]);
         
      drawLine(start, end);
   }
}

/*************************************************************************
 * DRAW NUMBER
 * Display an integer on the screen using the 7-segment method
 *   INPUT  topLeft   The top left corner of the character
 *          digit     The digit we are rendering: '0' .. '9'
 *************************************************************************/
void drawNumber(const Point & topLeft, int number)
{
   // our cursor, if you will. It will advance as we output digits
   Point point = topLeft;
   
   // is this negative
   bool isNegative = (number < 0);
   number *= (isNegative ? -1 : 1);
   
   // render the number as text
   ostringstream sout;
   sout << number;
   string text = sout.str();

   // handle the negative
   if (isNegative)
   {
      glBegin(GL_LINES);
      glVertex2f(point.getX() + 1, point.getY() - 5);
      glVertex2f(point.getX() + 5, point.getY() - 5);
      glEnd();
      point.addX(11);
   }
   
   // walk through the text one digit at a time
   for (const char *p = text.c_str(); *p; p++)
   {
      assert(isdigit(*p));
      drawDigit(point, *p);
      point.addX(11);
   }
}


/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/
void drawText(const Point & topLeft, const char * text)
{
   void *pFont = GLUT_BITMAP_HELVETICA_12;  // also try _18

   // prepare to draw the text from the top-left corner
   glRasterPos2f(topLeft.getX(), topLeft.getY());

   // loop through the text
   for (const char *p = text; *p; p++)
      glutBitmapCharacter(pFont, *p);
}

/************************************************************************
 * DRAW LINE
 * Draw a line on the screen from the beginning to the end.
 *   INPUT  begin     The position of the beginning of the line
 *          end       The position of the end of the line
 *************************************************************************/
void drawLine(const Point & begin, const Point & end,
              float red, float green, float blue)
{
   // Get ready...
   glBegin(GL_LINES);
   glColor3f(red, green, blue);

   // Draw the actual line
   glVertex2f(begin.getX(), begin.getY());
   glVertex2f(  end.getX(),   end.getY());

   // Complete drawing
   glColor3f(1.0 /* red % */, 1.0 /* green % */, 1.0 /* blue % */);
   glEnd();
}

/***********************************************************************
 * DRAW Lander
 * Draw a moon-lander spaceship on the screen at a given point
 ***********************************************************************/
void drawLander(const Point & point)
{
   // ultra simple point
   struct PT
   {
      int x;
      int y;
   } points[] = 
   {
      {-6, 0}, {-10,0}, {-8, 0}, {-8, 3},  // left foot
      {-5, 4}, {-5, 7}, {-8, 3}, {-5, 4},  // left leg
      {-1, 4}, {-3, 2}, { 3, 2}, { 1, 4}, {-1, 4}, // bottom
      { 5, 4}, { 5, 7}, {-5, 7}, {-3, 7},  // engine square
      {-6,10}, {-6,13}, {-3,16}, { 3,16},   // left of habitat
      { 6,13}, { 6,10}, { 3, 7}, { 5, 7},   // right of habitat
      { 5, 4}, { 8, 3}, { 5, 7}, { 5, 4},  // right leg
      { 8, 3}, { 8, 0}, {10, 0}, { 6, 0}   // right foot
   };

   // draw it
   glBegin(GL_LINE_STRIP);
   for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++)
        glVertex2f(point.getX() + points[i].x,
                   point.getY() + points[i].y);

   // complete drawing
   glEnd();
   
   
}


/***********************************************************************
 * DRAW Lander Flame
 * Draw the flames coming out of a moonlander for thrust
 ***********************************************************************/
void drawLanderFlames(const Point & point, 
                      bool bottom,
                      bool left,
                      bool right)
{
   // simple point
   struct PT
   {
      int x;
      int y;
   };

   int iFlame = random(0, 3);  // so the flame flickers
   
   // draw it
   glBegin(GL_LINE_LOOP);
   glColor3f(1.0 /* red % */, 0.0 /* green % */, 0.0 /* blue % */);
   
   // bottom thrust
   if (bottom)
   {
      PT points[3][3] =
      {
         { {-5,  -6}, { 0, -1}, { 3, -10} },
         { {-3,  -6}, {-1, -2}, { 0, -15} },
         { { 2, -12}, { 1,  0}, { 6,  -4} }
      };
      
      glVertex2f(point.getX() - 2, point.getY() + 2);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                   point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() + 2, point.getY() + 2);
   }

   // right thrust
   if (right)
   {
      PT points[3][3] =
      {
         { {10, 14}, { 8, 12}, {12, 12} },
         { {12, 10}, { 8, 10}, {10,  8} },
         { {14, 11}, {14, 11}, {14, 11} }
      };
      
      glVertex2f(point.getX() + 6, point.getY() + 12);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                    point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() + 6, point.getY() + 10);
   }

   // left thrust
   if (left)
   {
      PT points[3][3] =
      {
         { {-10, 14}, { -8, 12}, {-12, 12} },
         { {-12, 10}, { -8, 10}, {-10,  8} },
         { {-14, 11}, {-14, 11}, {-14, 11} }
      };
      
      glVertex2f(point.getX() - 6, point.getY() + 12);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                    point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() - 6, point.getY() + 10);
   }

   glColor3f(1.0 /* red % */, 1.0 /* green % */, 1.0 /* blue % */);
   glEnd();
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