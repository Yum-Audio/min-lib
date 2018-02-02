///	@brief 		Unit test for the allpass filter class
///	@author		Timothy Place, Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"


TEST_CASE ("Produce the correct impulse response using default constructor") {

    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with no arguments, which sets default gain at 0.0 and capacity to 4410 samples");
    
    allpass	f;
    REQUIRE( f.gain() == 0.0 );		// check the defaults
    REQUIRE( f.delay() == 4410 );	// ...
    
    INFO("Changing the delay time to 1 sample & gain to 0.5...");
    f.delay(1);
    f.gain(0.5);
    REQUIRE( f.delay() == 1 );     // check the new value
    REQUIRE( f.gain() == 0.5 );		// check the new value

    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector zero(64, 0.0);
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;

    // output from our object's processing
    sample_vector	output;

    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }

    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //	a1 = [0.5, 1.0]; % fir coefficients
    //  b1 = [1.0, 0.5]; % iir coefficients

    sample_vector reference = {
        0.500000000000000    ,
        0.750000000000000    ,
        -0.375000000000000   ,
        0.187500000000000    ,
        -0.0937500000000000  ,
        0.0468750000000000   ,
        -0.0234375000000000  ,
        0.0117187500000000   ,
        -0.00585937500000000 ,
        0.00292968750000000  ,
        -0.00146484375000000 ,
        0.000732421875000000 ,
        -0.000366210937500000,
        0.000183105468750000 ,
        -9.15527343750000e-05,
        4.57763671875000e-05 ,
        -2.28881835937500e-05,
        1.14440917968750e-05 ,
        -5.72204589843750e-06,
        2.86102294921875e-06 ,
        -1.43051147460938e-06,
        7.15255737304688e-07 ,
        -3.57627868652344e-07,
        1.78813934326172e-07 ,
        -8.94069671630859e-08,
        4.47034835815430e-08 ,
        -2.23517417907715e-08,
        1.11758708953857e-08 ,
        -5.58793544769287e-09,
        2.79396772384644e-09 ,
        -1.39698386192322e-09,
        6.98491930961609e-10 ,
        -3.49245965480804e-10,
        1.74622982740402e-10 ,
        -8.73114913702011e-11,
        4.36557456851006e-11 ,
        -2.18278728425503e-11,
        1.09139364212751e-11 ,
        -5.45696821063757e-12,
        2.72848410531878e-12 ,
        -1.36424205265939e-12,
        6.82121026329696e-13 ,
        -3.41060513164848e-13,
        1.70530256582424e-13 ,
        -8.52651282912120e-14,
        4.26325641456060e-14 ,
        -2.13162820728030e-14,
        1.06581410364015e-14 ,
        -5.32907051820075e-15,
        2.66453525910038e-15 ,
        -1.33226762955019e-15,
        6.66133814775094e-16 ,
        -3.33066907387547e-16,
        1.66533453693773e-16 ,
        -8.32667268468867e-17,
        4.16333634234434e-17 ,
        -2.08166817117217e-17,
        1.04083408558608e-17 ,
        -5.20417042793042e-18,
        2.60208521396521e-18 ,
        -1.30104260698261e-18,
        6.50521303491303e-19 ,
        -3.25260651745651e-19,
        1.62630325872826e-19
    };

    // check it
    REQUIRE_VECTOR_APPROX(output, reference);

}

TEST_CASE ("Produce the correct impulse response after constructor with initial values") {
    
		using namespace c74::min;
		using namespace c74::min::lib;
		INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 10 samples");

		allpass	f { 10 };
		REQUIRE( f.gain() == 0.0 );		// check the default value
		REQUIRE( f.delay() == 10 );     // check the initialized value

		INFO("Changing the delay time to 1 sample & gain to 0.5...");
		f.delay(1);
		f.gain(0.5);
		REQUIRE( f.delay() == 1 );     // check the new value
		REQUIRE( f.gain() == 0.5 );		// check the new value

		INFO ("And then pushing a 64-sample impulse through the unit...");
		sample_vector impulse(64, 0.0);
		impulse[0] = 1.0;

		// output from our object's processing
		sample_vector	output;

		// run the calculations
		for (auto x : impulse) {
				auto y = f(x);
				output.push_back(y);
		}

		INFO ("And finally checking our output against a reference produced with Octave.");
		// coefficients calculated in Octave using impz(a,b,64)
		//	a1 = [0.5, 1.0]; % fir coefficients
		//  b1 = [1.0, 0.5]; % iir coefficients

		sample_vector reference = {
				0.500000000000000    ,
				0.750000000000000    ,
				-0.375000000000000   ,
				0.187500000000000    ,
				-0.0937500000000000  ,
				0.0468750000000000   ,
				-0.0234375000000000  ,
				0.0117187500000000   ,
				-0.00585937500000000 ,
				0.00292968750000000  ,
				-0.00146484375000000 ,
				0.000732421875000000 ,
				-0.000366210937500000,
				0.000183105468750000 ,
				-9.15527343750000e-05,
				4.57763671875000e-05 ,
				-2.28881835937500e-05,
				1.14440917968750e-05 ,
				-5.72204589843750e-06,
				2.86102294921875e-06 ,
				-1.43051147460938e-06,
				7.15255737304688e-07 ,
				-3.57627868652344e-07,
				1.78813934326172e-07 ,
				-8.94069671630859e-08,
				4.47034835815430e-08 ,
				-2.23517417907715e-08,
				1.11758708953857e-08 ,
				-5.58793544769287e-09,
				2.79396772384644e-09 ,
				-1.39698386192322e-09,
				6.98491930961609e-10 ,
				-3.49245965480804e-10,
				1.74622982740402e-10 ,
				-8.73114913702011e-11,
				4.36557456851006e-11 ,
				-2.18278728425503e-11,
				1.09139364212751e-11 ,
				-5.45696821063757e-12,
				2.72848410531878e-12 ,
				-1.36424205265939e-12,
				6.82121026329696e-13 ,
				-3.41060513164848e-13,
				1.70530256582424e-13 ,
				-8.52651282912120e-14,
				4.26325641456060e-14 ,
				-2.13162820728030e-14,
				1.06581410364015e-14 ,
				-5.32907051820075e-15,
				2.66453525910038e-15 ,
				-1.33226762955019e-15,
				6.66133814775094e-16 ,
				-3.33066907387547e-16,
				1.66533453693773e-16 ,
				-8.32667268468867e-17,
				4.16333634234434e-17 ,
				-2.08166817117217e-17,
				1.04083408558608e-17 ,
				-5.20417042793042e-18,
				2.60208521396521e-18 ,
				-1.30104260698261e-18,
				6.50521303491303e-19 ,
				-3.25260651745651e-19,
				1.62630325872826e-19
		};

		// check it
		REQUIRE_VECTOR_APPROX(output, reference);
    
}


TEST_CASE ("Using other non-default settings") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments");
    
    allpass	f { 4800 };
        
    INFO("Confirming the size has been set correctly to match the initial argument.");
    REQUIRE( f.delay() == 4800 );
    
    INFO("Decreasing the delay time to 1000 samples, which is less than capacity...");
    f.delay(1000);
    REQUIRE( f.delay() == 1000 );     // check the new value
    
    INFO("Increasing the delay time to 2000 samples, which is higher but still less than capacity...");
    f.delay(2000);
    REQUIRE( f.delay() == 2000 );     // check the new value
    
    INFO("Decreasing the delay time to 2 samples, which is very small...");
    f.delay(2);
    REQUIRE( f.delay() == 2 );     // check the new value
    
    
}

TEST_CASE ("Produce the correct impulse response for 2 samples delay, 0.75 gain") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 2 samples");
    
    allpass	f { 2 };
    REQUIRE( f.gain() == 0.0 );		// check the default value
    REQUIRE( f.delay() == 2 );     // check the initialized value
    
    INFO("Changing the gain to 0.75...");
    f.gain(0.75);
    REQUIRE( f.gain() == 0.75 );		// check the new value
    
    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;
    
    // output from our object's processing
    sample_vector	output;
    
    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }
    
    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //	a2 = [0.75, 0.0, 1.0]; % fir coefficients
    //  b2 = [1.0, 0.0, 0.75]; % iir coefficients
    
    sample_vector reference = {
        0.75,
        0,
        0.4375,
        0,
        -0.328125,
        0,
        0.24609375,
        0,
        -0.1845703125,
        0,
        0.138427734375,
        0,
        -0.10382080078125,
        0,
        0.0778656005859375,
        0,
        -0.05839920043945312,
        0,
        0.04379940032958984,
        0,
        -0.03284955024719238,
        0,
        0.02463716268539429,
        0,
        -0.01847787201404572,
        0,
        0.01385840401053429,
        0,
        -0.01039380300790071,
        0,
        0.007795352255925536,
        0,
        -0.005846514191944152,
        0,
        0.004384885643958114,
        0,
        -0.003288664232968586,
        0,
        0.002466498174726439,
        0,
        -0.001849873631044829,
        0,
        0.001387405223283622,
        0,
        -0.001040553917462717,
        0,
        0.0007804154380970374,
        0,
        -0.000585311578572778,
        0,
        0.0004389836839295835,
        0,
        -0.0003292377629471877,
        0,
        0.0002469283222103907,
        0,
        -0.0001851962416577931,
        0,
        0.0001388971812433448,
        0,
        -0.0001041728859325086,
        0,
        7.812966444938144e-05,
        0
    };
    
    // check it
    REQUIRE_VECTOR_APPROX(output, reference);
}

