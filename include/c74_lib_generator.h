/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Nathan Wolek
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once


namespace c74 {
namespace min {
namespace lib {

    /// Defines several functions for use with <a href="http://en.cppreference.com/w/cpp/algorithm/generate">std::generate</a> to fill vectors with common shapes used in computer sound.

	namespace generator {


        /// Generates a line from -1 to 1 with consistent slope
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        class ramp {
        public:
            ramp (size_t size)
            : m_cycle_size(size)
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }

            T operator()() {
                ++m_current;
                return ( T(m_current) * 2.0 / m_cycle_size) - 1.0;
            }

        private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
        };


        /// Generates an ideal sawtooth waveform from -1 to 1. Not anti-aliased.
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        using sawtooth = generator::ramp<T>;


        /// Generates a line from 0 to 1 with consistent slope
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

		template <typename T>
		class ramp_unipolar {
		public:
			ramp_unipolar (size_t size)
			: m_cycle_size(size)
			{
                //TODO: we need way to protect against zero. static_assert did not work.
            }

			T operator()() {
				++m_current;
				return T(m_current) / m_cycle_size;
			}

		private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
		};


        /// Generates an ideal sawtooth waveform from 0 to 1. Not anti-aliased.
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        using sawtooth_unipolar = generator::ramp_unipolar<T>;


        /// Generates a sine wave constrained between -1 to 1
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

		template <typename T>
		class sine {
		public:
			sine (size_t size)
			: m_cycle_size(size)
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }

			T operator()() {
				++m_current;
				auto output = std::sin(m_current * (2.0 * M_PI) / m_cycle_size);
				return T(output);
			}

		private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
		};


        /// Generates a sine wave constrained between 0 to 1
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        class sine_unipolar {
        public:
            sine_unipolar (size_t size)
            : m_cycle_size(size)
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }

            T operator()() {
                ++m_current;
                auto output = 0.5 * std::sin(m_current * (2.0 * M_PI) / m_cycle_size);
                return T(output) + 0.5;
            }

        private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
        };


        /// Generates a cosine wave constrained between -1 to 1
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        class cosine {
        public:
            cosine (size_t size)
            : m_cycle_size(size)
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }

            T operator()() {
                ++m_current;
                auto output = std::cos(m_current * (2.0 * M_PI) / m_cycle_size);
                return T(output);
            }

        private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
        };


        /// Generates a cosine wave constrained between 0 to 1
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        class cosine_unipolar {
        public:
            cosine_unipolar (size_t size)
            : m_cycle_size(size)
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }

            T operator()() {
                ++m_current;
                auto output = 0.5 + 0.5 * std::cos(m_current * (2.0 * M_PI) / m_cycle_size);
                return T(output);
            }

        private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
        };


        /// Generates a triangle wave constrained between -1 to 1
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

		template <typename T>
		class triangle {
		public:
			triangle (size_t size)
			: m_cycle_size(size)
            {
                //TODO: we need way to protect against zero. static_assert did not work.
            }

			T operator()() {
				T out = 0.0;
				++m_current;

				if (m_current <= m_cycle_size/4)
					out = 4.0 * m_current / m_cycle_size;
				else if (m_current >= 3 * m_cycle_size / 4)
					out = -4.0 + 4.0 * m_current / m_cycle_size;
				else
					out = 2.0 - 4.0 * m_current / m_cycle_size;
				return out;
			}

		private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
		};


        /// Generates a triangle wave constrained between 0 to 1
        /// @param T       render output as this datatype. algorithm was designed to assume the use of floating point.
        /// @param size    size of the target vector

        template <typename T>
        class triangle_unipolar {
        public:
            triangle_unipolar (size_t size)
            : m_cycle_size(size)
			{
                //TODO: we need way to protect against zero. static_assert did not work.
            }

            T operator()() {
                T out = 0.0;
                ++m_current;

                if (m_current <= m_cycle_size/4)
                    out = 2.0 * m_current / m_cycle_size;
                else if (m_current >= 3 * m_cycle_size / 4)
                    out = -2.0 + 2.0 * m_current / m_cycle_size;
                else
                    out = 1.0 - 2.0 * m_current / m_cycle_size;
                return 0.5 + out;
            }

        private:
			int m_current { -1 };
			size_t m_cycle_size; // required by constructor
        };

	} // namespace generator
}}}  // namespace c74::min::lib
