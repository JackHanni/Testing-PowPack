/*************************************************************
 * File: simulation.h
 * Author: Kevin Foniciello
 *
 * Description: Contains the definition of the Simulator class.
 *************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#ifdef __APPLE__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif // __APPLE__

#include <vector>
using std::vector;

#include "uiDraw.h"
#include "Interface.h"
#include "Point.h"
#include "Camera.h"
#include "Sphere.h"
#include "Checkerboard.h"

#define GRAVITY_AMOUNT 0.1

/*****************************************
 * GAME
 * The main simulator class containing all the state
 *****************************************/
class Simulator
{
public:
  /*********************************************
   * Constructor
   * Initializes the simulator
   *********************************************/
  Simulator() {}
  Simulator(Point tl, Point br)
    : topLeft(tl), bottomRight(br) //, ground(Ground(topLeft, bottomRight))
  {
    checkerboard.setDisplayListId(generateGlList(1));
    createCheckerboard(
        checkerboard.getWidth(), checkerboard.getDepth(), checkerboard.getDisplayListId());

    for (int i = 0; i < 2; ++i)
    {
      Point point( (float)checkerboard.centerX(), (float)(i == 1 ? 5.0 : 0.5), (float)checkerboard.centerZ());
      spheres.push_back(Sphere(0.5, &point));
    }
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
   * Description: draws everything for the simulation.
   *********************************************/
  void draw(const Interface & ui);

  Checkerboard getCheckerboard() { return checkerboard; }

private:
  // The coordinates of the screen
  Point topLeft;
  Point bottomRight;

  Checkerboard checkerboard;
  /// Spheres that are not moving anymore would be
  /// moved to the vector of halted Spheres.
  vector<Sphere> fallingSpheres;
  vector<Sphere> haltedSpheres;
  /// for the time being for the sake of testing
  /// one vector will suffice.
  vector<Sphere> spheres;
};

#endif /*SIMULATION_H*/
