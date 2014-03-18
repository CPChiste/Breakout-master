#include "Brick.h"
#include <allegro5/allegro_primitives.h>

Brick::Brick(Point o, double l, double h) : Shape(o), length(l), height(h) {};

void Brick::draw() {
	al_draw_rectangle(origin.X(), origin.Y(), origin.X()+length, origin.Y()+height, al_map_rgb(150, 150, 255), 1);
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
