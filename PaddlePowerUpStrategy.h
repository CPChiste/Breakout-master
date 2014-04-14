#ifndef __PADDLEPOWERUPSTRATEGY_H
#define __PADDLEPOWERUPSTRATEGY_H

class PaddlePowerUpInterface {
public:
  virtual double width(double curLength) = 0;
};

typedef PaddlePowerUpInterface* PaddlePowerUpStrategy;

#endif