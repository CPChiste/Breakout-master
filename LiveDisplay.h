#ifndef __LIVEDISPLAY_H
#define __LIVEDISPLAY_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class LiveDisplay {
  private:
   int lives;
   ALLEGRO_FONT *liveFont;
  public:
   LiveDisplay();
   LiveDisplay(int);
   ~LiveDisplay();

   int addLives(int);
   int addLives();
   void draw(bool);
   int loseLives(int);
   int loseLives();
   const char* lifeString();
};

#endif
