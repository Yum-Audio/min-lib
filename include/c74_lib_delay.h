/// @file
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#pragma once


namespace c74 { namespace min { namespace lib {


	///	A single-channel interpolating delay line.

	class delay {
	public:
		/// Capacity of the delay is fixed at instantiation
		/// @param capacity	The number of samples to allocate for the maximum delay allowed, which will also be used as the initial delay.
		/// Default is 256.

		delay(number capacity = 256)
		: m_history(static_cast<size_t>(capacity + 5))    // 5 extra samples to accomodate the 'now' sample + up to 4 interpolation samples
		{
			size(capacity);
		}


		/// Capacity of the delay is fixed at instantiation
		/// @param capacity_and_size	The number of samples to allocate for the maximum delay allowed, along with a second initial delay
		/// setting that is less than this maximum.

		delay(std::pair<size_t, number> capacity_and_size)
		: m_history(capacity_and_size.first + 5) {
			assert(capacity_and_size.first > capacity_and_size.second);
			size(capacity_and_size.second);
		}


		/// Set a new delay time in samples.
		/// @param	new_size	The new delay time in samples.

		void size(number new_size) {
			m_size            = new_size;
			m_size_fractional = m_size - static_cast<std::size_t>(m_size);
		}

		/// Set a new delay time in samples.
		/// @param	new_size	The new delay time in samples.

		void size(size_t new_size) {
			m_size = static_cast<number>(m_size);
			m_size_fractional = 0;
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


		/// Read a single sample out from the delay.
		///	This will be the oldest sample in the history, unless an offset is specified.
		/// @param	offset	An optional parameter for getting an item that is N items newer than the oldest value.
		///	@return	output	The item from the buffer.

		sample tail(int offset = 0) {

			// calculate the difference between the capacity and our delay so that tail() can be properly offset
			// extra 2 "now" samples to allow for interpolation
			size_t true_offset = m_history.capacity() - integral_size() - 2 + offset;

			return m_interpolator(m_history.tail(true_offset + 2), m_history.tail(true_offset + 1), m_history.tail(true_offset),
				m_history.tail(true_offset - 1), m_size_fractional);
		}


		/// Write a single sample into the delay.
		///	@param	new_input	An item to add.

		void write(sample new_input) {
			m_history.write(new_input);
		}


		/// Erase the delay history.

		void clear() {
			m_history.zero();
		}


		/// Change the interpolation algorithm used.
		/// @param	new_type	option from the interpolator::type enum that names algorithm

		void change_interpolation(interpolator::type new_type = interpolator::type::none) {
			m_interpolator.change_interpolation(new_type);
		}


		/// Calculate one sample.
		///	@return		Calculated sample

		sample operator()(sample x) {
			// write first (then read) so that we can acheive a zero-sample delay
			write(x);
			return tail();
		}


	private:
		circular_storage<sample> m_history;            ///< Memory for storing the delayed samples.
		number                   m_size;               ///< Delay time in samples. May include a fractional component.
		double                   m_size_fractional;    ///< The fractional component of the delay time.
		interpolator::proxy<>    m_interpolator{
            interpolator::type::cubic};    ///< The interpolator instance used to produce interpolated output.
	};


}}}    // namespace c74::min::lib
