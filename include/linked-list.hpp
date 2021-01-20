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
		LinkedList() { head = tail = nullptr; size = 0; }
		~LinkedList() { this->clear(); }

		inline bool isEmpty()	{ return (size == 0); }
		inline int size_()		{ return size; }
		inline int head_()		{ return head->data; }
		inline int tail_()		{ return tail->data; }
		inline Node* phead_()	{ return head; }
		inline Node* ptail_()	{ return tail; }

		void clear() {
			tail = nullptr;
			while (head != nullptr) {
				auto temp = head;
				head = head->next;
				delete temp;
			}
			size = 0;
		}

		void addHead(int d) { head = (isEmpty() ? tail = new Node(d) : new Node(d, head)); size++; }
		void addTail(int d) { tail = (isEmpty() ? head = new Node(d) : tail->next = new Node(d)); size++; }

		void addAt(int idx, int d) {
			if (idx < 0) { /*throw bad index*/ return; }
			if (idx == 0) { addHead(d); return; }
			if (idx == size) { addTail(d); return; }
			if (idx > size) { /*throw cant access*/ return; }

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
	};

}