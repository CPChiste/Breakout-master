#include "BreakoutSimulator.h"


BreakoutSimulator::BreakoutSimulator(const Display & d, int fps) : Simulator(d, fps) { 
  width = d.getW(); height = d.getH(); 
}


void BreakoutSimulator::updateModel(double dt){
  for (std::list<Shape*>::iterator it=theList.begin(); 
       it!=theList.end(); ++it)
    (*it)->updatePosition(dt, 0, 0, width, height);
}


void BreakoutSimulator::addShape(Shape* sh) {
  theList.push_front(sh);
}


void BreakoutSimulator::drawModel() {
  al_clear_to_color(al_map_rgb(0,0,0));

  for (std::list<Shape*>::iterator it=theList.begin(); 
       it!=theList.end(); ++it)
    (*it)->draw();

  al_flip_display();
}


BreakoutSimulator::~BreakoutSimulator() {
  while(!theList.empty()) {
    delete theList.front(); // frees the object pointed to by the first item
    theList.pop_front();    // remove the first item from the list
  }
}
