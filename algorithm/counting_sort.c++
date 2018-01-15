#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, temp, index = 0;
    cin >> size;
    vector<int> counts(101);
    vector<int> results(size);
    for (int i = 0; i < size; ++i) {
        cin >> temp;
        ++counts[temp];
    }

    for (int i = 0; i <= 100; ++i) {
        while (counts[i] != 0) {
            results[index++] = i;
            --counts[i];
        }

    }
    for (auto& elem : results)
        cout << elem << " ";

    return 0;
}
