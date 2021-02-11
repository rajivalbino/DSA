// Stack
// template datatype

#include "linked-list.hpp"

#pragma once

namespace rds {

	template<typename T>
	class Stack {
	private:
		LinkedList<T> _list;
	
	public:
		Stack()					  = default;
		Stack(const Stack& s)	  = delete;
		Stack& operator=(Stack s) = delete;
		~Stack()				  { _list.clear(); }

		inline bool   empty() const { return _list.empty(); }
		inline size_t size()  const { return _list.size(); }
		inline T      top()   const { return _list.head(); }
		
		inline void push(const T& d) { _list.addHead(d); }
		inline T    pop()			 { return _list.removeHead(); }
		inline void popAll()		 { _list.clear(); }
	};
}