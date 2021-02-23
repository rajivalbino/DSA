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

TEST(TestDynamicArray, iterators1)
{
	rds::DynamicArray<int> vec;

	vec.pushBack(1);
	vec.pushBack(5);
	vec.popBack();
	vec.pushBack(10);
	vec.pushBack(20);
	vec.pushBack(50);

	for (int& value : vec)
		value *= 2;

	EXPECT_EQ(2, vec[0]);
	EXPECT_EQ(20, vec[1]);
	EXPECT_EQ(40, vec[2]);
	EXPECT_EQ(100, vec[3]);

	for (rds::DynamicArray<int>::Iterator it = vec.begin(); it != vec.end(); ++it)
		*it = *it + 5;

	EXPECT_EQ(7, vec[0]);
	EXPECT_EQ(25, vec[1]);
	EXPECT_EQ(45, vec[2]);
	EXPECT_EQ(105, vec[3]);
}

TEST(TestDynamicArray, iterators2)
{
	rds::DynamicArray<int> vec;

	vec.pushBack(5);
	vec.pushBack(10);
	vec.pushBack(15);
	vec.pushBack(1);
	vec.pushBack(1);
	vec.popBack();
	vec.popBack();
	vec.pushBack(20);
	vec.pushBack(25);
	vec.pushBack(30);

	//  0  1  2  3  4  5
	//  5 10 15 20 25 30
	
	auto it = vec.begin();
	EXPECT_EQ(5, vec[0]);
	EXPECT_EQ(5, it[0]);
	EXPECT_EQ(5, *it);
	EXPECT_EQ(10, *(it+1));
	
	it += 2;
	EXPECT_EQ(15, vec[2]);
	EXPECT_EQ(15, it[0]);
	EXPECT_EQ(15, *it);
	EXPECT_EQ(10, it[-1]);
	EXPECT_EQ(25, (it-2)[4]);
	EXPECT_EQ(10, (it+3)[-4]);
	
	it -= 1;
	EXPECT_EQ(25, *(it+=3));
	EXPECT_EQ(20, *--it);
	EXPECT_EQ(5, *(it-=3));
}

TEST(TestDynamicArray, iterators3)
{
	class MyInt {
	public:
		int _val;
		MyInt(int v) : _val(v) {}
		int val() { return _val; }
	};

	rds::DynamicArray<MyInt> vec;
	auto it = vec.begin();
	EXPECT_TRUE(it == vec.begin());
	EXPECT_TRUE(it == vec.end());
	
	vec.pushBack(5);
	vec.pushBack(10);
	vec.pushBack(15);
	vec.pushBack(20);
	vec.pushBack(25);
	
	//  0  1  2  3  4
	//  5 10 15 20 25

	EXPECT_EQ(5, it->val());
	EXPECT_EQ(10, (it+1)->val());
	EXPECT_EQ(15, ((it+3)-1)->val());

	EXPECT_TRUE(it == vec.begin());
	EXPECT_TRUE(it + 4 != vec.end());
	EXPECT_TRUE(it + vec.size() == vec.end());
}