#ifndef __BREAKOUTSIMULATOR_H
#define __BREAKOUTSIMULATOR_H

#include "Shape.h"
#include "2DGeom.h"
#include "Simulator.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "LiveDisplay.h"
#include <allegro5/allegro_primitives.h>
#include <list>


class BreakoutSimulator: public Simulator {
private:
   int width, height; // of the window
  std::list<Ball*> ballList;
  std::list<Brick*> brickList;
  std::list<Paddle*> paddleList;
  LiveDisplay *lives;
  bool gameOver;

public:
  /// constructor initializing the simulator
  /**
     \param d the Display object
     \param fps the number of frames per second the simulation runs at
   */
  BreakoutSimulator(const Display & d, int fps);

  /// destroys all Shapes added to the simulation
  ~BreakoutSimulator();

  void updateModel(double dt);


  void addBall(Ball* sh);
  void addBrick(Brick* sh);
  void addPaddle(Paddle* sh);

  void loseBall(std::list<Ball*>::iterator);
  
  void drawModel();
};

#endif
