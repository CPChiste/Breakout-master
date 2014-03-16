#include "Shape.h"

Shape::Shape(Point o, Vector s) : origin(o), speed(s) {};

void Shape::updatePosition(double dt, int minx, int miny, int maxx, int maxy) {
  origin = origin + speed*dt;

  if (origin.X() < minx - bBoxMinX()) { // colision left side
    speed = speed.reflectOverYAxis();
    origin = origin.reflectVerticalLine(minx - bBoxMinX());
  }

  if (origin.X() > maxx - bBoxMaxX()) { // collision right side
    speed = speed.reflectOverYAxis();
    origin = origin.reflectVerticalLine(maxx - bBoxMaxX());
  }

  if (origin.Y() > maxy - bBoxMaxY()) { // collision bottom side
    speed = speed.reflectOverXAxis();
    origin = origin.reflectHorizontalLine(maxy - bBoxMaxY());
  }

  if (origin.Y() < miny - bBoxMinY()) { // collision top side
    speed = speed.reflectOverXAxis();
    origin = origin.reflectHorizontalLine(miny - bBoxMinY());
  }
}
