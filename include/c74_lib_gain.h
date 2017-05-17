/// @file
///	@ingroup 	minlib
/// @author		Timothy Place
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once

#include "../core/JamomaAudioObject.h"


namespace c74 {
namespace min {


	/**	This AudioObject scales the values within a Sample or SampleBundle according to the current value of its gain Parameter.
		<a href="https://en.wikipedia.org/wiki/Gain">Gain</a> is currently represented internally as linear gain using a double.
	 */
	class Gain : public AudioObject {
	public:
		static constexpr Classname classname = { "gain" };
		static constexpr auto tags = { "dspEffectsLib", "audio", "processor", "dynamics" };


		Parameter<double, Limit::None<double>, NativeUnit::LinearGain>	gain = { this, "gain", 1.0 };	///< Linear gain to be applied to the input signal.


		/** Process one sample.
			@param	x	Sample to be processed.
			@return		Processed sample
		 */
		Sample operator()(const Sample x)
		{
			return x * gain;
		}


		/** Process a SharedSampleBundleGroup.
			@param	x	SharedSampleBundleGroup to be processed.
			@return		Processed SharedSampleBundleGroup.
		 */
		SharedSampleBundleGroup operator()(const SampleBundle& x)
		{
			auto out = adapt(x);

			for (int channel=0; channel<x.channelCount(); ++channel)
				std::transform(x[channel].begin(), x[channel].end(), out[0][channel].begin(), *this);
			return out;
		}

	};

}}  // namespace c74::min
