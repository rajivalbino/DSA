// Singly Linked List
// int datatype

#pragma once

namespace rds {
	template<typename T>
	class LinkedList {

	private:
		class Node {
		public:
			T data;
			Node* next;

			Node(T _d, Node* _n = nullptr) : data(_d), next(_n) {}
		};

	public:
		class Iterator {
			Node* ptr;
		
		public:
			Iterator(Node* _p = nullptr) : ptr(_p) {}

			void operator++() { ptr = ptr->next; }
			void operator++(int) { ptr = ptr->next; }
			bool operator==(Iterator other) { return (ptr == other.ptr); }
			bool operator!=(Iterator other) { return (ptr != other.ptr); }
			T&   operator*() { return ptr->data; }
			Iterator operator+(int idx) {
				auto it = *this;
				for (int i = 0; i < idx; ++i)
				{
					if (it.ptr != nullptr)
						++it;
					else
						break; /*throw out of list bounds*/
				}
				return it;
			}
		};

	private:
		int size;
		Node* head;
		Node* tail;

	public:
		LinkedList()  { head = tail = nullptr; size = 0; }
		LinkedList(const LinkedList& ll) = delete;
		LinkedList& operator=(LinkedList ll) = delete;
		~LinkedList() { this->clear(); }

		inline bool  isEmpty() const { return (size == 0); }
		inline int   size_()   const { return size; }
		inline T     head_()   const { return head->data; }
		inline T     tail_()   const { return tail->data; }
		inline Iterator& begin() const { return Iterator(head); }
		constexpr Iterator&& end() const { return Iterator(nullptr); }

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
			head = (isEmpty() ? tail = new Node(d) : new Node(d, head));
			size++;
		}

		void addTail(const T& d) { 
			tail = (isEmpty() ? head = new Node(d) : tail->next = new Node(d));
			size++;
		}

		void addAt(int idx, const T& d) {
			if (idx < 0)     { /*throw bad index*/ return; }
			if (idx == 0)    { addHead(d); return; }
			if (idx == size) { addTail(d); return; }
			if (idx > size)  { /*throw cant access*/ return; }

			auto ptr = head;
			for (int i = 0; i < idx-1; i++)
				ptr = ptr->next;

			ptr->next = new Node(d, ptr->next);
			size++;
		}

		T removeHead() {
			if (!isEmpty()) {
				auto temp = head;
				auto tdata = head->data;
				head = head->next;
				delete temp;
				size--;

				if (isEmpty()) tail = nullptr;
				return tdata;
			}
			else throw;
		}

		T removeTail() {
			if (!isEmpty()) {
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
			else throw;
		}

		T removeAt(int idx) {
			if (idx < 0)       /*throw bad index*/ return 0; //NULL
			if (idx == 0)      return removeHead();
			if (idx == size-1) return removeTail();
			if (idx >= size)   /*throw bad index*/ return 0; //NULL

			auto ptr = head;
			for (int i = 0; i < idx - 1; i++)
				ptr = ptr->next;

			auto temp = ptr->next;
			auto tdata = temp->data;
			ptr->next = ptr->next->next;
			delete temp;
			size--;

			return tdata;
		}

		bool remove(const T& d) {
			if (isEmpty())
				return false;
			
			if (head_() == d) {
				removeHead();
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

			if (tail_() == d) {
				removeTail();
				return true;
			}

			return false;
		}

		bool contains(const T& d) const {
			for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
				if (ptr->data == d)
					return true;
			return false;
		}

		void operator<<(const T& e) {
			addHead(e);
		}

		void operator>>(const T& e) {
			addTail(e);
		}

		T operator--() {
			return removeHead();
		}

		T operator--(int) {
			return removeTail();
		}
		
	};

}