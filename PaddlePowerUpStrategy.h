/** The ABSTRACT class PaddlePowerUpStrategy Interface

   Responsibilities:
                        
   1) Abstract class that provides fucntionality to set paddle width
*/

#ifndef __PADDLEPOWERUPSTRATEGY_H
#define __PADDLEPOWERUPSTRATEGY_H

class PaddlePowerUpInterface {
public:
  /// Pure Abstract function returns the new width of the paddle
  /// \param curLength  the current width of the paddle
  virtual double width(double curLength) = 0;
};

typedef PaddlePowerUpInterface* PaddlePowerUpStrategy;

#endif