/*****************************************************
 * File: Driver.cpp
 * Author: Kevin Foniciello
 *
 * Description: This file contains the main function
 *  that starts the simulation and the callback function
 *  that specifies what methods of the simulation class are
 *  called each time through the simulation loop.
 ******************************************************/

#include "../include/Simulator.h"
#include "../include/Camera.h"
#include "../include/Interface.h"

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
  Simulator * pSimulator = (Simulator *)p;

  pSimulator->advance();
  pSimulator->handleInput(*pUI);
  pSimulator->draw(*pUI);
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
  Simulator simulator(topLeft, bottomRight);
  Camera camera;
  ui.run(callBack, &simulator, &camera);

  return 0;
}
