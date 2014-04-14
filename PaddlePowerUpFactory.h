#ifndef __PADDLEPOWERUPFACTORY_H
#define __PADDLEPOWERUPFACTORY_H

#include "PaddlePowerUpStrategy.h"

class PaddlePowerUpFactory {
private:
	int randomNumber(int min, int max);
public:
	PaddlePowerUpFactory() {};
	PaddlePowerUpStrategy createRandomPowerUp();
	~PaddlePowerUpFactory() {};
};

#endif