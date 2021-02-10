// Deque
// template datatype

#include "doubly-linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Deque {
	private:
		DoublyLinkedList<T> list;

	public:
		Deque()                   = default;
		Deque(const Deque& d)     = delete;
		Deque& operator=(Deque d) = delete;
		~Deque()                  { list.clear(); }

		inline bool   empty()     const { return list.empty(); }
		inline size_t size()      const { return list.size_(); }
		inline T      peekFront() const { return list.head_(); }
		inline T      peekBack()  const { return list.tail_(); }

		inline void push(const T& d)   { list.addHead(d); }
		inline T    pop()              { return list.removeHead(); }
		inline void inject(const T& d) { list.addTail(d); }
		inline T    eject()            { return list.removeTail(); }
		inline void popAll()           { list.clear(); }
	};
}
