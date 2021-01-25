// Queue
// int datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	class Queue {
	private:
		LinkedList* list;

	public:
		Queue()  { list = new LinkedList(); }
		~Queue() { list->clear(); delete list; }

		inline bool isEmpty()	const { return list->isEmpty(); }
		inline int  size()		const { return list->size_(); }
		inline int  first()		const { return list->head_(); }
		inline void enque(int d)	  { list->addTail(d); }
		inline int  deque()			  { return list->removeHead(); }
		inline void dequeAll()		  { list->clear(); }
	};
}
