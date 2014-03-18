#ifndef __PADDLE_H
#define __PADDLE_H

#include "Shape.h"
#include <allegro5/allegro_primitives.h>

class Paddle: public Shape {
private:
	double width; // the paddle width
	double height; // the paddle height
	ALLEGRO_KEYBOARD_STATE *keystate;

public:
	/// Initialize the paddle, including 
	/** \param o the origin of the paddle, origin is the top left corner of the paddle rectangle
		\param w the width of the paddle, in pixels
		\param h the height of the paddle, in pixels
	*/
	Paddle(Point o, double w, double h);
	~Paddle();

	void draw();
	void updatePosition(double dt, int minx, int miny, int maxx, int maxy);

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif
