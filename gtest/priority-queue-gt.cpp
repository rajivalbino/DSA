#include "gtest/gtest.h"
#include "priority-queue.hpp"

TEST(TestPriorityQueue, initialization)
{
	rds::PriorityQueue<int> pq;
	EXPECT_TRUE(pq.empty());
	EXPECT_EQ(8, pq.capacity());

	pq.insert(5);
	EXPECT_FALSE(pq.empty());
	EXPECT_EQ(1, pq.size());
	EXPECT_EQ(8, pq.capacity());

	pq.clear();
	EXPECT_TRUE(pq.empty());
}

TEST(TestPriorityQueue, sizeControl)
{
	rds::PriorityQueue<int> pq(5);
	EXPECT_EQ(0, pq.size());
	EXPECT_EQ(5, pq.capacity());

	pq.insert(5);
	pq.insert(5);
	pq.insert(5);
	pq.insert(5);
	EXPECT_EQ(4, pq.size());
	EXPECT_EQ(5, pq.capacity());

	pq.insert(5);
	pq.insert(5);
	EXPECT_EQ(6, pq.size());
	EXPECT_EQ(10, pq.capacity());

	pq.poll();
	pq.poll();
	pq.poll();
	EXPECT_EQ(3, pq.size());
	EXPECT_EQ(10, pq.capacity());
}

TEST(TestPriorityQueue, peekAlwaysMaxValue)
{
	rds::PriorityQueue<int> pq;

	pq.insert(3);	EXPECT_EQ(3, pq.peek());
	pq.insert(9);	EXPECT_EQ(9, pq.peek());
	pq.insert(7);	EXPECT_EQ(9, pq.peek());
	pq.insert(10);	EXPECT_EQ(10, pq.peek());
	pq.insert(4);	EXPECT_EQ(10, pq.peek());
	pq.insert(1);	EXPECT_EQ(10, pq.peek());
	pq.poll();		EXPECT_EQ(9, pq.peek());
	pq.insert(12);	EXPECT_EQ(12, pq.peek());
	pq.insert(8);	EXPECT_EQ(12, pq.peek());
	pq.insert(15);	EXPECT_EQ(15, pq.peek());
	pq.insert(2);	EXPECT_EQ(15, pq.peek());
	pq.poll();		EXPECT_EQ(12, pq.peek());
	pq.poll();		EXPECT_EQ(9, pq.peek());
	pq.insert(4);	EXPECT_EQ(9, pq.peek());
	pq.insert(2);	EXPECT_EQ(9, pq.peek());
	pq.insert(11);	EXPECT_EQ(11, pq.peek());
	pq.poll();		EXPECT_EQ(9, pq.peek());
	pq.insert(14);	EXPECT_EQ(14, pq.peek());
}