// Dynamic Array

#pragma once

namespace rds {

	template<typename DynamicArray>
	class DynamicArrayIterator {

		// let's copy the standard library
	public:
		using Value     = typename DynamicArray::ValueType;
		using Pointer   = Value*;
		using Reference = Value&;
		using Iterator  = DynamicArrayIterator;

	private:
		Pointer _ptr;

	public:
		DynamicArrayIterator(Pointer p) : _ptr(p) {}

		Reference operator[](size_t idx) {
			return *(_ptr + idx);
		}

		Pointer operator->() {
			return _ptr;
		}

		Reference operator*() {
			return *_ptr;
		}

		Iterator& operator++() {
			++_ptr;
			return *this;
		}

		Iterator operator++(int) {
			Iterator temp(*this);
			++(*this);
			return temp;
		}

		Iterator& operator--() {
			--_ptr;
			return *this;
		}

		Iterator operator--(int) {
			Iterator temp(*this);
			--(*this);
			return temp;
		}

		Iterator& operator+=(size_t idx) {
			_ptr += idx;
			return *this;
		}

		Iterator operator+(size_t idx) {
			Iterator temp = *this;
			return (temp += idx);
		}

		Iterator& operator-=(size_t idx) {
			_ptr -= idx;
			return *this;
		}

		Iterator operator-(size_t idx) {
			Iterator temp = *this;
			return (temp -= idx);
		}

		bool operator==(const Iterator& other) {
			return (_ptr == other._ptr);
		}

		bool operator!=(const Iterator& other) {
			return !(*this == other);
		}

	};


	template<typename T>
	class DynamicArray {

	public:
		using ValueType = T;
		using Iterator = DynamicArrayIterator<DynamicArray<ValueType>>;

	private:
		T* _data;
		size_t _size;
		size_t _cap;

		friend class Iterator;

	public:
		DynamicArray(size_t c = 8) : _size(0), _cap(c), _data(nullptr) {
			reserve(_cap);
		}

		~DynamicArray() {
			clear();
			::operator delete(_data, _cap * sizeof(T));
		}
		
		DynamicArray(const DynamicArray& da)                = delete;
		DynamicArray& operator=(DynamicArray da)            = delete;
		DynamicArray(DynamicArray&& da)            noexcept = delete;
		DynamicArray& operator=(DynamicArray&& da) noexcept = delete;

		inline bool     empty()    const { return (_size == 0); }
		inline size_t   size()     const { return _size; }
		inline size_t   capacity() const { return _cap; }
		inline T&       front()          { empty() ? throw 0 : return _data[0]; }
		inline const T& front()    const { empty() ? throw 0 : return _data[0]; }
		inline T&       back()           { empty() ? throw 0 : return _data[_size - 1]; }
		inline const T& back()     const { empty() ? throw 0 : return _data[_size - 1]; }

		inline Iterator begin() { return Iterator(_data); }
		inline Iterator end()   { return Iterator(_data + _size); }

		void clear() {
			for (size_t i = 0; i < _size; ++i)
				_data[i].~T();

			_size = 0;
		}

		void reserve(size_t c) {
				auto oldData = _data;

				// this syntax allows allocate memory without
				// calling the constructor, since it can be
				// a reallocation we dont need reconstruction
				_data = (T*)::operator new(c * sizeof(T));

				if (_size > c)
					_size = c;

				for (size_t i = 0; i < _size; ++i)
					//_data[i] = std::move(oldData[i]);
					new (&_data[i]) T(std::move(oldData[i]));

				for (size_t i = 0; i < _size; ++i)
					oldData[i].~T();
				
				// this syntax allows deallocate the memory
				// without calling the destructor, since we
				// already called it manually above
				::operator delete(oldData, _cap * sizeof(T));
				_cap = c;
		}

		void pushBack(const T& d) {
			if (_size >= _cap)
				reserve(_cap << 1);
			
			_data[_size++] = d;
		}

		void pushBack(T&& d) noexcept {
			if (_size >= _cap)
				reserve(_cap << 1);

			_data[_size++] = std::move(d);
		}

		// variadic template
		template<typename... Args>
		void emplaceBack(Args&&... args) {
			if (_size >= _cap)
				reserve(_cap << 1);

			// construct in-place, no need to construct on the stack
			// and move to the heap, this syntax allow to construct
			// the object on the right memory address
			new(&_data[_size++]) T(std::forward<Args>(args)...);
		}

		void popBack() {
			if (!empty())
				_data[--_size].~T();
			else
				throw 0; /*empty list*/
		}

		bool contains(const T& d) const {
			for (size_t i = 0; i < _size; ++i)
				if (_data[i] == d)
					return true;
			return false;
		}

		T& operator[](size_t idx) {
			if (idx < 0 || idx >= _size)
				throw 1; /*bad index*/

			return _data[idx];
		}

		const T& operator[](size_t idx) const {
			if (idx < 0 || idx >= _size)
				throw 1; /*bad index*/

			return _data[idx];
		}

	};

}