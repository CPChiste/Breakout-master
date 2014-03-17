#ifndef __BREAKOUTSIMULATOR_H
#define __BREAKOUTSIMULATOR_H

#include "Shape.h"
#include "Simulator.h"
#include "2DGeom.h"
#include <allegro5/allegro_primitives.h>
#include <list>


class BreakoutSimulator: public Simulator {
private:
  int width, height; // of the window
  std::list<Shape*> theList;

public:
  /// constructor initializing the simulator
  /**
     \param d the Display object
     \param fps the number of frames per second the simulation runs at
   */
  BreakoutSimulator(const Display & d, int fps);

  /// destroys all shapes added to the simulation
  ~BreakoutSimulator();

  void updateModel(double dt);

  /// adds a shape to the simulation
  /**
     \param sh a pointer to the shape to be added. Object *sh is now
     owned by BreakoutSimulator and must be freed when BreakoutSimulator is
     destroyed. 
   */
  void addShape(Shape* sh);

  void drawModel();
};

#endif
