/// @file
///	@brief 		Unit test for the oscillator filter class
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"


TEST_CASE ("Produce the correct output using default constructor") {
	
	using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an oscillator instance with no arguments");
    
    oscillator o;
	
}
