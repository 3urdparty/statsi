#include<iostream>
using namespace std;

#include "../src/statsi.cpp"
int main(int argc, const char** argv) {
    vector<float> values = {10, 20, 30};
    // cout << calculateMean(values);
    for (int x = 0; x < 1000; x++){
        if (isPrime(x)) cout << x << endl;
    }
}