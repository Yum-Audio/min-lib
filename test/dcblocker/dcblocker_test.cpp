///	@brief 		Unit test for the dcblocker class
///	@author		Timothy Place, Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "c74_min.h"


SCENARIO ("produce the correct impulse response") {

	GIVEN ("An instance of the dcblocker class") {
		c74::min::lib::dcblocker f;

		WHEN ("processing a 64-sample impulse") {

			// create an impulse buffer to process
			const int				buffersize = 64;
			c74::min::sample_vector	impulse(buffersize);

			std::fill_n(impulse.begin(), buffersize, 0.0);
			impulse[0] = 1.0;

			// output from our object's processing
			c74::min::sample_vector	output;

			// run the calculations
			for (auto x : impulse) {
				auto y = f(x);
				output.push_back(y);
			}

			// get a reference impulse response to compare against
			auto reference = c74::min::filters::generate_impulse_response({1.0,-1.0}, {1.0,-0.9997}, buffersize);

			THEN("The result produced matches an externally produced reference impulse");
			REQUIRE( output == reference );
		}
	}
}
