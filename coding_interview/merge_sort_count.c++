#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

long long merge(vector<int>& numbers, int left, int right){
    long long count = 0;
    // mergesort downside => additional space(n)
    vector<int> temp(right-left+1);

    int middle = (left + right)/2;

    // indices
    int left_i  = left;
    int right_i = middle + 1;
    int temp_i = 0;

    while (left_i <= middle && right_i <= right) {
        if (numbers[left_i] <= numbers[right_i]) {
            temp[temp_i] = numbers[left_i];
            ++left_i;
        } else {
            temp[temp_i] = numbers[right_i];
            // the number of inversion is equal to space between left_index and middle
            count += middle - left_i + 1;
            ++right_i;
        }
        ++temp_i;
    }

    // copy leftover
    while (left_i <= middle) {
        temp[temp_i] = numbers[left_i];
        ++left_i;
        ++temp_i;
    }
    while (right_i <= right) {
        temp[temp_i] = numbers[right_i];
        ++right_i;
        ++temp_i;
    }

    temp_i = 0;
    for (int i = left; i <= right; ++i) {
        numbers[i] = temp[temp_i];
        ++temp_i;
    }

    return count;
}

// mergesort => always nlogn
long long mergesort(vector<int>& numbers, int left, int right){
    if (left >= right)
        return 0;

    long long count = 0;
    int middle = (left + right) / 2;

    count += mergesort(numbers, left, middle);
    count += mergesort(numbers, middle + 1, right);
    count += merge(numbers, left, right);

    return count;
}

long long count_inversions(vector<int>& a) {
    return mergesort(a, 0, a.size()-1);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
