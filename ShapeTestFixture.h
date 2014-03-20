#ifndef __SHAPETESTFIXTURE_H
#define __SHAPETESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Shape.h"
#include "Brick.h"

class ShapeTestFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(ShapeTestFixture);
	CPPUNIT_TEST(TestLineIntersectsShapeIsTrue);
	CPPUNIT_TEST(TestLineIntersectsShapeIsFalse);
	CPPUNIT_TEST_SUITE_END();
private:
	Shape* s;
public:
	void setUp() {
		s = new Brick(Point(100, 150), 130, 100);
	}

	void tearDown() {
		delete s;
	}

	void TestLineIntersectsShapeIsTrue() {
		CPPUNIT_ASSERT(s->lineIntersects(10, 10, 400, 400) == true);
		CPPUNIT_ASSERT(s->lineIntersects(10, 10, 200, 400) == true);
		CPPUNIT_ASSERT(s->lineIntersects(10, 10, 150, 180) == true);
	}

	void TestLineIntersectsShapeIsFalse() {
		CPPUNIT_ASSERT(s->lineIntersects(10, 10, 400, 20) == false);
		CPPUNIT_ASSERT(s->lineIntersects(10, 10, 400, 200) == false);
		CPPUNIT_ASSERT(s->lineIntersects(10, 10, 140, 150) == false);
	}
};

#endif