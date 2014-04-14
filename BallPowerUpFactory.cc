#include "BallPowerUpFactory.h"
#include "BallIncSpeedPowerUpStrategy.h"
#include "BallDecSpeedPowerUpStrategy.h"
#include <stdlib.h>

BallPowerUpStrategy BallPowerUpFactory::createRandomPowerUp() {
  int number = randomNumber(1, 3);
  switch(number) {
    case 1:
      return new BallIncSpeedPowerUpStrategy(); 
 	   break;
    case 2:
      return new BallDecSpeedPowerUpStrategy();
	   break;
  }
}

int BallPowerUpFactory::randomNumber(int min, int max) {
  return (rand()%(max-min))+min;
}