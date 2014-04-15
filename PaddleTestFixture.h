#ifndef __PADDLETESTFIXTURE_H
#define __PADDLETESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Shape.h"
#include "Paddle.h"
#include "PaddleNoPowerUpStrategy.h"

class PaddleTestFixture : public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE(PaddleTestFixture);
//   CPPUNIT_TEST(TestbBoxMinX);
//   CPPUNIT_TEST(TestbBoxMaxX);
//   CPPUNIT_TEST(TestbBoxMinY);
//   CPPUNIT_TEST(TestbBoxMaxY);
//   CPPUNIT_TEST(TestLeftWallCollision);
//   CPPUNIT_TEST(TestRightWallCollision);
   CPPUNIT_TEST_SUITE_END();
  private:
   Paddle* p;
  public:
   void setUp() {
      p = new Paddle(Point(400, 550), 20, new PaddleNoPowerUpStrategy());
   }

   void tearDown() {
      delete p;
   }

   void TestbBoxMinX() {
      CPPUNIT_ASSERT(p->bBoxMinX() == 400);
   }

   void TestbBoxMaxX() {
      CPPUNIT_ASSERT(p->bBoxMaxX() == 550);
   }

   void TestbBoxMinY() {
      CPPUNIT_ASSERT(p->bBoxMinY() == 550);
   }

   void TestbBoxMaxY() {
      CPPUNIT_ASSERT(p->bBoxMaxY() == 570);
   }

/*   void TestLeftWallCollision() {
      p->updatePosition(10, 0, 0, 800, 600);
      CPPUNIT_ASSERT(p->bBoxMinX() >= 0);
   }

   void TestRightWallCollision() {
      p->updatePosition(-10, 0, 0, 800, 600);
      CPPUNIT_ASSERT(p->bBoxMaxX() <= 800);
      }*/
};
#endif
