#include "statsi.hpp"

#include <cmath>
#include <vector>

using namespace std;

float calculateMedian(vector<float> values) {
  // To calculate the number of elements n
  int n = values.size();

  // We declate a variable to store the value of the median
  float median;

  // We sort the list of numbers that have been passed to the function by value
  // So we dont affect the vector outside this function
  // Using the sort function from std that
  // The vector of floats `values` is passed by value so using this function
  sort(values.begin(), values.end());

  // If n is even
  if (n % 2 == 0) {
    // We use a different formula to calculate the mean
    median = (values[n / 2 - 1] + values[(n / 2)]) / 2.0f;
  } else {  // Otherwise, if n is odd

    // We use a different formula to calculate the mean
    median = values[n / 2];
  }
  // We return the mean
  return median;
};

float calculateSum(vector<float>& values) {
  // We declare a variable to store the sum of values
  float sum;

  // Using a for loop...
  for (int n = 0; n < values.size(); n++) {
    // We iterate through all the values of values
    // and then incrementing sum by that value
    sum += values[n];
  }

  // Finally we return sum
  return sum;
};

float calculateMean(vector<float>& values) {
  // We calculate the mean by using the function calculateSum
  // That we wrote to calculate the sum of a list of values
  // We then divide it by the number of values
  // We convert the number of values to ensure a precise value
  return calculateSum(values) / float(values.size());
};

float calculateVariance(vector<float>& values) {
  // Formula for variance: σ2 = (∑ (x − x̅)^2) / n

  // First we define a float called sum
  float sum;

  // We calculate the mean for the set of values
  float mean = calculateMean(values);

  // Using a for loop we iterate through every value of values
  for (int n = 0; n < values.size(); n++) {
    // We subtract the mean from the value, then we square the result
    // And then add it to sum
    sum += pow((values[n] - mean), 2);
  };

  // We then return the sum divided by n
  return sum / float(values.size());
};

float calculateStandardDeviation(vector<float>& values) {
  // We calculate the value of variance, as it is the the standard deviation
  // squared
  float variance = calculateVariance(values);
  // We square root it, and then return it
  return sqrt(variance);
};

float calculateCorrelation(vector<float>& col1_values,
                           vector<float>& col2_values) {
  float sum1;
  float sum2;
  float sum3;
  float mean1 = calculateMean(col1_values);
  float mean2 = calculateMean(col2_values);
  for (int i = 0; i < col1_values.size(); i++) {
    sum1 += ((col1_values[i] - mean1) * (col2_values[i] - mean2));
    sum2 += pow((col1_values[i] - mean1), 2);
    sum3 += pow((col2_values[i] - mean2), 2);
  };
  return ((sum1) / (sqrt(sum2 * sum3)));
}

tuple<float, float> calculateRegression(vector<float>& values) {
  vector<float> indices;
  for (int x = 0; x < values.size(); x++) {
    indices.push_back(x);
  };

  float r = calculateCorrelation(indices, values);
  float stdx = calculateStandardDeviation(indices);
  float stdy = calculateStandardDeviation(values);

  float b = r * (stdx / stdy);

  float meanx = calculateMean(indices);
  float meany = calculateMean(values);
  float yIntercept = meany - b * (meanx);

  return tuple(yIntercept, b);
};
float getMax(vector<float>& values) {
  int index;
  float maxVal = values[0];
  for (int x = 0; x < values.size() - 1; x++) {
    if (max(values[x], values[x + 1]) > maxVal) {
      index = x;
      maxVal = max(values[x], values[x + 1]);
    }
  };
  return maxVal;
}

float getMin(vector<float>& values) {
  int index;
  float minVal = values[0];
  for (int x = 0; x < values.size() - 1; x++) {
    if (min(values[x], values[x + 1]) < minVal) {
      index = x;
      minVal = min(values[x], values[x + 1]);
    }
  };
  return minVal;
}

bool isPrime(int number) {
  // Using a for loop, we will iterate through all the numbers from 2 till the square root of the number + 1
  // We start at two since that is the smallest prime factor
  for (int x = 2; x < sqrt(number) + 1; x++) {
    // If any number in that range divides the number we are checking
    if (number % x == 0) {
      // We return
      return false;
    }
  }
  return true;
}