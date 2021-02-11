// Doubly Linked List
// int datatype

#pragma once

namespace rds {
	template<typename T>
	class DoublyLinkedList {

	private:
		class Node {
			T _data;
			Node* _prev;
			Node* _next;

			friend class DoublyLinkedList;
		public:
			Node(const T& d, Node* p = nullptr, Node* n = nullptr)
				: _data(d), _prev(p), _next(n) {}
		};

	private:
		size_t _size;
		Node* _head;
		Node* _tail;
	
	public:
		DoublyLinkedList()                              : _size(0), _head(nullptr), _tail(nullptr) {}
		DoublyLinkedList(const DoublyLinkedList& l)     = delete;
		DoublyLinkedList& operator=(DoublyLinkedList l) = delete;
		~DoublyLinkedList()                             { clear(); }

		inline bool   empty() const { return (_size == 0); }
		inline size_t size()  const { return _size; }
		inline T      head()  const { return _head->_data; }
		inline T      tail()  const { return _tail->_data; }
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

		void addHead(const T& d) {
			if (empty())
				_head = _tail = new Node(d);
			else {
				_head = new Node(d, nullptr, _head);
				_head->_next->_prev = _head;
			}
			_size++;
		}

		void addTail(const T& d) {
			if (empty())
				_tail = _head = new Node(d);
			else {
				_tail = new Node(d, _tail, nullptr);
				_tail->_prev->_next = _tail;
			}
			_size++;
		}

		void addAt(unsigned int idx, const T& d) {
			if (idx < 0)      { throw; /*bad index*/ }
			if (idx == 0)     { addHead(d); return; }
			if (idx == _size) { addTail(d); return; }
			if (idx > _size)  { throw; /*bad index*/ }

			auto ptr = _head;
			for (int i = 0; i < idx - 1; i++)
				ptr = ptr->_next;

			auto temp = new Node(d, ptr, ptr->_next);
			ptr->_next = temp;
			temp->_next->_prev = temp;
			_size++;
		}

		T removeHead() {
			if (!empty()) {
				if (_size == 1) {
					auto tdata = _head->_data;
					delete _head;
					_head = _tail = nullptr;
					_size = 0;
					return tdata;
				}

				auto temp = _head;
				auto tdata = _head->_data;
				_head = _head->_next;
				delete temp;
				_head->_prev = nullptr;
				_size--;

				if (empty()) _tail = nullptr;
				return tdata;
			}
			else throw; /*empty list*/
		}

		T removeTail() {
			if (!empty()) {
				if (_size == 1) {
					auto tdata = _head->_data;
					delete _head;
					_head = _tail = nullptr;
					_size = 0;
					return tdata;
				}

				auto temp = _tail;
				auto tdata = _tail->_data;
				_tail = _tail->_prev;
				delete temp;
				_tail->_next = nullptr;
				_size--;

				if (empty()) _head = nullptr;
				return tdata;
			}
			else throw; /*empty list*/
		}
		
		T removeAt(unsigned int idx) {
			if (idx < 0)        throw; /*bad index*/
			if (idx == 0)       return removeHead();
			if (idx == _size-1) return removeTail();
			if (idx >= _size)   throw; /*bad index*/

			auto ptr = _head;
			for (unsigned int i = 0; i < idx - 1; i++)
				ptr = ptr->_next;

			auto temp = ptr->_next;
			auto tdata = temp->_data;
			ptr->_next = temp->_next;
			temp->_next->_prev = ptr;
			delete temp;
			_size--;

			return tdata;
		}

		bool remove(int d) {
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
					ptr->_next = temp->_next;
					temp->_next->_prev = ptr;
					delete temp;
					_size--;
					return true;
				}
			}

			return false;
		}

		bool contains(const T& d) const {
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

		T operator--() {
			return removeHead();
		}

		T operator--(int) {
			return removeTail();
		}

		T& operator[](unsigned int idx) {
			if (idx < 0 || idx >= _size)
				throw; /*bad index*/
			auto ptr = _head;
			for (int i = 0; i < idx; ++i)
				ptr = ptr->_next;
			return ptr->_data;
		}

	};

}