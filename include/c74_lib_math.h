/// @file
///	@ingroup 	minlib
///	@copyright	Copyright 2018 The Min-Lib Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#pragma once

#include <random>
#include <numeric>

namespace c74 { namespace min { namespace lib { namespace math {


	/// Generate a random number.
	/// @param	min		The minimum value for the range in which to generate.
	/// @param	max		The maximum value for the range in which to generate.
	///	@return			The generated pseudo-random number.
	/// @see 			http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	/// @see 			http://en.cppreference.com/w/cpp/numeric/random

	inline double random(double min, double max) {
		std::random_device               rd;
		std::mt19937                     gen{rd()};
		std::uniform_real_distribution<> dis{min, max};

		return dis(gen);
	}


	/// Calculate the mean and standard-deviation from a vector of numerical input.
	/// @tparam     The data type of the items in the vector of input.
	/// @param	v	A vector of numerical input.
	///	@return		A std::pair containing the mean and the standard deviation.

	template<class T>
	auto mean(const std::vector<T>& v) {
		double sum  = std::accumulate(v.begin(), v.end(), 0.0);
		double mean = sum / v.size();

		std::vector<double> diff(v.size());
		std::transform(v.begin(), v.end(), diff.begin(), [mean](double x) { return x - mean; });

		double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
		double stdev  = std::sqrt(sq_sum / v.size());

		return std::make_pair(mean, stdev);
	}


}}}}    // namespace c74::min::lib::math
