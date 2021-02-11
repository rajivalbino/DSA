#include "gtest/gtest.h"
#include "deque.hpp"

TEST(TestDeque, empty)
{
	rds::Deque<const char*> dq;
	EXPECT_TRUE(dq.empty());

	dq.pushFront("hello");
	EXPECT_FALSE(dq.empty());

	dq.popFront();
	EXPECT_TRUE(dq.empty());

	dq.pushBack("gtest");
	dq.pushFront("c++");
	dq.pushBack("_");
	EXPECT_FALSE(dq.empty());

	dq.popAll();
	EXPECT_TRUE(dq.empty());
}

TEST(TestDeque, size)
{
	rds::Deque<double> dq;
	EXPECT_EQ(0, dq.size());

	dq.pushFront(2.2);
	EXPECT_EQ(1, dq.size());

	dq.popBack();
	EXPECT_EQ(0, dq.size());

	dq.pushFront(5.);
	dq.pushBack(10.10);
	dq.pushFront(3.3);
	dq.pushBack(0);
	EXPECT_EQ(4, dq.size());

	dq.popAll();
	EXPECT_EQ(0, dq.size());

	dq.pushBack(1.);
	dq.pushBack(4.5);
	dq.pushFront(3);
	dq.popBack();
	dq.popFront();
	dq.pushFront(3);
	EXPECT_EQ(2, dq.size());
}

TEST(TestDeque, peek)
{
	rds::Deque<const char*> dq;

	dq.pushFront("red");
	EXPECT_EQ("red", dq.peekFront());
	EXPECT_EQ("red", dq.peekBack());

	dq.pushFront("black");
	EXPECT_EQ("black", dq.peekFront());

	dq.pushBack("blue");
	EXPECT_EQ("blue", dq.peekBack());

	EXPECT_EQ("blue", dq.popBack());
	EXPECT_EQ("red", dq.peekBack());

	dq.pushFront("green");
	dq.pushFront("gray");
	EXPECT_EQ("gray", dq.peekFront());
	EXPECT_EQ("red", dq.peekBack());

	dq.popFront();
	dq.popBack();
	EXPECT_EQ("green", dq.peekFront());
	EXPECT_EQ("black", dq.peekBack());
}