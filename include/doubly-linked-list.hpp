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

		// addHead
		// addTail
		// addAt
		// removeHead
		// removeTail
		// removeAt
		// remove

	};

}