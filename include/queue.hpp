// Queue
// template datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Queue {
	private:
		LinkedList<T> list;

	public:
		Queue()					  = default;
		Queue(const Queue& q)	  = delete;
		Queue& operator=(Queue q) = delete;
		~Queue()				  { list.clear(); }

		inline bool   empty() const { return list.empty(); }
		inline size_t size()  const { return list.size_(); }
		inline T      first() const { return list.head_(); }

		inline void enque(const T& d) { list.addTail(d); }
		inline T    deque()			  { return list.removeHead(); }
		inline void dequeAll()		  { list.clear(); }
	};
}
