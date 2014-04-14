#ifndef __BALL_H
#define __BALL_H

#include "2DGeom.h"
#include "Shape.h"
#include "BallPowerUpStrategy.h"
#include <string>

class Ball: public Shape {
private:
	Vector speed;  // the speed of the ball
	double radius; // the balls raidius 
	BallPowerUpStrategy powerUp; // the balls power strategy

public:
	/// initialize a ball that can be animated
	/** \param o the origin of the drawing in pixels
		\param s the speed vector, in pixels per second
		\param r the radius of the ball
	*/
	Ball(Point o, double r, BallPowerUpStrategy p);

	/// updates the positon of the ball
    /**
     	\param dt is the d vs time travelled since last update
    */
  	void updatePosition(double dt);
    
    /// draws the ball based on the origin of the shape
    void draw();
  	
  	/// updates the Power Up of the ball (inc/dec/none speed)
    /**
     	\param p is the PowerUpStrategy to implement
    */
  	void setPowerUp(BallPowerUpStrategy p);

  	/// checks and updates the balls positon/speed if it hits the side/top walls
    /**
     	\param minX - the mininum X position
     	\param minY - the mininum Y position
     	\param maxX - the maximum X position
     	\param maxY - the maximum Y position
    */
	void checkWallCollisions(double minX, double minY, double maxX, double maxY);

	/// checks/updates the balls position if it hits another shape
	/// returns true if the ball does hit another shape; else false
    /**
     	\param minX - the mininum X position
     	\param minY - the mininum Y position
     	\param maxX - the maximum X position
     	\param maxY - the maximum Y position
    */
	bool checkShapeCollision(double minX, double minY, double maxX, double maxY);

	/// Check if the ball has gone past the bottom of the game window
    /**
     	\param maxY, the maximum window height
     	\return true/false if ball goes past maxY
    */
	bool checkBottomWallCollision(double maxY);
     
    /// returns all boundary boxes of the Ball - currently acts as a Rectangle
	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif
