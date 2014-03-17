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
	
	sim.addShape(new Ball(Point(100, 100), Vector(200, 200), 10));
	sim.addShape(new Paddle(Point(400, 400), Vector(0, 0), 100, 10));
	
	sim.run();
}
