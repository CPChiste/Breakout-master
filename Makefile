## CFLAGS = -I /home/lib2720/allegro5/include/ -Wall
## LIBDIR = /home/lib2720/allegro5/lib/

CFLAGS = -I /home/lib2720/allegro5/include -std=c++0x
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
COMMONOBJECTS = Display.o Simulator.o ShapeSimulator.o Shape.o Ball.o Brick.o BrickGenerator.o
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
