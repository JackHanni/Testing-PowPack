/*************************************************************
 * File: simulation.cpp
 * Author: Kevin Foniciello
 *
 * Description: Contains the implementations of the
 *  method bodies for the simulation class.
 *************************************************************/

#include <iostream>
#include <vector>
using namespace std;
using std::vector;

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
  for (auto & sphere : spheres)
  {
    sphere.advance();
//    cout << sphere.getVelocity() << endl;
  }
/// Iterate forward
//  for (vector<Sphere>::iterator sphereIterator1 = spheres.begin(); sphereIterator1 != spheres.end();
//       ++sphereIterator1)
//  {
//    Sphere * sphere1 = &(*sphereIterator1);
//
//    if (((int)(sphere1->getPoint().getY())) <= 0)
//      continue;
//    else
//    {
//      sphere1->advance();
//    }

/// Iterate backward
//    for (vector<Sphere>::reverse_iterator sphereIterator2 = spheres.rbegin(); sphereIterator2 != spheres.rend();
//         ++sphereIterator2)
//    {
//      Sphere * sphere2 = &(*sphereIterator2);
//
//      if (((int)(sphere2->getPoint().getY())) <= 0 || sphere1 == sphere2)
//        continue;
//
//      if ((sphere1->isTouching(sphere2)))
//      {
//        sphere1->advance();
//      }
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
  //  for (auto & sphere : spheres)
  //    sphere.draw();
  for (vector<Sphere>::iterator sphereIterator = spheres.begin(); sphereIterator != spheres.end();
       ++sphereIterator)
  {
    Sphere * sphere = &(*sphereIterator);
    sphere->draw();
  }

  checkerboard.draw();
}
