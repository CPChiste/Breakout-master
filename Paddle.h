#ifndef __PADDLE_H
#define __PADDLE_H

#include "Shape.h"

class Paddle: public Shape {
private:
	Vector speed;
	double length;
	double height;

public:
	/// initialize a paddle that can be animated
	/** \param o the origin of the drawing in pixels
		\param s the speed vector, in pixels per second
		\param l the lenght of the paddle
		\param h the height of the paddle
	*/
	Paddle(Point o, Vector s, double l, double h);

	void draw();

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif