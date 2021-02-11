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
		};

	private:
		size_t _size;
		Node* _head;
		Node* _tail;

	public:
		LinkedList()                        : _size(0), _head(nullptr), _tail(nullptr) {}
		LinkedList(const LinkedList& l)     = delete;
		LinkedList& operator=(LinkedList l) = delete;
		~LinkedList()                       { clear(); }

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
			_head = (empty() ? _tail = new Node(d) : new Node(d, _head));
			_size++;
		}

		void addTail(const T& d) { 
			_tail = (empty() ? _head = new Node(d) : _tail->_next = new Node(d));
			_size++;
		}

		void addAt(unsigned int idx, const T& d) {
			if (idx < 0)      { throw; /*bad index*/ }
			if (idx == 0)     { addHead(d); return; }
			if (idx == _size) { addTail(d); return; }
			if (idx > _size)  { throw; /*cant access*/ }

			auto ptr = _head;
			for (unsigned int i = 0; i < idx - 1; ++i)
				ptr = ptr->_next;

			ptr->_next = new Node(d, ptr->_next);
			_size++;
		}

		T removeHead() {
			if (!empty()) {
				auto temp = _head;
				auto tdata = _head->_data;
				_head = _head->_next;
				delete temp;
				_size--;

				if (empty()) _tail = nullptr;
				return tdata;
			}
			else throw; /*empty list*/
		}

		T removeTail() {
			if (!empty()) {
				if (_size == 1) return removeHead();

				auto ptr = _head;
				while (ptr->_next->_next != nullptr)
					ptr = ptr->_next;

				auto tdata = ptr->_next->_data;
				delete ptr->_next;
				_tail = ptr;
				_tail->_next = nullptr;
				_size--;

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
			auto tdata = _temp->_data;
			ptr->_next = ptr->_next->_next;
			delete temp;
			_size--;

			return tdata;
		}

		bool remove(const T& d) {
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