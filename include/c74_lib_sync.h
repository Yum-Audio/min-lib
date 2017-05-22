/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Nathan Wolek
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once


namespace c74 {
namespace min {
namespace lib {

	///	Generate a non-bandlimited <a href="https://en.wikipedia.org/wiki/Sawtooth_wave">sawtooth wave</a> oscillator (a phasor~ in MSP parlance).
	/// This function is typically used as a control signal for <a href="https://en.wikipedia.org/wiki/Phase_(waves)">phase</a> ramping.

	class sync {
	public:

		void frequency(number oscillator_frequency, number sampling_frequency) {
			oscillator_frequency = MIN_CLAMP(oscillator_frequency, sampling_frequency * -0.5, sampling_frequency * 0.5),
			m_step = oscillator_frequency / sampling_frequency;

		}

		//number frequency() {
		//	return m_frequency;
		//}


		void phase(number new_phase) {
			m_phase = MIN_CLAMP(new_phase, 0.0, 1.0);
		}

		number phase() {
			return m_phase;
		}


		// TODO: add offset Parameter from Jamoma1
		// TODO: add gain Parameter from Jamoma1


		/// Process one sample.
		///	@param	x	Sample to be processed.
		///	@return		Processed sample

		sample operator()(sample x) {
			if (m_phase > 1.0)
				m_phase -= 1.0;
			else if (m_phase < 0.0)
				m_phase += 1.0;

			auto y = m_phase * m_gain + m_offset;

			m_phase += m_step;
			return y;
		}


	private:

		number	m_gain		{ 1.0 };
		number	m_offset	{};
		number	m_phase		{};
		number	m_step		{};

	};


}}}  // namespace c74::min::lib
