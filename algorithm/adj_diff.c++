#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

int eval(vector<int>& arr) {
    sort(begin(arr), end(arr));
    adjacent_difference(begin(arr), end(arr), begin(arr),
                            [](int a, int b){ return abs(a-b); });
    return *min_element(begin(arr)+1, end(arr));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, temp;
    cin >> size;
    vector<int> nums;
    for (int i = 0; i < size; ++i)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    int min_val = eval(nums);
    cout << min_val;

    return 0;
}
