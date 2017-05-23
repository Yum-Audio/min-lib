/// @file
///	@ingroup 	minlib
/// @author		Timothy Place, Nathan Wolek
///	@copyright	Copyright (c) 2017, Cycling '74
///	@license	Usage of this file and its contents is governed by the MIT License

#pragma once

#include <thread>
//#include <cassert>

namespace c74 {
namespace min {
namespace lib {


	///	A generic circular buffer designed specifically for access from a single thread.
	///
	///	Allows items of a single datatype to be written into a vector that wraps around to the beginning whenever the end is exceeded.
	///	Reading items from the vector can then return chunks of the N most recent items.
	///	The initial design of this class was for use as an audio sample delay buffer,
	///	however it's functionality has been generalized to allow for other datatypes and applications.

	template <class T>
	class circular_storage {
//		friend class CircularStorageTest;

	public:
		/// Constructor specifies a fixed amount of storage for the container.
		///	If you want a different amount of storage, create a new container and dispose of the one you don't want.

		explicit circular_storage(std::size_t itemcount)
		: m_items(itemcount)
		, m_size(itemcount)
		{}


		circular_storage(std::pair<size_t, size_t> capacity_and_size)
		: m_items(capacity_and_size.first)
		, m_size(capacity_and_size.second)
		{}


//		virtual ~circular_storage()
//		{}


		/// Write a block of things into the container.
		///	@param	newInput	A block of things to add. May not be larger than the size of the buffer.

		void write(const std::vector<T>& new_input) {
			assert(std::this_thread::get_id() == m_thread);
			assert(new_input.size() <= size());

			std::size_t count = new_input.size();
			std::size_t roomRemaining = size() - m_index;
			bool		wrap = false;

			if (count > roomRemaining) {
				count = roomRemaining;
				wrap = true;
			}

			std::copy_n(new_input.begin(), count, m_items.begin()+m_index);
			m_index += count;

			if (wrap) {
				std::size_t offset = count;

				count = new_input.size() - offset;
				std::copy_n(new_input.begin()+offset, count, m_items.begin());
				m_index = count;
			}
		}


		void write(const T& new_input) {
			assert(std::this_thread::get_id() == m_thread);

			m_items[m_index] = new_input;
			++m_index;
			if (m_index == size())
				m_index = 0;
		}


		/// Read a block of things out from the container.
		///	These will be the N most recent items added to the history.
		///	@param	output	A place to write the block of things from the buffer.
		///					The size of this buffer will determine the number of things to request.
		///					May not be larger than the size of the buffer.

		void read(std::vector<T>& output) {
			head(output);
		}


		/// Read a block of things out from the container.
		///	These will be the N most recent items added to the history.
		///	@param	output	A place to write the block of things from the buffer.
		///					The size of this buffer will determine the number of things to request.
		///					May not be larger than the size of the buffer.
		///	@see	tail()

		void head(std::vector<T>& output) {
			assert(std::this_thread::get_id() == m_thread);
			assert(size() >= output.size());

			long	count = output.size();
			long	start = m_index - count;
			bool	wrap = false;

			if (start<0) {
				count = -start;
				start = size() + start;
				wrap = true;
			}

			std::copy_n(m_items.begin()+start, count, output.begin());

			if (wrap) {
				std::size_t offset = count;

				count = output.size() - offset;
				std::copy_n(m_items.begin(), count, output.begin()+offset);
			}
		}


		/// Read a block of things out from the container.
		///	These will be the N oldest items added in the history.
		///	@param	output	A place to write the block of things from the buffer.
		///					The size of this buffer will determine the number of things to request.
		///					May not be larger than the size of the buffer.
		///	@see	head()

		void tail(std::vector<T>& output) {
			assert(std::this_thread::get_id() == m_thread);
			assert(size() >= output.size());

			long	count = output.size();
			long	start = m_index % size();
			bool	wrap = false;

			if (start+count > size()) {
				count = size() - start;
				wrap = true;
			}

			std::copy_n(m_items.begin()+start, count, output.begin());

			if (wrap) {
				std::size_t offset = count;

				count = output.size() - offset;
				std::copy_n(m_items.begin(), count, output.begin()+offset);
			}
		}


		T tail(int offset = 0)  {
			// TODO: benchmark / evaluate use of modulo here
			return m_items[ (m_index+offset) % size() ];
		}


		///	Zero the contents.
	
		void clear() {
			assert(std::this_thread::get_id() == m_thread);
			m_items.clear();
		}


		///	The number of items in the buffer.

		std::size_t size() {
			return m_size;
		}


		///	Change the number of items in the buffer.

		void resize(std::size_t	new_size) {
			assert(new_size <= m_items.size());
			m_size = new_size;
		}

	private:
		std::vector<T>		m_items;									///< storage for the circular buffer's data
		std::size_t			m_index {};									///< location of the record head
		std::size_t			m_size;										///< the size of the circular buffer (may be different from the amount of allocated storage)
		std::thread::id		m_thread = { std::this_thread::get_id() };	///< used to ensure we don't access unsafely from multiple threads

	};


}}}  // namespace c74::min::lib
