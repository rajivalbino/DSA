#include "gtest/gtest.h"

TEST(TestCaseName, TestA)
{
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestB)
{
	EXPECT_EQ(2, 2);
}

/*
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
*/