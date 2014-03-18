#include "Ball.h"
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "2DGeom.h"

Ball::Ball(Point o, Vector s, double r) : Shape(o), speed(s), radius(r) {};

void Ball::checkWallCollisions(int minX, int minY, int maxX, int maxY) {
	if (bBoxMinX() <= minX) { // colision left side
    	leftCollision(minX);
 	}

  if (bBoxMaxX() >= maxX) { // collision right side
    rightCollision(maxX);
  }

  //TODO:: Remove bottom collisions when running in actual game

  if (bBoxMaxY() >= maxY) { // collision bottom side
    bottomCollision(maxY);
  }

  if (bBoxMinY() < minY) { // collision top side
    topCollision(minY);
  }
}

bool Ball::checkShapeCollision(int minX, int minY, int maxX, int maxY, bool sBounce) {
  //if sbounce then change vector speed based on where it hit the object

  Point topLeft = Point(minX, minY);
  Point topRight = Point(maxX, minY);
  Point botLeft = Point(minX, maxY);
  Point botRight = Point(maxX, maxY);

  if (lineIntersects(topLeft.X(), topLeft.Y(), botLeft.X(), botLeft.Y())) { 
    //rightCollision(maxX);
    speed = speed.reflectOverYAxis();
    return true;
  }

  if (lineIntersects(topLeft.X(), topLeft.Y(), topRight.X(), topRight.Y())) {
    //bottomCollision(maxY);
    speed = speed.reflectOverXAxis();
    return true;
  }

  if (lineIntersects(topRight.X(), topRight.Y(), botRight.X(), botRight.Y())) {
    //leftCollision(minX);
    speed = speed.reflectOverYAxis();
    //origin = Point(minX, origin.Y() + radius );
    return true;
  }

  if (lineIntersects(botLeft.X(), botLeft.Y(), botRight.X(), botRight.Y())) {
    //topCollision(minY);
    speed = speed.reflectOverXAxis();
    //origin = Point(origin.X(), minY + radius);
    return true;
  } 

  return false;
}

bool Ball::lineIntersects(double x1, double y1, double x2, double y2) {
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

bool Ball::checkBottomWallCollision(int maxY) {
  if (bBoxMaxY() > maxY) return true;
  return false;
}

void Ball::leftCollision(int minX) {
  speed = speed.reflectOverYAxis();
  origin = origin.reflectVerticalLine(minX + radius);
}

void Ball::rightCollision(int maxX) {
  speed = speed.reflectOverYAxis();
  origin = origin.reflectVerticalLine(maxX - radius);
}

void Ball::bottomCollision(int maxY) {
  speed = speed.reflectOverXAxis();
  origin = origin.reflectHorizontalLine(maxY - radius);
}

void Ball::topCollision(int minY) {
  speed = speed.reflectOverXAxis();
  origin = origin.reflectHorizontalLine(minY + radius);
}

void Ball::updatePosition(double dt) {
  origin = origin + speed*dt;
}

void Ball::draw() {
	al_draw_circle(origin.X(), origin.Y(), radius, al_map_rgb(0, 200, 200), 2);
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
