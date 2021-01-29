// Queue
// int datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Queue {
	private:
		LinkedList<T> list;

	public:
		Queue()  {}
		Queue(const Queue& q) = delete;
		Queue& operator=(Queue q) = delete;
		~Queue() { list.clear(); }

		inline bool isEmpty()	const { return list.isEmpty(); }
		inline int  size()		const { return list.size_(); }
		inline T    first()		const { return list.head_(); }
		inline void enque(T d)		  { list.addTail(d); }
		inline T    deque()			  { return list.removeHead(); }
		inline void dequeAll()		  { list.clear(); }
	};
}
