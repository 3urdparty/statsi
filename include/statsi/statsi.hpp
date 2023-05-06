#ifndef STATSI_HPP
#define STATSI_HPP

#include <cmath>
#include <vector>

using namespace std;
float calculateMedian(vector<float> values);
double calculateSum(vector<float>& values);
float calculateMean(vector<float>& values);
float calculateVariance(vector<float>& values);
float calculateStandardDeviation(vector<float>& values);
float calculateCorrelation(vector<float>& col1_values,
                           vector<float>& col2_values);
tuple<double, double> calculateRegression(vector<float>& values);
float getMax(vector<float>& values);
float getMin(vector<float>& values);
bool isPrime(int number);
#endif
