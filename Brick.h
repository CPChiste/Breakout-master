#ifndef __BRICK_H
#define __BRICK_H

#include "Shape.h"
#include <string>
///Brick class
/**
   Inherits from the abstract Shape class
   Provides implementations for drawing a Square
   Computes its own boundary box for collision
*/

class Brick: public Shape
{
  private:
   double length; // the length of the box
   double height; // the height of the box
   bool destroyed; // is brick destroyed?
   ALLEGRO_BITMAP *image; // image the brick uses
public:
	/// initializing a square that can be animated
	/**
	   \param o the origin of the drawing, in pixels
   	 \param s the speed vector, in pixels per second
   	  \param _size a vector describing the length of all of the sides of the square
	 */
  Brick(Point o, double l, double h, bool destroyed=false);

  /// returns true if the brick is destroyed
  bool isDestroyed();

  /// set the brick to destroyed if the brick was hit
  void setDestroyed(bool isHit);

  /// draws the brick at the location of origin
	void draw();
	
  /// returns all boundary boxes of the Brick - currently acts as a Rectangle
	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif
