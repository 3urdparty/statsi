#include <gtest/gtest.h>

#include <statsi/statsi.hpp>
#include <vector>
using namespace std;
// Some basic tests
TEST(UnitTest, isPrime) {
  // To test if isPrime function works properly
  EXPECT_EQ(true, isPrime(7));
  EXPECT_EQ(false, isPrime(0));
  EXPECT_EQ(false, isPrime(1));
  EXPECT_EQ(true, isPrime(2));
  EXPECT_EQ(true, isPrime(101));
}

TEST(UnitTest, correlation) {
  vector<float> values_x = {1, 4, 10, 23, 43};
  vector<float> values_y = {10, 12, 11, 5, 20};

  // We check if the calculateCorrelation returns correct values
  ASSERT_NEAR(0.5463f, calculateCorrelation(values_x, values_y), 0.0001);
  ASSERT_NEAR(10.30, get<1>(calculateRegression(values_x)), 0.0001);
  ASSERT_NEAR(7.700, get<0>(calculateRegression(values_y)), 0.0001);
  ASSERT_NEAR(1.300, get<1>(calculateRegression(values_y)), 0.0001);
}
