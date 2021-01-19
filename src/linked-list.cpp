#include "linked-list.h"

bool LinkedList::isEmpty()	{return (size == 0);}
int LinkedList::size_()		{return size;}
int LinkedList::head_()		{return head->data;}
int LinkedList::tail_()		{return tail->data;}

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