#ifndef __BALL_H
#define __BALL_H

#include "Shape.h"

class Ball: public Shape {
private:
	double r; // the balls raidius 

public:
	/// initialize a ball that can be animated
	/** \param o the origin of the drawing in pixels
		\param s the speed vector, in pixels per second
		\param _r the radius of the ball
	*/
	Ball(Point o, Vector s, double _r);

	void draw();

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif