/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Kevin Foniciello
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#include "point.h"

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float y) : x(0.0), y(0.0), z(0.0)
{
  setX(x);
  setY(y);
  setZ(0.0);
}

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y,Z
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float y, float z) : x(0.0), y(0.0), z(0.0)
{
  setX(x);
  setY(y);
  setZ(z);
}

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