TEST_CASE ("Produce the correct impulse response for for 4 samples delay, 0.5 gain") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 4 samples");
    
    allpass	f { 4 };
    REQUIRE( f.gain() == 0.0 );		// check the default value
    REQUIRE( f.delay() == 4 );     // check the initialized value
    
    INFO("Changing the gain to 0.5...");
    f.gain(0.5);
    REQUIRE( f.gain() == 0.5 );		// check the new value
    
    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;
    
    // output from our object's processing
    sample_vector	output;
    
    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }
    
    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //	a4 = [0.5, 0.0, 0.0, 0.0, 1.0]; % fir coefficients
    //  b4 = [1.0, 0.0, 0.0, 0.0, 0.5]; % iir coefficients
    
    sample_vector reference = {
        0.5,
        0,
        0,
        0,
        0.75,
        0,
        0,
        0,
        -0.375,
        0,
        0,
        0,
        0.1875,
        0,
        0,
        0,
        -0.09375,
        0,
        0,
        0,
        0.046875,
        0,
        0,
        0,
        -0.0234375,
        0,
        0,
        0,
        0.01171875,
        0,
        0,
        0,
        -0.005859375,
        0,
        0,
        0,
        0.0029296875,
        0,
        0,
        0,
        -0.00146484375,
        0,
        0, 
        0, 
        0.000732421875, 
        0, 
        0, 
        0, 
        -0.0003662109375, 
        0, 
        0, 
        0, 
        0.00018310546875, 
        0, 
        0, 
        0, 
        -9.1552734375e-05, 
        0, 
        0, 
        0, 
        4.57763671875e-05, 
        0, 
        0, 
        0
    };
    
    // check it
    REQUIRE_VECTOR_APPROX(output, reference);
}

TEST_CASE ("Produce the correct impulse response for for 6 samples delay, -0.25 gain") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 6 samples");
    
    allpass	f { 6 };
    REQUIRE( f.gain() == 0.0 );		// check the default value
    REQUIRE( f.delay() == 6 );     // check the initialized value
    
    INFO("Changing the gain to -0.25...");
    f.gain(-0.25);
    REQUIRE( f.gain() == -0.25 );		// check the new value
    
    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;
    
    // output from our object's processing
    sample_vector	output;
    
    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }
    
    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //  a6 = [-0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0]; % fir coefficients
    //  b6 = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.25]; % iir coefficients
    
    sample_vector reference = {
        -0.25,
        0,
        0,
        0,
        0,
        0,
        0.9375,
        0,
        0,
        0,
        0,
        0,
        0.234375,
        0,
        0,
        0,
        0,
        0,
        0.05859375,
        0,
        0,
        0,
        0,
        0,
        0.0146484375,
        0,
        0,
        0,
        0,
        0,
        0.003662109375,
        0, 
        0, 
        0, 
        0, 
        0, 
        0.00091552734375, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0.0002288818359375, 
        0, 
        0, 
        0, 
        0, 
        0, 
        5.7220458984375e-05, 
        0, 
        0, 
        0, 
        0, 
        0, 
        1.430511474609375e-05, 
        0, 
        0, 
        0, 
        0, 
        0, 
        3.576278686523438e-06, 
        0, 
        0, 
        0
    };
    
    // check it
    REQUIRE_VECTOR_APPROX(output, reference);
}

TEST_CASE ("Produce the correct impulse response for 7 samples delay, -0.65 gain") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 7 samples");
    
    allpass	f { 7 };
    REQUIRE( f.gain() == 0.0 );		// check the default value
    REQUIRE( f.delay() == 7 );     // check the initialized value
    
    INFO("Changing the gain to -0.65...");
    f.gain(-0.65);
    REQUIRE( f.gain() == -0.65 );		// check the new value
    
    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;
    
    // output from our object's processing
    sample_vector	output;
    
    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }
    
    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //	a7 = [-0.65, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0]; % fir coefficients
    //  b7 = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.65]; % iir coefficients
    
    sample_vector reference = {
        -0.65,
        0,
        0,
        0,
        0,
        0,
        0,
        0.5774999999999999,
        0,
        0,
        0,
        0,
        0,
        0,
        0.375375,
        0,
        0,
        0,
        0,
        0,
        0,
        0.24399375,
        0,
        0,
        0,
        0,
        0,
        0,
        0.1585959375,
        0, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0.103087359375, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0.06700678359375001, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0.04355440933593751, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0.02831036606835938, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0, 
        0.0184017379444336
    };
    
    // check it
    REQUIRE_VECTOR_APPROX(output, reference);
}

