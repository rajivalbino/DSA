#include "gtest/gtest.h"
#include "doubly-linked-list.hpp"

using DoublyLinkedList = rds::DoublyLinkedList<int>;

TEST(TestDoublyLinkedList, empty)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
	EXPECT_TRUE(plist->empty());

	plist->addHead(5);
	EXPECT_FALSE(plist->empty());

	plist->removeHead();
	EXPECT_TRUE(plist->empty());

	delete plist;
}

TEST(TestDoublyLinkedList, clear)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
	plist->addHead(5);
	plist->addHead(10);
	plist->addHead(20);
	EXPECT_EQ(3, plist->size_());
	EXPECT_EQ(20, plist->head_());
	EXPECT_EQ(5, plist->tail_());
	EXPECT_FALSE(plist->empty());

	plist->clear();
	EXPECT_EQ(0, plist->size_());
	EXPECT_TRUE(plist->begin() == nullptr);
	EXPECT_TRUE(plist->empty());

	plist->addHead(2);
	plist->addTail(3);
	EXPECT_EQ(2, plist->size_());
	EXPECT_TRUE(plist->begin() != nullptr);
	EXPECT_FALSE(plist->empty());

	plist->clear();
	EXPECT_EQ(0, plist->size_());
	EXPECT_TRUE(plist->begin() == nullptr);
	EXPECT_TRUE(plist->empty());

	delete plist;
}

TEST(TestDoublyLinkedList, size_)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
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

TEST(TestDoublyLinkedList, head_)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
	plist->addHead(5);
	EXPECT_EQ(5, plist->head_());

	delete plist;
}

TEST(TestDoublyLinkedList, tail_)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
	plist->addHead(10);
	plist->addHead(20);
	EXPECT_EQ(10, plist->tail_());

	delete plist;
}

TEST(TestDoublyLinkedList, addHead)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
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

TEST(TestDoublyLinkedList, addTail)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
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

TEST(TestDoublyLinkedList, addAt)
{
	DoublyLinkedList plist;
	plist.addHead(5);
	plist.addTail(10);
	plist.addTail(20);
	plist.addAt(1, 100);
	EXPECT_EQ(4, plist.size_());
	EXPECT_EQ(100, plist[1]);
	EXPECT_EQ(5, plist.head_());
	EXPECT_EQ(20, plist.tail_());

	plist.clear();
	plist.addHead(1);
	plist.addTail(2);
	plist.addTail(3);
	plist.addTail(4);
	plist.addAt(2, 200);
	EXPECT_EQ(5, plist.size_());
	EXPECT_EQ(200, plist[2]);
	EXPECT_EQ(1, plist.head_());
	EXPECT_EQ(4, plist.tail_());
}

TEST(TestDoublyLinkedList, removeHead)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
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
	EXPECT_TRUE(plist->empty());
	EXPECT_TRUE(plist->begin() == nullptr);
	EXPECT_EQ(0, plist->size_());

	delete plist;
}

TEST(TestDoublyLinkedList, removeTail)
{
	DoublyLinkedList* plist = new DoublyLinkedList();
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
	EXPECT_TRUE(plist->empty());
	EXPECT_TRUE(plist->begin() == nullptr);
	EXPECT_EQ(0, plist->size_());

	delete plist;
}

TEST(TestDoublyLinkedList, remove)
{
	DoublyLinkedList list;

	list >> 5;
	list >> 10;
	list >> 15;
	list >> 20;
	list >> 25;

	EXPECT_TRUE(list.remove(15));
	EXPECT_EQ(4, list.size_());
	EXPECT_FALSE(list.remove(2));
	EXPECT_TRUE(list.remove(5));
	EXPECT_EQ(10, list.head_());
}

TEST(TestDoublyLinkedList, operatorLeftShift)
{
	DoublyLinkedList list;

	list << 5;
	list << 10;
	list << 15;
	list << 20;
	list << 25;

	EXPECT_EQ(25, list.removeHead());
	EXPECT_EQ(20, list.removeHead());
	EXPECT_EQ(15, list.removeHead());
	EXPECT_EQ(10, list.removeHead());
	EXPECT_EQ(5, list.removeHead());
}

TEST(TestDoublyLinkedList, operatorRightShift)
{
	DoublyLinkedList list;

	list >> 5;
	list >> 10;
	list >> 15;
	list >> 20;
	list >> 25;

	EXPECT_EQ(5, list.removeHead());
	EXPECT_EQ(10, list.removeHead());
	EXPECT_EQ(15, list.removeHead());
	EXPECT_EQ(20, list.removeHead());
	EXPECT_EQ(25, list.removeHead());

}

TEST(TestDoublyLinkedList, operatorDecrement)
{
	DoublyLinkedList list;

	list << 5;
	list << 10;
	list << 15;
	list << 20;
	list << 25;

	EXPECT_EQ(25, --list);
	EXPECT_EQ(5, list--);
	EXPECT_EQ(20, --list);
	EXPECT_EQ(10, list--);
	EXPECT_EQ(15, --list);
}
