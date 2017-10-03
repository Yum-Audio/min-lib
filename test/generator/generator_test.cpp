///	@brief 		Unit test for the interpolator classes
///	@author		Timothy Place, Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"


SCENARIO ("Generate a Ramp") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'ramp' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				-1,
				-0.96875,
				-0.9375,
				-0.90625,
				-0.875,
				-0.84375,
				-0.8125,
				-0.78125,
				-0.75,
				-0.71875,
				-0.6875,
				-0.65625,
				-0.625,
				-0.59375,
				-0.5625,
				-0.53125,
				-0.5,
				-0.46875,
				-0.4375,
				-0.40625,
				-0.375,
				-0.34375,
				-0.3125,
				-0.28125,
				-0.25,
				-0.21875,
				-0.1875,
				-0.15625,
				-0.125,
				-0.09375,
				-0.0625,
				-0.03125,
				0,
				0.03125,
				0.0625,
				0.09375,
				0.125,
				0.15625,
				0.1875,
				0.21875,
				0.25,
				0.28125,
				0.3125,
				0.34375,
				0.375,
				0.40625,
				0.4375,
				0.46875,
				0.5,
				0.53125,
				0.5625,
				0.59375,
				0.625,
				0.65625,
				0.6875,
				0.71875,
				0.75,
				0.78125,
				0.8125,
				0.84375,
				0.875,
				0.90625,
				0.9375,
				0.96875
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Ramp with 3.0 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'ramp' generator for the sample type, with count set to 3.0.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp<c74::min::sample>(v.size(), 3.0));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                -1,
                -0.90625,
                -0.8125,
                -0.71875,
                -0.625,
                -0.53125,
                -0.4375,
                -0.34375,
                -0.25,
                -0.15625,
                -0.0625,
                0.03125,
                0.125,
                0.21875,
                0.3125,
                0.40625,
                0.5,
                0.59375,
                0.6875,
                0.78125,
                0.875,
                0.96875,
                -0.9374999999999999,
                -0.8437499999999999,
                -0.7499999999999999,
                -0.6562499999999999,
                -0.5624999999999999,
                -0.4687499999999999,
                -0.3749999999999999,
                -0.2812499999999999,
                -0.1874999999999999,
                -0.09374999999999989,
                2.220446049250313e-16,
                0.09375000000000022,
                0.1875000000000002,
                0.2812500000000002,
                0.3750000000000002,
                0.4687500000000002,
                0.5625000000000002,
                0.6562500000000002,
                0.7500000000000002,
                0.8437500000000002,
                0.9375000000000002,
                -0.9687499999999998,
                -0.8749999999999998,
                -0.7812499999999998,
                -0.6874999999999998,
                -0.5937499999999998,
                -0.4999999999999998,
                -0.4062499999999998,
                -0.3124999999999998,
                -0.2187499999999998,
                -0.1249999999999998,
                -0.03124999999999978,
                0.06250000000000022,
                0.1562500000000002,
                0.2500000000000002,
                0.3437500000000002,
                0.4375000000000002,
                0.5312500000000002,
                0.6250000000000002,
                0.7187500000000002,
                0.8125000000000002,
                0.9062500000000002
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Ramp with 2.5 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'ramp' generator for the sample type, with count set to 2.5.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp<c74::min::sample>(v.size(), 2.5));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                -1,
                -0.921875,
                -0.84375,
                -0.765625,
                -0.6875,
                -0.609375,
                -0.53125,
                -0.453125,
                -0.375,
                -0.296875,
                -0.21875,
                -0.140625,
                -0.0625,
                0.015625,
                0.09375,
                0.171875,
                0.25,
                0.328125,
                0.40625,
                0.484375,
                0.5625,
                0.640625,
                0.71875,
                0.796875,
                0.875,
                0.953125,
                -0.9687500000000001,
                -0.8906250000000001,
                -0.8125000000000001,
                -0.7343750000000001,
                -0.6562500000000001,
                -0.5781250000000001,
                -0.5000000000000001,
                -0.4218750000000001,
                -0.3437500000000001,
                -0.2656250000000001,
                -0.1875000000000001,
                -0.1093750000000001,
                -0.03125000000000011,
                0.04687499999999978,
                0.1249999999999998,
                0.2031249999999998,
                0.2812499999999998,
                0.3593749999999998,
                0.4374999999999998,
                0.5156249999999998,
                0.5937499999999998,
                0.6718749999999998,
                0.7499999999999998,
                0.8281249999999998,
                0.9062499999999998,
                0.9843749999999998,
                -0.9375000000000002,
                -0.8593750000000002,
                -0.7812500000000002,
                -0.7031250000000002,
                -0.6250000000000002,
                -0.5468750000000002,
                -0.4687500000000002,
                -0.3906250000000002,
                -0.3125000000000002,
                -0.2343750000000002,
                -0.1562500000000002,
                -0.07812500000000022
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Ramp with 0.25 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'ramp' generator for the sample type, with count set to 0.25.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp<c74::min::sample>(v.size(), 0.25));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                -1,
                -0.9921875,
                -0.984375,
                -0.9765625,
                -0.96875,
                -0.9609375,
                -0.953125,
                -0.9453125,
                -0.9375,
                -0.9296875,
                -0.921875,
                -0.9140625,
                -0.90625,
                -0.8984375,
                -0.890625,
                -0.8828125,
                -0.875,
                -0.8671875,
                -0.859375,
                -0.8515625,
                -0.84375,
                -0.8359375,
                -0.828125,
                -0.8203125,
                -0.8125,
                -0.8046875,
                -0.796875,
                -0.7890625,
                -0.78125,
                -0.7734375,
                -0.765625,
                -0.7578125,
                -0.75,
                -0.7421875,
                -0.734375,
                -0.7265625,
                -0.71875,
                -0.7109375,
                -0.703125,
                -0.6953125,
                -0.6875,
                -0.6796875,
                -0.671875,
                -0.6640625,
                -0.65625,
                -0.6484375,
                -0.640625,
                -0.6328125,
                -0.625,
                -0.6171875,
                -0.609375,
                -0.6015625,
                -0.59375,
                -0.5859375,
                -0.578125,
                -0.5703125,
                -0.5625,
                -0.5546875,
                -0.546875,
                -0.5390625,
                -0.53125,
                -0.5234375,
                -0.515625,
                -0.5078125
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Sawtooth") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'sawtooth' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				-1,
				-0.96875,
				-0.9375,
				-0.90625,
				-0.875,
				-0.84375,
				-0.8125,
				-0.78125,
				-0.75,
				-0.71875,
				-0.6875,
				-0.65625,
				-0.625,
				-0.59375,
				-0.5625,
				-0.53125,
				-0.5,
				-0.46875,
				-0.4375,
				-0.40625,
				-0.375,
				-0.34375,
				-0.3125,
				-0.28125,
				-0.25,
				-0.21875,
				-0.1875,
				-0.15625,
				-0.125,
				-0.09375,
				-0.0625,
				-0.03125,
				0,
				0.03125,
				0.0625,
				0.09375,
				0.125,
				0.15625,
				0.1875,
				0.21875,
				0.25,
				0.28125,
				0.3125,
				0.34375,
				0.375,
				0.40625,
				0.4375,
				0.46875,
				0.5,
				0.53125,
				0.5625,
				0.59375,
				0.625,
				0.65625,
				0.6875,
				0.71875,
				0.75,
				0.78125,
				0.8125,
				0.84375,
				0.875,
				0.90625,
				0.9375,
				0.96875
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Sawtooth with 3.0 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sawtooth' generator for the sample type, with count set to 3.0.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth<c74::min::sample>(v.size(), 3.0));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                -1,
                -0.90625,
                -0.8125,
                -0.71875,
                -0.625,
                -0.53125,
                -0.4375,
                -0.34375,
                -0.25,
                -0.15625,
                -0.0625,
                0.03125,
                0.125,
                0.21875,
                0.3125,
                0.40625,
                0.5,
                0.59375,
                0.6875,
                0.78125,
                0.875,
                0.96875,
                -0.9374999999999999,
                -0.8437499999999999,
                -0.7499999999999999,
                -0.6562499999999999,
                -0.5624999999999999,
                -0.4687499999999999,
                -0.3749999999999999,
                -0.2812499999999999,
                -0.1874999999999999,
                -0.09374999999999989,
                2.220446049250313e-16,
                0.09375000000000022,
                0.1875000000000002,
                0.2812500000000002,
                0.3750000000000002,
                0.4687500000000002,
                0.5625000000000002,
                0.6562500000000002,
                0.7500000000000002,
                0.8437500000000002,
                0.9375000000000002,
                -0.9687499999999998,
                -0.8749999999999998,
                -0.7812499999999998,
                -0.6874999999999998,
                -0.5937499999999998,
                -0.4999999999999998,
                -0.4062499999999998,
                -0.3124999999999998,
                -0.2187499999999998,
                -0.1249999999999998,
                -0.03124999999999978,
                0.06250000000000022,
                0.1562500000000002,
                0.2500000000000002,
                0.3437500000000002,
                0.4375000000000002,
                0.5312500000000002,
                0.6250000000000002,
                0.7187500000000002,
                0.8125000000000002,
                0.9062500000000002
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Sawtooth with 2.5 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sawtooth' generator for the sample type, with count set to 2.5.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth<c74::min::sample>(v.size(), 2.5));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                -1,
                -0.921875,
                -0.84375,
                -0.765625,
                -0.6875,
                -0.609375,
                -0.53125,
                -0.453125,
                -0.375,
                -0.296875,
                -0.21875,
                -0.140625,
                -0.0625,
                0.015625,
                0.09375,
                0.171875,
                0.25,
                0.328125,
                0.40625,
                0.484375,
                0.5625,
                0.640625,
                0.71875,
                0.796875,
                0.875,
                0.953125,
                -0.9687500000000001,
                -0.8906250000000001,
                -0.8125000000000001,
                -0.7343750000000001,
                -0.6562500000000001,
                -0.5781250000000001,
                -0.5000000000000001,
                -0.4218750000000001,
                -0.3437500000000001,
                -0.2656250000000001,
                -0.1875000000000001,
                -0.1093750000000001,
                -0.03125000000000011,
                0.04687499999999978,
                0.1249999999999998,
                0.2031249999999998,
                0.2812499999999998,
                0.3593749999999998,
                0.4374999999999998,
                0.5156249999999998,
                0.5937499999999998,
                0.6718749999999998,
                0.7499999999999998,
                0.8281249999999998,
                0.9062499999999998,
                0.9843749999999998,
                -0.9375000000000002,
                -0.8593750000000002,
                -0.7812500000000002,
                -0.7031250000000002,
                -0.6250000000000002,
                -0.5468750000000002,
                -0.4687500000000002,
                -0.3906250000000002,
                -0.3125000000000002,
                -0.2343750000000002,
                -0.1562500000000002,
                -0.07812500000000022
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Sawtooth with 0.25 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sawtooth' generator for the sample type, with count set to 0.25.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth<c74::min::sample>(v.size(), 0.25));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                -1,
                -0.9921875,
                -0.984375,
                -0.9765625,
                -0.96875,
                -0.9609375,
                -0.953125,
                -0.9453125,
                -0.9375,
                -0.9296875,
                -0.921875,
                -0.9140625,
                -0.90625,
                -0.8984375,
                -0.890625,
                -0.8828125,
                -0.875,
                -0.8671875,
                -0.859375,
                -0.8515625,
                -0.84375,
                -0.8359375,
                -0.828125,
                -0.8203125,
                -0.8125,
                -0.8046875,
                -0.796875,
                -0.7890625,
                -0.78125,
                -0.7734375,
                -0.765625,
                -0.7578125,
                -0.75,
                -0.7421875,
                -0.734375,
                -0.7265625,
                -0.71875,
                -0.7109375,
                -0.703125,
                -0.6953125,
                -0.6875,
                -0.6796875,
                -0.671875,
                -0.6640625,
                -0.65625,
                -0.6484375,
                -0.640625,
                -0.6328125,
                -0.625,
                -0.6171875,
                -0.609375,
                -0.6015625,
                -0.59375,
                -0.5859375,
                -0.578125,
                -0.5703125,
                -0.5625,
                -0.5546875,
                -0.546875,
                -0.5390625,
                -0.53125,
                -0.5234375,
                -0.515625,
                -0.5078125
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Ramp") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'ramp_unipolar' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp_unipolar<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				0,
				0.015625,
				0.03125,
				0.046875,
				0.0625,
				0.078125,
				0.09375,
				0.109375,
				0.125,
				0.140625,
				0.15625,
				0.171875,
				0.1875,
				0.203125,
				0.21875,
				0.234375,
				0.25,
				0.265625,
				0.28125,
				0.296875,
				0.3125,
				0.328125,
				0.34375,
				0.359375,
				0.375,
				0.390625,
				0.40625,
				0.421875,
				0.4375,
				0.453125,
				0.46875,
				0.484375,
				0.5,
				0.515625,
				0.53125,
				0.546875,
				0.5625,
				0.578125,
				0.59375,
				0.609375,
				0.625,
				0.640625,
				0.65625,
				0.671875,
				0.6875,
				0.703125,
				0.71875,
				0.734375,
				0.75,
				0.765625,
				0.78125,
				0.796875,
				0.8125,
				0.828125,
				0.84375,
				0.859375,
				0.875,
				0.890625,
				0.90625,
				0.921875,
				0.9375,
				0.953125,
				0.96875,
				0.984375
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Unipolar Ramp with 3.0 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'ramp_unipolar' generator for the sample type, with count set to 3.0.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp_unipolar<c74::min::sample>(v.size(), 3.0));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.046875,
                0.09375,
                0.140625,
                0.1875,
                0.234375,
                0.28125,
                0.328125,
                0.375,
                0.421875,
                0.46875,
                0.515625,
                0.5625,
                0.609375,
                0.65625,
                0.703125,
                0.75,
                0.796875,
                0.84375,
                0.890625,
                0.9375,
                0.984375,
                0.03125000000000006,
                0.07812500000000006,
                0.1250000000000001,
                0.1718750000000001,
                0.2187500000000001,
                0.2656250000000001,
                0.3125000000000001,
                0.3593750000000001,
                0.4062500000000001,
                0.4531250000000001,
                0.5000000000000001,
                0.5468750000000001,
                0.5937500000000001,
                0.6406250000000001,
                0.6875000000000001,
                0.7343750000000001,
                0.7812500000000001,
                0.8281250000000001,
                0.8750000000000001,
                0.9218750000000001,
                0.9687500000000001,
                0.01562500000000011,
                0.06250000000000011,
                0.1093750000000001,
                0.1562500000000001,
                0.2031250000000001,
                0.2500000000000001,
                0.2968750000000001,
                0.3437500000000001,
                0.3906250000000001,
                0.4375000000000001,
                0.4843750000000001,
                0.5312500000000001,
                0.5781250000000001,
                0.6250000000000001,
                0.6718750000000001,
                0.7187500000000001,
                0.7656250000000001,
                0.8125000000000001,
                0.8593750000000001,
                0.9062500000000001,
                0.9531250000000001
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Ramp with 2.5 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'ramp_unipolar' generator for the sample type, with count set to 2.5.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp_unipolar<c74::min::sample>(v.size(), 2.5));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.0390625,
                0.078125,
                0.1171875,
                0.15625,
                0.1953125,
                0.234375,
                0.2734375,
                0.3125,
                0.3515625,
                0.390625,
                0.4296875,
                0.46875,
                0.5078125,
                0.546875,
                0.5859375,
                0.625,
                0.6640625,
                0.703125,
                0.7421875,
                0.78125,
                0.8203125,
                0.859375,
                0.8984375,
                0.9375,
                0.9765625,
                0.01562499999999994,
                0.05468749999999994,
                0.09374999999999994,
                0.1328124999999999,
                0.1718749999999999,
                0.2109374999999999,
                0.2499999999999999,
                0.2890624999999999,
                0.3281249999999999,
                0.3671874999999999,
                0.4062499999999999,
                0.4453124999999999,
                0.4843749999999999,
                0.5234374999999999,
                0.5624999999999999,
                0.6015624999999999,
                0.6406249999999999,
                0.6796874999999999,
                0.7187499999999999,
                0.7578124999999999,
                0.7968749999999999,
                0.8359374999999999,
                0.8749999999999999,
                0.9140624999999999,
                0.9531249999999999,
                0.9921874999999999,
                0.03124999999999989,
                0.07031249999999989,
                0.1093749999999999,
                0.1484374999999999,
                0.1874999999999999,
                0.2265624999999999,
                0.2656249999999999,
                0.3046874999999999,
                0.3437499999999999,
                0.3828124999999999,
                0.4218749999999999,
                0.4609374999999999
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Ramp with 0.25 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'ramp_unipolar' generator for the sample type, with count set to 0.25.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::ramp_unipolar<c74::min::sample>(v.size(), 0.25));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.00390625,
                0.0078125,
                0.01171875,
                0.015625,
                0.01953125,
                0.0234375,
                0.02734375,
                0.03125,
                0.03515625,
                0.0390625,
                0.04296875,
                0.046875,
                0.05078125,
                0.0546875,
                0.05859375,
                0.0625,
                0.06640625,
                0.0703125,
                0.07421875,
                0.078125,
                0.08203125,
                0.0859375,
                0.08984375,
                0.09375,
                0.09765625,
                0.1015625,
                0.10546875,
                0.109375,
                0.11328125,
                0.1171875,
                0.12109375,
                0.125,
                0.12890625,
                0.1328125,
                0.13671875,
                0.140625,
                0.14453125,
                0.1484375,
                0.15234375,
                0.15625,
                0.16015625,
                0.1640625,
                0.16796875,
                0.171875,
                0.17578125,
                0.1796875,
                0.18359375,
                0.1875,
                0.19140625,
                0.1953125,
                0.19921875,
                0.203125,
                0.20703125,
                0.2109375,
                0.21484375,
                0.21875,
                0.22265625,
                0.2265625,
                0.23046875,
                0.234375,
                0.23828125,
                0.2421875,
                0.24609375
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Sawtooth") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'sawtooth_unipolar' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth_unipolar<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				0,
				0.015625,
				0.03125,
				0.046875,
				0.0625,
				0.078125,
				0.09375,
				0.109375,
				0.125,
				0.140625,
				0.15625,
				0.171875,
				0.1875,
				0.203125,
				0.21875,
				0.234375,
				0.25,
				0.265625,
				0.28125,
				0.296875,
				0.3125,
				0.328125,
				0.34375,
				0.359375,
				0.375,
				0.390625,
				0.40625,
				0.421875,
				0.4375,
				0.453125,
				0.46875,
				0.484375,
				0.5,
				0.515625,
				0.53125,
				0.546875,
				0.5625,
				0.578125,
				0.59375,
				0.609375,
				0.625,
				0.640625,
				0.65625,
				0.671875,
				0.6875,
				0.703125,
				0.71875,
				0.734375,
				0.75,
				0.765625,
				0.78125,
				0.796875,
				0.8125,
				0.828125,
				0.84375,
				0.859375,
				0.875,
				0.890625,
				0.90625,
				0.921875,
				0.9375,
				0.953125,
				0.96875,
				0.984375
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Unipolar Sawtooth with 3.0 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sawtooth_unipolar' generator for the sample type, with count set to 3.0.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth_unipolar<c74::min::sample>(v.size(), 3.0));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.046875,
                0.09375,
                0.140625,
                0.1875,
                0.234375,
                0.28125,
                0.328125,
                0.375,
                0.421875,
                0.46875,
                0.515625,
                0.5625,
                0.609375,
                0.65625,
                0.703125,
                0.75,
                0.796875,
                0.84375,
                0.890625,
                0.9375,
                0.984375,
                0.03125000000000006,
                0.07812500000000006,
                0.1250000000000001,
                0.1718750000000001,
                0.2187500000000001,
                0.2656250000000001,
                0.3125000000000001,
                0.3593750000000001,
                0.4062500000000001,
                0.4531250000000001,
                0.5000000000000001,
                0.5468750000000001,
                0.5937500000000001,
                0.6406250000000001,
                0.6875000000000001,
                0.7343750000000001,
                0.7812500000000001,
                0.8281250000000001,
                0.8750000000000001,
                0.9218750000000001,
                0.9687500000000001,
                0.01562500000000011,
                0.06250000000000011,
                0.1093750000000001,
                0.1562500000000001,
                0.2031250000000001,
                0.2500000000000001,
                0.2968750000000001,
                0.3437500000000001,
                0.3906250000000001,
                0.4375000000000001,
                0.4843750000000001,
                0.5312500000000001,
                0.5781250000000001,
                0.6250000000000001,
                0.6718750000000001,
                0.7187500000000001,
                0.7656250000000001,
                0.8125000000000001,
                0.8593750000000001,
                0.9062500000000001,
                0.9531250000000001
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Sawtooth with 2.5 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sawtooth_unipolar' generator for the sample type, with count set to 2.5.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth_unipolar<c74::min::sample>(v.size(), 2.5));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.0390625,
                0.078125,
                0.1171875,
                0.15625,
                0.1953125,
                0.234375,
                0.2734375,
                0.3125,
                0.3515625,
                0.390625,
                0.4296875,
                0.46875,
                0.5078125,
                0.546875,
                0.5859375,
                0.625,
                0.6640625,
                0.703125,
                0.7421875,
                0.78125,
                0.8203125,
                0.859375,
                0.8984375,
                0.9375,
                0.9765625,
                0.01562499999999994,
                0.05468749999999994,
                0.09374999999999994,
                0.1328124999999999,
                0.1718749999999999,
                0.2109374999999999,
                0.2499999999999999,
                0.2890624999999999,
                0.3281249999999999,
                0.3671874999999999,
                0.4062499999999999,
                0.4453124999999999,
                0.4843749999999999,
                0.5234374999999999,
                0.5624999999999999,
                0.6015624999999999,
                0.6406249999999999,
                0.6796874999999999,
                0.7187499999999999,
                0.7578124999999999,
                0.7968749999999999,
                0.8359374999999999,
                0.8749999999999999,
                0.9140624999999999,
                0.9531249999999999,
                0.9921874999999999,
                0.03124999999999989,
                0.07031249999999989,
                0.1093749999999999,
                0.1484374999999999,
                0.1874999999999999,
                0.2265624999999999,
                0.2656249999999999,
                0.3046874999999999,
                0.3437499999999999,
                0.3828124999999999,
                0.4218749999999999,
                0.4609374999999999
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Sawtooth with 0.25 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sawtooth_unipolar' generator for the sample type, with count set to 0.25.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sawtooth_unipolar<c74::min::sample>(v.size(), 0.25));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.00390625,
                0.0078125,
                0.01171875,
                0.015625,
                0.01953125,
                0.0234375,
                0.02734375,
                0.03125,
                0.03515625,
                0.0390625,
                0.04296875,
                0.046875,
                0.05078125,
                0.0546875,
                0.05859375,
                0.0625,
                0.06640625,
                0.0703125,
                0.07421875,
                0.078125,
                0.08203125,
                0.0859375,
                0.08984375,
                0.09375,
                0.09765625,
                0.1015625,
                0.10546875,
                0.109375,
                0.11328125,
                0.1171875,
                0.12109375,
                0.125,
                0.12890625,
                0.1328125,
                0.13671875,
                0.140625,
                0.14453125,
                0.1484375,
                0.15234375,
                0.15625,
                0.16015625,
                0.1640625,
                0.16796875,
                0.171875,
                0.17578125,
                0.1796875,
                0.18359375,
                0.1875,
                0.19140625,
                0.1953125,
                0.19921875,
                0.203125,
                0.20703125,
                0.2109375,
                0.21484375,
                0.21875,
                0.22265625,
                0.2265625,
                0.23046875,
                0.234375,
                0.23828125,
                0.2421875,
                0.24609375
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
} //


