/*****************************************************
 * File: Driver.cpp
 * Author: Kevin Foniciello
 *
 * Description: This file contains the main function
 *  that starts the simulation and the callback function
 *  that specifies what methods of the simulation class are
 *  called each time through the simulation loop.
 ******************************************************/

#include "simulation.h"
#include "uiInteract.h"

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void
callBack(const Interface * pUI, void * p)
{
  Simulation * pSimulation = (Simulation *)p;

  pSimulation->advance();
  pSimulation->handleInput(*pUI);
  pSimulation->draw(*pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the simulation and call the display engine.
 * That is all!
 *********************************/
int
main(int argc, char ** argv)
{
  Point topLeft(-400, 300);
  Point bottomRight(400, -300);

  Interface ui(argc, argv, "Powder Packing", topLeft, bottomRight);
  Simulation simulation(topLeft, bottomRight);
  ui.run(callBack, &simulation);

  return 0;
}
