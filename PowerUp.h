///PowerUp class
/**
   Inherits from the abstract Shape class
   Provides implementations for drawing a PowerUp -> square
   Computes its own boundary box for collision
*/

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
   ALLEGRO_BITMAP *image;

  public:

   /// initializing a square that can be animated
   /**
     \param o the origin of the drawing, in pixels
     \param s the speed vector, in pixels per second
     \param l the length of the square
     \param h the height of the square
     \param destroyed the isDestroyed value of the powerup (default: false)
   */
   PowerUp(Point o, Vector s, double l, double h, bool destroyed=false);

   /// draws the square that represents a power up
   void draw();

   /// updates the positon of the power up
    /**
      \param dt is the d vs time travelled since last update
    */
   void updatePosition(double dt);

   /// checks/updates the balls position if it hits another shape
   /// returns true if the ball does hit another shape; else false
    /**
      \param minX - the mininum X position of the shape
      \param minY - the mininum Y position of the shape
      \param maxX - the maximum X position of the shape
      \param maxY - the maximum Y position of the shape
    */
   bool checkShapeCollision(double minX, double minY, double maxX, double maxY); 
   
   /// GETTER: returns true if the power up has been destroyed
   bool isDestroyed();

   /// SETTER: sets the bool value of destroyed
   /** 
      \param value - the value to set destroyed
   */
   void setDestroyed(bool value);
  
   /// returns all boundary boxes of the Powerup - currently acts as a Rectangle
   double bBoxMaxX();
   double bBoxMaxY();
   double bBoxMinX();
   double bBoxMinY();
};

#endif
