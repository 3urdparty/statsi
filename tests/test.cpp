#include<stati/statsi.hpp>
#include <gtest/gtest.h>
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    vector<float> values = {1,2,3,4,5};
    ASSERT_EQ(calculateSum(values));
}
