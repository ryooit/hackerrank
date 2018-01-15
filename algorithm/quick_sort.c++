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

int partition (vector<int>& nums, int left, int right, int pivot) {
    while (left <= right) {
        while (nums[left] < pivot) {
            ++left;
        }
        while (nums[right] > pivot) {
            --right;
        }
        if (left <= right) {
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
    }
    return left;
}

void quick_sort (vector<int>& nums, int start, int end) {
    if (start >= end)
        return;
    int pivot = nums[(start + end) / 2];
    int pIndex = partition (nums, start, end, pivot);
    quick_sort(nums, 0, pIndex-1);
    quick_sort(nums, pIndex, end);
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
    quick_sort(nums, 0, size-1);
    print(nums);
    return 0;
}
