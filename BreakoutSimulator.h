#ifndef __BREAKOUTSIMULATOR_H
#define __BREAKOUTSIMULATOR_H

#include "Shape.h"
#include "2DGeom.h"
#include "Simulator.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "PowerUp.h"
#include "BallPowerUpFactory.h"
#include "PaddlePowerUpFactory.h"
#include "LiveDisplay.h"
#include <allegro5/allegro_primitives.h>
#include <list>

class BreakoutSimulator: public Simulator {
private:
   int width, height; // of the window
   Ball* ball;
   Paddle* paddle;
   std::list<Brick*> brickList;
   std::list<PowerUp*> powerUpList;

   LiveDisplay *lives;  // the lives counter + display
   bool gameOver;     

   BallPowerUpFactory* ballFactory;
   PaddlePowerUpFactory* paddleFactory;

public:
  /// constructor initializing the simulator
  /**
     \param d the Display object
     \param fps the number of frames per second the simulation runs at
   */
  BreakoutSimulator(const Display & d, int fps);

  /// destroys all Shapes/Objects added to the simulation
  ~BreakoutSimulator();

  /// called by the simulator class, updates all shapes/control variables of the game
  /**
      \param dt is the distance vs time travelled since last update
  */
  void updateModel(double dt);
  
  /// Adds a ball to the current simulation
  /**
      \param b the ball to add
  */
  void addBall(Ball* b);

  /// Adds a Paddle to the current simulation
  /**
      \param p the paddle to add
  */
  void addPaddle(Paddle* p);

  /// Adds a Brick to the current simulation Brick List
  /**
      \param sh the brick to add to the brick list
  */
  void addBrick(Brick* sh);

  /// Adds a Power up to the current simulation PowerUp List
  /**
      \param pu the powerUp to add to the power up list
  */
  void addPowerUp(PowerUp* pu);
  
  /// Function Creates a power up at the location of the destroyed brick
  /**
      \param x - the center x position of the destroyed brick
      \param y - the center y position of the destroyed brick
  */
  void createPowerUp(double x, double y);

  /// Calls a random Power Up Factory to create and apply a new StrategyPattern
  void applyPowerUp();

  /// Returns a random number using rand()
  /**
      \param min - the mininum random number
      \param max - the maximum random number
  */
  int randomNumber(int min, int max);

  /// sets lives to -1 when ball goes past bottom of simulation screen
  /// resets the ball to the middle of simulation if !gameover()
  void loseBall();
  
  /// draw all our shapes
  void drawModel();
};

#endif
