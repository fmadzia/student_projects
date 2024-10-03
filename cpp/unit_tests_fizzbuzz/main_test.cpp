// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(mojagrupatestow, buzz) {
   string test = fizz_buzz(50);
   EXPECT_EQ(test, "buzz");
}

TEST(mojagrupatestow, fizzbuzz) {
   string test = fizz_buzz(15);
   EXPECT_EQ(test, "fizzbuzz");
}

TEST(mojagrupatestow, fizz) {
   string test = fizz_buzz(9);
   EXPECT_EQ(test, "fizz");
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

