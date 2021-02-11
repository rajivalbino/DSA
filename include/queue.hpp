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
		Queue()					  = default;
		Queue(const Queue& q)	  = delete;
		Queue& operator=(Queue q) = delete;
		~Queue()				  { _list.clear(); }

		inline bool   empty() const { return _list.empty(); }
		inline size_t size()  const { return _list.size(); }
		inline T      first() const { return _list.head(); }

		inline void enque(const T& d) { _list.addTail(d); }
		inline T    deque()			  { return _list.removeHead(); }
		inline void dequeAll()		  { _list.clear(); }
	};
}
