///	@brief 		Unit test for the Sync class
///	@author		Timothy Place, Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "c74_min.h"


SCENARIO ("responds appropriately to messages and attrs") {

	GIVEN ("An instance of the sync class") {
		c74::min::lib::sync	s;

		REQUIRE( s.phase() == 0.0 );

		WHEN ("phase is set within a valid range") {
			s.phase(0.25);
			THEN("phase is set to the value specified");
			REQUIRE( s.phase() == Approx(0.25) );
		}
		AND_WHEN ("setting phase param over range") {
			s.phase(1.3);
			THEN("phase is wrapped into range (integral part is discarded)" );
			REQUIRE( s.phase() == Approx(0.3) );
		}
		AND_WHEN ("setting phase param way over range") {
			s.phase(2.45);
			THEN("phase is wrapped into range (integral part is discarded)" );
			REQUIRE( s.phase() == Approx(0.45) );
		}
		AND_WHEN ("setting phase param under range") {
			s.phase(-1.3);
			THEN( "phase is wrapped into range" );
			REQUIRE( s.phase() == Approx(0.7) );
		}

		// There is no gain or offset parameter because we are calculating single-sample and
		// this class is kept to its essential function

		WHEN ("frequency is set within a valid range") {
			s.frequency(1000.0, 96000.0);
			THEN("frequency is set to the value specified");
			REQUIRE( s.frequency() == Approx(1000.0) );
		}
		AND_WHEN ("setting frequency param way above range 1") {
			s.frequency(50000.0, 96000.0);
			THEN("frequency is folded back down into range");
			REQUIRE( s.frequency() == Approx(46000.0) );
		}
		AND_WHEN ("setting frequency param way above range 2") {
			s.frequency(98000.0, 96000.0);
			THEN("frequency is folded back down into range");
			REQUIRE( s.frequency() == Approx(-2000.0) );
		}
		AND_WHEN ("setting frequency param below range") {
			s.frequency(-2000.0, 96000.0);
			THEN("frequency is set to the value specified");
			REQUIRE( s.frequency() == Approx(-2000.0) );
		}
	}
}

