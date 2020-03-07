//
// Created by happyPenguinMac on 06/03/20.
//

#ifndef POWPACK_SPHERE_H
#define POWPACK_SPHERE_H

//#ifdef __APPLE_CC__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif
#include <cmath>

#include "point.cpp"

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
  Sphere(float r, float * c, float y, float x, float z) : radius(r)
  {
    acc = -1.0;
    dt = 0.05;
    p.setX(x);
    p.setY(y);
    p.setZ(z);
  }

  float get_radius() { return radius; }
  Point get_point() { return p; }

  bool touching(Sphere ball);
  void advance();
  void draw();
};

#endif // POWPACK_SPHERE_H
