///	@brief 		Unit test for the easing classes
///	@author		Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"

SCENARIO ("Using Linear Easing") {
    
    // bring in the octave reference set here
    
	GIVEN ("A for loop that generates 64 steps from 0 to 1") {
		for (auto i = 0; i < 64; i++) {
			auto x = i / 63;
            
            WHEN("The entire length is filled by a 'ramp' generator for the sample type.") {
                INFO("when i == " << i);
                THEN("The output matches an externally generated reference set.")
                REQUIRE( x == Approx(1.0) );
                
            }
            
		}
	
	}
}