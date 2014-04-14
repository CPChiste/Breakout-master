#ifndef __POWERUP_H
#define __POWERUP_H

#include "2DGeom.h"
#include "Shape.h"

class PowerUp: public Shape
{
  private:
   Vector speed;
   double length;
   double height;
   bool destroyed;

  public:
   PowerUp(Point o, Vector s, double l, double h, bool destroyed=false);

   void draw();
   void updatePosition(double dt);
   bool checkShapeCollision(double minX, double minY, double maxX, double maxY); 
   
   bool isDestroyed();
   void setDestroyed(bool value);
  
   double bBoxMaxX();
   double bBoxMaxY();
   double bBoxMinX();
   double bBoxMinY();
};

#endif
