/*************************************************************
 * File: lander.cpp
 * Author: Kevin Foniciello
 *
 * Description: 
 *************************************************************/

#include <cassert>

#include "lander.h"
#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

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
