// main_test.cpp
#include <gtest/gtest.h>
#include "main.cpp"


TEST(stairsTests, validInput) {
	StairCalculationResult stairs = calculateStairs(250, 150);
	EXPECT_EQ(stairs.stairsCount, 13);
	EXPECT_NE(stairs.depthOfEachStair, 0);
}

TEST(stairsTests, invalidInput) {
	try
	{
		StairCalculationResult stairs = calculateStairs(0, 0);
	}
	catch(std::exception& e)
	{
		EXPECT_STREQ("Exception was thrown as expected: ", e.what());
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

