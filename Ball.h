#ifndef __BALL_H
#define __BALL_H

#include "2DGeom.h"
#include "Shape.h"
#include "BallPowerUpStrategy.h"
#include <string>

class Ball: public Shape {
private:
	Vector speed;
	double radius; // the balls raidius 
	BallPowerUpStrategy powerUp;

public:
	/// initialize a ball that can be animated
	/** \param o the origin of the drawing in pixels
		\param s the speed vector, in pixels per second
		\param r the radius of the ball
	*/
	Ball(Point o, double r, BallPowerUpStrategy p);

  	void updatePosition(double dt);
    void draw();
  	
  	void setPowerUp(BallPowerUpStrategy p);

	void checkWallCollisions(double minX, double minY, double maxX, double maxY);
	bool checkShapeCollision(double minX, double minY, double maxX, double maxY);
	bool checkBottomWallCollision(double maxY);
      
	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif
