#include "Brick.h"
#include <allegro5/allegro_primitives.h>

void Brick::draw() {
	al_draw_rectangle(origin.X(), origin.Y(), origin.X()+length, origin.Y()+height, al_map_rgb(150, 150, 255), 1);
}

double Brick::bBoxMaxX() {
   return length;
}

double Brick::bBoxMaxY() {
   return height;
}

double Brick::bBoxMinX() {
   return origin.X();
}


double Brick::bBoxMinY() {
   return origin.Y();
}
