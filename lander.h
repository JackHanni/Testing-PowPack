/*************************************************************
 * File: lander.h
 * Author: Kevin Foniciello
 *
 * Description: 
**************************************************************/

#define CRASH_FLAMES
#ifndef LANDER_H
#define LANDER_H

using namespace std;

#include "point.h"
#include "velocity.h"

/*****************************************
 * LANDER
 *
 *****************************************/
class Lander
{
   private:
      float x;
      float y;
      int fuel;
      bool alive;
      bool landed;
      Velocity velocity;
      Point p;

   public:
   // contructors
      Lander() : x(-150.0), y(150.0), alive(1), landed(0)
      {
         //setFuel(500);
         //setLanded(0);
         Velocity velocity;
         p.setX(x);
         p.setY(y);
      }

   // Getters
      int getFuel();
      Point getPoint() const;
      Velocity getVelocity() const;

   // Setters
      void setFuel(int);
      void setAlive(bool);
      void setLanded(bool);
      
      bool isAlive();
      bool isLanded();
      void applyGravity(float);
      void advance();
      bool canThrust();
      void applyThrustBottom();
      void applyThrustLeft();
      void applyThrustRight();
      void draw();
      void drawCrashFlames(const Point &);

};

#endif
