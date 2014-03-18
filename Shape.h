#ifndef __2DOBJECT_H
#define __2DOBJECT_H

#include "2DGeom.h"

/// generic Shape class.
/**
 It is aware of its bounding box
 */
class Shape {
 protected:
  Point origin; // the origin of the shape

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
  Shape(Point o);

	/// destructor must be virtual
	virtual ~Shape() {}

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
