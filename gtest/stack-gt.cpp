#include "gtest/gtest.h"
#include "stack.hpp"

typedef rds::Stack<int> Stack;

/* Stack
 *
 * Attributes:
 * private singly linked list
 * 
 * Methods:
 * isEmpty, size, top, push, pop, popAll
 * 
 */

TEST(TestStack, isEmpty)
{
	Stack* pstck = new Stack();
	EXPECT_TRUE(pstck->isEmpty());

	pstck->push(2);
	EXPECT_FALSE(pstck->isEmpty());

	pstck->pop();
	EXPECT_TRUE(pstck->isEmpty());

	pstck->push(5);
	pstck->push(10);
	pstck->push(15);
	EXPECT_FALSE(pstck->isEmpty());

	pstck->popAll();
	EXPECT_TRUE(pstck->isEmpty());

	delete pstck;
}

TEST(TestStack, size)
{
	Stack* pstck = new Stack();
	EXPECT_EQ(0, pstck->size());

	pstck->push(2);
	EXPECT_EQ(1, pstck->size());

	pstck->pop();
	EXPECT_EQ(0, pstck->size());

	pstck->push(5);
	pstck->push(10);
	pstck->push(15);
	pstck->push(20);
	EXPECT_EQ(4, pstck->size());

	pstck->popAll();
	EXPECT_EQ(0, pstck->size());

	pstck->push(1);
	pstck->push(2);
	pstck->push(3);
	pstck->pop();
	pstck->pop();
	pstck->push(4);
	EXPECT_EQ(2, pstck->size());


	delete pstck;
}

TEST(TestStack, top)
{
	Stack* pstck = new Stack();

	pstck->push(5);
	EXPECT_EQ(5, pstck->top());

	pstck->push(10);
	EXPECT_EQ(10, pstck->top());

	pstck->push(15);
	EXPECT_EQ(15, pstck->top());

	pstck->pop();
	EXPECT_EQ(10, pstck->top());

	pstck->push(20);
	pstck->push(50);
	EXPECT_EQ(50, pstck->top());

	pstck->pop();
	pstck->pop();
	pstck->pop();
	EXPECT_EQ(5, pstck->top());

	delete pstck;
}
