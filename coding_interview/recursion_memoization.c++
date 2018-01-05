#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long count (int n, vector<long>& cache) {
    if (n < 3)
        return n;
    else if (n == 3)
        return 4;
    else if (cache[n] != 0)
        return cache[n];
    else {
        cache[n] = count(n - 1, cache) + count(n - 2, cache) + count(n - 3, cache);
        return cache[n];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int cases = 0;
    cin >> cases;
    while (cases--) {
        int n = 0;
        vector<long> cache(37);
        cin >> n;
        cout << count(n, cache) << endl;
    }
    return 0;
}
