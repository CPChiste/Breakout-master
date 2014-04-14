#ifndef __BALLPOWERUPSTRATEGY_H
#define __BALLPOWERUPSTRATEGY_H

#include "2DGeom.h"

class BallPowerUpInterface {
public:
  virtual Vector speed(Vector curSpeed) = 0;
};

typedef BallPowerUpInterface* BallPowerUpStrategy;

#endif