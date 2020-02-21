#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>

struct Point
{
   float x;
   float y;
   float z;
};

class Sphere
{
   private:
      float radius;
      static float density;
      static float totalMass;
      static int sphereCount;
      Point p;
      float mass;
   public:
      float calculateVolume();
      bool isTouching();
};

#endif
