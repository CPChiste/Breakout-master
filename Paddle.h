#ifndef __PADDLE_H
#define __PADDLE_H

#include "Shape.h"
#include "2DGeom.h"
#include "PaddlePowerUpStrategy.h"
#include <allegro5/allegro_primitives.h>

class Paddle: public Shape {
private:
	Vector speed;
	double width; // the paddle width
	double height; // the paddle height
	ALLEGRO_KEYBOARD_STATE *keystate;
	PaddlePowerUpStrategy powerUp;

public:
	/// Initialize the paddle, including 
	/** \param o the origin of the paddle, origin is the top left corner of the paddle rectangle
		\param w the width of the paddle, in pixels
		\param h the height of the paddle, in pixels
	*/
	Paddle(Point o, double h, PaddlePowerUpStrategy p);
	~Paddle();

	/// draws the paddle based on the origin of the shape
	void draw();

	/// updates the positon of the paddle
    /**
     	\param dt is the d vs time travelled since last update
     	\param minX - the min X location of the screen
     	\param minY - the min Y location of the screen
     	\param maxX - the max X location of the screen
     	\param maxY - the max Y location of the screen
    */
	void updatePosition(double dt, int minX, int minY, int maxX, int maxY);
    
    /// sets the power of the paddle (inc/dec/none width)
    /** 
    	\param p is the PowerUpStrategy to implment
    */
    void setPowerUp(PaddlePowerUpStrategy p);
	
	/// returns all boundary boxes of the Ball - currently acts as a Rectangle
	double bBoxMaxX();
	double bBoxMaxY();
	double bBoxMinX();
	double bBoxMinY();
};

#endif
