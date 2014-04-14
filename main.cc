#include "Display.h"
#include "BreakoutSimulator.h"
#include "Ball.h"
#include "Paddle.h"
#include "BrickGenerator.h"
#include "Paddle.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

int main(void) {  
   Display disp;  // create a 1000x1000 window
   BreakoutSimulator sim(disp, 100);
   BrickGenerator brickGen(disp.getW(), disp.getH());
   
   sim = brickGen.generateBricks(sim);
   
   sim.addBall(new Ball(Point(400, 400), Vector(200, 200), 8));
   sim.addPaddle(new Paddle(Point(400, 500), 150, 20));

   sim.run();
}
