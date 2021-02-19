// Priority Queue
// max heap
// template datatype
// the objects must be comparable (operator<() and operator>() defined)

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

		PriorityQueue(const PriorityQueue& other)     = delete;
		PriorityQueue& operator=(PriorityQueue other) = delete;

		PriorityQueue(PriorityQueue&& other) noexcept {
			_data = other._data;
			_size = other._size;
			_cap = other._cap;

			other._data = nullptr;
			other._size = 0;
			other._cap = 0;
		}

		PriorityQueue& operator=(PriorityQueue&& other) noexcept {
			if (this != &other) {
				clear();
				::operator delete(_data, _cap * sizeof(T));

				_data = other._data;
				_size = other._size;
				_cap = other._cap;

				other._data = nullptr;
				other._size = 0;
				other._cap = 0;
			}
		}

		bool   empty()    const { return (_size == 0); }
		size_t size()     const { return _size; }
		size_t capacity() const { return _cap; }
		T&     peek()     const { if (empty()) throw 0; else return _data[0]; }

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

			_data[_size] = d;
			bubbleUp(_size);
			_size++;
		}

		void insert(T&& d) noexcept {
			if (_size >= _cap)
				reserve(_cap << 1);

			_data[_size] = std::move(d);
			bubbleUp(_size);
			_size++;
		}
		
		template<typename... Args>
		void emplace(Args&&... args) {
			if (_size >= _cap)
				reserve(_cap << 1)

			new(&_data[_size]) T(std::forward<Args>(args)...);
			bubbleUp(_size);
			_size++;
		}
		
		void poll() {
			if (empty())
				throw 0; /*empty list*/
			else {
				_data[0].~T();
				_size--;
				_data[0] = std::move(_data[_size]);
				bubbleDown(0);
			}
		}

		bool remove(const T& d) {
			// TODO: binary search
			return false;
		}

		bool contains(const T& d) const {
			// TODO: binary search
			return false;
		}

	private:
		void bubbleUp(size_t idx) {
			if (idx == 0)
				return;

			size_t idxParent = (idx-1) >> 1;

			if (_data[idx] > _data[idxParent]) {
				std::swap(_data[idx], _data[idxParent]);
				bubbleUp(idxParent);
			}
			else
				return;
		}

		void bubbleDown(size_t idx) {
			size_t idxLeftChild  = (idx << 1) + 1;
			size_t idxRightChild = (idx << 1) + 2;

			if (idxLeftChild >= _size)
				return;

			if (_data[idx] < _data[idxLeftChild]) {
				std::swap(_data[idx], _data[idxLeftChild]);
				bubbleDown(idxLeftChild);
			}
			else if (_data[idx] < _data[idxRightChild]) {
				std::swap(_data[idx], _data[idxRightChild]);
				bubbleDown(idxRightChild);
			}
			else
				return;
		}
	};
}