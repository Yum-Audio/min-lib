/// @file
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#pragma once

namespace c74 {
namespace min {
namespace lib {
	
	/// Generate basic <a href="https://en.wikipedia.org/wiki/Waveform">waveforms</a> using a single-cycle <a href="https://en.wikipedia.org/wiki/Wavetable_synthesis">wavetable</a>
	
	class oscillator {
	public:
		
		/// Default constructor
		
		oscillator (c74::min::lib::generator waveform = c74::min::lib::generator::sine)
		{
			std::generate(wavetable.begin(), wavetable.end(), waveform<c74::min::sample>(wavetable.size()));
		}
		
		
	private:
		c74::min::lib::sync			phase_ramp;
		c74::min::sample_vector		wavetable(4096);
		
	};
	
}}}  // namespace c74::min::lib