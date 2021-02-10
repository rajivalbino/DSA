// Singly Linked List
// int datatype

#pragma once

namespace rds {
	template<typename T>
	class LinkedList {

	private:
		class Node {
			T data;
			Node* next;

			friend class LinkedList;

		public:
			Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
		};

	private:
		size_t size;
		Node* head;
		Node* tail;

	public:
		LinkedList()                        : size(0), head(nullptr), tail(nullptr) {}
		LinkedList(const LinkedList& l)     = delete;
		LinkedList& operator=(LinkedList l) = delete;
		~LinkedList()                       { clear(); }

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
			head = (empty() ? tail = new Node(d) : new Node(d, head));
			size++;
		}

		void addTail(const T& d) { 
			tail = (empty() ? head = new Node(d) : tail->next = new Node(d));
			size++;
		}

		void addAt(unsigned int idx, const T& d) {
			if (idx < 0)     { throw; /*bad index*/ }
			if (idx == 0)    { addHead(d); return; }
			if (idx == size) { addTail(d); return; }
			if (idx > size)  { throw; /*cant access*/ }

			auto ptr = head;
			for (unsigned int i = 0; i < idx - 1; ++i)
				ptr = ptr->next;

			ptr->next = new Node(d, ptr->next);
			size++;
		}

		T removeHead() {
			if (!empty()) {
				auto temp = head;
				auto tdata = head->data;
				head = head->next;
				delete temp;
				size--;

				if (empty()) tail = nullptr;
				return tdata;
			}
			else throw; /*empty list*/
		}

		T removeTail() {
			if (!empty()) {
				if (size == 1) return removeHead();

				auto ptr = head;
				while (ptr->next->next != nullptr)
					ptr = ptr->next;

				auto tdata = ptr->next->data;
				delete ptr->next;
				tail = ptr;
				tail->next = nullptr;
				size--;

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
			ptr->next = ptr->next->next;
			delete temp;
			size--;

			return tdata;
		}

		bool remove(const T& d) {
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
					ptr->next = ptr->next->next;
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