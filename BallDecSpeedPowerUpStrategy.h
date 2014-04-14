#ifndef __BALLIDECSPEEDPOWERUPSTRATEGY_H
#define __BALLIDECSPEEDPOWERUPSTRATEGY_H

#include "BallDecSpeedPowerUpStrategy.h"

class BallDecSpeedPowerUpStrategy : public BallPowerUpInterface {
public:
	BallDecSpeedPowerUpStrategy() {};
	~BallDecSpeedPowerUpStrategy() {};
	Vector speed(Vector curSpeed) {return curSpeed * Vector(0.7, 0.7);}
};

#endif