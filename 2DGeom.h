#ifndef __2DGEOM_H
#define __2DGEOM_H

/// This file contains definitions for various geometrical structures

/// a 2 dimensional vector in the geometric sense
class Vector {
 private:
  double x;
  double y;
 public:
  /// creates a vector with given x and y projections
  /**
     \param a the x component of the vector
     \param b the y component of the vector
   */
  Vector (double a=0.0, double b=0.0) : x(a), y(b) {};
  
  /// scalar multiplication
  /**
     \param scalar the scalar value to multiply the vector with
     \return a vector equal to the result of multiplying *this with
     the scalar
   */
  Vector operator * (double scalar) const {
    return Vector(x*scalar, y*scalar);
  }
  
  /// *this is reflected over the X axis
  /**
     \return the reflection of *this over the x axis, ie a vector with
     the sign of this->y changed
   */
  Vector reflectOverXAxis() const {
    return Vector(x, -y);
  }
  
  /// *this is reflected over the Y axis
  /**
     \return the reflection of *this over the y axis, ie a vector with
     the sign of this->x changed
   */
  Vector reflectOverYAxis() const {
    return Vector(-x, y);
  }

  /// \return the x component of the vector
  double X() const { return x; }

  /// \return the y component of the vector
  double Y() const { return y; }
};


/// a 2 dimensional point
class Point {
 private:
  double x;
  double y;
 public:
  /// constructs a point with given x and y coordinates
  /**
     \param a the x coordinate
     \param b the y coordinate
   */
 Point(double a=0.0, double b=0.0): x(a), y(b) {};

  /// translation by a vector
  /**
     \param v the vector used in the translation
     \return a point representing the translation of this by v
   */
  Point operator + (Vector v) const {
    return Point(x+v.X(), y+v.Y());
  }

  /// returns the point that is the reflection of *this over the
  /// vertical line
  /**
     \param Lx the x coordinate of the vertical line
   */
  Point reflectVerticalLine(double Lx) {
    return Point(2*Lx - x, y);
  }

  /// returns the point that is the reflection of *this over the
  /// horizontal line
  /**
     \param Lx the x coordinate of the vertical line
   */
  Point reflectHorizontalLine(double Ly) {
    return Point(x, 2*Ly-y);
  }
	
  /// \return the x coordinate of the point
  double X() const { return x; }

  /// \return the y coordinate of the point
  double Y() const { return y; }
};


#endif
