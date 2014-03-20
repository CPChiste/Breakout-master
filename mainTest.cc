#include <stdlib.h>
#include <iostream>
#include <cppunit/ui/text/TestRunner.h>
#include <allegro5/allegro_primitives.h>

#include "ShapeTestFixture.h"
#include "BallTestFixture.h"

int main(void) {
	///Run our test suite
	
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(ShapeTestFixture::suite());
	runner.addTest(BallTestFixture::suite());
	runner.run();
	
	return(0);
}