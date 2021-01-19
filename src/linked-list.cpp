#include "linked-list.hpp"

void LinkedList::clear()
{
	while (head != nullptr)
	{
		auto temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::addHead(int d)
{
	if (isEmpty())
		head = tail = new Node(d);
	else
		head = new Node(d, head);

	size++;
}

void LinkedList::addTail(int d)
{
	if (isEmpty())
		tail = head = new Node(d);
	else
		tail = tail->next = new Node(d);

	size++;
}