SCENARIO ("Generate a Sine") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'sine' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::sine<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				0,
				0.0980171403295606,
				0.1950903220161282,
				0.2902846772544623,
				0.3826834323650898,
				0.4713967368259976,
				0.5555702330196022,
				0.6343932841636455,
				0.7071067811865475,
				0.7730104533627369,
				0.8314696123025451,
				0.8819212643483549,
				0.9238795325112867,
				0.9569403357322089,
				0.9807852804032304,
				0.9951847266721968,
				1,
				0.9951847266721969,
				0.9807852804032304,
				0.9569403357322089,
				0.9238795325112867,
				0.881921264348355,
				0.8314696123025455,
				0.7730104533627371,
				0.7071067811865476,
				0.6343932841636455,
				0.5555702330196022,
				0.4713967368259978,
				0.3826834323650898,
				0.2902846772544623,
				0.1950903220161286,
				0.09801714032956084,
				1.224646799147353e-16,
				-0.09801714032956059,
				-0.1950903220161284,
				-0.2902846772544622,
				-0.3826834323650897,
				-0.4713967368259976,
				-0.555570233019602,
				-0.6343932841636453,
				-0.7071067811865475,
				-0.7730104533627367,
				-0.8314696123025452,
				-0.8819212643483549,
				-0.9238795325112865,
				-0.9569403357322088,
				-0.9807852804032303,
				-0.9951847266721969,
				-1,
				-0.9951847266721969,
				-0.9807852804032304,
				-0.9569403357322089,
				-0.9238795325112866,
				-0.881921264348355,
				-0.8314696123025456,
				-0.7730104533627369,
				-0.7071067811865477,
				-0.6343932841636459,
				-0.5555702330196022,
				-0.4713967368259979,
				-0.3826834323650904,
				-0.2902846772544624,
				-0.1950903220161287,
				-0.09801714032956052
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Sine with 3.0 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sine' generator for the sample type, with count set to 3.0.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sine<c74::min::sample>(v.size(), 3.0));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.2902846772544623,
                0.5555702330196022,
                0.7730104533627369,
                0.9238795325112867,
                0.9951847266721968,
                0.9807852804032304,
                0.881921264348355,
                0.7071067811865476,
                0.4713967368259978,
                0.1950903220161286,
                -0.09801714032956059,
                -0.3826834323650897,
                -0.6343932841636453,
                -0.8314696123025452,
                -0.9569403357322088,
                -1,
                -0.9569403357322089,
                -0.8314696123025456,
                -0.6343932841636459,
                -0.3826834323650904,
                -0.09801714032956052,
                0.1950903220161286,
                0.4713967368259979,
                0.7071067811865477,
                0.8819212643483552,
                0.9807852804032305,
                0.9951847266721968,
                0.9238795325112866,
                0.7730104533627369,
                0.5555702330196022,
                0.2902846772544619,
                -7.657137397853899e-16,
                -0.290284677254463,
                -0.5555702330196026,
                -0.7730104533627371,
                -0.9238795325112868,
                -0.9951847266721969,
                -0.9807852804032303,
                -0.8819212643483546,
                -0.707106781186547,
                -0.4713967368259971,
                -0.1950903220161279,
                0.09801714032956128,
                0.3826834323650904,
                0.634393284163646,
                0.8314696123025456,
                0.956940335732209,
                1,
                0.9569403357322086,
                0.8314696123025449,
                0.6343932841636452,
                0.3826834323650891,
                0.09801714032955995,
                -0.1950903220161288,
                -0.471396736825998,
                -0.707106781186548,
                -0.8819212643483554,
                -0.9807852804032305,
                -0.9951847266721968,
                -0.9238795325112866,
                -0.7730104533627369,
                -0.5555702330196015,
                -0.2902846772544616
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Sine with 2.5 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sine' generator for the sample type, with count set to 2.5.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sine<c74::min::sample>(v.size(), 2.5));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.2429801799032639,
                0.4713967368259976,
                0.6715589548470183,
                0.8314696123025451,
                0.9415440651830208,
                0.9951847266721968,
                0.989176509964781,
                0.9238795325112867,
                0.8032075314806449,
                0.6343932841636455,
                0.427555093430282,
                0.1950903220161286,
                -0.04906767432741772,
                -0.2902846772544622,
                -0.5141027441932216,
                -0.7071067811865475,
                -0.857728610000272,
                -0.9569403357322088,
                -0.9987954562051724,
                -0.9807852804032304,
                -0.9039892931234433,
                -0.7730104533627369,
                -0.5956993044924332,
                -0.3826834323650904,
                -0.1467304744553624,
                0.09801714032956026,
                0.3368898533922197,
                0.555570233019602,
                0.7409511253549588,
                0.8819212643483548,
                0.9700312531945439,
                1,
                0.9700312531945441,
                0.8819212643483552,
                0.7409511253549594,
                0.5555702330196025,
                0.3368898533922203,
                0.09801714032956127,
                -0.1467304744553611,
                -0.3826834323650888,
                -0.5956993044924326,
                -0.7730104533627367,
                -0.9039892931234431,
                -0.9807852804032302,
                -0.9987954562051724,
                -0.9569403357322093,
                -0.8577286100002727,
                -0.7071067811865483,
                -0.5141027441932227,
                -0.2902846772544633,
                -0.04906767432741897,
                0.1950903220161276,
                0.4275550934302814,
                0.6343932841636449,
                0.8032075314806444,
                0.9238795325112865,
                0.9891765099647809,
                0.9951847266721969,
                0.941544065183021,
                0.8314696123025457,
                0.6715589548470189,
                0.4713967368259982,
                0.2429801799032645
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Sine with 0.25 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sine' generator for the sample type, with count set to 0.25.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sine<c74::min::sample>(v.size(), 0.25));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0,
                0.02454122852291229,
                0.04906767432741801,
                0.07356456359966743,
                0.0980171403295606,
                0.1224106751992162,
                0.1467304744553617,
                0.1709618887603012,
                0.1950903220161282,
                0.2191012401568698,
                0.2429801799032639,
                0.2667127574748984,
                0.2902846772544623,
                0.3136817403988915,
                0.3368898533922201,
                0.3598950365349881,
                0.3826834323650898,
                0.4052413140049899,
                0.4275550934302821,
                0.4496113296546065,
                0.4713967368259976,
                0.492898192229784,
                0.5141027441932217,
                0.5349976198870972,
                0.5555702330196022,
                0.5758081914178453,
                0.5956993044924334,
                0.6152315905806268,
                0.6343932841636455,
                0.6531728429537768,
                0.6715589548470183,
                0.6895405447370668,
                0.7071067811865475,
                0.7242470829514669,
                0.740951125354959,
                0.7572088465064845,
                0.7730104533627369,
                0.7883464276266062,
                0.8032075314806448,
                0.8175848131515837,
                0.8314696123025451,
                0.844853565249707,
                0.8577286100002721,
                0.8700869911087113,
                0.8819212643483549,
                0.8932243011955153,
                0.9039892931234433,
                0.9142097557035307,
                0.9238795325112867,
                0.9329927988347388,
                0.9415440651830208,
                0.9495281805930367,
                0.9569403357322089,
                0.9637760657954398,
                0.970031253194544,
                0.9757021300385286,
                0.9807852804032304,
                0.9852776423889412,
                0.989176509964781,
                0.99247953459871,
                0.9951847266721968,
                0.9972904566786902,
                0.9987954562051724,
                0.9996988186962042
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Sine") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'sine_unipolar' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::sine_unipolar<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				0.5,
				0.5490085701647803,
				0.5975451610080641,
				0.6451423386272311,
				0.6913417161825449,
				0.7356983684129988,
				0.7777851165098011,
				0.8171966420818227,
				0.8535533905932737,
				0.8865052266813684,
				0.9157348061512726,
				0.9409606321741775,
				0.9619397662556434,
				0.9784701678661045,
				0.9903926402016152,
				0.9975923633360984,
				1,
				0.9975923633360985,
				0.9903926402016152,
				0.9784701678661045,
				0.9619397662556434,
				0.9409606321741775,
				0.9157348061512727,
				0.8865052266813686,
				0.8535533905932737,
				0.8171966420818227,
				0.7777851165098011,
				0.735698368412999,
				0.6913417161825449,
				0.6451423386272311,
				0.5975451610080643,
				0.5490085701647804,
				0.5000000000000001,
				0.4509914298352197,
				0.4024548389919358,
				0.3548576613727689,
				0.3086582838174552,
				0.2643016315870012,
				0.222214883490199,
				0.1828033579181774,
				0.1464466094067263,
				0.1134947733186317,
				0.08426519384872738,
				0.05903936782582253,
				0.03806023374435674,
				0.02152983213389559,
				0.00960735979838484,
				0.002407636663901536,
				0,
				0.002407636663901536,
				0.009607359798384785,
				0.02152983213389553,
				0.03806023374435669,
				0.05903936782582248,
				0.08426519384872722,
				0.1134947733186316,
				0.1464466094067262,
				0.182803357918177,
				0.2222148834901989,
				0.264301631587001,
				0.3086582838174548,
				0.3548576613727688,
				0.4024548389919356,
				0.4509914298352197
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Unipolar Sine with 3.0 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sine_unipolar' generator for the sample type, with count set to 3.0.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sine_unipolar<c74::min::sample>(v.size(), 3.0));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0.5,
                0.6451423386272311,
                0.7777851165098011,
                0.8865052266813684,
                0.9619397662556434,
                0.9975923633360984,
                0.9903926402016152,
                0.9409606321741775,
                0.8535533905932737,
                0.735698368412999,
                0.5975451610080643,
                0.4509914298352197,
                0.3086582838174552,
                0.1828033579181774,
                0.08426519384872738,
                0.02152983213389559,
                0,
                0.02152983213389553,
                0.08426519384872722,
                0.182803357918177,
                0.3086582838174548,
                0.4509914298352197,
                0.5975451610080643,
                0.735698368412999,
                0.8535533905932738,
                0.9409606321741776,
                0.9903926402016152,
                0.9975923633360984,
                0.9619397662556433,
                0.8865052266813684,
                0.7777851165098011,
                0.645142338627231,
                0.4999999999999996,
                0.3548576613727685,
                0.2222148834901987,
                0.1134947733186314,
                0.03806023374435658,
                0.002407636663901536,
                0.00960735979838484,
                0.0590393678258227,
                0.1464466094067265,
                0.2643016315870014,
                0.4024548389919361,
                0.5490085701647807,
                0.6913417161825453,
                0.8171966420818231,
                0.9157348061512728,
                0.9784701678661045,
                1,
                0.9784701678661043,
                0.9157348061512725,
                0.8171966420818226,
                0.6913417161825446,
                0.54900857016478,
                0.4024548389919356,
                0.264301631587001,
                0.146446609406726,
                0.05903936782582231,
                0.009607359798384729,
                0.002407636663901591,
                0.03806023374435669,
                0.1134947733186316,
                0.2222148834901992,
                0.3548576613727692
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Unipolar Sine with 2.5 cycles") {
    GIVEN ("An empty vector of samples") {
        c74::min::sample_vector	v(64);
        
        WHEN("The entire length is filled by a 'sine_unipolar' generator for the sample type, with count set to 2.5.") {
            THEN("The output matches an externally generated reference set.")
            
            std::generate(v.begin(), v.end(), c74::min::lib::generator::sine_unipolar<c74::min::sample>(v.size(), 2.5));
            
            // The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
            c74::min::sample_vector reference = {
                0.5,
                0.6214900899516319,
                0.7356983684129988,
                0.8357794774235092,
                0.9157348061512726,
                0.9707720325915103,
                0.9975923633360984,
                0.9945882549823906,
                0.9619397662556434,
                0.9016037657403224,
                0.8171966420818227,
                0.713777546715141,
                0.5975451610080643,
                0.4754661628362911,
                0.3548576613727689,
                0.2429486279033892,
                0.1464466094067263,
                0.071135694999864,
                0.02152983213389559,
                0.0006022718974137975,
                0.009607359798384785,
                0.04800535343827833,
                0.1134947733186316,
                0.2021503477537834,
                0.3086582838174548,
                0.4266347627723188,
                0.5490085701647801,
                0.6684449266961099,
                0.777785116509801,
                0.8704755626774794,
                0.9409606321741775,
                0.9850156265972719,
                1,
                0.985015626597272,
                0.9409606321741776,
                0.8704755626774797,
                0.7777851165098013,
                0.6684449266961101,
                0.5490085701647807,
                0.4266347627723194,
                0.3086582838174556,
                0.2021503477537837,
                0.1134947733186317,
                0.04800535343827844,
                0.009607359798384896,
                0.0006022718974137975,
                0.02152983213389537,
                0.07113569499986366,
                0.1464466094067258,
                0.2429486279033887,
                0.3548576613727683,
                0.4754661628362905,
                0.5975451610080638,
                0.7137775467151407,
                0.8171966420818224,
                0.9016037657403222,
                0.9619397662556433,
                0.9945882549823905,
                0.9975923633360985,
                0.9707720325915106,
                0.9157348061512729,
                0.8357794774235094,
                0.7356983684129991,
                0.6214900899516322
            };
            
            REQUIRE_VECTOR_APPROX( v, reference );
        }
    }
}


