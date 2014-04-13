#include "PowerUp.h"
#include <allegro5/allegro_primitives.h>

PowerUp::PowerUp()
{
   length = 10;
   height = 10;
}

double PowerUp::bBoxMaxX() {
   return origin.X() + length;
}

double PowerUp::bBoxMaxY() {
   return origin.Y() + height;
}

double PowerUp::bBoxMinX() {
   return origin.X();
}

double PowerUp::bBoxMinY() {
   return origin.Y();
}
