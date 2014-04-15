#ifndef __BALLTESTFIXTURE_H
#define __BALLTESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Shape.h"
#include "Ball.h"
#include "BallNoPowerUpStrategy.h"

class BallTestFixture : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BallTestFixture);
	CPPUNIT_TEST(TestbBoxMinX);
	CPPUNIT_TEST(TestbBoxMaxX);
	CPPUNIT_TEST(TestbBoxMinY);
	CPPUNIT_TEST(TestbBoxMaxY);
	CPPUNIT_TEST(TestLeftWallCollision);
	CPPUNIT_TEST(TestRightWallCollision);
	CPPUNIT_TEST(TestTopWallCollision);
	CPPUNIT_TEST(TestBottomWallCollision);
	CPPUNIT_TEST_SUITE_END();
private:
	Ball* b;
	Point minWall;
	Point maxWall;
public:
	void setUp() {
	   b = new Ball(Point(100, 100), 10, new BallNoPowerUpStrategy());
	   minWall = Point(0,0);
	   maxWall = Point(200,200);
	}

	void tearDown() {
		delete b;
	}

	void TestbBoxMinX() {
		CPPUNIT_ASSERT(b->bBoxMinX() == 90);
	}

	void TestbBoxMaxX() {
		CPPUNIT_ASSERT(b->bBoxMaxX() == 110);
	}

	void TestbBoxMinY() {
		CPPUNIT_ASSERT(b->bBoxMinY() == 90);
	}

	void TestbBoxMaxY() {
		CPPUNIT_ASSERT(b->bBoxMaxY() == 110);
	}

	void TestLeftWallCollision() {
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == false);
		b->translate(Vector(-100, 0));
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == true);
	}

	void TestTopWallCollision() {
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == false);
		b->translate(Vector(0, -100));
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == true);
	}

	void TestRightWallCollision() {
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == false);
		b->translate(Vector(100, 0));
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == true);
	}

	void TestBottomWallCollision() {
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == false);
		b->translate(Vector(0, 100));
		CPPUNIT_ASSERT(b->checkShapeCollision(minWall.X(), minWall.Y(), maxWall.X(), maxWall.Y()) == true);
	}

};

#endif
