// Priority Queue
// int datatype

#include "dynamic-array.hpp"

#pragma once

namespace rds {
	template<typename T>
	class PriorityQueue {
		DynamicArray<T> _array;

	public:

		bool empty() const {}
		size_t size() const {}
		size_t capacity() const {}

		void clear() {}

		void reserve() {}

		void insert(const T& d) {}

		void insert(T&& d) {}
		
		template<typename... Args>
		void emplace(Args&&... args) {}

		T peek() const {}
		
		T poll() {}

		bool remove(const T& d) {}

		bool contains(const T& d) const {}

	};
}