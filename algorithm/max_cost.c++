#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void count(const vector<int>& B){
    int hi = 0, lo = 0;
    int hi_lo_diff, lo_hi_diff, lo_temp, hi_temp;
    for(int i = 1; i < B.size(); ++i)
    {
        hi_lo_diff = B[i-1] - 1;
        lo_hi_diff = B[i] - 1;

        lo_temp = max(lo, hi + hi_lo_diff);
        hi_temp = max(hi, lo + lo_hi_diff);

        lo = lo_temp;
        hi = hi_temp;
    }
    cout << max(hi, lo) << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<int> B(N);
        for(int i = 0; i < N; ++i)
            cin >> B[i];
        count(B);
    }
    return 0;
}
