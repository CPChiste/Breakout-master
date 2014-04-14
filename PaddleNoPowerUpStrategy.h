/** The PaddleNoWidthPowerUpS Strategy Implementation

   Responsibilities:
                        
   1) Return the Paddles default width
*/

#ifndef __PADDLENOPOWERUPSTRATEGY_H
#define __PADDLENOPOWERUPSTRATEGY_H

#include "PaddlePowerUpStrategy.h"

class PaddleNoPowerUpStrategy : public PaddlePowerUpInterface {
public:
	PaddleNoPowerUpStrategy() {};
	~PaddleNoPowerUpStrategy() {};

	/// Returns the default paddle width
	double width(double curWidth) {return 150;}
};

#endif