#ifndef __BRICKGENERATOR_H
#define __BRICKGENERATOR_H

#include "Brick.h"
#include "ShapeSimulator.h"
#include <stdio.h>
#include <stdlib.h>

class BrickGenerator
{
  protected:
   int width, height; //width and height of the window
   int randomGrid[10][10];
  public:
   ///Constructor to get the dimensions of the play field
   /**
      \param _width width of the play field
      \param _height height of the ply field
   */
  BrickGenerator(int _width, int _height) : width(_width), height(_height) {};
   ///Generate bricks randomly on the top 50% of the play field
   /**
      \param sim reference to ShapeSimulator object to add bricks to for animation and drawing
      \return reference to ShapeSimulator object containing the randomly generated bricks
   */
   ShapeSimulator& generateBricks(ShapeSimulator& sim);
};

#endif
