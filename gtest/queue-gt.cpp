#include "gtest/gtest.h"
#include "queue.hpp"
using rds::Queue;

/* Queue
 *
 * Attributes:
 * private singly linked list
 *
 * Methods:
 * isEmpty, size, first, enque, deque, dequeAll
 *
 */

TEST(TestQueue, isEmpty)
{
	Queue* pque = new Queue();
	EXPECT_TRUE(pque->isEmpty());

	pque->enque(2);
	EXPECT_FALSE(pque->isEmpty());

	pque->deque();
	EXPECT_TRUE(pque->isEmpty());

	pque->enque(5);
	pque->enque(10);
	pque->enque(15);
	EXPECT_FALSE(pque->isEmpty());

	pque->dequeAll();
	EXPECT_TRUE(pque->isEmpty());

	delete pque;
}

TEST(TestQueue, size)
{
	Queue* pque = new Queue();
	EXPECT_EQ(0, pque->size());

	pque->enque(2);
	EXPECT_EQ(1, pque->size());

	pque->deque();
	EXPECT_EQ(0, pque->size());

	pque->enque(5);
	pque->enque(10);
	pque->enque(15);
	pque->enque(20);
	EXPECT_EQ(4, pque->size());

	pque->dequeAll();
	EXPECT_EQ(0, pque->size());

	pque->enque(1);
	pque->enque(2);
	pque->enque(3);
	pque->deque();
	pque->deque();
	pque->enque(4);
	EXPECT_EQ(2, pque->size());


	delete pque;
}

TEST(TestQueue, first)
{
	Queue* pque = new Queue();

	pque->enque(5);
	EXPECT_EQ(5, pque->first());

	pque->enque(10);
	EXPECT_EQ(5, pque->first());

	pque->enque(15);
	EXPECT_EQ(5, pque->first());

	pque->deque();
	EXPECT_EQ(10, pque->first());

	pque->enque(20);
	pque->enque(50);
	EXPECT_EQ(10, pque->first());

	pque->deque();
	pque->deque();
	pque->deque();
	EXPECT_EQ(50, pque->first());

	delete pque;
}
