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
		
		/// Constructor specifies a fixed size for the internal wavetable.
		///	If you want a different size, create a new oscillator and dispose of the one you don't want.
		/// @param	wavetable_size	The number of samples in the wavetable.
		
		oscillator (std::size_t wavetable_size = 4096)
		: m_wavetable(wavetable_size)
		{
			std::generate(m_wavetable.begin(), m_wavetable.end(), waveform_type(m_wavetable.size()));
		}
		
		
	private:
		sync				m_phase_ramp {};
		sample_vector		m_wavetable {};
		
	};
	
}}}  // namespace c74::min::lib