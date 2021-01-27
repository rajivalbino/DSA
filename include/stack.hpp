// Stack
// int datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	class Stack {
	private:
		LinkedList* list;
	
	public:
		Stack()	 { list = new LinkedList(); }
		~Stack() { list->clear(); delete list; }

		inline bool isEmpty()	const { return list->isEmpty(); }
		inline int  size()		const { return list->size_(); }
		inline int  top()		const { return list->head_(); }
		inline void push(int d)		  { list->addHead(d); }
		inline int  pop()			  { return list->removeHead(); }
		inline void popAll()		  { list->clear(); }
	};
}