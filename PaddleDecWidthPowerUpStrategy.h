#ifndef __PADDLEDECWIDTHPOWERUPSTRATEGY_H
#define __PADDLEDECWIDTHPOWERUPSTRATEGY_H

#include "PaddleDecWidthPowerUpStrategy.h"

class PaddleDecWidthPowerUpStrategy : public PaddlePowerUpInterface {
public:
	PaddleDecWidthPowerUpStrategy() {};
	~PaddleDecWidthPowerUpStrategy() {};
	double width(double curWidth) {
		if (curWidth > 80) {
    		return curWidth -= 50;
  		}
  		return curWidth;
  	}
};

#endif