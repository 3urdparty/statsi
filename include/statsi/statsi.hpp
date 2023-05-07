#ifndef STATSI_HPP
#define STATSI_HPP

#include <cmath>
#include <vector>

using namespace std;
/// @brief calculates the median from a list of values and returns a float
/// @param values the list of values
/// @return the float representing the median
float calculateMedian(vector<float> values);

/// @brief calculates the sum of a list of values
/// @param values list of values to calculate the sum for
/// @return the sum
double calculateSum(vector<float>& values);

/// @brief calculates the mean of a list of values
/// @param values list of values
/// @return the mean of the list of values
float calculateMean(vector<float>& values);

/// @brief calculates the variance of th list of values
/// @param values the list of values
/// @return the value for the variance of the list of values
float calculateVariance(vector<float>& values);

/// @brief calculates the standard deviation of a list of values
/// @param values
/// @return the standard deviation of the list of values
float calculateStandardDeviation(vector<float>& values);

/// @brief calculates the correlation of 2 sets of values
/// @param col1_values the first list of values (x-axis)
/// @param col2_values the second list of values (y-axis)
/// @return the value representing the correlation
float calculateCorrelation(vector<float>& col1_values,
                           vector<float>& col2_values);

/// @brief returns a tuple containing the y intercept of the linear regression
/// as well as the regression coefficient
/// @param values the list of values
/// @return the y intercept of the linear regression as well as the regression
/// coefficient
tuple<double, double> calculateRegression(vector<float>& values);

/// @brief returns the maximum value in that list of values
/// @param values the list of values
/// @return the maximum value in that list
float getMax(vector<float>& values);

/// @brief returns the minimum value in that list of values
/// @param values
/// @return the minimum value in that list
float getMin(vector<float>& values);

/// @brief if the number is prime, it returns true
/// @param number the number to check
/// @return true if the number is prime and false if it isn't
bool isPrime(int number);
#endif
