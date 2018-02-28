#include <vector>
#include <iostream>
#include <algorithm>    //max
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n); // ratings
    vector<int> c(n); // candies

    int num_c = 1; // num of candies to give
    c[0] = 1;
    cin >> r[0];
    // left to right
    for(int i = 1; i < n; ++i)
    {
        cin >> r[i];
        if(r[i] > r[i-1])
            ++num_c;
        else
            num_c = 1;
        c[i] = num_c;
    }

    // right to left
    num_c = 1;
    long total = c[n-1];
    for(int i = n-2; i >= 0; --i)
    {
        if (r[i] > r[i+1])
            ++num_c;
        else
            num_c = 1;
        c[i] = max(num_c, c[i]);
        total += c[i];
    }
    cout << total;
    return 0;
}
