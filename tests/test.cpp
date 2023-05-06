#include <gtest/gtest.h>

#include <statsi/statsi.hpp>
#include <vector>
using namespace std;
// Demonstrate some basic assertions.
TEST(UnitTest, isPrime) {
  // vector<>
  EXPECT_EQ(true, isPrime(7));
  EXPECT_EQ(false, isPrime(0));
  EXPECT_EQ(false, isPrime(1));
  EXPECT_EQ(true, isPrime(2));
  EXPECT_EQ(true, isPrime(101));
}

TEST(UnitTest, hey) {
  vector<float> values_x = {1,4,10, 23, 43};
  vector<float> values_y = {10,12,11, 5, 20};

  // float corr = 0.5463;
  ASSERT_NEAR(0.5463f, calculateCorrelation (values_x, values_y), 0.0001);
}
