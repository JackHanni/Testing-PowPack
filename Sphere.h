//
// Created by happyPenguinMac on 06/03/20.
//

#ifndef POWPACK_SPHERE_H
#define POWPACK_SPHERE_H

#include <cmath>

#include "point.h"

// A ball.  A ball has a radius, a color, and bounces up and down between
// a maximum height and the xz plane.  Therefore its x and z coordinates
// are fixed.  It uses a lame bouncing algorithm, simply moving up or
// down by 0.05 units at each frame.
class Sphere
{
private:
  float radius;
  Point p;
  float velocity;
  float acc;
  float dt;

public:
  Sphere() : acc(-1.0), dt(0.05), p(Point(0, 0, 0)), radius(1)
  {
    velocity = acc * dt;
  }
  Sphere(float r, Point * p) : radius(r)
  {
    acc = -1.0;
    dt = 0.05;
    velocity = acc * dt;
    this->p = *p;
  }

  float getRadius() { return radius; }
  Point getPoint() { return p; }

  bool touching(Sphere sphere);
  void advance();
  void draw();
};

#endif // POWPACK_SPHERE_H
