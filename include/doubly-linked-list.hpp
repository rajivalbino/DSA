// Doubly Linked List
// int datatype

#pragma once

namespace rds {
	template<typename T>
	class DoublyLinkedList {

	private:
		class Node {
			T data;
			Node* prev;
			Node* next;

			friend class DoublyLinkedList;
		public:
			Node(const T& _d, Node* _p = nullptr, Node* _n = nullptr) : data(_d), prev(_p), next(_n) {}
		};

	private:
		size_t size;
		Node* head;
		Node* tail;
	
	public:
		DoublyLinkedList() { head = tail = nullptr; size = 0; }
		DoublyLinkedList(const DoublyLinkedList& l) = delete;
		DoublyLinkedList& operator=(DoublyLinkedList l) = delete;
		~DoublyLinkedList() { clear(); }

		inline bool   empty() const { return (size == 0); }
		inline size_t size_() const { return size; }
		inline T      head_() const { return head->data; }
		inline T      tail_() const { return tail->data; }
		inline Node*  begin() const { return head; }
		inline Node*  end()   const { return tail; }

		void clear() {
			tail = nullptr;
			while (head != nullptr) {
				auto temp = head;
				head = head->next;
				delete temp;
			}
			size = 0;
		}

		void addHead(const T& d) {
			if (empty())
				head = tail = new Node(d);
			else {
				head = new Node(d, nullptr, head);
				head->next->prev = head;
			}
			size++;
		}

		void addTail(const T& d) {
			if (empty())
				tail = head = new Node(d);
			else {
				tail = new Node(d, tail, nullptr);
				tail->prev->next = tail;
			}
			size++;
		}

		void addAt(unsigned int idx, const T& d) {
			if (idx < 0)     { throw; /*bad index*/ }
			if (idx == 0)    { addHead(d); return; }
			if (idx == size) { addTail(d); return; }
			if (idx > size)  { throw; /*cant access*/ }

			auto ptr = head;
			for (int i = 0; i < idx - 1; i++)
				ptr = ptr->next;

			auto temp = new Node(d, ptr, ptr->next);
			ptr->next = temp;
			temp->next->prev = temp;
			size++;
		}

		T removeHead() {
			if (!empty()) {
				auto temp = head;
				auto tdata = head->data;
				head = head->next;
				head->prev = nullptr;
				delete temp;
				size--;

				if (empty()) tail = nullptr;
				return tdata;
			}
			else throw; /*empty list*/
		}

		T removeTail() {
			if (!empty()) {
				auto temp = tail;
				auto tdata = tail->data;
				tail = tail->prev;
				tail->next = nullptr;
				delete temp;
				size--;

				if (empty()) head = nullptr;
				return tdata;
			}
			else throw; /*empty list*/
		}
		
		T removeAt(unsigned int idx) {
			if (idx < 0)       throw; /*bad index*/
			if (idx == 0)      return removeHead();
			if (idx == size-1) return removeTail();
			if (idx >= size)   throw; /*bad index*/

			auto ptr = head;
			for (unsigned int i = 0; i < idx - 1; i++)
				ptr = ptr->next;

			auto temp = ptr->next;
			auto tdata = temp->data;
			ptr->next = temp->next;
			temp->next->prev = ptr;
			delete temp;
			size--;

			return tdata;
		}

		bool remove(int d) {
			if (empty())
				return false;

			if (head_() == d) {
				removeHead();
				return true;
			}

			if (tail_() == d) {
				removeTail();
				return true;
			}

			for (auto ptr = head; ptr->next != nullptr; ptr = ptr->next) {
				if (ptr->next->data == d) {
					auto temp = ptr->next;
					ptr->next = temp->next;
					temp->next->prev = ptr;
					delete temp;
					size--;
					return true;
				}
			}

			return false;
		}

		bool contains(const T& d) const {
			for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
				if (ptr->data == d)
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
			if (idx < 0 || idx >= size)
				throw; /*bad index*/
			auto ptr = head;
			for (int i = 0; i < idx; ++i)
				ptr = ptr->next;
			return ptr->data;
		}

	};

}