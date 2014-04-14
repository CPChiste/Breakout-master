#ifndef __PADDLENOPOWERUPSTRATEGY_H
#define __PADDLENOPOWERUPSTRATEGY_H

#include "PaddlePowerUpStrategy.h"

class PaddleNoPowerUpStrategy : public PaddlePowerUpInterface {
public:
	PaddleNoPowerUpStrategy() {};
	~PaddleNoPowerUpStrategy() {};
	double width(double curWidth) {return 150;}
};

#endif