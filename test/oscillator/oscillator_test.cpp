/// @file
///	@brief 		Unit test for the oscillator filter class
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"


TEST_CASE ("Produce correctly sized wavetables using constructor parameters") {
	
	using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an oscillator instance with no arguments, creates a wavetable with 4096 samples");
    
    oscillator<> o;
	
	REQUIRE( o.size() == 4096 );		// check the defaults
	
	INFO ("Using oscillator with argument set to 512, creates a properly sized wavetable");
	
	oscillator<> o2(512);
	
	REQUIRE( o2.size() == 512 );		// check the defaults
	
	INFO ("Using oscillator with argument set to 16384, creates a properly sized wavetable");
	
	oscillator<> o3(16384);
	
	REQUIRE( o3.size() == 16384 );		// check the defaults
	
}
