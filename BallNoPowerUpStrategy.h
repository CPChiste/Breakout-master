/** The BallNoPowerUp Strategy Implementation

   Responsibilities:
                        
   1) Return the Balls Default Speed
*/

#ifndef __BALLNOPOWERUPSTRATEGY_H
#define __BALLNOPOWERUPSTRATEGY_H

#include "BallPowerUpStrategy.h"

class BallNoPowerUpStrategy : public BallPowerUpInterface {
public:
	BallNoPowerUpStrategy() {};
	~BallNoPowerUpStrategy() {};

	/// Updates the Speed based on the current speed of the ball
	/// \return a Vector of the new Speed
	Vector speed(Vector curSpeed) {return Vector(200, 200);}
};

#endif