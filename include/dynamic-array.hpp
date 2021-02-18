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
					_data[i] = std::move(oldData[i]);

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