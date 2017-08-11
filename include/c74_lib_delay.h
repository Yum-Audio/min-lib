/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Nathan Wolek
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once


namespace c74 {
namespace min {
namespace lib {


	///	A single-channel interpolating delay line.
	/// @tparam The type of interpolation. The default is no interpolation.

	template <class interpolation_type = interpolator::none<>>
	class delay {
	public:

		/// Capacity of the delay is fixed at instantiation
		/// @param capacity	The number of samples to allocate for the delay line. Default is 256.

		delay(number capacity = 256)
		: m_history(static_cast<size_t>(capacity + 5)) // 5 extra samples to accomodate the 'now' sample + up to 4 interpolation samples
		, m_size(capacity)
		{}


		/// Set a new delay time in samples.
		/// @param	new_size	The new delay time in samples.

		void size(number new_size) {
			m_size = new_size;
			m_size_fractional = m_size - static_cast<std::size_t>(m_size);
		}

		/// Return the current delay time in samples.
		/// @return The delay time in samples.

		number size() const {
			return m_size;
		}

		/// Return the integer part of the current delay time in samples.
		/// @return The integer part of the delay time in samples.

		std::size_t integral_size() {
			return static_cast<std::size_t>(m_size);
		}

		/// Return the fractional part of the current delay time in samples.
		/// @return The fractional part of the delay time in samples.

		double fractional_size() {
			return m_size_fractional;
		}


		/// Erase the delay history.

		void clear() {
			m_history.clear();
		}


		/// Calculate one sample.
		///	@return		Calculated sample

		sample operator()(sample x) {
			// must resize in the audio thread because circular storage requires single-threaded access
			// need delay samples plus 2 "now" samples for interpolation
			auto new_size = static_cast<size_t>(m_size) + 2;
			m_history.resize(new_size);
			m_size_fractional = m_size - static_cast<std::size_t>(m_size);

			// write first (then read) so that we can acheive a zero-sample delay
			m_history.write(x);
			return m_interpolator(m_history.tail(1), m_history.tail(), m_size_fractional);
		}

	private:
		circular_storage<sample>		m_history;			///< Memory for storing the delayed samples.
		number							m_size;				///< Delay time in samples. May include a fractional component.
		double							m_size_fractional;	///< The fractional component of the delay time.
		interpolation_type				m_interpolator;		///< The interpolator instance used to produce interpolated output.
	};


}}}  // namespace c74::min::lib
