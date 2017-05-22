/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Trond Lossius
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once

#include "c74_min_api.h"


namespace c74 {
namespace min {
namespace lib {


	/// one-channel soft-saturation/distortion filter

	class saturation {
	public:

		void set_drive(number drive_percentage) {
			m_drive = drive_percentage;
			auto f = MIN_CLAMP(drive_percentage / 100.0, 0.001, 0.999);

			m_z = M_PI * f;
			m_s = 1.0 / sin(m_z);
			m_b = MIN_CLAMP(1.0 / f, 0.0, 1.0);
			m_nb = m_b * -1.0;
			auto i = int(f);
			if ((f-(double)i) > 0.5)
				m_scale = sin(m_z); // sin(f * kTTPi);
			else
				m_scale = 1.0;
		}


		sample operator()(sample x) {
			if (x > m_b)
				x = 1.0;
			else if (x < m_nb)
				x = -1.0;
#ifdef WIN_VERSION
			else {
				// http://redmine.jamoma.org/issues/show/54
				// It is insane, but on Windows sin() returns bad values
				// if the argument is negative, so we have to do this crazy workaround.
				number sign;
				if (x < 0.0) {
					x = -x;
					sign = -1.0;
				}
				else
					sign = 1.0;
				x = sign * sin(m_z * x) * m_s;
			}
#else
			else
				x = sin(m_z * x) * m_s;
#endif
			return x * m_scale;
		}


	private:
		number m_drive {};
		number m_z;
		number m_s;
		number m_b;
		number m_nb; // negative b
		number m_scale;
	};


}}}  // namespace c74::min::lib
