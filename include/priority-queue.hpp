// Priority Queue
// int datatype

#pragma once

namespace rds {
	template<typename T>
	class PriorityQueue {

	private:
		T* _data;
		size_t _size;
		size_t _cap;

	public:
		PriorityQueue(size_t c = 8) : _size(0), _cap(c), _data(nullptr) {
			reserve(_cap);
		}

		~PriorityQueue() {
			clear();
			::operator delete(_data, _cap * sizeof(T));
		}

		PriorityQueue(const PriorityQueue& da)                = delete;
		PriorityQueue& operator=(PriorityQueue da)            = delete;
		PriorityQueue(PriorityQueue&& da)            noexcept = delete;
		PriorityQueue& operator=(PriorityQueue&& da) noexcept = delete;

		bool   empty()    const { return (_size == 0); }
		size_t size()     const { return _size; }
		size_t capacity() const { return _cap; }

		void clear() {
			for (size_t i = 0; i < _size; ++i)
				_data[i].~T();

			_size = 0;
		}

		void reserve(size_t c) {
			auto oldData = _data;

			_data = (T*)::operator new(c * sizeof(T));

			if (_size > c)
				_size = c;

			for (size_t i = 0; i < _size; ++i)
				_data[i] = std::move(oldData[i]);

			for (size_t i = 0; i < _size; ++i)
				oldData[i].~T();

			::operator delete(oldData, _cap * sizeof(T));
			_cap = c;
		}

		void insert(const T& d) {
			if (_size >= _cap)
				reserve(_cap << 1);

			_data[_size++] = d;
		}

		void insert(T&& d) noexcept {
			if (_size >= _cap)
				reserve(_cap << 1);

			_data[_size++] = std::move(d);
		}
		
		template<typename... Args>
		void emplace(Args&&... args) {
			if (_size >= _cap)
				reserve(_cap << 1)

				new(&_data[_size++]) T(std::forward<Args>(args)...);
		}

		T peek() const {
			if (empty())
				throw 0; /*empty list*/
			else
				return _data[0];
		}
		
		T poll() {
			if (empty())
				throw 0; /*empty list*/
			else {
				auto tdata = _data[0];

			}
		}

		bool remove(const T& d) {}

		bool contains(const T& d) const {}

	};
}