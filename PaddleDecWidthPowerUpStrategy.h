/** The PaddleDecWidthPowerUpS Strategy Implementation

   Responsibilities:
                        
   1) Return the Paddles width by decreasing the current width
*/

#ifndef __PADDLEDECWIDTHPOWERUPSTRATEGY_H
#define __PADDLEDECWIDTHPOWERUPSTRATEGY_H

#include "PaddleDecWidthPowerUpStrategy.h"

class PaddleDecWidthPowerUpStrategy : public PaddlePowerUpInterface {
public:
	PaddleDecWidthPowerUpStrategy() {};
	~PaddleDecWidthPowerUpStrategy() {};

	/// Updates the width based on the current width of the paddle
	/// \return a double of the new width
	double width(double curWidth) {
		if (curWidth > 80) {
    		return curWidth -= 50;
  		}
  		return curWidth;
  	}
};

#endif