/***********************************************************************
 * Header File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Kevin Fonciello
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#ifndef UI_DRAW_H
#define UI_DRAW_H

#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include "point.h"    // Where things are drawn
using std::string;

int generateGlList(int range);
void positionCamera(double x, double y, double z, double centerX, float smtg, double centerZ, float upX, float upY, float upZ);
void drawSphere(const Point & centerPt, double radius);
void createCheckerboard(const int width, const int depth, int displayListId);
void drawCheckerboard(int displayListId);

/************************************************************************
 * DRAW DIGIT
 * Draw a single digit in the old school line drawing style.  The
 * size of the glyph is 8x11 or x+(0..7), y+(0..10)
 *************************************************************************/
void drawDigit(const Point & topLeft, char digit);

/*************************************************************************
 * DRAW NUMBER
 * Display an integer on the screen using the 7-segment method
 *************************************************************************/
void drawNumber(const Point & topLeft, int number);

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 ************************************************************************/
void drawText(const Point & topLeft, const char * text);

/************************************************************************
 * DRAW LINE
 * Draw a line on the screen from the beginning to the end.
 *************************************************************************/
void drawLine(const Point & begin, const Point & end,
             float red = 1.0, float green = 1.0, float blue = 1.0);


/***********************************************************************
 * DRAW Lander
 * Draw a moon-lander spaceship on the screen at a given point
 ***********************************************************************/
void drawLander(const Point & point);

/***********************************************************************
 * DRAW Lander Flame
 * Draw the flames coming out of a moonlander for thrust
 ***********************************************************************/
void drawLanderFlames(const Point & point, 
                      bool bottom,
                      bool left,
                      bool right);

/******************************************************************
 * RANDOM
 * This function generates a random number.  The user specifies
 * The parameters 
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int    random(int    min, int    max);
double random(double min, double max);


#endif // UI_DRAW_H
