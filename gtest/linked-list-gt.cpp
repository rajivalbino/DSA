#include "gtest/gtest.h"
#include "linked-list.hpp"

typedef rds::LinkedList<int> LinkedList;

/* Singly Linked List
 * 
 * Attributes:
 * - int size
 * - Node* head
 * - Node* tail
 *
 * Methods:
 * addHead(), addTail(), addAt()
 * remove(data), removeHead(), removeTail(), removeAt(), clear()
 * head(), tail()
 * size(), isEmpty(), 
 */

TEST(TestLinkedList, isEmpty)
{
	LinkedList* plist = new LinkedList();
	EXPECT_TRUE(plist->isEmpty());

	plist->addHead(5);
	EXPECT_FALSE(plist->isEmpty());

	plist->removeHead();
	EXPECT_TRUE(plist->isEmpty());
	
	delete plist;
}

TEST(TestLinkedList, clear)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(20);
	EXPECT_EQ(3, plist->size_());
	EXPECT_EQ(20, plist->head_());
	EXPECT_EQ(5, plist->tail_());
	EXPECT_FALSE(plist->isEmpty());

	plist->clear();
	EXPECT_EQ(0, plist->size_());
	EXPECT_EQ(nullptr, plist->phead_());
	EXPECT_EQ(nullptr, plist->ptail_());
	EXPECT_TRUE(plist->isEmpty());

	plist->addHead(2);
	plist->addTail(3);
	EXPECT_EQ(2, plist->size_());
	EXPECT_NE(nullptr, plist->phead_());
	EXPECT_NE(nullptr, plist->ptail_());
	EXPECT_FALSE(plist->isEmpty());

	plist->clear();
	EXPECT_EQ(0, plist->size_());
	EXPECT_EQ(nullptr, plist->phead_());
	EXPECT_EQ(nullptr, plist->ptail_());
	EXPECT_TRUE(plist->isEmpty());

	delete plist;
}

TEST(TestLinkedList, size_)
{
	LinkedList* plist = new LinkedList();
	EXPECT_EQ(0, plist->size_());

	plist->addHead(10);
	EXPECT_EQ(1, plist->size_());

	plist->addHead(20);
	EXPECT_EQ(2, plist->size_());

	plist->addTail(30);
	EXPECT_EQ(3, plist->size_());
	
	plist->removeHead();
	EXPECT_EQ(2, plist->size_());

	for (int i = 0; i < 10; i++)
		plist->addTail(i);
	EXPECT_EQ(12, plist->size_());

	delete plist;
}

TEST(TestLinkedList, head_)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	EXPECT_EQ(5, plist->head_());

	delete plist;
}

TEST(TestLinkedList, tail_)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(10);
	plist->addHead(20);
	EXPECT_EQ(10, plist->tail_());

	delete plist;
}

TEST(TestLinkedList, addHead)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(20);
	plist->addHead(30);
	EXPECT_EQ(4, plist->size_());
	EXPECT_EQ(30, plist->head_());
	EXPECT_EQ(5, plist->tail_());

	plist->addHead(50);
	EXPECT_EQ(5, plist->size_());
	EXPECT_EQ(50, plist->head_());
	
	delete plist;
}

TEST(TestLinkedList, addTail)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addTail(10);
	plist->addTail(20);
	plist->addTail(30);
	EXPECT_EQ(4, plist->size_());
	EXPECT_EQ(5, plist->head_());
	EXPECT_EQ(30, plist->tail_());

	plist->addTail(50);
	EXPECT_EQ(5, plist->size_());
	EXPECT_EQ(50, plist->tail_());
	
	delete plist;
}

TEST(TestLinkedList, addAt)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addTail(10);
	plist->addTail(20);
	plist->addAt(1, 100);
	EXPECT_EQ(4, plist->size_());
	EXPECT_EQ(100, plist->phead_()->next->data);
	EXPECT_EQ(5, plist->head_());
	EXPECT_EQ(20, plist->tail_());

	plist->clear();
	plist->addHead(1);
	plist->addTail(2);
	plist->addTail(3);
	plist->addTail(4);
	plist->addAt(2, 200);
	EXPECT_EQ(5, plist->size_());
	EXPECT_EQ(200, plist->phead_()->next->next->data);
	EXPECT_EQ(1, plist->head_());
	EXPECT_EQ(4, plist->tail_());
	
	delete plist;
}

TEST(TestLinkedList, removeHead)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	EXPECT_EQ(10, plist->head_());
	EXPECT_EQ(5, plist->tail_());
	EXPECT_EQ(2, plist->size_());

	plist->removeHead();
	EXPECT_EQ(5, plist->head_());
	EXPECT_EQ(5, plist->tail_());
	EXPECT_EQ(1, plist->size_());

	plist->removeHead();
	EXPECT_TRUE(plist->isEmpty());
	EXPECT_EQ(nullptr, plist->phead_());
	EXPECT_EQ(nullptr, plist->ptail_());
	EXPECT_EQ(0, plist->size_());

	delete plist;
}

TEST(TestLinkedList, removeTail)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(15);
	EXPECT_EQ(15, plist->head_());
	EXPECT_EQ(5, plist->tail_());
	EXPECT_EQ(3, plist->size_());
	
	plist->removeTail();
	EXPECT_EQ(15, plist->head_());
	EXPECT_EQ(10, plist->tail_());
	EXPECT_EQ(2, plist->size_());

	plist->removeTail();
	EXPECT_EQ(15, plist->head_());
	EXPECT_EQ(15, plist->tail_());
	EXPECT_EQ(1, plist->size_());
	
	plist->removeTail();
	EXPECT_TRUE(plist->isEmpty());
	EXPECT_EQ(nullptr, plist->phead_());
	EXPECT_EQ(nullptr, plist->ptail_());
	EXPECT_EQ(0, plist->size_());

	delete plist;
}

