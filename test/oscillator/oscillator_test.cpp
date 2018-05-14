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


TEST_CASE ("Confirm changes to frequency and phase parameters") {
	
	using namespace c74::min;
	using namespace c74::min::lib;
	INFO ("Using an oscillator instance with no arguments, which should set default values of 0.0 phase, 0.0 frequency");
	
	oscillator<> o;
	
	REQUIRE( o.phase() == 0.0 );		// check the defaults
	REQUIRE( o.frequency() == 0.0 );	// ..
	
	INFO ("Changing the phase to 0.25");
	o.phase(0.25);
	REQUIRE( o.phase() == Approx(0.25) );	// check the new value for phase
	REQUIRE( o.frequency() == 0.0 );		// and confirm the default frequency remains
	
	INFO ("Changing the phase to 1.35 should wrap back around");
	o.phase(1.32);
	REQUIRE( o.phase() == Approx(0.32) );	// check the new value for phase
	REQUIRE( o.frequency() == 0.0 );		// and confirm the default frequency remains
	
	INFO ("Changing the phase to -0.15 should wrap back around");
	o.phase(-0.17);
	REQUIRE( o.phase() == Approx(0.83) );	// check the new value for phase
	REQUIRE( o.frequency() == 0.0 );		// and confirm the default frequency remains
	
	INFO ("Changing the frequency to 2000.0 at 96k sampling rate");
	o.frequency(2000.0, 96000.0);
	REQUIRE( o.frequency() == Approx(2000.0) );	// check the new value for frequency
	REQUIRE( o.phase() == Approx(0.83) );		// and confirm the phase remains unchanged
	
	INFO ("Changing the frequency to 2000.0 at 96k sampling rate");
	o.frequency(2000.0, 96000.0);
	REQUIRE( o.frequency() == Approx(2000.0) );	// check the new value for frequency
	REQUIRE( o.phase() == Approx(0.83) );		// and confirm the phase remains unchanged
	
	INFO ("Trying to set frequency above the Nyquist, which should fold back below");
	o.frequency(52000.0, 96000.0);
	REQUIRE( o.frequency() == Approx(44000.0) );	// check the new value for frequency
	REQUIRE( o.phase() == Approx(0.83) );		// and confirm the phase remains unchanged
	
	INFO ("Trying to set frequency above the sampling rate, which should fold back below");
	o.frequency(100000.0, 96000.0);
	REQUIRE( o.frequency() == Approx(-4000.0) );	// check the new value for frequency
	REQUIRE( o.phase() == Approx(0.83) );		// and confirm the phase remains unchanged
	
	INFO ("Trying to set frequency to negative value, which should be allowed");
	o.frequency(-6000.0, 96000.0);
	REQUIRE( o.frequency() == Approx(-6000.0) );	// check the new value for frequency
	REQUIRE( o.phase() == Approx(0.83) );		// and confirm the phase remains unchanged
	
}


TEST_CASE ("Confirm sample operator changes the phase") {
	
	using namespace c74::min;
	using namespace c74::min::lib;
	INFO ("Using an oscillator instance with wavetable size of 256");
	
	oscillator<> o { 256 };
	o.frequency(1.0, 256.0);
	sample output;
	
	INFO ("After 64 samples of output, phase should be 0.25");
	for (int i=0; i < 64; i++)
	{
		output = o();
	}
	REQUIRE( o.phase() == Approx(0.25) );	// check the new value for phase
	
	INFO ("After another 64 samples of output, phase should be 0.5");
	for (int i=0; i < 64; i++)
	{
		output = o();
	}
	REQUIRE( o.phase() == Approx(0.5) );	// check the new value for phase
	
	INFO ("After another 128 samples of output, phase should be 1.0");
	for (int i=0; i < 128; i++)
	{
		output = o();
	}
	REQUIRE( o.phase() == Approx(1.0) );	// check the new value for phase
	
	INFO ("After another 64 samples of output, phase should be back at 0.25");
	for (int i=0; i < 64; i++)
	{
		output = o();
	}
	REQUIRE( o.phase() == Approx(0.25) );	// check the new value for phase
	
	
}

TEST_CASE ("Changes waveform using the generator classes") {
	
	using namespace c74::min;
	using namespace c74::min::lib;
	INFO ("Using an oscillator instance with wavetable size of 256");
	
	oscillator<> o { 256 };
	
	o.change_waveform<generator::ramp_unipolar<>>();
	
	o.change_waveform<generator::ramp<>>();
	
}
