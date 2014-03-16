#include "Ball.h"
#include <allegro5/allegro_primitives.h>

Ball::Ball(Point o, Vector s, double _r) :
	Shape(o, s), r(_r) {
}


void Ball::draw() {
	al_draw_circle(origin.X(), origin.Y(), r, al_map_rgb(0, 200, 200), 3);
}


double Ball::bBoxMaxX() {
	return r;
}

double Ball::bBoxMaxY() {
	return r;
}

double Ball::bBoxMinX() {
	return -r;
}

double Ball::bBoxMinY() {
	return -r;
}
