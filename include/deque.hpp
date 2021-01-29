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
		inline int  size()		const { return list.size_(); }
		// ...
	};
}
