#ifndef __BALL_H
#define __BALL_H

#include "2DGeom.h"
#include "Shape.h"

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

	void checkWallCollisions(int minX, int minY, int maxX, int maxY);
	bool checkShapeCollision(int minX, int minY, int maxX, int maxY, bool sBounce);
	bool checkBottomWallCollision(int maxY);

	void draw();

	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();

private:
	void leftCollision(int minX);
	void rightCollision(int maxX);
	void bottomCollision(int minY);
	void topCollision(int maxY);
};

#endif