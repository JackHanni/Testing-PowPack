/*************************************************************
 * File: simulation.cpp
 * Author: Kevin Foniciello
 *
 * Description: Contains the implementations of the
 *  method bodies for the simulation class.
 *************************************************************/

#include "simulator.h"

#include "uiInteract.h"

/***************************************
 * SIMULATION :: ADVANCE
 * advance the simulation one unit of time.
 * TODO: Advance all the spheres here (in a loop or something similar)
 ***************************************/
void
Simulator::advance()
{
  sphere.advance();
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
    ((Camera *)(ui.camera))->moveDown();
  }

  if (ui.isLeft())
  {
    ((Camera *)(ui.camera))->moveLeft();
  }

  if (ui.isRight())
  {
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
  sphere.draw();

  checkerboard.draw();
}
