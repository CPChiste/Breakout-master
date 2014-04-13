#include "Shape.h"

Shape::Shape(Point o) : origin(o) {};


void Shape::translate(Vector v)
{
  origin.setX(origin.X() + v.X());
  origin.setY(origin.Y() + v.Y());
}

bool Shape::lineIntersects(double x1, double y1, double x2, double y2) {
  if ((x1 <= bBoxMinX() && x2 <= bBoxMinX()) || (y1 <= bBoxMinY() && y2 <= bBoxMinY()) || 
      (x1 >= bBoxMaxX() && x2 >= bBoxMaxX()) || (y1 >= bBoxMaxY() && y2 >= bBoxMaxY())) {
    return false;
  }
  
  double m = (y2 - y1) / (x2 - x1);
  
  double y = m * (bBoxMinX() - x1) + y1;
  if (y > bBoxMinY() && y < bBoxMaxY()) return true;

  y = m * (bBoxMaxX() - x1) + y1;
  if (y > bBoxMinY() && y < bBoxMaxY()) return true;
  
  double x = (bBoxMinY() - y1) / m + x1;
  if (x > bBoxMinX() && x < bBoxMaxX()) return true;

  x = (bBoxMaxY() - y1) / m + x1;
  if (x > bBoxMinX() && x < bBoxMaxX()) return true;

  return false;
}
