#include "statsi.hpp"

#include <cmath>
#include <vector>

using namespace std;
float calculateMedian(vector<float> values) {
  int n = values.size();
  float median;
  sort(values.begin(), values.end());

  if (n % 2 == 0) {
    median = (values[n / 2 - 1] + values[(n / 2)]) / 2.0f;
  } else {
    median = values[n / 2];
  }
  return median;
};
float calculateSum(vector<float>& values) {
  float sum;
  for (int n = 0; n < values.size(); n++) {
    sum += values[n];
  }
  return sum;
};
float calculateMean(vector<float>& values) {
  return calculateSum(values) / float(values.size());
};

float calculateVariance(vector<float>& values) {
  // σ2 = ∑ (x − x̅)^2 / n
  float sum;
  float mean = calculateMean(values);
  for (int n = 0; n < values.size(); n++) {
    sum += pow((values[n] - mean), 2);
  };
  return sum / 2.f;
};

float calculateStandardDeviation(vector<float>& values) {
  float variance = calculateVariance(values);
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
  for (int x = 2; x < number / 2; x++) {
    if (number % x == 0) {
      return false;
    }
  }
  return true;
}