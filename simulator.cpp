/*************************************************************
 * File: simulation.cpp
 * Author: Kevin Foniciello
 *
 * Description: Contains the implementations of the
 *  method bodies for the simulation class.
 *************************************************************/

#include <iostream>
using std::cout;

#include "simulator.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

//******************************************
// * SIMULATION :: JUST LANDED
// * Did we land successfully?
// ******************************************/
//bool
//Simulator::justLanded() const
//{
//  bool landed = false;
//
//  Point platformCenter = ground.getPlatformPosition();
//  int width = ground.getPlatformWidth();
//
//  float xDiff = lander.getPoint().getX() - platformCenter.getX();
//  float yDiff = lander.getPoint().getY() - platformCenter.getY();
//
//  float margin = width / 2.0;
//
//  if (fabs(xDiff) < margin)
//  {
//    // between edges
//
//    if (yDiff < 4 && yDiff >= 0)
//    {
//      // right above it
//
//      if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
//      {
//        // we're there!
//        landed = true;
//      }
//    }
//  }
//
//  return landed;
//}

/***************************************
 * SIMULATION :: ADVANCE
 * advance the simulation one unit of time.
 * TODO: Advance all the spheres here (in a loop or something similar)
 ***************************************/
void
Simulator::advance()
{
  sphere.advance();
//  if (lander.isAlive() && !lander.isLanded())
//  {
//    // advance the lander
//    lander.applyGravity(GRAVITY_AMOUNT);
//    lander.advance();
//
//    // check for crash
//    if (!ground.isAboveGround(lander.getPoint()))
//    {
//      lander.setAlive(false);
//    }
//
//    // check for just landed
//    if (justLanded())
//    {
//      lander.setLanded(true);
//    }
//  }
}

/***************************************
 * SIMULATION :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void
Simulator::handleInput(const Interface & ui)
{
  if (ui.isUp())
  {
    ((Camera *)(ui.camera))->moveUp();
  }
  if (ui.isDown())
  {
//    lander.applyThrustBottom();
    ((Camera *)(ui.camera))->moveDown();
  }

  if (ui.isLeft())
  {
//    lander.applyThrustLeft();
    ((Camera *)(ui.camera))->moveLeft();
  }

  if (ui.isRight())
  {
//    lander.applyThrustRight();
    ((Camera *)(ui.camera))->moveRight();
  }
  reDraw();
}

/*********************************************
 * SIMULATION :: DRAW
 * Draw everything on the screen
 *********************************************/
void
Simulator::draw(const Interface & ui)
{
//  cout << "simulatorDraw()\n";
//  positionCamera(camera.getX(),camera.getY(),camera.getZ(),
//            checkerboard.centerx(),0.0,
//            checkerboard.centerz(),
//            0.0,1.0,0.0);
//  lander.draw();
  sphere.draw();

//  if (lander.isLanded())
//  {
//    drawText(Point(), "You have successfully landed!");
//  }
//
//  if (!lander.isAlive())
//  {
//    drawText(Point(), "You have crashed!");
//  }
//
//  if (lander.canThrust())
//  {
//    drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
//  }

//  Point fuelLocation;
//  fuelLocation.setX(topLeft.getX() + 5);
//  fuelLocation.setY(topLeft.getY() - 5);

//  drawNumber(fuelLocation, lander.getFuel());

  // draw ground
//  ground.draw();
  checkerboard.draw();
//  flush();
}
