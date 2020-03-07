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
  Point() : x(0.0), y(0.0) {}
  Point(bool check) : x(0.0), y(0.0) {}
  Point(float x, float y);
  //// alt constructors
  //  Point()            : x(0.0), y(0.0), z(0.0) {}
  //  Point(bool check)  : x(0.0), y(0.0), z(0.0) {}
  Point(float x, float y, float z);

  //// getters
  float getX() const { return x; }
  float getY() const { return y; }
  float getZ() const { return z; }

  //// setters
  void setX(float x);
  void setY(float y);
  void setZ(float Z);
  void addX(float dx) { setX(getX() + dx); }
  void addY(float dy) { setY(getY() + dy); }
  void addZ(float dz) { setZ(getZ() + dz); }

private:
  float x; //// width position
  float y; //// vertical position
  float z; //// depth position
};

//// stream I/O useful for debugging
std::ostream & operator<<(std::ostream & out, const Point & pt);
std::istream & operator>>(std::istream & in, Point & pt);

#endif // POINT_H
