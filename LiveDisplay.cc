#include "LiveDisplay.h"
#include <iostream>
#include <string>

LiveDisplay::LiveDisplay(int _lives = 3)
{
   lives = _lives;
   al_init_font_addon();
   if(!al_init_ttf_addon())
   {
      std::cerr << "Cannot initialize allegro font library" << std::endl;
      exit(1); // panic
   }
   liveFont = al_load_ttf_font("Fixedsys500c.ttf", 30, 0);
   if(liveFont == NULL)
   {
      std::cerr << "Cannot initialize font" << std::endl;
      exit(1); // panic
   }
}

LiveDisplay::~LiveDisplay()
{
   al_destroy_font(liveFont);
   al_shutdown_ttf_addon();
   al_shutdown_font_addon();
}

//default parameters don't work suddenly?
int LiveDisplay::addLives()
{
   return addLives(1);
}
int LiveDisplay::addLives(int toAdd = 1)
{
   return lives = lives + toAdd;
}
int LiveDisplay::loseLives()
{
   return loseLives(1);
}
int LiveDisplay::loseLives(int toLose = 1)
{
   return addLives(0 - toLose);
}

const char* LiveDisplay::lifeString()
{
   std::string text = " LIVES: " + std::to_string(static_cast<long long>(lives));
   return text.c_str();
}

void LiveDisplay::draw(bool gameOver)
{
   if (gameOver)
   {
      al_draw_text(liveFont, al_map_rgb(255, 255, 255), 300, 200, 0, std::string(" GAME OVER").c_str());
   }
   else
   {
      al_draw_text(liveFont, al_map_rgb(255, 255, 255), 1, 1, 0, lifeString());
   }
}
