/// @file
///	@ingroup 	minlib
/// @author		Timothy Place
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once


namespace c74 {
namespace min {
namespace dataspace {

	class dataspace_base {
	public:
		// TODO: error checking -- can we do a static_assert that both source and dest are defined in the same dataspace?
		template<class source_unit_type, class dest_unit_type>
		static inline number convert(number x) {
			return dest_unit_type::from_neutral( source_unit_type::to_neutral(x) );
		}
	};

}}} // namespace c74::min::dataspace


#include "c74_lib_dataspace_gain.h"
#include "c74_lib_dataspace_none.h"
#include "c74_lib_dataspace_time.h"

