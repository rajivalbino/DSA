// Dynamic Array

#pragma once

namespace rds {
	template<typename T>
	class DynamicArray {

	private:
		T* _data;
		size_t _size;
		size_t _cap;

	public:
		DynamicArray(size_t c = 8)               : _size(0), _cap(c) { _data = new T[_cap]; }
		DynamicArray(const DynamicArray& da)     = delete;
		DynamicArray& operator=(DynamicArray da) = delete;
		~DynamicArray()                          { delete[] _data; }

		inline bool   empty()    const { return (_size == 0); }
		inline size_t size()     const { return _size; }
		inline size_t capacity() const { return _cap; }

		void clear() {
			delete[] _data;
			DynamicArray();
		}

		void reserve(size_t c) {
				auto temp = _data;
				_data = new T[c];

				if (_size > c)
					_size = c;

				for (int i = 0; i < _size; ++i)
					_data[i] = std::move(temp[i]);
				
				_cap = c;
				delete[] temp;
		}

		void pushBack(const T& d) {
			if (_size >= _cap)
				reserve(_cap << 1);
			
			_data[_size++] = d;
		}

		void pushBack(T&& d) {
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

		T popBack() {
			if (!empty()) {
				_data[--_size].~T();
				return _data[_size];
			}
			else
				throw 0; /*empty list*/
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