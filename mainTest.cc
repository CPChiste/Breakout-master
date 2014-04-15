#include <stdlib.h>
#include <iostream>
#include <cppunit/ui/text/TestRunner.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "ShapeTestFixture.h"
#include "BallTestFixture.h"
//#include "TestBrickGenerator.h"
#include "PaddleTestFixture.h"

int main(void) {
  	///Run our test suite

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(ShapeTestFixture::suite());
	runner.addTest(BallTestFixture::suite());
	//runner.addTest(TestBrickGenerator::suite());
	runner.addTest(PaddleTestFixture::suite());
	runner.run();

	return(0);
}
