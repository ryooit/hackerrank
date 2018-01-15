#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, temp;
    vector<int> nums;
    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    int half = size >> 1;
    if (size % 2 == 0)
        cout << (nums[half-1] + nums[half]) / 2 << endl;
    else
        cout << nums[half];
        
    return 0;
}
