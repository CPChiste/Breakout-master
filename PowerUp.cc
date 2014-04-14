#include "PowerUp.h"
#include <allegro5/allegro_primitives.h>

PowerUp::PowerUp(Point o, Vector s, double l, double h, bool d) : Shape(o), speed(s), length(l), height(h), destroyed(d) {};

bool PowerUp::isDestroyed() {
  return destroyed;
}

void PowerUp::draw() {
   if(!destroyed) {
	al_draw_rectangle(origin.X(), origin.Y(), origin.X()+length, origin.Y()+height, al_map_rgb(150, 150, 255), 1);
   }
}

void PowerUp::updatePosition(double dt) {
  if (!destroyed) {
    origin = origin + speed*dt;
  }
}

bool PowerUp::checkShapeCollision(double minX, double minY, double maxX, double maxY) {
    return (bBoxMinX() < maxX && bBoxMaxX() > minX && bBoxMinY() < maxY && bBoxMaxY() > minY);
}

void PowerUp::setDestroyed(bool value) {
  destroyed = value;
}

double PowerUp::bBoxMaxX() {
   return origin.X() + length;
}

double PowerUp::bBoxMaxY() {
   return origin.Y() + height;
}

double PowerUp::bBoxMinX() {
   return origin.X();
}

double PowerUp::bBoxMinY() {
   return origin.Y();
}
