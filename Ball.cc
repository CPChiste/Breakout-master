#include "Ball.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "2DGeom.h"

Ball::Ball(Point o, double r, BallPowerUpStrategy p) : Shape(o), radius(r), powerUp(p) {
  speed = powerUp->speed(speed);
}

void Ball::updatePosition(double dt) {
  origin = origin + speed*dt;
}

void Ball::draw() {
   al_draw_filled_circle(origin.X(),origin.Y(),radius, al_map_rgb(237, 237, 41));
}

void Ball::setPowerUp(BallPowerUpStrategy p) {
  delete powerUp;
  powerUp = p;
  speed = powerUp->speed(speed);
}

void Ball::checkWallCollisions(double minX, double minY, double maxX, double maxY) {
  if (bBoxMinX() <= minX) { // colision left side
    speed = speed.reflectOverYAxis();
    origin = origin.reflectVerticalLine(minX + radius);
  }

  if (bBoxMaxX() >= maxX) { // collision right side
    speed = speed.reflectOverYAxis();
    origin = origin.reflectVerticalLine(maxX - radius);
  }

  if (bBoxMinY() < minY) { // collision top side
    speed = speed.reflectOverXAxis();
    origin = origin.reflectHorizontalLine(minY + radius);
  } 
}

bool Ball::checkShapeCollision(double minX, double minY, double maxX, double maxY) {
  Point topLeft = Point(minX, minY);
  Point topRight = Point(maxX, minY);
  Point botLeft = Point(minX, maxY);
  Point botRight = Point(maxX, maxY);
    
  if (lineIntersects(topLeft.X(), topLeft.Y(), topRight.X(), topRight.Y())) {  //top input shape
    speed = speed.reflectOverXAxis();
    origin = Point(origin.X(), minY - radius);
    return true;
  }

  if (lineIntersects(botLeft.X(), botLeft.Y(), botRight.X(), botRight.Y())) {  //bottom input shape
    speed = speed.reflectOverXAxis();
    origin = Point(origin.X(), maxY + radius);
    return true;
  }

  if (lineIntersects(topLeft.X(), topLeft.Y(), botLeft.X(), botLeft.Y())) { //left input shape
    speed = speed.reflectOverYAxis();
    origin = Point(minX - radius, origin.Y());
    return true;
  }

  if (lineIntersects(topRight.X(), topRight.Y(), botRight.X(), botRight.Y())) { //right input shape
    speed = speed.reflectOverYAxis();
    origin = Point(maxX + radius, origin.Y());
    return true;
  }

  return false;
}

bool Ball::checkBottomWallCollision(double maxY) {
  if (bBoxMaxY() > maxY) return true;
  return false;
}

double Ball::bBoxMaxX() {
  return origin.X() + radius;
}

double Ball::bBoxMaxY() {
  return origin.Y() + radius;
}

double Ball::bBoxMinX() {
  return origin.X() - radius;
}

double Ball::bBoxMinY() {
  return origin.Y() - radius;
}
