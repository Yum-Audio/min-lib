///	@brief 		Unit test for the allpass filter class
///	@author		Timothy Place
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"


SCENARIO ("Produce the correct impulse response") {

	GIVEN ("An instance of the allpass filter class") {
		c74::min::lib::allpass	f;

		REQUIRE( f.gain() == 0.0 );		// check the defaults
		REQUIRE( f.delay() == 4410 );	// ...

		f.delay(1);
		f.gain(0.5);

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

			// coefficients calculated in Octave
			//	a = [0.5, 1.0];	% numerator (fir)
			//	b = [1.0, 0.5];	% denominator (iir)
			//	i = impz(a, b, 64);

			c74::min::sample_vector reference = {
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

			THEN("The result produced matches an externally produced reference impulse")

			// check it
			REQUIRE_VECTOR_APPROX(output, reference);
		}
	}
}

SCENARIO ("Using non-default settings") {
    
    WHEN ("Overriding the default capacity for allpass filter") {
        c74::min::lib::allpass	f(4800);
        
        THEN("The size has been set correctly.")
        
        REQUIRE( f.delay() == 4800 );
    
        WHEN("Changing the size to less than default capacity") {
            
            f.delay(1000);
            
            THEN("The size has been set correctly.")
            
            REQUIRE( f.delay() == 1000 );
            

        
            WHEN ("processing a 1100-sample impulse") {
                // create an impulse buffer to process
                const int				buffersize = 1100;
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
                
            }
            
            // What can we test here?
            
            WHEN("Changing the size again to a higher value, but still less than default capacity")
            
            f.delay(2000);
            
            THEN("The size has been set correctly.")
            
            REQUIRE( f.delay() == 2000 );
            
            WHEN ("processing another 1100-sample impulse") {
                // create an impulse buffer to process
                const int				buffersize = 1100;
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
                
            }
            
            // What can we test here?
            
        }
        
    }
    
}

