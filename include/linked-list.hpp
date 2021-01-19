// Singly Linked List
// int datatype

#pragma once

class LinkedList {

private:
	class Node {
	public:
		int data;
		Node* next;

		Node(int _d) : data(_d) {next = nullptr;}
		Node(int _d, Node* _n) : data(_d), next(_n) {}
	};

private:
	int size;
	Node* head;
	Node* tail;

public:
	LinkedList()  { head = tail = nullptr; size = 0; }
	~LinkedList() { this->clear(); }

	inline bool isEmpty()	{ return (size == 0); }
	inline int size_()		{ return size; }
	inline int head_()		{ return head->data; }
	inline int tail_()		{ return tail->data; }
	
	void clear() {
		while (head != nullptr) {
			auto temp = head;
			head = head->next;
			delete temp;
		}
	}
	
	void addHead(int d) { head = (isEmpty() ? tail = new Node(d) : new Node(d, head)); size++; }
	void addTail(int d) { tail = (isEmpty() ? head = new Node(d) : tail->next = new Node(d)); size++; }
};