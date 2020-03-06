/*************************************************************
 * File: lander.cpp
 * Author: Kevin Foniciello
 *
 * Description: 
 *************************************************************/

#include <iostream>
#include <cassert>

#include "lander.h"
#include "uiDraw.h"
#include "game.h"
#include "point.h"
#include "velocity.h"

#ifdef CRASH_FLAMES

#ifdef __APPLE__
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#endif // _WIN32

#endif // CRASH_FLAMES

using namespace std;

/******************************************
 * LANDER :: GET FUEL
 * gets the amount of fuel
 ******************************************/
int Lander :: getFuel()
{
   return fuel;
}

/******************************************
 * LANDER :: GET POINT 
 * accesses point p
 ******************************************/
Point Lander :: getPoint() const
{
   return p;
}

/******************************************
 * LANDER :: GET VELOCITY
 * accesses velocity
 ******************************************/
Velocity Lander :: getVelocity() const
{
   return velocity;
}

/******************************************
 * LANDER :: SET FUEL
 * sets fuel
 ******************************************/
void Lander :: setFuel(int fuel)
{
   assert(fuel >= 0);
   this->fuel = fuel;
}

/******************************************
 * LANDER :: SET ALIVE
 * sets alive
 ******************************************/
void Lander :: setAlive(bool alive)
{
   this->alive = alive;
}

/******************************************
 * LANDER :: SET LANDED
 * sets landed
 ******************************************/
void Lander :: setLanded(bool landed)
{
   this->landed = landed;
}

/******************************************
 * LANDER :: IS ALIVE
 * returns either true or false
 ******************************************/
bool Lander :: isAlive()
{
   return alive;//(alive ? 0 : 1);
}

/******************************************
 * LANDER :: IS LANDED
 * returns either true or false
 ******************************************/
bool Lander :: isLanded()
{
   return landed;
}

/******************************************
 * LANDER :: APPLY GRAVITY
 * Applies gravity to y coordinate on the
 * velocity of lander
 ******************************************/
void Lander :: applyGravity(float gravity)
{
   if (!isLanded())
      velocity.setDy(velocity.getDy() - gravity);
}

/******************************************
 * LANDER :: ADVANCE
 * moves the lander to the new coordinate
 * after modifying the old one apply gravity
 * and thrusts if applicable.
 ******************************************/
void Lander :: advance()
{
   p.addX(velocity.getDx());
   p.addY(velocity.getDy());
}

/******************************************
 * LANDER :: CAN THRUST
 * Checks fuel for compatbility to thrust
 ******************************************/
bool Lander :: canThrust()
{
   if (landed)
      return 0;
   else
      return (alive ? fuel > 0 : 0);
   //return (fuel <= 0 ? 0 : 1);
}

/******************************************
 * LANDER :: APPLY THRUST BOTTOM 
 * Applies thrust if still alive of their
 * remains fuel
 ******************************************/
void Lander :: applyThrustBottom()
{
   if (canThrust() && fuel > 2 && alive)// && !landed)
   {
      setFuel(fuel - 3);
      velocity.setDy(velocity.getDy() + 0.3);
   }
}

/******************************************
 * LANDER :: APPLY THRUST LEFT
 * Applies thrust if still alive of their
 * remains fuel
 ******************************************/
void Lander :: applyThrustLeft()
{
   if (canThrust() && alive)// && !landed)
   {
      setFuel(fuel - 1);
      velocity.setDx(velocity.getDx() + 0.1);
   }
}

/******************************************
 * LANDER :: APPLY THRUST RIGHT
 * Applies thrust if still alive of their
 * remains fuel
 ******************************************/
void Lander :: applyThrustRight()
{
   if (canThrust() && alive)// && !landed)
   {
      setFuel(fuel - 1);
      velocity.setDx(velocity.getDx() - 0.1);
   }
}

/******************************************
 * LANDER :: DRAW
 * Draws the lander at point(-150, 150)
 ******************************************/
void Lander :: draw()
{
   drawLander(p);
}

#ifdef CRASH_FLAMES

/******************************************
 * LANDER DRAW CRASH FLAMES
 * Draw the flames coming out of lander
 *  when crashes
 ******************************************/
void Lander :: drawCrashFlames(const Point & point)
{
   //cout << "CRASH_FLAMES not defined ";
   // simple point
   struct PT
   {
      int x;
      int y;
   };

   int iFlame = random(0, 3);  // so the flame flickers
   
   // draw it
   glBegin(GL_LINE_LOOP);
      
   // bottom flames
   if (1)
   {
      glColor3f(0.0 /* red % */, 0.0 /* green % */, 1.0 /* blue % */);
      PT points[3][3] =
      {
         { {-5,   6}, { 0,  1}, { 3,  10} },
         { {-3,   6}, {-1,  2}, { 0,  15} },
         { { 2,  12}, { 1,  0}, { 6,   4} }
      };
      
      glVertex2f(point.getX() - 2, point.getY() + 2);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                   point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() + 2, point.getY() + 2);
   }

   // top right flames
   if (1)
   {
      glColor3f(0.94 /* red % */, 0.65 /* green % */, 0.06 /* blue % */);
      PT points[3][3] =
      {
         { { 0, 30}, { 2, 18}, { 2, 21} },
         { { 4, 21}, { 4, 18}, { 6, 20} },
         { { 3, 23}, { 3, 23}, { 3, 23} }
      };
      
      glVertex2f(point.getX(), point.getY() + 20);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                    point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() + 6, point.getY() + 10);
   }

   // top left flames
   if (1)
   {
      glColor3f(0.94 /* red % */, 0.65 /* green % */, 0.06 /* blue % */);
      PT points[3][3] =
      {
         { {  0, 30}, { -2, 18}, { -2, 21} },
         { { -4, 21}, { -4, 18}, { -6, 20} },
         { { -3, 23}, { -3, 23}, { -3, 23} }
      };
      
      glVertex2f(point.getX(), point.getY() + 18);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                    point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() - 6, point.getY() + 10);
   }

   glColor3f(1.0 /* red % */, 1.0 /* green % */, 1.0 /* blue % */);
   glEnd();
}

#endif
