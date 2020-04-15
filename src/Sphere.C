//
// Created by happyPenguinMac on 06/03/20.
//

#include "../include/Sphere.h"
#include "../include/uiDraw.h"

bool Sphere::isTouching(Sphere * sphere)
{
  double x_diff = sphere->getPoint().getX();
  double y_diff = sphere->getPoint().getY();
  double z_diff = sphere->getPoint().getZ();
  double h = sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);

  return h <= radius + sphere->getRadius();
}

/**
 * Updates the values of the Sphere
 */
void Sphere::advance() {
  //// this code should be in Simulator::advance()
//  if (isTouching(ball))
//    acc = -0.5;
  velocity += acc * dt;
  p.setY(p.getY() + velocity * dt);
  if (p.getY() - radius < 0)
  {
    p.setY(radius);
    velocity *= -.8;
  }
}

/**
 * Updates the UI for the Sphere
 */
void Sphere::draw() {
  drawSphere(p, radius);
}
