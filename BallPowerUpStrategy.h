/** The ABSTRACT class BallPowerUpStrategy Interface

   Responsibilities:
                        
   1) Abstract class that provides fucntionality to set ball speed vector
*/

#ifndef __BALLPOWERUPSTRATEGY_H
#define __BALLPOWERUPSTRATEGY_H

#include "2DGeom.h"

class BallPowerUpInterface {
public:
  /// Pure Abstract function returns the new speed of the ball
  /// \param curSpeed  the current speed of the ball
  virtual Vector speed(Vector curSpeed) = 0;
};

/// TypeDef for BallPowerUpInterface
typedef BallPowerUpInterface* BallPowerUpStrategy;

#endif