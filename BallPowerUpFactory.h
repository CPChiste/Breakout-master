#ifndef __BALLPOWERUPFACTORY_H
#define __BALLPOWERUPFACTORY_H

#include "BallPowerUpStrategy.h"

class BallPowerUpFactory {
private:
	int randomNumber(int min, int max);
public:
	BallPowerUpFactory() {};
	BallPowerUpStrategy createRandomPowerUp();
	~BallPowerUpFactory() {};
};

#endif