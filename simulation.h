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
#include "ground.h"
#include "lander.h"
#include "Camera.h"
#include "Sphere.h"
#include "Checkerboard.h"

#define FUEL        500    // initial fuel for the game

#define GRAVITY_AMOUNT 0.1

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Simulation
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
  Simulation(Point tl, Point br) : topLeft(tl), bottomRight(br), ground(Ground(topLeft, bottomRight))
   {
      // Set up the initial conditions of the game
      lander.setFuel(FUEL);
      checkerboard.setDisplayListId(generateGlList(1));
      createCheckerboard(checkerboard.getWidth(), checkerboard.getDepth(), checkerboard.getDisplayListId());
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
   
private:
   /*********************************************
    * Function: justLanded
    * Description: Returns true if the lander has
    *  just successfully landed.
    *********************************************/
   bool justLanded() const;
   
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   Ground ground;
   Lander lander;
   Sphere sphere;
   Camera camera;
   Checkerboard checkerboard;
   
};

#endif /*SIMULATION_H*/
