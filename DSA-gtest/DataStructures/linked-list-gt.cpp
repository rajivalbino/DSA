#include "gtest/gtest.h"
#include "linked-list.hpp"

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
	EXPECT_TRUE(plist->isEmpty());
	delete plist;
}

TEST(TestLinkedList, size_)
{
	LinkedList* plist = new LinkedList();
	EXPECT_EQ(0, plist->size_());
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

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}