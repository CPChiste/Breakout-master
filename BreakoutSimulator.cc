#include "BreakoutSimulator.h"
#include "BallNoPowerUpStrategy.h"
#include "BallPowerUpFactory.h"
#include "PaddlePowerUpFactory.h"

BreakoutSimulator::BreakoutSimulator(const Display & d, int fps) : Simulator(d, fps) { 
   width = d.getW(); height = d.getH(); 
   lives = new LiveDisplay(3);
   gameOver = false;
   ballFactory = new BallPowerUpFactory();
   paddleFactory = new PaddlePowerUpFactory();
}

void BreakoutSimulator::updateModel(double dt){
  if(!gameOver)
  {
    ball->updatePosition(dt);
    paddle->updatePosition(dt, 0, 0, width, height);
      

    for (std::list<PowerUp*>::iterator pit=powerUpList.begin(); pit!=powerUpList.end(); ++pit) {
      if (!(*pit)->isDestroyed()) {
        (*pit)->updatePosition(dt);
      }
    } 
	 
    //check wall collisions
    ball->checkWallCollisions(0, 0, width, height);
      
    if (ball->checkBottomWallCollision(height+40) == true) {
	   loseBall();
    }

    //check ball->brick collisions
    for (std::list<Brick*>::iterator bit=brickList.begin(); bit!=brickList.end(); ++bit) {	       
	   if(!(*bit)->isDestroyed()) {
        if (ball->checkShapeCollision((*bit)->bBoxMinX(), (*bit)->bBoxMinY(), (*bit)->bBoxMaxX(), (*bit)->bBoxMaxY()) == true) {
          (*bit)->setDestroyed(true);
          createPowerUp( ((*bit)->bBoxMinX() + (*bit)->bBoxMaxX()) / 2, 
                         ((*bit)->bBoxMinY() + (*bit)->bBoxMaxY()) / 2 ); //Create power up at brick location
        }
	    }
    }
 
    //check ball->paddle collision
    ball->checkShapeCollision(paddle->bBoxMinX(), paddle->bBoxMinY(), paddle->bBoxMaxX(), paddle->bBoxMaxY());
 
    //check paddle->powerUp collision
    for (std::list<PowerUp*>::iterator pit=powerUpList.begin(); pit!=powerUpList.end(); ++pit) {
      if (!(*pit)->isDestroyed()) {
        if ((*pit)->checkShapeCollision(paddle->bBoxMinX(), paddle->bBoxMinY(), paddle->bBoxMaxX(), paddle->bBoxMaxY()) == true) {
          (*pit)->setDestroyed(true);
          applyPowerUp();
        }   
      }
    } 

  }
}

void BreakoutSimulator::addBall(Ball* b) {
  ball = b;
}

void BreakoutSimulator::addPaddle(Paddle* p) {
  paddle = p;
}

void BreakoutSimulator::addBrick(Brick* sh) {
   brickList.push_front(sh);
}

void BreakoutSimulator::addPowerUp(PowerUp* pu) {
   powerUpList.push_front(pu);
}

void BreakoutSimulator::createPowerUp(double x, double y) {
  bool isPowerUp = (rand() % 100) < 100;
   
  if (isPowerUp) {
    addPowerUp(new PowerUp(Point(x, y), Vector(0, 150), 15, 15));
  }
}

void BreakoutSimulator::applyPowerUp() {
  int number = randomNumber(1, 3);
  switch(number) {
    case 1:
      ball->setPowerUp(ballFactory->createRandomPowerUp());
 	    break;
    case 2:
      paddle->setPowerUp(paddleFactory->createRandomPowerUp());
	    break;
  }
}

int BreakoutSimulator::randomNumber(int min, int max) {
  return (rand()%(max-min))+min;
}

void BreakoutSimulator::drawModel() {
   al_clear_to_color(al_map_rgb(0,0,0));
   if(!gameOver)
   {
      ball->draw();
      paddle->draw();
      for (std::list<Brick*>::iterator it=brickList.begin(); it!=brickList.end(); ++it){
	 (*it)->draw();
      }
      for (std::list<PowerUp*>::iterator pit=powerUpList.begin(); pit!=powerUpList.end(); ++pit){
	 (*pit)->draw();
      }
   }
   lives->draw(gameOver);
      
   al_flip_display();
}

void BreakoutSimulator::loseBall() {
   delete ball;

   if(lives->loseLives() <= 0)
   {
     gameOver = true;
   }
   ball = new Ball(Point(400, 400), 8, new BallNoPowerUpStrategy());
}

BreakoutSimulator::~BreakoutSimulator() {
  delete ball;
  delete paddle;
  while(!brickList.empty()) {
     delete brickList.front(); // frees the object pointed to by the first item
     brickList.pop_front();    // remove the first item from the list
  }
  while(!powerUpList.empty()) {
     delete powerUpList.front(); // frees the object pointed to by the first item
     powerUpList.pop_front();    // remove the first item from the list
  }
  delete lives;
  delete ballFactory;
  delete paddleFactory;
}
