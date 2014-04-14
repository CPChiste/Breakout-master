/** The BallIncreaseSpeedPowerUp Strategy Implementation

   Responsibilities:
                        
   1) Return the Balls Speed Increased based on the current speed
*/

#ifndef __BALLIINCSPEEDPOWERUPSTRATEGY_H
#define __BALLIINCSPEEDPOWERUPSTRATEGY_H

#include "BallIncSpeedPowerUpStrategy.h"

class BallIncSpeedPowerUpStrategy : public BallPowerUpInterface {
public:
	BallIncSpeedPowerUpStrategy() {};
	~BallIncSpeedPowerUpStrategy() {};

    /// Updates the Speed based on the current speed of the ball
	/// \return a Vector of the new Speed
	Vector speed(Vector curSpeed) {return curSpeed * Vector(1.5, 1.5);}
};

#endif