// Dynamic Array

#pragma once

namespace rds {
	template<typename T>
	class DynamicArray {

	private:
		T* _array;
		size_t _size;
		size_t _cap;

	public:
		DynamicArray(size_t c = 8)               : _size(0), _cap(c) { _array = new T[_cap]; }
		DynamicArray(const DynamicArray& da)     = delete;
		DynamicArray& operator=(DynamicArray da) = delete;
		~DynamicArray()                          { delete[] _array; }

		inline bool   empty()    const { return (_size == 0); }
		inline size_t size()     const { return _size; }
		inline size_t capacity() const { return _cap; }

		void clear() {
			delete[] _array;
			DynamicArray();
		}

		void reserve(size_t c) {
			if (c > _cap) {
				auto temp = _array;
				_array = new T[c];
				::memcpy(_array, temp, _size);
				_cap = c;
				delete temp;
			}
		}

		void pushBack(const T& d) {
			if (_size == _cap)
				reserve(_cap << 1);
			
			_array[_size++] = d;
		}

		void pushFront(const T& d) {
			if (_size == _cap)
				reserve(_cap << 1);

			::memcpy(_array+1, _array, _size++);
			_array[0] = d;
		}

		T popBack() {
			if (!empty())
				return _array[--_size];
			else
				throw 0; /*empty list*/
		}

		T popFront() {
			if (!empty()) {
				auto tdata = _array[0];
				::memcpy(_array, _array+1, --_size);
				return tdata;
			}
			else
				throw 0; /*empty list*/
		}

		T& operator[](unsigned int idx) {
			if (idx < 0 || idx >= _size)
				throw 1; /*bad index*/

			return _array[idx];
		}


	};

}