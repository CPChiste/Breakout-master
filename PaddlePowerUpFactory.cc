#include "PaddlePowerUpFactory.h"
#include "PaddleIncWidthPowerUpStrategy.h"
#include "PaddleDecWidthPowerUpStrategy.h"
#include <stdlib.h>

PaddlePowerUpStrategy PaddlePowerUpFactory::createRandomPowerUp() {
  int number = randomNumber(1, 3);
  switch(number) {
    case 1:
      return new PaddleIncWidthPowerUpStrategy(); 
 	   break;
    case 2:
      return new PaddleDecWidthPowerUpStrategy();
	   break;
  }
}

int PaddlePowerUpFactory::randomNumber(int min, int max) {
  return (rand()%(max-min))+min;
}