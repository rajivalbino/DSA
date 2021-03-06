// Singly Linked List
// int datatype

#pragma once

namespace rds {
	template<typename LinkedList>
	class LinkedListIterator {
	
	public:
		using Value = typename LinkedList::ValueType;
		using Pointer = typename LinkedList::NodePointer;
		using Iterator = LinkedListIterator;

	private:
		Pointer _ptr;

	public:
		LinkedListIterator(Pointer p) : _ptr(p) {}

		Value& operator*() {
			return _ptr->_data;
		}

		//Value* operator->() {
		//	return &(_ptr->_data);
		//}

		Iterator& operator++() {
			_ptr = _ptr->_next;
			return *this;
		}

		Iterator operator++(int) {
			Iterator temp(*this);
			++(*this);
			return temp;
		}

		Iterator& operator+=(size_t idx) {
			for (int i = 0; i < idx; ++i) {
				if (_ptr)
					++(*this);
				else
					break;
			}
			return *this;
		}

		Iterator operator+(size_t idx) {
			Iterator temp = *this;
			return (temp += idx);
		}

		Value& operator[](size_t idx) {
			return *(*this + idx);
		}
		
		bool operator==(const Iterator& other) {
			return (_ptr == other._ptr);
		}

		bool operator!=(const Iterator& other) {
			return !(*this == other);
		}

	};

	template<typename T>
	class LinkedList {

	private:
		class Node {
			T _data;
			Node* _next;

			Node(const T& d, Node* n = nullptr) : _data(d), _next(n) {}
			Node(T&& d, Node* n = nullptr) : _data(std::move(d)), _next(n) {}
			
			friend class LinkedList<T>;
			friend class Iterator;
		};

	public:
		using ValueType = T;
		using NodePointer = Node*;
		using Iterator = LinkedListIterator<LinkedList<ValueType>>;

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
		inline T&     head()  const { if (empty()) throw 0; else return _head->_data; }
		inline T&     tail()  const { if (empty()) throw 0; else return _tail->_data; }
		
		inline Iterator begin() const { return Iterator(_head); }
		constexpr Iterator end() { return Iterator(nullptr); }

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
			if (empty())
				_head = _tail = new Node(d);
			else
				_head = new Node(d, _head);
			_size++;
		}

		void addHead(T&& d) { // O(1)
			if (empty())
				_head = _tail = new Node(std::move(d));
			else
				_head = new Node(std::move(d), _head);
			_size++;
		}

		void addTail(const T& d) { // O(1)
			if (empty())
				_tail = _head = new Node(d);
			else
				_tail = _tail->_next = new Node(d);
			_size++;
		}

		void addTail(T&& d) { // O(1)
			if (empty())
				_tail = _head = new Node(std::move(d));
			else
				_tail = _tail->_next = new Node(std::move(d));
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
				
				auto ptr = _head;
				while (ptr->_next->_next != nullptr)
					ptr = ptr->_next;

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