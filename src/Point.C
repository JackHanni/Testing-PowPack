/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Kevin Foniciello
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#include "../include/Point.h"

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float z) : x(0.0), y(0.0), z(0.0)
{
  setX(x);
  setY(0.0);
  setZ(z);
}

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y,Z
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float height, float z) : x(0.0), y(0.0), z(0.0)
{
  setX(x);
  setY(height);
  setZ(z);
}

//Point & Point::operator = (const Point & rhs) {
//  if (this == &rhs)
//    return *this;
//  this->x = rhs.x;
//  this->y = rhs.y;
//  this->z = rhs.z;
//  return *this;
//}

/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream &
operator<<(std::ostream & out, const Point & pt)
{
  out << "(" << pt.getX() << ", " << pt.getY() << ", " << pt.getZ() << ")";
  return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream &
operator>>(std::istream & in, Point & pt)
{
  float x, y, z;
  in >> x >> y >> z;

  pt.setX(x);
  pt.setY(y);
  pt.setZ(z);

  return in;
}
