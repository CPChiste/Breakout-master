#include <stdlib.h>
#include <iostream>
#include <cppunit/ui/text/TestRunner.h>
#include <allegro5/allegro_primitives.h>

#include "ShapeTestFixture.h"
#include "BallTestFixture.h"

int main(void) {
	///Run our test suite
	
<<<<<<< HEAD
	//CppUnit::TextUi::TestRunner runner;
	//runner.addTest(TestBrickGenerator::suite());
	//runner.run();
=======
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(ShapeTestFixture::suite());
	runner.addTest(BallTestFixture::suite());
	runner.run();
>>>>>>> 604d38171d7af1ff7fa22aa9f808a0a394bb96cc
	
	return(0);
}
