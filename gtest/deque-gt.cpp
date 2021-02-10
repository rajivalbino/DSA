#include "gtest/gtest.h"
#include "deque.hpp"

TEST(TestDeque, empty)
{
	rds::Deque<const char*> dq;
	EXPECT_TRUE(dq.empty());

	dq.push("hello");
	EXPECT_FALSE(dq.empty());

	dq.pop();
	EXPECT_TRUE(dq.empty());

	dq.inject("gtest");
	dq.push("c++");
	dq.inject("_");
	EXPECT_FALSE(dq.empty());

	dq.popAll();
	EXPECT_TRUE(dq.empty());
}

TEST(TestDeque, size)
{
	rds::Deque<double> dq;
	EXPECT_EQ(0, dq.size());

	dq.push(2.2);
	EXPECT_EQ(1, dq.size());

	dq.eject();
	EXPECT_EQ(0, dq.size());

	dq.push(5.);
	dq.inject(10.10);
	dq.push(3.3);
	dq.inject(0);
	EXPECT_EQ(4, dq.size());

	dq.popAll();
	EXPECT_EQ(0, dq.size());

	dq.inject(1.);
	dq.inject(4.5);
	dq.push(3);
	dq.eject();
	dq.pop();
	dq.push(3);
	EXPECT_EQ(2, dq.size());
}

TEST(TestDeque, peek)
{
	rds::Deque<const char*> dq;

	dq.push("red");
	EXPECT_EQ("red", dq.peekFront());
	EXPECT_EQ("red", dq.peekBack());

	dq.push("black");
	EXPECT_EQ("black", dq.peekFront());

	dq.inject("blue");
	EXPECT_EQ("blue", dq.peekBack());

	EXPECT_EQ("blue", dq.eject());
	EXPECT_EQ("red", dq.peekBack());

	dq.push("green");
	dq.push("gray");
	EXPECT_EQ("gray", dq.peekFront());
	EXPECT_EQ("red", dq.peekBack());

	dq.pop();
	dq.eject();
	EXPECT_EQ("green", dq.peekFront());
	EXPECT_EQ("black", dq.peekBack());
}