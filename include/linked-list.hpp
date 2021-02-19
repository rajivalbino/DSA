// Singly Linked List
// int datatype

#pragma once

namespace rds {
	template<typename T>
	class LinkedList {

	private:
		class Node {
			T _data;
			Node* _next;

			friend class LinkedList;

		public:
			Node(const T& d, Node* n = nullptr) : _data(d), _next(n) {}
			Node(T&& d, Node* n = nullptr) : _data(std::move(d)), _next(n) {}
		};

	private:
		size_t _size;
		Node* _head;
		Node* _tail;

	public:
		LinkedList()  : _size(0), _head(nullptr), _tail(nullptr) {}
		~LinkedList() { clear(); }
		
		LinkedList(const LinkedList& other)     = delete; // copying discouraged
		LinkedList& operator=(LinkedList other) = delete; // copying discouraged

		LinkedList(LinkedList&& other) noexcept {
			_size = other._size;
			_head = other._head;
			_tail = other._tail;

			other._size = 0;
			other._head = nullptr;
			other._tail = nullptr;
		}

		LinkedList& operator=(LinkedList&& other) noexcept {
			if (this != &other) {
				clear();

				_size = other._size;
				_head = other._head;
				_tail = other._tail;

				other._size = 0;
				other._head = nullptr;
				other._tail = nullptr;
			}
			return *this;
		}

		inline bool   empty() const { return (_size == 0); }
		inline size_t size()  const { return _size; }
		inline T&     head()  const { empty() ? throw 0; : return _head->_data; }
		inline T&     tail()  const { empty() ? throw 0; : return _tail->_data; }
		inline Node*  begin() const { return _head; }
		inline Node*  end()   const { return _tail; }

		void clear() {
			_tail = nullptr;
			while (_head != nullptr) {
				auto temp = _head;
				_head = _head->_next;
				delete temp;
			}
			_size = 0;
		}

		void addHead(const T& d) { // O(1)
			_head = (empty() ? _tail = new Node(d) : new Node(d, _head));
			_size++;
		}

		void addHead(T&& d) { // O(1)
			_head = (empty() ? _tail = new Node(std::move(d)) : new Node(std::move(d), _head));
			_size++;
		}

		void addTail(const T& d) { // O(1)
			_tail = (empty() ? _head = new Node(d) : _tail->_next = new Node(d));
			_size++;
		}

		void addTail(T&& d) { // O(1)
			_tail = (empty() ? _head = new Node(std::move(d)) : _tail->_next = new Node(std::move(d)));
			_size++;
		}

		void addAt(size_t idx, const T& d) { // O(n)
			if (idx < 0)      { throw 1; /*bad index*/ }
			if (idx == 0)     { addHead(d); return; }
			if (idx == _size) { addTail(d); return; }
			if (idx > _size)  { throw 1; /*bad index*/ }

			auto ptr = _head;
			for (size_t i = 0; i < idx-1; ++i)
				ptr = ptr->_next;

			ptr->_next = new Node(d, ptr->_next);
			_size++;
		}

		void addAt(size_t idx, T&& d) { // O(n)
			if (idx < 0)      { throw 1; /*bad index*/ }
			if (idx == 0)     { addHead(std::move(d)); return; }
			if (idx == _size) { addTail(std::move(d)); return; }
			if (idx > _size)  { throw 1; /*bad index*/ }

			auto ptr = _head;
			for (size_t i = 0; i < idx - 1; ++i)
				ptr = ptr->_next;

			ptr->_next = new Node(std::move(d), ptr->_next);
			_size++;
		}

		void removeHead() { // O(1)
			if (!empty()) {
				auto temp = _head;
				_head = _head->_next;
				delete temp;
				_size--;

				if (empty()) _tail = nullptr;
			}
			else
				throw 0; /*empty list*/
		}

		void removeTail() { // O(n)
			if (!empty()) {
				if (_size == 1) return removeHead();
				
				for (auto ptr = _head; ptr->_next->_next != nullptr; ptr = ptr->_next);
					// empty for

				delete ptr->_next;
				_tail = ptr;
				_tail->_next = nullptr;
				_size--;
			}
			else
				throw 0; /*empty list*/
		}

		void removeAt(size_t idx) { // O(n)
			if (idx < 0)        throw 1; /*bad index*/
			if (idx == 0)       return removeHead();
			if (idx == _size-1) return removeTail();
			if (idx >= _size)   throw 1; /*bad index*/

			auto ptr = _head;
			for (size_t i = 0; i < idx - 1; i++)
				ptr = ptr->_next;

			auto temp = ptr->_next;
			ptr->_next = ptr->_next->_next;
			delete temp;
			_size--;
		}

		bool remove(const T& d) { // O(n)
			if (empty())
				return false;
			
			if (head() == d) {
				removeHead();
				return true;
			}

			if (tail() == d) {
				removeTail();
				return true;
			}
			
			for (auto ptr = _head; ptr->_next != nullptr; ptr = ptr->_next) {
				if (ptr->_next->_data == d) {
					auto temp = ptr->_next;
					ptr->_next = ptr->_next->_next;
					delete temp;
					_size--;
					return true;
				}
			}

			return false;
		}

		bool contains(const T& d) const { // O(n)
			for (auto ptr = _head; ptr != nullptr; ptr = ptr->_next)
				if (ptr->_data == d)
					return true;
			return false;
		}

		void operator<<(const T& d) {
			addHead(d);
		}

		void operator>>(const T& d) {
			addTail(d);
		}

		void operator--() {
			removeHead();
		}

		void operator--(int) {
			removeTail();
		}
		
		T& operator[](size_t idx) {
			if (idx < 0 || idx >= _size)
				throw 1; /*bad index*/

			auto ptr = _head;
			for (int i = 0; i < idx; ++i)
				ptr = ptr->_next;
			return ptr->_data;
		}

		const T& operator[](size_t idx) const {
			if (idx < 0 || idx >= _size)
				throw 1; /*bad index*/

			auto ptr = _head;
			for (int i = 0; i < idx; ++i)
				ptr = ptr->_next;
			return ptr->_data;
		}

	};

}