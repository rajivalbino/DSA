// Stack
// template datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Stack {
	private:
		LinkedList<T> list;
	
	public:
		Stack()					  = default;
		Stack(const Stack& s)	  = delete;
		Stack& operator=(Stack s) = delete;
		~Stack()				  { list.clear(); }

		inline bool   empty() const { return list.empty(); }
		inline size_t size()  const { return list.size_(); }
		inline T      top()   const { return list.head_(); }
		
		inline void push(const T& d) { list.addHead(d); }
		inline T    pop()			 { return list.removeHead(); }
		inline void popAll()		 { list.clear(); }
	};
}