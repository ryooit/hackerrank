#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test_cases = 0;
    double temp = 0;
    double weight_sum = 0;
    double numbers_sum = 0;
    vector<double> numbers;

    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        cin >> temp;
        numbers.push_back(temp);
    }
    for (int i = 0; i < test_cases; ++i) {
        cin >> temp;
        weight_sum += temp;
        numbers[i] = numbers[i] * temp;
        numbers_sum += numbers[i];
    }
    printf("%.1f", (double) (numbers_sum / weight_sum));
    return 0;
}
