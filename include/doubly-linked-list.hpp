// Doubly Linked List
// int datatype

#pragma once

namespace rds {

	class DoublyLinkedList {

	private:
		class Node {
		public:
			int data;
			Node* prev;
			Node* next;

			Node(int _d) : data(_d) { prev = next = nullptr; }
			Node(int _d, Node* _p, Node* _n) : data(_d), prev(_p), next(_n) {}
		};

	private:
		int size;
		Node* head;
		Node* tail;
	
	public:
		DoublyLinkedList() { head = tail = nullptr; size = 0; }
		~DoublyLinkedList() { this->clear(); }

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
			if (isEmpty())
				head = tail = new Node(d);
			else {
				head = new Node(d, nullptr, head);
				head->next->prev = head;
			}
			size++;
		}

		void addTail(int d) {
			if (isEmpty())
				tail = head = new Node(d);
			else {
				tail = new Node(d, tail, nullptr);
				tail->prev->next = tail;
			}
			size++;
		}

		void addAt(int idx, int d) {
			if (idx < 0) { /*throw bad index*/ return; }
			if (idx == 0) { addHead(d); return; }
			if (idx == size) { addTail(d); return; }
			if (idx > size) { /*throw cant access*/ return; }

			auto ptr = head;
			for (int i = 0; i < idx - 1; i++)
				ptr = ptr->next;

			auto temp = new Node(d, ptr, ptr->next);
			ptr->next = temp;
			temp->next->prev = temp;
			size++;
		}

		int removeHead() {
			if (!isEmpty()) {
				auto temp = head;
				auto tdata = head->data;
				head = head->next;
				head->prev = nullptr;
				delete temp;
				size--;

				if (isEmpty()) tail = nullptr;
				return tdata;
			}
			/*else throw empty list*/
		}

		int removeTail() {
			if (!isEmpty()) {
				auto temp = tail;
				auto tdata = tail->data;
				tail = tail->prev;
				tail->next = nullptr;
				delete temp;
				size--;

				if (isEmpty()) head = nullptr;
				return tdata;
			}
			/*else throw empty list*/
		}
		
		// removeAt
		// contains
		// remove

	};

}