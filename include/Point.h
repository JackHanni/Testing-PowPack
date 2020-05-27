/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Kevin Foniciello
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#ifndef POINT_H
#define POINT_H

#include <iostream>

/*********************************************
 * POINT
 * A single position.
 *********************************************/
class Point
{
public:
  //// constructors
  Point() : x(0.0), y(0.0), z(0.0) {}
  Point(float x, float z);
  Point(float x, float height, float z);

  //// getters
  float getX() const { return x; }
  float getY() const { return y; }
  float getZ() const { return z; }

  //// setters
  void setX(float x) { this->x = x; }
  void setY(float y) { this->y = y; }
  void setZ(float z) { this->z = z; }
  void addX(float dx) { x += + dx; }
  void addY(float dy) { y += + dy; }
  void addZ(float dz) { z += + dz; }

//  Point & operator = (const Point & rhs);

private:
  float x; //// width position
  float y; //// vertical position
  float z; //// depth position
};

//// stream I/O useful for debugging
std::ostream & operator<<(std::ostream & out, const Point & pt);
std::istream & operator>>(std::istream & in, Point & pt);

#endif /// POINT_H
