#ifndef POWPACK_CAMERA_H
#define POWPACK_CAMERA_H

#include <cmath>

// A camera.  It moves horizontally in a circle centered at the origin of
// radius 10.  It moves vertically straight up and down.
class Camera
{
  double theta;  // determines the x and z positions
  double y;      // the current y position
  double dTheta; // increment in theta for swinging the camera around
  double dy;     // increment in y for moving the camera up/down
public:
  Camera() : theta(3), y(7), dTheta(0.04), dy(0.2) {}
//  ~Camera() {}
  double getX() { return 10 * cos(theta); }
  double getY() { return y; }
  double getZ() { return 10 * sin(theta); }
  void moveRight() { theta += dTheta; }
  void moveLeft() { theta -= dTheta; }
  void moveUp() { y += dy; }
  void moveDown()
  {
    if (y > dy)
      y -= dy;
  }
};

#endif // POWPACK_CAMERA_H
