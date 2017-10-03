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
