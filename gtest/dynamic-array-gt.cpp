#include "gtest/gtest.h"
#include "dynamic-array.hpp"

TEST(TestDynamicArray, sizeCapacity)
{
	rds::DynamicArray<int> vec;
	EXPECT_TRUE(vec.empty());

	vec.pushBack(5);
	vec.pushBack(10);
	vec.pushBack(15);
	vec.pushBack(20);
	vec.pushBack(25);
	EXPECT_FALSE(vec.empty());
	EXPECT_EQ(5, vec.size());
	EXPECT_EQ(8, vec.capacity());

	vec.pushBack(30);
	vec.pushBack(35);
	vec.pushBack(40);
	vec.pushBack(45);
	EXPECT_EQ(9, vec.size());
	EXPECT_EQ(16, vec.capacity());

	vec.popBack();
	vec.popBack();
	vec.popBack();
	EXPECT_EQ(6, vec.size());
	EXPECT_EQ(16, vec.capacity());
}

TEST(TestDynamicArray, operatorBrackets)
{
	rds::DynamicArray<int> vec;

	vec.pushBack(5);
	vec.pushBack(10);
	vec.pushBack(15);
	EXPECT_EQ(5, vec[0]);
	EXPECT_EQ(10, vec[1]);
	EXPECT_EQ(15, vec[2]);

	vec[2] = 200;
	EXPECT_EQ(200, vec[2]);
	vec.popBack();
	vec.popBack();
	EXPECT_EQ(5, vec[0]);
	EXPECT_EQ(1, vec.size());
}

TEST(TestDynamicArray, throws)
{
	rds::DynamicArray<int> vec;

	EXPECT_ANY_THROW(vec.popBack());

	vec.pushBack(5);
	vec.pushBack(10);
	vec.pushBack(15);
	EXPECT_EQ(30, vec[0] + vec[1] + vec[2]);
	EXPECT_ANY_THROW(vec[-1]);
	EXPECT_ANY_THROW(vec[3]);
	EXPECT_ANY_THROW(vec[5]);

	vec.popBack();
	EXPECT_ANY_THROW(vec[2]);

	vec.popBack();
	vec.popBack();
	EXPECT_ANY_THROW(vec.popBack());
}
