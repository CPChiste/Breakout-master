/** The Paddle Factory Implmentation

   Responsibilities:
                        
   1) Create/Return a random PaddlePowerUpStrategy
*/


#ifndef __PADDLEPOWERUPFACTORY_H
#define __PADDLEPOWERUPFACTORY_H

#include "PaddlePowerUpStrategy.h"

class PaddlePowerUpFactory {
private:
	int randomNumber(int min, int max);
public:
	PaddlePowerUpFactory() {};
	~PaddlePowerUpFactory() {};

	/// Randomly create a PaddlePowerUpStrategy- currently only implements 2 Strategys
	/// \return a PaddlePowerUpStrategy
	PaddlePowerUpStrategy createRandomPowerUp();
};

#endif