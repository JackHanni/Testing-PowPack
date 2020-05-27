#ifndef POWPACK_CHECKERBOARD_H
#define POWPACK_CHECKERBOARD_H

#include "uiDraw.h"
// A checkerboard class.  A checkerboard has alternating red and white
// squares.  The number of squares is set in the constructor.  Each square
// is 1 x 1.  One corner of the board is (0, 0) and the board stretches out
// along positive x and positive z.  It rests on the xz plane.  I put a
// spotlight at (4, 3, 7).
class Checkerboard
{
  float displayListId;
  float width;
  float depth;

public:
  Checkerboard() : width(8), depth(8) {}
  Checkerboard(float width, float depth) : width(width), depth(depth) {}
  float centerX() { return width / 2; }
  float centerZ() { return depth / 2; }

  float getDisplayListId() const { return displayListId; }
  void setDisplayListId(int dlID) { displayListId = dlID; }
  float getWidth() const { return width; }
//  void setWidth(int width) { Checkerboard::width = width; }
  float getDepth() const { return depth; }
//  void setDepth(int depth) { Checkerboard::depth = depth; }

  void draw() { drawCheckerboard(displayListId); }
};

#endif // POWPACK_CHECKERBOARD_H
