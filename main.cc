#include "Display.h"
#include "ShapeSimulator.h"
#include "Ball.h"
#include "BrickGenerator.h"
#include "Paddle.h"

int main(void) {
   Display disp;  // create a 1000x1000 window
   ShapeSimulator sim(disp, 100);
   BrickGenerator brickGen(disp.getW(), disp.getH());
   
   sim = brickGen.generateBricks(sim);
   
   sim.addShape(new Ball(Point(100, 100), Vector(200, 200), 10));
   sim.addShape(new Paddle(Point(400, 500), 150, 20));
   
   sim.run();
}
