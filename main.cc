#include "Display.h"
#include "BreakoutSimulator.h"
#include "Ball.h"
#include "Paddle.h"
#include "BrickGenerator.h"

int main(void) {
	Display disp;  // create a 800x600 window
	BreakoutSimulator sim(disp, 100);
	BrickGenerator brickGen(disp.getW(), disp.getH());

	sim = brickGen.generateBricks(sim);
	
	sim.addBall(new Ball(Point(400, 400), Vector(200, 200), 10));
	//sim.addPaddle(new Paddle(Point(400, 400), Vector(20, 0), 100, 10));
	
	sim.run();
}
