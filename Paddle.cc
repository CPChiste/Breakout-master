#include "Paddle.h"
#include "iostream"

Paddle::Paddle(Point o, double w, double h)
{
   if (!al_install_keyboard()) {
      std::cerr << "Cannot initialize the keyboard" << std::endl;
      exit(1); // panic
   }
   origin = o;
   width = w;
   height = h;
   keystate = new ALLEGRO_KEYBOARD_STATE;
}

Paddle::~Paddle()
{
   delete keystate;
   al_uninstall_keyboard();
}

void Paddle::updatePosition(double dt, int minx, int miny, int maxx, int maxy)
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
   
   if (origin.X() < minx) { // colision left side
      origin = Point(minx + 1,origin.Y());
   }
   
   if (origin.X() > maxx - bBoxMaxX()) { // collision right side
      origin = Point(maxx - bBoxMaxX(),origin.Y());
   } 
}

void Paddle::draw() {
   al_draw_filled_rectangle(origin.X(), origin.Y(), origin.X()+width, origin.Y()+height, al_map_rgb(237, 41, 57));
}

double Paddle::bBoxMaxX() {
   return width;
}

double Paddle::bBoxMaxY() {
   return height;
}

double Paddle::bBoxMinX() {
   return origin.X();
}

double Paddle::bBoxMinY() {
   return origin.Y();
}
