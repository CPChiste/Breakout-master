#ifndef __BRICK_H
#define __BRICK_H

#include "Shape.h"
///Brick class
/**
   Inherits from the abstract Shape class
   Provides implementations for drawing a Square
   Computes its own boundary box for collision
*/

class Brick: public Shape
{
  private:
   Point origin; // position for the beginning of the brick drawing
   double length; // the length of the box
   double height; // the height of the box

public:
	/// initializing a square that can be animated
	/**
		 \param o the origin of the drawing, in pixels
		 \param s the speed vector, in pixels per second
		 \param _size a vector describing the length of all of the sides of the square
	 */
  Brick(Point o, double _length, double _height) : origin(o), length(_length), height(_height) {};
	void draw();

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif