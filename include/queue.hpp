// Queue
// template datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Queue {
	private:
		LinkedList<T> _list;

	public:
		Queue()	 = default;
		~Queue() { _list.clear(); }
		
		Queue(const Queue& other)	  = delete;
		Queue& operator=(Queue other) = delete;

		Queue(Queue&& other) noexcept {
			_list = std::move(other._list);
		}

		Queue& operator=(Queue&& other) noexcept {
			_list = std::move(other._list);
			return *this;
		}

		inline bool   empty() const { return _list.empty(); }
		inline size_t size()  const { return _list.size(); }
		inline T&     first() const { return _list.head(); }

		inline void enque(const T& d) { _list.addTail(d); }
		inline void deque()			  { _list.removeHead(); }
		inline void dequeAll()		  { _list.clear(); }
	};
}
