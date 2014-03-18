#include "Paddle.h"
#include <allegro5/allegro_primitives.h>

Paddle::Paddle(Point o, Vector s, double l, double h) :
	Shape(o), speed(s), length(l), height(h) {
}

void Paddle::draw() {
	al_draw_rectangle(origin.X(), origin.Y(), origin.X()+length, 
		origin.Y()+height, al_map_rgb(239, 239, 239), 1);
}

double Paddle::bBoxMaxX() {
	return origin.X() + length;
}

double Paddle::bBoxMaxY() {
	return origin.Y() + height;
}

double Paddle::bBoxMinX() {
	return origin.X();
}

double Paddle::bBoxMinY() {
	return origin.Y();
}
