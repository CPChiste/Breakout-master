#include "Display.h"
#include "BreakoutSimulator.h"
#include "Ball.h"
#include "Paddle.h"
#include "BrickGenerator.h"
#include "Paddle.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <ncurses.h>

int main(void) {  
   initscr();
   noecho();
   cbreak();
   keypad(stdscr, TRUE);
   mvprintw(0,0,"Press q to quit, Spacebar to play.");

   int ch = getch();

   while (ch != ERR && ch != 'Q' && ch != 'q') {
      if(ch == ' ')
      {
	 Display disp;  // create a 1000x1000 window
	 BreakoutSimulator sim(disp, 100);
	 BrickGenerator brickGen(disp.getW(), disp.getH());
	 
	 sim = brickGen.generateBricks(sim);
	 
	 sim.addBall(new Ball(Point(400, 400), Vector(200, 200), 8));
	 sim.addPaddle(new Paddle(Point(400, 500), 150, 20));
	 
	 sim.run();

	 ch = getch();
      }
   }
   return 0;
}
