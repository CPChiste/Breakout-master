#ifndef __RANDOMIZER_H
#define __RANDOMIZER_H

#include <time.h>
#include <math.h>
#include "2DGeom.h"

class Randomizer
{
public:
  int randomNumber(int min, int max) {
    return (rand()%(max-min))+min;
  }

  Point randomOrigin(){
    return Point(randomNumber(0, 800 ), randomNumber(0, 450));
  }

  Vector randomSpeed() {
    return Vector(0, randomNumber(100, 200));
  }

  Vector randomVector() {
    return Vector(randomNumber(25, 100), randomNumber(25, 100));
  }
};
#endif
