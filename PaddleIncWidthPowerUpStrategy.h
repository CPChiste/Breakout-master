/** The PaddleIncWidthPowerUpS Strategy Implementation

   Responsibilities:
                        
   1) Return the Paddles width by increasing the current width
*/


#ifndef __PADDLEINCWIDTHPOWERUPSTRATEGY_H
#define __PADDLEINCWIDTHPOWERUPSTRATEGY_H

#include "PaddleIncWidthPowerUpStrategy.h"

class PaddleIncWidthPowerUpStrategy : public PaddlePowerUpInterface {
public:
	PaddleIncWidthPowerUpStrategy() {};
	~PaddleIncWidthPowerUpStrategy() {};

	/// Updates the width based on the current width of the paddle
	/// \return a double of the new width
	double width(double curWidth) {
		if (curWidth < 650) {
    		return curWidth += 50;
  		}
  		return curWidth;
  	}
};

#endif