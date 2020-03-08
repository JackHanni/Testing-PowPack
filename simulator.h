/*************************************************************
 * File: simulation.h
 * Author: Kevin Foniciello
 *
 * Description: Contains the definition of the simulation class.
 *************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#ifdef __APPLE__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif // __APPLE__

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "Camera.h"
#include "Sphere.h"
#include "Checkerboard.h"


#define GRAVITY_AMOUNT 0.1

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Simulator
{
public:
  /*********************************************
   * Constructor
   * Initializes the game
   *********************************************/
   Simulator() {}
  Simulator(Point tl, Point br)
    : topLeft(tl), bottomRight(br) //, ground(Ground(topLeft, bottomRight))
  {
    checkerboard.setDisplayListId(generateGlList(1));
    createCheckerboard(
        checkerboard.getWidth(), checkerboard.getDepth(), checkerboard.getDisplayListId());
  }

  /*********************************************
   * Function: handleInput
   * Description: Takes actions according to whatever
   *  keys the user has pressed.
   *********************************************/
  void handleInput(const Interface & ui);

  /*********************************************
   * Function: advance
   * Description: Move everything forward one
   *  step in time.
   *********************************************/
  void advance();

  /*********************************************
   * Function: draw
   * Description: draws everything for the game.
   *********************************************/
  void draw(const Interface & ui);

  Checkerboard getCheckerboard() { return checkerboard; }

private:
  // The coordinates of the screen
  Point topLeft;
  Point bottomRight;

  Checkerboard checkerboard;
  Sphere sphere;
};

#endif /*SIMULATION_H*/