TEST_CASE ("Produce the correct impulse response for for 8 samples delay, 0.05 gain") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 8 samples");
    
    allpass	f { 8 };
    REQUIRE( f.gain() == 0.0 );		// check the default value
    REQUIRE( f.delay() == 8 );     // check the initialized value
    
    INFO("Changing the gain to 0.05...");
    f.gain(0.05);
    REQUIRE( f.gain() == 0.05 );		// check the new value
    
    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;
    
    // output from our object's processing
    sample_vector	output;
    
    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }
    
    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //  a8 = [0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0]; % fir coefficients
    //  b8 = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05]; % iir coefficients
    
    sample_vector reference = {
        0.05,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0.9975000000000001,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        -0.049875,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0.00249375,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        -0.0001246875,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        6.234375000000001e-06,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        -3.117187500000001e-07,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1.55859375e-08,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    };
    
    // check it
    REQUIRE_VECTOR_APPROX(output, reference);
}

TEST_CASE ("Produce the correct impulse response for for 12 samples delay, 0.99 gain") {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    INFO ("Using an allpass instance with arguments, which should set default gain at 0.0 and new capacity to 12 samples");
    
    allpass	f { 12 };
    REQUIRE( f.gain() == 0.0 );		// check the default value
    REQUIRE( f.delay() == 12 );     // check the initialized value
    
    INFO("Changing the gain to 0.99...");
    f.gain(0.99);
    REQUIRE( f.gain() == 0.99 );		// check the new value
    
    INFO ("And then pushing a 64-sample impulse through the unit...");
    sample_vector impulse(64, 0.0);
    impulse[0] = 1.0;
    
    // output from our object's processing
    sample_vector	output;
    
    // run the calculations
    for (auto x : impulse) {
        auto y = f(x);
        output.push_back(y);
    }
    
    INFO ("And finally checking our output against a reference produced with Octave.");
    // coefficients calculated in Octave using impz(a,b,64)
    //	a12 = [0.99, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0]; % fir coefficients
    //  b12 = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.99]; % iir coefficients
    
    sample_vector reference = {
        0.99,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0.01990000000000003,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        -0.01970100000000003,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0.01950399000000003,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        -0.01930895010000003,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0.01911586059900003,
        0,
        0,
        0
    };
    
    // check it
    REQUIRE_VECTOR_APPROX(output, reference);
}

// NW: developed in response to issue here: https://github.com/nwolek/min-verbs/issues/5
TEST_CASE( "survives a sudden drop in delay time without crashing" ) {
    
    using namespace c74::min;
    using namespace c74::min::lib;
    
    size_t test_size = 44100;
    
    INFO( "Start with a new instance of the allpass object." );
    // create an instance of our object
    allpass my_object { test_size };
    
    // create a vector to save output from our object's processing
    sample_vector	output;
    
    INFO( "Setup an impulse that is just shorter than the allpass circular_storage." );
    // create an impulse buffer to process
    const int		buffersize = 64;
    sample_vector	impulse(buffersize, 0.0);
    impulse[0] = 1.0;



    // change the delay_time to something larger than the default
    INFO( "Change the delay_time attribute to 44 samples (approx 1 ms)." );
    my_object.delay(44);
	my_object.gain(0.5);
    
    REQUIRE( my_object.delay() == 44 );
    // note that this is our object's attribute only
    // value does not actually get changed for the allpass circular_storage until the next call to its sample_operator
    
    // run the calculations
    INFO( "Push the impulse sample_vector through the allpass object one time." );
	for (auto i=0; i<10000; ++i)
    for (auto x : impulse) {
        auto y = my_object(x);
        output.push_back(y);
    }


	// change the delay_time to something larger than the default
	INFO( "Change the delay_time attribute UP to 441 samples (approx 10 ms)." );
	my_object.delay(441);
	REQUIRE( my_object.delay() == 441 );

	// run the calculations
	INFO( "Push the impulse sample_vector through the allpass object one time." );
	for (auto i=0; i<10000; ++i)
	for (auto x : impulse) {
		auto y = my_object(x);
		output.push_back(y);
	}

    
    // change the delay_time to something smaller
    INFO( "Change the delay_time attribute BACK DOWB to 44 samples (approx 1 ms)." );
    my_object.delay(44);
    REQUIRE( my_object.delay() == 44 );

    // run the calculations again, which should wrap around the internal circular_storage
    INFO( "Push the impulse sample_vector through the allpass object another time." );
	for (auto i=0; i<10000; ++i)
    for (auto x : impulse) {
        // CRASH HAPPENS HERE
        auto y = my_object(x);
        output.push_back(y);
    }
    
    REQUIRE( output != impulse );
    
}
