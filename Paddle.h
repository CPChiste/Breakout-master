#ifndef __PADDLE_H
#define __PADDLE_H

#include "Shape.h"
#include "2DGeom.h"
#include <allegro5/allegro_primitives.h>

class Paddle: public Shape {
private:
	Vector speed;
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
	
	void updatePosition(double dt, int minX, int minY, int maxX, int maxY);

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif