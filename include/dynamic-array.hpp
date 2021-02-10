// Dynamic Array
// template datatype

#pragma once

namespace rds {
	template<typename T>
	class DynamicArray {

	private:
		T* first;
		size_t size;
		size_t capacity;

	public:
		DynamicArray() = default;
		DynamicArray(const DynamicArray& da) = delete;
		DynamicArray& operator=(DynamicArray da) = delete;
		~DynamicArray() {}



	};

}