SCENARIO ("Generate a Cosine") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'cosine' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::cosine<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				1,
				0.9951847266721969,
				0.9807852804032304,
				0.9569403357322088,
				0.9238795325112867,
				0.881921264348355,
				0.8314696123025452,
				0.773010453362737,
				0.7071067811865476,
				0.6343932841636456,
				0.5555702330196023,
				0.4713967368259978,
				0.3826834323650898,
				0.2902846772544623,
				0.1950903220161283,
				0.09801714032956077,
				6.123233995736766e-17,
				-0.09801714032956066,
				-0.1950903220161282,
				-0.2902846772544622,
				-0.3826834323650897,
				-0.4713967368259977,
				-0.555570233019602,
				-0.6343932841636453,
				-0.7071067811865475,
				-0.773010453362737,
				-0.8314696123025453,
				-0.8819212643483549,
				-0.9238795325112867,
				-0.9569403357322088,
				-0.9807852804032304,
				-0.9951847266721968,
				-1,
				-0.9951847266721969,
				-0.9807852804032304,
				-0.9569403357322089,
				-0.9238795325112867,
				-0.881921264348355,
				-0.8314696123025455,
				-0.7730104533627371,
				-0.7071067811865477,
				-0.6343932841636459,
				-0.5555702330196022,
				-0.4713967368259979,
				-0.3826834323650903,
				-0.2902846772544624,
				-0.1950903220161287,
				-0.09801714032956045,
				-1.83697019872103e-16,
				0.09801714032956009,
				0.1950903220161283,
				0.2902846772544621,
				0.38268343236509,
				0.4713967368259976,
				0.5555702330196018,
				0.6343932841636456,
				0.7071067811865475,
				0.7730104533627367,
				0.8314696123025452,
				0.8819212643483549,
				0.9238795325112865,
				0.9569403357322088,
				0.9807852804032303,
				0.9951847266721969
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Unipolar Cosine") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'cosine_unipolar' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::cosine_unipolar<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				1,
				0.9975923633360985,
				0.9903926402016152,
				0.9784701678661044,
				0.9619397662556434,
				0.9409606321741775,
				0.9157348061512727,
				0.8865052266813684,
				0.8535533905932737,
				0.8171966420818229,
				0.7777851165098011,
				0.735698368412999,
				0.6913417161825449,
				0.6451423386272311,
				0.5975451610080642,
				0.5490085701647804,
				0.5,
				0.4509914298352197,
				0.4024548389919359,
				0.3548576613727689,
				0.3086582838174551,
				0.2643016315870012,
				0.222214883490199,
				0.1828033579181774,
				0.1464466094067263,
				0.1134947733186315,
				0.08426519384872733,
				0.05903936782582253,
				0.03806023374435663,
				0.02152983213389559,
				0.009607359798384785,
				0.002407636663901591,
				0,
				0.002407636663901536,
				0.009607359798384785,
				0.02152983213389553,
				0.03806023374435663,
				0.05903936782582248,
				0.08426519384872727,
				0.1134947733186314,
				0.1464466094067262,
				0.182803357918177,
				0.2222148834901989,
				0.264301631587001,
				0.3086582838174549,
				0.3548576613727688,
				0.4024548389919357,
				0.4509914298352198,
				0.4999999999999999,
				0.54900857016478,
				0.5975451610080641,
				0.645142338627231,
				0.691341716182545,
				0.7356983684129987,
				0.7777851165098009,
				0.8171966420818229,
				0.8535533905932737,
				0.8865052266813683,
				0.9157348061512727,
				0.9409606321741775,
				0.9619397662556433,
				0.9784701678661044,
				0.9903926402016152,
				0.9975923633360985
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}













