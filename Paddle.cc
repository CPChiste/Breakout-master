#include "Paddle.h"
#include <iostream>

Paddle::Paddle(Point o, double h, PaddlePowerUpStrategy p) : Shape(o), height(h), powerUp(p) {
   if (!al_install_keyboard()) {
      std::cerr << "Cannot initialize the keyboard" << std::endl;
      exit(1); // panic
   }
   keystate = new ALLEGRO_KEYBOARD_STATE;

   width = powerUp->width(width);
}

Paddle::~Paddle()
{
   delete keystate;
   al_uninstall_keyboard();
}

void Paddle::updatePosition(double dt, int minX, int minY, int maxX, int maxY)
{
   al_get_keyboard_state(keystate);
   speed = Vector(0,0);
   if(al_key_down(keystate,ALLEGRO_KEY_LEFT))
   {
      speed = speed - Vector(300,0);
   }
   if(al_key_down(keystate,ALLEGRO_KEY_RIGHT))
   {
      speed = speed + Vector(300,0);
   }
   
   origin = origin + speed*dt;
   
   if (bBoxMinX() < minX) { // colision left side
      origin = Point(minX, origin.Y());
   }
   
   if (bBoxMaxX() > maxX) { // collision right side
      origin = Point(maxX - width, origin.Y());
   } 
}

void Paddle::draw() {
   al_draw_filled_rounded_rectangle(origin.X(), origin.Y(), origin.X()+width, origin.Y()+height, 10, 10, al_map_rgb(237, 41, 237));
}

void Paddle::setPowerUp(PaddlePowerUpStrategy p) {
  delete powerUp;
  powerUp = p;
  width = powerUp->width(width);
}

double Paddle::bBoxMaxX() {
   return origin.X() + width;
}

double Paddle::bBoxMaxY() {
   return origin.Y() + height;
}

double Paddle::bBoxMinX() {
   return origin.X();
}

double Paddle::bBoxMinY() {
   return origin.Y();
}
