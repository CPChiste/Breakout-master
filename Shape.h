#ifndef __SHAPE_H
#define __SHAPE_H

#include "2DGeom.h"

/// generic Shape class.
/**
 It is aware of its bounding box, it contains a speed vector, and is
 responsible with collision with the window sides
 */
class Shape {
 protected:
  Point origin; // the origin of the shape
  Vector speed; // speed in pixels per sec

  /** private default constructor forces the explicit constructor to
      be used
  */
  Shape() {};

 public:
  /// this constructor must be called by every child shape to enable
  /// animation and handling collision 
  /**
     \param o the origin of the shape; drawing is done relative to
     this point. It is chosen in child classes in such a way that
     drawing is simple. 
     \param s the speed vector in pixels per second
   */
  Shape(Point o, Vector s);

	/// destructor must be virtual
	virtual ~Shape() {}

  /// called to update the position of the shape; responsible for
  /// collisions
  /**
     \param dt the time in seconds since the most recent update
     \param minx the minimum x coordinate of the window inside which
     the shape bounces, in pixels
     \param miny the minimum y coordinate of the window inside which
     the shape bounces, in pixels
     \param maxx the maximum x coordinate of the window inside which
     the shape bounces, in pixels
     \param maxy the maximum y coordinate of the window inside which
     the shape bounces, in pixels
   */
  void updatePosition(double dt, int minx, int miny, int maxx, int maxy);

  /// the drawing function, to be defined by child classes
  virtual void draw() = 0;
  
  /// bounding box for the shape, relative to the origin of the shape
  /**
     \return by how much the shape extends along the x axis to the
     right, relative to the origin.
     Must be correctly calculated by child classes for collision
     detection to properly work.
   */
  virtual double bBoxMaxX() = 0;

  /// bounding box for the shape, relative to the origin of the shape
  /**
     \return by how much the shape extends along the x axis to the
     left, relative to the origin.
     Must be correctly calculated by child classes for collision
     detection to properly work.
   */
  virtual double bBoxMinX() = 0;

  /// bounding box for the shape, relative to the origin of the shape
  /**
     \return by how much the shape extends along the y above,
     relative to the origin.
     Must be correctly calculated by child classes for collision
     detection to properly work.
   */
  virtual double bBoxMinY() = 0;

  /// bounding box for the shape, relative to the origin of the shape
  /**
     \return by how much the shape extends along the y axis below,
     relative to the origin.
     Must be correctly calculated by child classes for collision
     detection to properly work.
   */
  virtual double bBoxMaxY() = 0;
};


#endif