SCENARIO ("Generate a Triangle") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'triangle' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::triangle<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				0,
				0.0625,
				0.125,
				0.1875,
				0.25,
				0.3125,
				0.375,
				0.4375,
				0.5,
				0.5625,
				0.625,
				0.6875,
				0.75,
				0.8125,
				0.875,
				0.9375,
				1,
				0.9375,
				0.875,
				0.8125,
				0.75,
				0.6875,
				0.625,
				0.5625,
				0.5,
				0.4375,
				0.375,
				0.3125,
				0.25,
				0.1875,
				0.125,
				0.0625,
				0,
				-0.0625,
				-0.125,
				-0.1875,
				-0.25,
				-0.3125,
				-0.375,
				-0.4375,
				-0.5,
				-0.5625,
				-0.625,
				-0.6875,
				-0.75,
				-0.8125,
				-0.875,
				-0.9375,
				-1,
				-0.9375,
				-0.875,
				-0.8125,
				-0.75,
				-0.6875,
				-0.625,
				-0.5625,
				-0.5,
				-0.4375,
				-0.375,
				-0.3125,
				-0.25,
				-0.1875,
				-0.125,
				-0.0625
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}


SCENARIO ("Generate a Unipolar Triangle") {
	GIVEN ("An empty vector of samples") {
		c74::min::sample_vector	v(64);

		WHEN("The entire length is filled by a 'triangle_unipolar' generator for the sample type.") {
			THEN("The output matches an externally generated reference set.")

			std::generate(v.begin(), v.end(), c74::min::lib::generator::triangle_unipolar<c74::min::sample>(v.size()));

			// The following output was generated using the Octave code in GeneratorTargetOutput.m by NW
			c74::min::sample_vector reference = {
				0.5,
				0.53125,
				0.5625,
				0.59375,
				0.625,
				0.65625,
				0.6875,
				0.71875,
				0.75,
				0.78125,
				0.8125,
				0.84375,
				0.875,
				0.90625,
				0.9375,
				0.96875,
				1,
				0.96875,
				0.9375,
				0.90625,
				0.875,
				0.84375,
				0.8125,
				0.78125,
				0.75,
				0.71875,
				0.6875,
				0.65625,
				0.625,
				0.59375,
				0.5625,
				0.53125,
				0.5,
				0.46875,
				0.4375,
				0.40625,
				0.375,
				0.34375,
				0.3125,
				0.28125,
				0.25,
				0.21875,
				0.1875,
				0.15625,
				0.125,
				0.09375,
				0.0625,
				0.03125,
				0,
				0.03125,
				0.0625,
				0.09375,
				0.125,
				0.15625,
				0.1875,
				0.21875,
				0.25,
				0.28125,
				0.3125,
				0.34375,
				0.375,
				0.40625,
				0.4375,
				0.46875
			};

			REQUIRE_VECTOR_APPROX( v, reference );
		}
	}
}
