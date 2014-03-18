#include "Ball.h"
#include <allegro5/allegro_primitives.h>

Ball::Ball(Point o, Vector s, double r) : Shape(o), speed(s), radius(r) {};

void Ball::checkWallCollisions(int minX, int minY, int maxX, int maxY) {
	if (origin.X() < minX - bBoxMinX()) { // colision left side
    	speed = speed.reflectOverYAxis();
    	origin = origin.reflectVerticalLine(minX - bBoxMinX());
 	}

  if (origin.X() > maxX - bBoxMaxX()) { // collision right side
    speed = speed.reflectOverYAxis();
    origin = origin.reflectVerticalLine(maxX - bBoxMaxX());
  }

  //TODO:: Remove bottom collisions when running in actual game

  if (origin.Y() > maxY - bBoxMaxY()) { // collision bottom side
    speed = speed.reflectOverXAxis();
    origin = origin.reflectHorizontalLine(maxY - bBoxMaxY());
  }

  if (origin.Y() < minY - bBoxMinY()) { // collision top side
    speed = speed.reflectOverXAxis();
    origin = origin.reflectHorizontalLine(minY - bBoxMinY());
  }
}

bool Ball::checkShapeCollision(int minX, int minY, int maxX, int maxY, bool sBounce) {
  //if sbounce then change vector speed based on where it hit the object
  //return true if it collided
  return false;
}

bool Ball::checkBottomWallCollision(int maxY) {
	if (origin.Y() > maxY - bBoxMaxY()) {
    return true;
  }
  else { 
    return false;
  }
}

void Ball::updatePosition(double dt) {
  origin = origin + speed*dt;
}

void Ball::draw() {
	al_draw_circle(origin.X(), origin.Y(), radius, al_map_rgb(0, 200, 200), 2);
}

double Ball::bBoxMaxX() {
	return radius;
}

double Ball::bBoxMaxY() {
	return radius;
}

double Ball::bBoxMinX() {
	return -radius;
}

double Ball::bBoxMinY() {
	return -radius;
}
