// Singly Linked List
// int datatype

#pragma once

namespace rds {

	class LinkedList {

	private:
		class Node {
		public:
			int data;
			Node* next;

			Node(int _d) : data(_d) { next = nullptr; }
			Node(int _d, Node* _n) : data(_d), next(_n) {}
		};

	private:
		int size;
		Node* head;
		Node* tail;

	public:
		LinkedList()  { head = tail = nullptr; size = 0; }
		~LinkedList() { this->clear(); }

		inline bool  isEmpty() const { return (size == 0); }
		inline int   size_()   const { return size; }
		inline int   head_()   const { return head->data; }
		inline int   tail_()   const { return tail->data; }
		inline Node* phead_()  const { return head; }
		inline Node* ptail_()  const { return tail; }

		void clear() {
			tail = nullptr;
			while (head != nullptr) {
				auto temp = head;
				head = head->next;
				delete temp;
			}
			size = 0;
		}

		void addHead(int d) {
			head = (isEmpty() ? tail = new Node(d) : new Node(d, head));
			size++;
		}

		void addTail(int d) { 
			tail = (isEmpty() ? head = new Node(d) : tail->next = new Node(d));
			size++;
		}

		void addAt(int idx, int d) {
			if (idx < 0)     { /*throw bad index*/ return; }
			if (idx == 0)    { addHead(d); return; }
			if (idx == size) { addTail(d); return; }
			if (idx > size)  { /*throw cant access*/ return; }

			auto ptr = head;
			for (int i = 0; i < idx - 1; i++)
				ptr = ptr->next;

			ptr->next = new Node(d, ptr->next);
			size++;
		}

		int removeHead() {
			if (!isEmpty()) {
				auto temp = head;
				auto tdata = head->data;
				head = head->next;
				delete temp;
				size--;

				if (isEmpty()) tail = nullptr;
				return tdata;
			}
			/*else throw empty list*/
		}

		int removeTail() {
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
			/*else throw empty list*/
		}

		int removeAt(int idx) {
			if (idx < 0)       /*throw bad index*/ return NULL;
			if (idx == 0)      return removeHead();
			if (idx == size-1) return removeTail();
			if (idx >= size)   /*throw bad index*/ return NULL;

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

		bool remove(int d) {
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

		bool contains(int d) {
			for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
				if (ptr->data == d)
					return true;
			return false;
		}

		// TODO: sort() ?
	};

}