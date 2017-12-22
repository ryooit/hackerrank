#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test_num = 0;
    int temp = 0;
    int sum = 0;
    vector<int> numbers;
    map<int, int> counts;

    cin >> test_num;
    for (int i = 0; i < test_num; ++i) {
        cin >> temp;
        sum += temp;
        numbers.push_back(temp);
        ++counts[numbers[i]];
    } 
    cout << (double)sum / test_num << endl;
    
    sort(numbers.begin(), numbers.end());
    int index = test_num >> 1;
    if (test_num % 2 != 0) 
        cout << numbers[index];
    else
        cout << (double) (numbers[index-1] + numbers[index]) / 2 << endl;

    int max_count = 0;
    for (auto val : counts) {
        int count = val.second;
        max_count = max_count < count ? count : max_count;
    }
    for (auto val : counts) {
        int count = val.second;
        if (count == max_count) {
            cout << val.first << endl;
            break;
        }
    }
    return 0;
}