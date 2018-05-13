/// @file
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#pragma once

namespace c74 {
namespace min {
namespace lib {
	
	/// Generate basic <a href="https://en.wikipedia.org/wiki/Waveform">waveforms</a> using a single-cycle <a href="https://en.wikipedia.org/wiki/Wavetable_synthesis">wavetable</a>
	
	template <class waveform_type = generator::sine<sample>>
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
		
		
		///	Return the size of the internal wavetable.
		/// @return	The size of the sample_vector containing our single-cycle wavetable.
		
		std::size_t size() {
			return m_wavetable.size();
		}
		
		
		/// Set the frequency of the oscillator.
		/// @param	oscillator_frequency	The frequency of the oscillator in hertz.
		/// @param	sampling_frequency		The sampling frequency of the environment in hertz.
		
		void frequency(number oscillator_frequency, number sampling_frequency) {
			m_phase_ramp.frequency(oscillator_frequency, sampling_frequency);
		}
		
		
		/// Get the current frequency of the oscillator.
		/// @return	The current frequency of the oscillator in the range [0.0, f_s].
		
		number frequency() {
			return m_phase_ramp.frequency();
		}
		
		
		/// Set the phase of the oscillator
		///	@param	new_phase	The new phase to which the oscillator will be set. Range is [0.0, 1.0).
		
		void phase(number new_phase) {
			m_phase_ramp.phase(new_phase);
		}
		
		
		/// Get the current phase of the oscillator
		/// @return	The current phase of the oscillator in the range [0.0, 1.0).
		
		number phase() {
			return m_phase_ramp.phase();
		}
		
		
		/// Calculate one sample.
		///	@return		Calculated sample
		
		sample operator()() {
			sample phase_now = m_phase_ramp();
			sample position_now = phase_now * m_wavetable.size();
			
			int position_now_integer = int(position_now);
			
			return m_wavetable.at(position_now_integer);
		}
		
		
	private:
		sync				m_phase_ramp {};	///< manages the frequency and phase of our oscillator
		sample_vector		m_wavetable {};		///< vector containing single cycle of the waveform
		
	};
	
}}}  // namespace c74::min::lib