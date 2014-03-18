#include "Ball.h"
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <iostream>

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

  // An Intersect Depth Vector Algorithm
  //calculate center
  double halfWidth = (minX + maxX) / 2;
  double halfHeight = (minY + maxY) / 2;
  Point shapeCenter = Point(minX + halfWidth, minY + halfHeight);
  Point circleCenter = Point(origin.X(), origin.Y());

  //calculate current and minimum--non-instersecting distance between centers
  double distanceX = shapeCenter.X() - circleCenter.X();
  double distanceY = shapeCenter.Y() - circleCenter.Y();
  double minDistanceX = halfWidth + radius;
  double minDistanceY = halfHeight + radius;

  //check if there is an intersection
  if (fabs(distanceX) >= minDistanceX || fabs(distanceY) >= minDistanceY) {
    return false;
  }
  
  //calculate intersection depths
  double depthX = distanceX > 0 ? minDistanceX - distanceY : -minDistanceX - distanceX;
  double depthY = distanceY > 0 ? minDistanceY - distanceY : -minDistanceY - distanceY;

  if (fabs(depthX) > fabs(depthY)) { //y axis
    if (depthY < 0) {
      topCollision(minY);
    }
    else{
      bottomCollision(maxY);    
    }
  }
  else { // x axis
    if (depthX < 0) {
      leftCollision(minX);
    }
    else { 
      rightCollision(maxX);
    }
  }

  return true;
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
