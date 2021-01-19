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
	LinkedList() { head = tail = nullptr; size = 0; }

	bool isEmpty();
	int size_();
	int head_();
	int tail_();
	void addHead(int d);
	void addTail(int d);

};