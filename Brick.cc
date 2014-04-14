#include "Brick.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>


Brick::Brick(Point o, double l, double h, bool d) : Shape(o), length(l), height(h) , destroyed(d) {
   std::string texture = "brick" + std::to_string(static_cast<long long>(rand() % 5)) + ".png";
   image = al_load_bitmap(texture.c_str());
   if(image == NULL)
   {
      std::cerr << "Cannot allocate brick bitmap" << std::endl;
      exit(1); // panic
   }
};

void Brick::draw() {
   if(!destroyed)
   {
      al_draw_bitmap(image, origin.X(), origin.Y(), 0);
   }
}

bool Brick::isDestroyed()
{
   return destroyed;
}

void Brick::setDestroyed(bool isHit)
{
   destroyed = isHit;
}

double Brick::bBoxMaxX() {
   return origin.X() + length;
}

double Brick::bBoxMaxY() {
   return origin.Y() + height;
}

double Brick::bBoxMinX() {
   return origin.X();
}

double Brick::bBoxMinY() {
   return origin.Y();
}
