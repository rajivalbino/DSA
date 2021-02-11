// Deque
// template datatype

#include "doubly-linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Deque {
	private:
		DoublyLinkedList<T> _list;

	public:
		Deque()                   = default;
		Deque(const Deque& d)     = delete;
		Deque& operator=(Deque d) = delete;
		~Deque()                  { _list.clear(); }

		inline bool   empty()     const { return _list.empty(); }
		inline size_t size()      const { return _list.size(); }
		inline T      peekFront() const { return _list.head(); }
		inline T      peekBack()  const { return _list.tail(); }

		inline void pushFront(const T& d) { _list.addHead(d); }
		inline T    popFront()            { return _list.removeHead(); }
		inline void pushBack(const T& d)  { _list.addTail(d); }
		inline T    popBack()             { return _list.removeTail(); }
		inline void popAll()              { _list.clear(); }
	};
}
