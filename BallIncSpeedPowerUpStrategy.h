#ifndef __BALLIINCSPEEDPOWERUPSTRATEGY_H
#define __BALLIINCSPEEDPOWERUPSTRATEGY_H

#include "BallIncSpeedPowerUpStrategy.h"

class BallIncSpeedPowerUpStrategy : public BallPowerUpInterface {
public:
	BallIncSpeedPowerUpStrategy() {};
	~BallIncSpeedPowerUpStrategy() {};
	Vector speed(Vector curSpeed) {return curSpeed * Vector(1.5, 1.5);}
};

#endif