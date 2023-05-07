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

double calculateSum(vector<float>& values) {
  // We declare a variable to store the sum of values
  double sum = 0;

  // Using a for loop...
  for (float value : values) {
    // We iterate through all the values of values
    // and then incrementing sum by that value
    sum += value;
  }

  // Finally we return sum
  return sum;
};

float calculateMean(vector<float>& values) {
  // We calculate the mean by using the function calculateSum
  // That we wrote to calculate the sum of a list of values
  // We then divide it by the number of values
  // We convert the number of values to ensure a precise value
  float n = values.size();
  return (calculateSum(values) / n);
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
  // we initiate 3 values to hold the sums
  double sum1 = 0;
  double sum2 = 0;
  double sum3 = 0;

  // we get the mean for the values of column 1
  double mean1 = calculateMean(col1_values);
  // we get the mean for the values of column 2
  double mean2 = calculateMean(col2_values);

  // we iterate through every x,y pair of values in column 1 ad column 2
  for (int i = 0; i < col1_values.size(); i++) {
    // we get x
    float x = col1_values[i];
    // we get y
    float y = col2_values[i];

    // we add to the sum1 the result of (x - mean_x)(y - mean_y)
    sum1 += (x - mean1) * (y - mean2);
    // add the value of (x - mean_x)^2 to sum2
    sum2 += pow((x - mean1), 2);
    // add the value of (y - mean_y)^2 to sum3
    sum3 += pow((y - mean2), 2);
  }

  // return mean2;
  return (sum1 / (sqrt(sum2) * sqrt(sum3)));
}

tuple<double, double> calculateRegression(vector<float>& values) {
  // vector of values to store indices
  vector<float> indices;

  // we populate the vector with indices
  for (int x = 1; x <= values.size(); x++) {
    indices.push_back(x);
  };

  // we get the value for n, or the number of values
  int n = values.size();

  // sum of xy
  double sumxy = 0;
  // sum of x
  double sumx = 0;
  // sum of y
  double sumy = 0;
  // sum of x^2
  double sumx2 = 0;
  // sum of y^2
  double sumy2 = 0;

  // fior every value in values
  for (int i = 0; i < n; i++) {
    // we get the index
    float x = indices[i];
    // we get the value
    float y = values[i];

    // we add the result of x * y for each pair to sum x y
    sumxy += x * y;
    // we add each value of x together
    sumx += x;
    // we add each value of y together
    sumy += y;
    // we add the values of x ^ 2 together
    sumx2 += x * x;
    // we add the values of y ^ 2 together
    sumy2 += y * y;
  }

  // we calculate the value for b from the formula
  double b = ((n * sumxy) - (sumx * sumy)) / ((n * sumx2) - pow(sumx, 2));
  // we calculate the value for the intercept
  double yintercept = (sumy - b * sumx) / n;

  // returnt the tuple containing the yintercept and the b value
  return {yintercept, b};
};

float getMax(vector<float>& values) {
  // we declared a variable that holds the max value and initialised it to the
  // first value
  float maxVal = values[0];
  // for every value in values
  for (int x = 0; x < values.size() - 1; x++) {
    // if the max value of the pair of the current value and the next value is
    // bigger than the current maxVal
    if (max(values[x], values[x + 1]) > maxVal) {
      // then we change maxVal
      maxVal = max(values[x], values[x + 1]);
    }
  };
  return maxVal;
}

float getMin(vector<float>& values) {
  // we declared a variable that holds the min value and initialised it to the
  // first value
  float minVal = values[0];
  // for every value in values
  for (int x = 0; x < values.size() - 1; x++) {
    // if the min value of the pair of the current value and the next value is
    // bigger than the current minVal
    if (min(values[x], values[x + 1]) < minVal) {
      // then we change minVal
      minVal = min(values[x], values[x + 1]);
    }
  };
  return minVal;
}

bool isPrime(int number) {
  // if the number is 0 or 1, return false
  if (number == 0 || number == 1) return false;
  // if the value is 2 or 3, then return true
  if (number == 2 || number == 3) return true;
  // Using a for loop, we will iterate through all the numbers from 2 till the
  // square root of the number + 1 We start at two since that is the smallest
  // prime factor
  for (int x = 2; x < sqrt(number) + 1; x++) {
    // If any number in that range divides the number we are checking
    if (number % x == 0) {
      // We return
      return false;
    }
  }
  return true;
}