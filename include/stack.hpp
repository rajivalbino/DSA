// Stack
// int datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Stack {
	private:
		LinkedList<T> list;
	
	public:
		Stack()	 {}
		Stack(const Stack& s) = delete;
		Stack& operator=(Stack s) = delete;
		~Stack() { list.clear(); }

		inline bool isEmpty()	const { return list.isEmpty(); }
		inline int  size()		const { return list.size_(); }
		inline T    top()		const { return list.head_(); }
		inline void push(T d)		  { list.addHead(d); }
		inline T    pop()			  { return list.removeHead(); }
		inline void popAll()		  { list.clear(); }
	};
}