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
		Stack()	 = default;
		~Stack() { _list.clear(); }

		Stack(const Stack& other)	  = delete;
		Stack& operator=(Stack other) = delete;

		Stack(Stack&& other) noexcept {
			_list = std::move(other._list);
		}

		Stack& operator=(Stack&& other) noexcept {
			_list = std::move(other._list);
			return *this;
		}

		inline bool   empty() const { return _list.empty(); }
		inline size_t size()  const { return _list.size(); }
		inline T&     top()   const { return _list.head(); }
		
		inline void push(const T& d) { _list.addHead(d); }
		inline void pop()			 { _list.removeHead(); }
		inline void popAll()		 { _list.clear(); }
	};
}