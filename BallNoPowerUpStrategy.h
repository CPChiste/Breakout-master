#ifndef __BALLNOPOWERUPSTRATEGY_H
#define __BALLNOPOWERUPSTRATEGY_H

#include "BallPowerUpStrategy.h"

class BallNoPowerUpStrategy : public BallPowerUpInterface {
public:
	BallNoPowerUpStrategy() {};
	~BallNoPowerUpStrategy() {};
	Vector speed(Vector curSpeed) {return Vector(200, 200);}
};

#endif