#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void print (vector<int>& nums) {
    for (auto& elem : nums)
        cout << elem << " ";
    cout << endl;
}

void insertion_sort (vector<int>& nums, int size) {
    for (int i = 1; i < size; ++i) {
        int value = nums[i];
        int hole = i;
        while (hole > 0 && nums[hole-1] > value) {
            nums[hole] = nums[hole-1];
            --hole;
        }
        nums[hole] = value;
    }
    print(nums);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, temp;
    vector<int> nums;
    cin >> size;
    for (int i = 0; i < size; ++i) {
        cin >> temp;
        nums.push_back(temp);
    }
    insertion_sort(nums, size);
    return 0;
}
