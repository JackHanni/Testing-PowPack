//
// Created by happyPenguinMac on 06/03/20.
//

#include "Sphere.h"
#include "uiDraw.h"

bool Sphere::touching(Sphere ball)
{
  double x_diff = ball.get_point().getX();
  double y_diff = ball.get_point().getY();
  double z_diff = ball.get_point().getZ();
  double h = sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);

  return h <= radius + ball.get_radius();
}

/**
 * Updates the values of the Sphere
 */
void Sphere::advance() {
////    for(std::Ball :: iterator ball = balls.begin(); ball != balls.end(); ++ball) {
////        if (*it.get_point().getX)
//  if (touching(ball))
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