/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Nathan Wolek
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once

#include "c74_min_api.h"


namespace c74 {
namespace min {
namespace lib {


	/// one-channel dc-blocking filter

	class dcblocker {
	public:

		void clear() {
			x_1 = 0.0;
			y_1 = 0.0;
		}

		sample operator()(sample x) {
			auto y = x - x_1 + y_1 * 0.9997;
			y_1 = y;
			x_1 = x;
			return y;
		}

	private:
		sample x_1 {};
		sample y_1 {};
	};


}}}  // namespace c74::min::lib
