/** The Ball Factory Implmentation

   Responsibilities:
                        
   1) Create/Return a random BallPowerUpStrategy
*/

#ifndef __BALLPOWERUPFACTORY_H
#define __BALLPOWERUPFACTORY_H

#include "BallPowerUpStrategy.h"

class BallPowerUpFactory {
private:
	int randomNumber(int min, int max);
public:
	BallPowerUpFactory() {};
	~BallPowerUpFactory() {};

	/// Randomly create a BallPowerUpStrategy- currently only implements 2 Strategys
	/// \return a BallPowerUpStrategy
	BallPowerUpStrategy createRandomPowerUp();
};

#endif