/// @file
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#pragma once

namespace c74 {
namespace min {
namespace lib {
	
	/// Generate basic <a href="https://en.wikipedia.org/wiki/Waveform">waveforms</a> using a single-cycle <a href="https://en.wikipedia.org/wiki/Wavetable_synthesis">wavetable</a>
	
	template <class waveform_type = generator::sine<c74::min::sample>>
	class oscillator {
	public:
		
		/// Default constructor
		
		oscillator ()
		{
			std::generate(m_wavetable.begin(), m_wavetable.end(), m_generator(m_wavetable.size()));
		}
		
		
	private:
		c74::min::lib::sync			m_phase_ramp;
		c74::min::sample_vector		m_wavetable(4096);
		waveform_type				m_generator;
		
	};
	
}}}  // namespace c74::min::lib