/// @file
///	@ingroup 	minlib
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once

namespace c74 {
namespace min {

	const double k_gain_midi_power		{ log(pow(10.0, 10.0/20.0)) / log(127.0/100.0) };
	const double k_gain_midi_power_r	{ 1.0 / k_gain_midi_power };

}}  // namespace c74::min



//#include "c74_lib_allpass1.h"
#include "c74_lib_circular_storage.h"
#include "c74_lib_dataspace.h"
#include "c74_lib_dcblocker.h"
//#include "c74_lib_delay.h"
//#include "c74_lib_gain.h"
//#include "c74_lib_generator.h"
//#include "c74_lib_impulse.h"
//#include "c74_lib_interpolator.h"
//#include "c74_lib_limit.h"
//#include "c74_lib_lowpass_fourpole.h"
//#include "c74_lib_lowpass_onepole.h"
//#include "c74_lib_noise.h"
#include "c74_lib_saturation.h"
//#include "c74_lib_sync.h"
