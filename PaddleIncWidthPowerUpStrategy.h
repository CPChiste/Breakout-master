#ifndef __PADDLEINCWIDTHPOWERUPSTRATEGY_H
#define __PADDLEINCWIDTHPOWERUPSTRATEGY_H

#include "PaddleIncWidthPowerUpStrategy.h"

class PaddleIncWidthPowerUpStrategy : public PaddlePowerUpInterface {
public:
	PaddleIncWidthPowerUpStrategy() {};
	~PaddleIncWidthPowerUpStrategy() {};
	double width(double curWidth) {
		if (curWidth < 650) {
    		return curWidth += 50;
  		}
  		return curWidth;
  	}
};

#endif