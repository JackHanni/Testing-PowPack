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
    : topLeft(tl), bottomRight(br)
  {
    checkerboard.setDisplayListId(generateGlList(1));
    createCheckerboard(
        checkerboard.getWidth(), checkerboard.getDepth(), checkerboard.getDisplayListId());

    /// bottom left back
    boxLimits[0] = Point( (float)checkerboard.getWidth(), 0.0);
    /// bottom left front
    boxLimits[1] = Point( 0.0, 0.0);
    /// bottom right back
    boxLimits[2] = Point( (float)checkerboard.getWidth(), (float)checkerboard.getDepth());
    /// bottom right front
    boxLimits[3] = Point( 0.0, (float)checkerboard.getDepth());

///    Create 6 spheres in different places
    for (int i = 0; i < 6; ++i)
    {
      float radius = random(0.1, 0.5);
      Point point;
      switch (i) {
///        bottom center
        case 0:
          point = Point( (float)checkerboard.centerX(), 0.0, (float)checkerboard.centerZ());
          spheres.push_back(Sphere(0.3, &point));
          break;
///        "top" center
        case 1:
          point = Point( (float)checkerboard.centerX()+2.0, 5.0, (float)checkerboard.centerZ());
          spheres.push_back(Sphere(0.2, &point));
          break;
///        bottom left back
        case 2:
          spheres.push_back(Sphere(0.1, &boxLimits[0]));
          break;
///        Bottom left front
        case 3:
          spheres.push_back(Sphere(0.2, &boxLimits[1]));
          break;
///        bottom right back
        case 4:
          spheres.push_back(Sphere(0.3, &boxLimits[2]));
          break;
///        bottom right front
        case 5:
          spheres.push_back(Sphere(0.4, &boxLimits[3]));
          break;
      }

//      point( (float)(i == 1 ? checkerboard.centerX() + 0.01 : checkerboard.centerX()), (float)(i == 1 ? 5.0 : 0.5), (float)checkerboard.centerZ());
//      spheres.push_back(Sphere(0.1, &point));
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
  /// These are the corners delimiting where the spheres can be
  Point boxLimits[4];
  /// Spheres that are not moving anymore would be
  /// moved to the vector of halted Spheres.
  vector<Sphere> fallingSpheres;
  vector<Sphere> haltedSpheres;
  /// for the time being for the sake of testing
  /// one vector will suffice.
  vector<Sphere> spheres;
};

#endif /*SIMULATION_H*/
