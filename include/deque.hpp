// Deque
// int datatype

#include "doubly-linked-list.hpp"

#pragma once

namespace rds {

	class Deque {
	private:
		DoublyLinkedList list;

	public:
		Deque() {}
		~Deque() { list.clear(); }

		inline bool isEmpty()	const { return list.isEmpty(); }
		inline int size()		const { return list.size_(); }
		inline int peekFront()	const { return list.head_(); }
		inline int peekBack()	const { return list.tail_(); }

		inline void push(int d) { list.addHead(d); }
		inline int pop() { return list.removeHead(); }
		inline void inject(int d) { list.addTail(d); }
		inline int eject() { return list.removeTail(); }
		inline void popAll() { list.clear(); }
	};
}
