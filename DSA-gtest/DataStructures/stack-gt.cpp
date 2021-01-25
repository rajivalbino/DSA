#include "gtest/gtest.h"
#include "stack.hpp"
using rds::Stack;

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
	Stack* pstk = new Stack();
	EXPECT_TRUE(pstk->isEmpty());

	pstk->push(2);
	EXPECT_FALSE(pstk->isEmpty());

	pstk->pop();
	EXPECT_TRUE(pstk->isEmpty());

	pstk->push(5);
	pstk->push(10);
	pstk->push(15);
	EXPECT_FALSE(pstk->isEmpty());

	pstk->popAll();
	EXPECT_TRUE(pstk->isEmpty());

	delete pstk;
}

TEST(TestStack, size)
{
	Stack* pstk = new Stack();
	EXPECT_EQ(0, pstk->size());

	pstk->push(2);
	EXPECT_EQ(1, pstk->size());

	pstk->pop();
	EXPECT_EQ(0, pstk->size());

	pstk->push(5);
	pstk->push(10);
	pstk->push(15);
	pstk->push(20);
	EXPECT_EQ(4, pstk->size());

	pstk->popAll();
	EXPECT_EQ(0, pstk->size());

	pstk->push(1);
	pstk->push(2);
	pstk->push(3);
	pstk->pop();
	pstk->pop();
	pstk->push(4);
	EXPECT_EQ(2, pstk->size());


	delete pstk;
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
