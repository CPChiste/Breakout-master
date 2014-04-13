#ifndef __POWERUP_H
#define __POWERUP_H

class PowerUp: public Shape
{
  private:
   double length;
   double height;

  public:
   Powerup();

   virtual void draw() = 0;

   double bBoxMaxX();
   double bBoxMaxY();
   double bBoxMinX();
   double bBoxMinY();
}

#endif
