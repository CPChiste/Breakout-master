#include "Display.h"
#include "BreakoutSimulator.h"
#include "Ball.h"
#include "Paddle.h"
#include "BrickGenerator.h"
#include "Paddle.h"
#include "BallNoPowerUpStrategy.h"
#include "PaddleNoPowerUpStrategy.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <ctime>
#include <ncurses.h>

int main(void) { 
   //srand(time(0));

   Display disp;  // create a 1000x1000 window
   BreakoutSimulator* sim = new BreakoutSimulator(disp, 100);
   BrickGenerator brickGen(disp.getW(), disp.getH());
   
   brickGen.generateBricks(sim);
   
   sim->addBall(new Ball(Point(400, 400), 8, new BallNoPowerUpStrategy()));
   sim->addPaddle(new Paddle(Point(400, 500), 20, new PaddleNoPowerUpStrategy()));
	 
   sim->run();
   
   delete sim;

   return 0;
}
