#ifndef __TESTBRICKGENERATOR_H
#define __TESTBRICKGENERATOR_H

#include "Display.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BrickGenerator.h"
#include "BreakoutSimulator.h"
#include <list>

class Display;

class TestBrickGenerator : public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE(TestBrickGenerator);
   CPPUNIT_TEST(testBricksInBounds);
   CPPUNIT_TEST_SUITE_END();

  private:
   BrickGenerator * bg;
   std::list<Brick*> * brickList;
   Display * disp;
   BreakoutSimulator sim;
  public:
   void setUp()
   {
      bg = new BrickGenerator;
      brickList = new std::list<Brick*>;
      disp = new Display;
      sim = new BreakoutSimulator(disp(800,600), 100);
   }

   void tearDown()
   {
      delete bg;
   }

   void testBricksInBounds() {
      sim = bg->generateBricks(sim);
      for(auto it : brickList)
	 CPPUNIT_ASSERT(it.bBoxMaxX() >= 0 && it.bBoxMaxX() <= disp.getW()
			&& it.bBoxMaxY() >= 0 && it.bBoxMaxY() <= disp.getH()
			&& it.bBoxMinX() >= 0 && it.bBoxMinX() <= disp.getW()
			&& it.bBoxMinY() >= 0 && it.bBoxMinY() <= disp.getH());
   }
};
#endif
