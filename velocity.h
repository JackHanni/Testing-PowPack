/*************************************************************
 * File: velocity.h
 * Author: Kevin Foniciello
 *
 * Description: 
**************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

using namespace std;

/*****************************************
 * VELOCITY
 *
 *****************************************/
class Velocity
{
   private:
      float dx;
      float dy;

   public:
   // Getters
      float getDx();
      float getDy();
  
   // Setters
      void setDx(float);
      void setDy(float);

   // Constructors
      Velocity()
      {
         dx = 0.0;
         dy = 0.0; 
      }

      Velocity(float dx, float dy)
      {
      }

};

#endif
