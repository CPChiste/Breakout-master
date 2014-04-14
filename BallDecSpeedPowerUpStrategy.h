/** The BallDecreaseSpeedPowerUp Strategy Implementation

   Responsibilities:
                        
   1) Return the Balls Speed Descreased based on the current speed
*/

#ifndef __BALLDECSPEEDPOWERUPSTRATEGY_H
#define __BALLDECSPEEDPOWERUPSTRATEGY_H

#include "BallDecSpeedPowerUpStrategy.h"

class BallDecSpeedPowerUpStrategy : public BallPowerUpInterface {
public:
	BallDecSpeedPowerUpStrategy() {};
	~BallDecSpeedPowerUpStrategy() {};

	/// Updates the Speed based on the current speed of the ball
	/// \return a Vector of the new Speed
	Vector speed(Vector curSpeed) {return curSpeed * Vector(0.7, 0.7);}
};

#endif