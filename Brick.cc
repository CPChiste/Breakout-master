#include "Brick.h"
#include <allegro5/allegro_primitives.h>

Brick::Brick(Point o, double l, double h, bool isHit) : Shape(o), length(l), height(h) , destroyed(isHit) {};

void Brick::draw() {
   if(!destroyed)
	al_draw_rectangle(origin.X(), origin.Y(), origin.X()+length, origin.Y()+height, al_map_rgb(150, 150, 255), 1);
}

bool Brick::isDestroyed()
{
   return destroyed;
}

void Brick::setDestroyed(bool isHit)
{
   destroyed = isHit;
}

double Brick::bBoxMaxX() {
   return origin.X() + length;
}

double Brick::bBoxMaxY() {
   return origin.Y() + height;
}

double Brick::bBoxMinX() {
   return origin.X();
}

double Brick::bBoxMinY() {
   return origin.Y();
}
