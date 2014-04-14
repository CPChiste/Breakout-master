#ifndef __BALL_H
#define __BALL_H

#include "2DGeom.h"
#include "Shape.h"
#include <string>

class Ball: public Shape {
private:
	Vector speed;
	double radius; // the balls raidius 
public:
	/// initialize a ball that can be animated
	/** \param o the origin of the drawing in pixels
		\param s the speed vector, in pixels per second
		\param r the radius of the ball
	*/
	Ball(Point o, Vector s, double r);

  	void updatePosition(double dt);

	void checkWallCollisions(double minX, double minY, double maxX, double maxY);
	bool checkShapeCollision(double minX, double minY, double maxX, double maxY, bool sBounce);
	bool checkBottomWallCollision(double maxY);

	void draw();

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif
