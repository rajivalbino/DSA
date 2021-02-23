#include "gtest/gtest.h"
#include "linked-list.hpp"

using LinkedList = rds::LinkedList<int>;

TEST(TestLinkedList, empty)
{
	LinkedList* plist = new LinkedList();
	EXPECT_TRUE(plist->empty());

	plist->addHead(5);
	EXPECT_FALSE(plist->empty());

	plist->removeHead();
	EXPECT_TRUE(plist->empty());
	
	delete plist;
}

TEST(TestLinkedList, clear)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(20);
	EXPECT_EQ(3, plist->size());
	EXPECT_EQ(20, plist->head());
	EXPECT_EQ(5, plist->tail());
	EXPECT_FALSE(plist->empty());

	plist->clear();
	EXPECT_EQ(0, plist->size());
	EXPECT_TRUE(plist->begin() == LinkedList::Iterator(nullptr));
	EXPECT_TRUE(plist->empty());

	plist->addHead(2);
	plist->addTail(3);
	EXPECT_EQ(2, plist->size());
	EXPECT_TRUE(plist->begin() != LinkedList::Iterator(nullptr));
	EXPECT_FALSE(plist->empty());

	plist->clear();
	EXPECT_EQ(0, plist->size());
	EXPECT_TRUE(plist->begin() == LinkedList::Iterator(nullptr));
	EXPECT_TRUE(plist->empty());

	delete plist;
}

TEST(TestLinkedList, size)
{
	LinkedList* plist = new LinkedList();
	EXPECT_EQ(0, plist->size());

	plist->addHead(10);
	EXPECT_EQ(1, plist->size());

	plist->addHead(20);
	EXPECT_EQ(2, plist->size());

	plist->addTail(30);
	EXPECT_EQ(3, plist->size());
	
	plist->removeHead();
	EXPECT_EQ(2, plist->size());

	for (int i = 0; i < 10; i++)
		plist->addTail(i);
	EXPECT_EQ(12, plist->size());

	delete plist;
}

TEST(TestLinkedList, head)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	EXPECT_EQ(5, plist->head());

	delete plist;
}

TEST(TestLinkedList, tail)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(10);
	plist->addHead(20);
	EXPECT_EQ(10, plist->tail());

	delete plist;
}

TEST(TestLinkedList, addHead)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(20);
	plist->addHead(30);
	EXPECT_EQ(4, plist->size());
	EXPECT_EQ(30, plist->head());
	EXPECT_EQ(5, plist->tail());

	plist->addHead(50);
	EXPECT_EQ(5, plist->size());
	EXPECT_EQ(50, plist->head());
	
	delete plist;
}

TEST(TestLinkedList, addTail)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addTail(10);
	plist->addTail(20);
	plist->addTail(30);
	EXPECT_EQ(4, plist->size());
	EXPECT_EQ(5, plist->head());
	EXPECT_EQ(30, plist->tail());

	plist->addTail(50);
	EXPECT_EQ(5, plist->size());
	EXPECT_EQ(50, plist->tail());
	
	delete plist;
}

TEST(TestLinkedList, addAt)
{
	LinkedList plist;
	plist.addHead(5);
	plist.addTail(10);
	plist.addTail(20);
	plist.addAt(1, 100);
	EXPECT_EQ(4, plist.size());
	EXPECT_EQ(100, plist[1]);
	EXPECT_EQ(5, plist.head());
	EXPECT_EQ(20, plist.tail());

	plist.clear();
	plist.addHead(1);
	plist.addTail(2);
	plist.addTail(3);
	plist.addTail(4);
	plist.addAt(2, 200);
	EXPECT_EQ(5, plist.size());
	EXPECT_EQ(200, plist[2]);
	EXPECT_EQ(1, plist.head());
	EXPECT_EQ(4, plist.tail());
}

TEST(TestLinkedList, removeHead)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	EXPECT_EQ(10, plist->head());
	EXPECT_EQ(5, plist->tail());
	EXPECT_EQ(2, plist->size());

	plist->removeHead();
	EXPECT_EQ(5, plist->head());
	EXPECT_EQ(5, plist->tail());
	EXPECT_EQ(1, plist->size());

	plist->removeHead();
	EXPECT_TRUE(plist->empty());
	EXPECT_TRUE(plist->begin() == LinkedList::Iterator(nullptr));
	EXPECT_EQ(0, plist->size());

	delete plist;
}

TEST(TestLinkedList, removeTail)
{
	LinkedList* plist = new LinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(15);
	EXPECT_EQ(15, plist->head());
	EXPECT_EQ(5, plist->tail());
	EXPECT_EQ(3, plist->size());
	
	plist->removeTail();
	EXPECT_EQ(15, plist->head());
	EXPECT_EQ(10, plist->tail());
	EXPECT_EQ(2, plist->size());

	plist->removeTail();
	EXPECT_EQ(15, plist->head());
	EXPECT_EQ(15, plist->tail());
	EXPECT_EQ(1, plist->size());
	
	plist->removeTail();
	EXPECT_TRUE(plist->empty());
	EXPECT_TRUE(plist->begin() == LinkedList::Iterator(nullptr));
	EXPECT_EQ(0, plist->size());

	delete plist;
}

TEST(TestLinkedList, remove)
{
	LinkedList list;

	list >> 5;
	list >> 10;
	list >> 15;
	list >> 20;
	list >> 25;

	EXPECT_TRUE(list.remove(15));
	EXPECT_EQ(4, list.size());
	EXPECT_FALSE(list.remove(2));
	EXPECT_TRUE(list.remove(5));
	EXPECT_EQ(10, list.head());
}

TEST(TestLinkedList, operatorLeftShift)
{
	LinkedList list;

	list << 5;
	list << 10;
	list << 15;
	list << 20;
	list << 25;

	EXPECT_EQ(25, list[0]);
	EXPECT_EQ(20, list[1]);
	EXPECT_EQ(15, list[2]);
	EXPECT_EQ(10, list[3]);
	EXPECT_EQ(5,  list[4]);
}

TEST(TestLinkedList, operatorRightShift)
{
	LinkedList list;

	list >> 5;
	list >> 10;
	list >> 15;
	list >> 20;
	list >> 25;

	EXPECT_EQ(5,  list[0]);
	EXPECT_EQ(10, list[1]);
	EXPECT_EQ(15, list[2]);
	EXPECT_EQ(20, list[3]);
	EXPECT_EQ(25, list[4]);

}

TEST(TestLinkedList, operatorDecrement)
{
	LinkedList list;

	list << 5;
	list << 10;
	list << 15;
	list << 20;
	list << 25;
	list << 30;

	EXPECT_EQ(30, list.head());
	EXPECT_EQ(5, list.tail());

	--list;
	EXPECT_EQ(25, list.head());
	
	list--;
	EXPECT_EQ(10, list.tail());
	
	--list;
	EXPECT_EQ(20, list.head());

	list--;
	EXPECT_EQ(15, list.tail());

	--list;
	EXPECT_EQ(15, list.head());

	list--;
	EXPECT_ANY_THROW(list.head());
}

TEST(TestLinkedList, iterators1)
{
	rds::LinkedList<int> list;
	list.addTail(1);
	list.addTail(5);
	list.removeTail();
	list.addTail(10);
	list.addTail(20);
	list.addTail(50);

	for (int& value : list)
		value *= 2;

	EXPECT_EQ(2,   list[0]);
	EXPECT_EQ(20,  list[1]);
	EXPECT_EQ(40,  list[2]);
	EXPECT_EQ(100, list[3]);

	for (rds::LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it)
		*it = *it + 5;

	EXPECT_EQ(7,   list[0]);
	EXPECT_EQ(25,  list[1]);
	EXPECT_EQ(45,  list[2]);
	EXPECT_EQ(105, list[3]);
}

TEST(TestLinkedList, iterators2)
{
	rds::LinkedList<int> list;

	list.addTail(5);
	list.addTail(10);
	list.addTail(15);
	list.addTail(1);
	list.addTail(1);
	list.removeTail();
	list.removeTail();
	list.addTail(20);
	list.addTail(25);
	list.addTail(30);

	//  0  1  2  3  4  5
	//  5 10 15 20 25 30

	auto it = list.begin();
	EXPECT_EQ(5, list[0]);
	EXPECT_EQ(5, it[0]);
	EXPECT_EQ(5, *it);
	EXPECT_EQ(10, *(it+1));

	it += 2;
	EXPECT_EQ(15, list[2]);
	EXPECT_EQ(15, it[0]);
	EXPECT_EQ(15, *it);
	EXPECT_EQ(20, it[1]);
	EXPECT_EQ(30, (it+1)[2]);
	EXPECT_EQ(30, *(it += 3));
}