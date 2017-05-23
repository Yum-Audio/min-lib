/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Trond Lossius
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once

namespace c74 {
namespace min {
namespace lib {

	///	A single-channel generalized allpass filter.

	class allpass {
	public:

		/// Capacity is fixed at creation

		explicit allpass(std::size_t capacity = 4410)
		: m_feedforward_history(capacity)
		, m_feedback_history(capacity)
		{}


		/// size of the history buffers -- i.e. the delay time
		///	TODO: dataspace integration for units other than samples

		void delay(size_t new_size) {
			m_feedforward_history.resize(new_size);
			m_feedback_history.resize(new_size);
		};


		number delay() {
			return m_feedforward_history.size();
		};


		/// Feedback coefficient.

		void gain(number new_gain) {
			m_gain = new_gain;
		}

		number gain() {
			return m_gain;
		}


		///	This algorithm is an IIR filter, meaning that it relies on feedback.  If the filter should
		///	not be producing any signal (such as turning audio off and then back on in a host) or if the
		///	feedback has become corrupted (such as might happen if a NaN is fed in) then it may be
		///	neccesary to clear the filter by calling this method.

		void clear() {
			m_feedforward_history.clear();
			m_feedback_history.clear();
		}


		sample operator()(sample x) {
			auto x1 = m_feedforward_history.tail(-1);
			auto y1 = m_feedback_history.tail(-1);
			auto alpha = m_gain;

			// Store the input in the feedforward buffer
			m_feedforward_history.write(x);

			// Apply the filter
			// We start with the equation in standard form:
			//		y = alpha * x  +  x1  -  alpha * y1;
			// Then to a version that Fred Harris refers to as a "Re-Ordered All-Pass Filter Structure" in Multirate Signal Processing
			//		y = x1  +  alpha * x  -  alpha * y1;
			// Finally, here is a "Single Coefficient All-Pass Filter", dropping from 2 adds and 2 mults down to 2 adds and 1 mult
			auto y = x1 + ((x - y1) * alpha);

			// Store the output in the feedback buffer
			m_feedback_history.write(y);

			return y;
		}

	private:
		circular_storage<sample>	m_feedforward_history;
		circular_storage<sample>	m_feedback_history;
		number						m_gain {};

	};


}}}  // namespace c74::min::lib
