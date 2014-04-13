#include "BrickGenerator.h"

BreakoutSimulator& BrickGenerator::generateBricks(BreakoutSimulator& sim)
{
   double halfWindow = (height / 2);
   double column = width/10.0; //10 columns
   double row = halfWindow/10.0; //10 rows

   srand(time(NULL));

   //Generate a 10x10 grid of 0's and 1's, 1's are where bricks will go
   for(int i=0;i<10;i++)
   {
      for(int j=1;j<10;j++)
      {
	 if(rand() % 2==1)
	    sim.addBrick(new Brick(Point(i*column, j*row), column, row));
      }
   }

   return sim;
}
