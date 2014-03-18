#include "BreakoutSimulator.h"

BreakoutSimulator::BreakoutSimulator(const Display & d, int fps) : Simulator(d, fps) { 
  width = d.getW(); height = d.getH(); 
}


void BreakoutSimulator::updateModel(double dt){
  
  //Get keyboard state and update paddle here

  //update and check collisions
  for (std::list<Ball*>::iterator it=ballList.begin(); it!=ballList.end(); ++it) {
    
    //moveable objects
    (*it)->updatePosition(dt);
    
    //world
    (*it)->checkWallCollisions(0, 0, width, height);
    if ((*it)->checkBottomWallCollision(height) == true) {
      //gameOver();   //remove comment once this has been implemented
    }

    //bricks
    for (std::list<Brick*>::iterator bit=brickList.begin(); bit!=brickList.end(); ++bit) {
      if ((*it)->checkShapeCollision((*bit)->bBoxMinX(), (*bit)->bBoxMinY(), 
                        (*bit)->bBoxMaxX(), (*bit)->bBoxMaxY(), false) == true) {
        // do something with the bricks
      }
    }

    //paddles
    for (std::list<Paddle*>::iterator pit=paddleList.begin(); pit!=paddleList.end(); ++pit) {
      (*it)->checkShapeCollision((*pit)->bBoxMinX(), (*pit)->bBoxMinY(), 
                            (*pit)->bBoxMaxX(), (*pit)->bBoxMaxY(), true);
    }
  }
}

void BreakoutSimulator::addBall(Ball* sh) {
  ballList.push_front(sh);
}

void BreakoutSimulator::addBrick(Brick* sh) {
  brickList.push_front(sh);
}

void BreakoutSimulator::addPaddle(Paddle* sh) {
  paddleList.push_front(sh);
}


void BreakoutSimulator::drawModel() {
  al_clear_to_color(al_map_rgb(0,0,0));

  for (std::list<Ball*>::iterator it=ballList.begin(); it!=ballList.end(); ++it){
    (*it)->draw();
  }
  for (std::list<Brick*>::iterator it=brickList.begin(); it!=brickList.end(); ++it){
    (*it)->draw();
  }
  for (std::list<Paddle*>::iterator it=paddleList.begin(); it!=paddleList.end(); ++it){
    (*it)->draw();
  }

  al_flip_display();
}

void BreakoutSimulator::gameOver() {
  //do something to end the game
}

BreakoutSimulator::~BreakoutSimulator() {
  while(!ballList.empty()) {
    delete ballList.front(); // frees the object pointed to by the first item
    ballList.pop_front();    // remove the first item from the list
  }
  while(!brickList.empty()) {
    delete brickList.front(); // frees the object pointed to by the first item
    brickList.pop_front();    // remove the first item from the list
  }
  while(!paddleList.empty()) {
    delete paddleList.front(); // frees the object pointed to by the first item
    paddleList.pop_front();    // remove the first item from the list
  }
}
