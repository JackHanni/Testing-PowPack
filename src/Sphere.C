//
// Created by happyPenguinMac on 06/03/20.
//

#include "../include/Sphere.h"
#include "../include/uiDraw.h"
#include "../include/myTools.h"

bool
Sphere::isTouching(Sphere * sphere)
{
  float x = abs(this->p.getX() - sphere->p.getX());
  float y = abs(this->p.getY() - sphere->p.getY());
  float z = abs(this->p.getZ() - sphere->p.getZ());
  float h = sqrt(sq(x) + sq(y) + sq(z));
  float radii = radius + sphere->radius;

  /// correct this sphere if h < sum of radii
  if (h < radii && isAbove(sphere))
  {
    float newY = sqrt(sq(radii) - sq(x) - sq(z)) + sphere->p.getY();
    p.setY(newY);
    print("here\n");
  }

  return h <= radii;
}

bool
Sphere::isAbove(Sphere * sphere)
{
  return this->p.getY() > sphere->p.getY();
}

/**
 * Updates the values of the Sphere
 */
void
Sphere::advance()
{
  velocity += acc * dt;
  p.setY(p.getY() + velocity * dt);
  if (p.getY() - radius <= 0)
  {
    p.setY(radius);
    velocity *= -.8;
  }
}


/**
 * Updates the UI for the Sphere
 */
void
Sphere::draw()
{
  drawSphere(p, radius);
}
