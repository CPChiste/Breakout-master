##   LAB BUILDS
##CFLAGS = -I /home/lib2720/allegro5/include -std=c++0x
##LIBDIR = /home/lib2720/allegro5/lib/

##  KIERNAN BUILDS
##CFLAGS = -I /usr/include/allegro5 -std=c++0x
##LIBDIR = /usr/lib


CFLAGS = -I /home/lib2720/allegro5/include -std=c++0x
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives -lallegro_image -lcppunit -ldl
COMMONOBJECTS = Display.o Simulator.o BreakoutSimulator.o Shape.o Ball.o Paddle.o Brick.o BrickGenerator.o
OBJECTS = main.o
TESTOBJS = mainTest.o
CC = g++

all: breakout tests

breakout: $(COMMONOBJECTS) $(OBJECTS)
	$(CC) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

tests: $(COMMONOBJECTS) $(TESTOBJS)
	$(CC) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 


%.o : %.cc
	g++ $(CFLAGS) -c $< -o $@
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d

.PHONY : clean
clean :
	rm -f *.o *~ *.d

## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJECTS)))
